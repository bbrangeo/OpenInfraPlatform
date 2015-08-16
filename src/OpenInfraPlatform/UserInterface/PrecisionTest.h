#pragma once

#include "OpenInfraPlatform/DataManagement/AsyncJob.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class PrecisionTest
		{
			enum State
			{
				DoNothing,
				ExportingIfc,
				ImportingIfc,
				ExportingOkstra,
				ImportingOkstra
			};

		public:
			PrecisionTest()
			{
				state = DoNothing;
				OpenInfraPlatform::AsyncJob::getInstance().jobFinished.connect(boost::bind(&PrecisionTest::jobFinished, this, _1, _2));
			}

			void startTest(int iterations)
			{

				/*
				<Spiral length="100." radiusEnd="INF" radiusStart="63." rot="cw" spiType="clothoid" theta="45.472840883399" totalY="25.28836814527" totalX="93.882217969276" tanLong="69.007833869073" tanShort="35.471630182656">
				<Start>4007.416452674545 7812.092296369315</Start>
				<PI>3973.275113622304 7821.715472328171</PI>
				<End>3913.351640529602 7787.491818113435</End>
				</Spiral>
				*/

				buw::vector2d startPosition(4007.416452674545, 7812.092296369315);
				double startDirection = buw::HorizontalAlignmentElement2DClothoid::computeStartDirection(startPosition, buw::vector2d(3973.275113622304, 7821.715472328171));
				double startCurvature = 1.0/63.0;
				bool counterClockwise = false;
				double clothoidConstant = buw::HorizontalAlignmentElement2DClothoid::computeClothoidConstant(100, startCurvature, 0);
				bool entry = buw::HorizontalAlignmentElement2DClothoid::computeEntry(startCurvature, 0);;
				double length = 90;

				clothoid = std::make_shared<buw::HorizontalAlignmentElement2DClothoid>(
					startPosition,
					startDirection,
					startCurvature,
					counterClockwise,
					clothoidConstant,
					entry,
					length);

				tempClothoid = clothoid;


				totalIterations = iterations;
				iteration = 0;

				exportIfc();
			}
		private:

			void jobFinished(int jobID, bool completed)
			{
				if (completed)
				{
					next();
				}
			}

			void next()
			{				
				switch (state)
				{
				case DoNothing:
					break;
				case ExportingIfc:
					importIfc();
					break;
				case ImportingIfc:
					importFinished();
					exportOkstra();
					break;
				case ExportingOkstra:
					importOkstra();
					iteration++;
					break;
				case ImportingOkstra:
					importFinished();
					if (iteration < totalIterations)
						exportIfc();
					else
						eval();

					break;
				default:
					break;
				}
			}

			void exportIfc()
			{
				std::cout << "export ifc" << std::endl;

				state = ExportingIfc;

				buw::HorizontalAlignment2D::Ptr horizontalAlignment = std::make_shared<buw::HorizontalAlignment2D>();
				horizontalAlignment->addElement(tempClothoid);
				buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment);

				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().clear();
				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);

				buw::ifcAlignmentExportDescription desc;
				desc.exportAlignment = true;
				desc.exportTerrain = false;
				desc.useRadiansInsteadOfDegrees = true;

				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcAlignment(desc, "ifcPrecisionTest.ifc");
			}

			void exportOkstra()
			{
				std::cout << "export okstra" << std::endl;
				state = ExportingOkstra;

				buw::HorizontalAlignment2D::Ptr horizontalAlignment = std::make_shared<buw::HorizontalAlignment2D>();
				horizontalAlignment->addElement(tempClothoid);
				buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment);

				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().clear();
				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);

				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportOkstra("okstraPrecisionTest.xml", "2.016");
			}

			void importIfc()
			{
				std::cout << "import ifc" << std::endl;
				state = ImportingIfc;

				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().clear();
				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("ifcPrecisionTest.ifc");
			}

			void importOkstra()
			{
				std::cout << "import okstra" << std::endl;
				state = ImportingOkstra;

				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().clear();
				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("okstraPrecisionTest.xml");
			}

			void importFinished()
			{
				buw::IAlignment3D::Ptr a = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel()->getAlignment(0);

				buw::Alignment2DBased3D::Ptr alignment2D = std::static_pointer_cast<buw::Alignment2DBased3D>(a);
				buw::HorizontalAlignment2D::Ptr horizontalAlignment = alignment2D->getHorizontalAlignment();

				buw::HorizontalAlignmentElement2D::Ptr element = horizontalAlignment->getAlignmentElementByIndex(0);
				tempClothoid = std::static_pointer_cast<buw::HorizontalAlignmentElement2DClothoid>(element);
			}

			template<typename T>
			struct Diff
			{
				T target;
				T actual;

				T diff()
				{
					return actual - target;
				}
			};

			template<>
			struct Diff < bool >
			{
				bool target;
				bool actual;
				bool diff()
				{
					return actual != target;
				}
			};

			

			void eval()
			{
				state = DoNothing;

				Diff<buw::vector2d> start;
				start.target = clothoid->getStartPosition();
				start.actual = tempClothoid->getStartPosition();

				Diff<buw::vector2d> end;
				end.target = clothoid->getEndPosition();
				end.actual = tempClothoid->getEndPosition();

				Diff<buw::vector2d> pi;
				pi.target = clothoid->getPiPosition();
				pi.actual = tempClothoid->getPiPosition();

				Diff<double> startDirection;
				startDirection.target = clothoid->getStartDirection();
				startDirection.actual = tempClothoid->getStartDirection();

				Diff<double> endDirection;
				endDirection.target = clothoid->getEndDirection();
				endDirection.actual = tempClothoid->getEndDirection();


				Diff<double> startCurvature;
				startCurvature.target = clothoid->getStartCurvature();
				startCurvature.actual = tempClothoid->getStartCurvature();

				Diff<double> endCurvature;
				endCurvature.target = clothoid->getEndCurvature();
				endCurvature.actual = tempClothoid->getEndCurvature();

				Diff<double> clothoidConstant;
				clothoidConstant.target = clothoid->getClothoidConstant();
				clothoidConstant.actual = tempClothoid->getClothoidConstant();

				Diff<double> length;
				length.target = clothoid->getLength();
				length.actual = tempClothoid->getLength();

				Diff<bool> isEntry;
				isEntry.target = clothoid->isEntry();
				isEntry.actual = tempClothoid->isEntry();

				Diff<bool> ccw;
				ccw.target = clothoid->isCounterClockwise();
				ccw.actual = tempClothoid->isCounterClockwise();

				std::cout << "Results:" << std::endl;
				std::cout << "StartPosition:\t" << start.diff() << std::endl;
				std::cout << "EndPosition:\t\t" << end.diff() << std::endl;
				std::cout << "PiPosition:\t\t" << pi.diff() << std::endl;
				std::cout << "StartDirection:\t" << startDirection.diff() << std::endl;
				std::cout << "EndDirection:\t\t" << endDirection.diff() << std::endl;
				std::cout << "StartCurvature:\t\t" << startCurvature.diff() << std::endl;
				std::cout << "EndCurvature:\t\t" << endCurvature.diff() << std::endl;
				std::cout << "ClothoidConstant:\t" << clothoidConstant.diff() << std::endl;
				std::cout << "Length:\t\t\t" << length.diff() << std::endl;
				std::cout << "IsEntry:\t\t\t" << isEntry.diff() << std::endl;
				std::cout << "IsCCW:\t\t\t" << ccw.diff() << std::endl;
				std::cout << std::endl;

				/*buw::vector2d start, startIfc, startOkstra;
				buw::vector2d end, endIfc, endOkstra;
				buw::vector2d pi, piIfc, piOkstra;
				double startDirection, startDirectionIfc, startDirectionOkstra;
				double endDirection, endDirectionIfc, endDirectionOkstra;
				double clothoidConstant, clothoidConstantIfc, clothoidConstantOkstra;
				double length, lengthIfc, lengthOkstra;
				bool isEntry, isEntryIfc, isEntryOkstra;
				bool ccw, ccwIfc, ccwOkstra;


				start = clothoid->getStartPosition();
				startIfc = clothoidIfc->getStartPosition();
				startOkstra = clothoidOkstra->getStartPosition();

				end = clothoid->getEndPosition();
				endIfc = clothoidIfc->getEndPosition();
				endOkstra = clothoidOkstra->getEndPosition();

				pi = clothoid->getPiPosition();
				piIfc = clothoidIfc->getPiPosition();
				piOkstra = clothoidOkstra->getPiPosition();

				startDirection = clothoid->getStartDirection();
				startDirectionIfc = clothoidIfc->getStartDirection();
				startDirectionOkstra = clothoidOkstra->getStartDirection();

				endDirection = clothoid->getEndDirection();
				endDirectionIfc = clothoidIfc->getEndDirection();
				endDirectionOkstra = clothoidOkstra->getEndDirection();

				clothoidConstant = clothoid->getClothoidConstant();
				clothoidConstantIfc = clothoidIfc->getClothoidConstant();
				clothoidConstantOkstra = clothoidOkstra->getClothoidConstant();

				length = clothoid->getLength();
				lengthIfc = clothoidIfc->getLength();
				lengthOkstra = clothoidOkstra->getLength();

				isEntry = clothoid->isEntry();
				isEntryIfc = clothoidIfc->isEntry();
				isEntryOkstra = clothoidOkstra->isEntry();

				ccw = clothoid->isCounterClockwise();
				ccwIfc = clothoidIfc->isCounterClockwise();
				ccwOkstra = clothoidOkstra->isCounterClockwise();

				double startRadius, startRadiusIfc, startRadiusOkstra;
				double endRadius, endRadiusIfc, endRadiusOkstra;

				startRadius = clothoid->getStartRadius();
				startRadiusIfc = clothoidIfc->getStartRadius();
				startRadiusOkstra = clothoidOkstra->getStartRadius();

				endRadius = clothoid->getEndRadius();
				endRadiusIfc = clothoidIfc->getEndRadius();
				endRadiusOkstra = clothoidOkstra->getEndRadius();*/

				int i = 0;
			}


		private:
			buw::HorizontalAlignmentElement2DClothoid::Ptr clothoid, tempClothoid;
			State state;

			int iteration, totalIterations;
		};
	}
}