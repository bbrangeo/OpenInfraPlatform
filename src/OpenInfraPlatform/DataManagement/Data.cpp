/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "Data.h"

#include "buw.BlueInfrastructure.h"
#include "BlueFramework/Core/Perlin.h"



#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Model.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadModel.h"
#include "OpenInfraPlatform/IfcRoad/reader/IfcStepReader.h"

#include "OpenInfraPlatform/IfcGeometryConverter/EMTIfcEntityTypes.h"
#include "OpenInfraPlatform/IfcGeometryConverter/EMTIfc2x3EntityTypes.h"
//#include "OpenInfraPlatform/IfcGeometryConverter/EMTIfc4EntityTypes.h"
//
#include "OpenInfraPlatform/DataManagement/IfcZipper.h"

#include "OpenInfraPlatform/Infrastructure/Export/LandXMLExport.h"

#include "OpenInfraPlatform/Ifc2x3/model/Ifc2x3Model.h"
#include "OpenInfraPlatform/Ifc2x3/model/Ifc2x3Exception.h"
#include "OpenInfraPlatform/Ifc2x3/reader/IfcStepReader.h"

#include "OpenInfraPlatform/IfcGeometryConverter/EMTIfcEntityTypesBridge.h"
#include "OpenInfraPlatform/IfcGeometryConverter/EMTIfcBridgeEntityTypes.h"

#include "OpenInfraPlatform/IfcBridge/model/IfcBridgeModel.h"
#include "OpenInfraPlatform/IfcBridge/model/IfcBridgeException.h"
#include "OpenInfraPlatform/IfcBridge/reader/IfcStepReader.h"

#include "OpenInfraPlatform/IfcGeometryConverter/IfcImporter.h"

#include "OpenInfraPlatform/IfcGeometryConverter/GeometryInputData.h"
#include "OpenInfraPlatform/IfcGeometryConverter/IfcPeekStepReader.h"

#include <QtXml>
#include <QtXmlPatterns>

#include "AsyncJob.h"

void import_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel, const std::string & filename);
void importLandXML_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename);
void importOKSTRA_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename);
void importRoadXML_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename);
void importIfcAlignment_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename);
void importIfcRoad_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename);
void importIfcBridge_Job(OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel, const std::string &filename);
void importStepFile_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename);
void importIfcStepFile_Job(OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel, const std::string &filename);
void importXYZ_Job(buw::DigitalElevationModel::Ptr digitalElevationModel, const std::vector<buw::vector3d>& positions);
void createTerrainFromHeightMap_Job(buw::DigitalElevationModel::Ptr digitalElevationModel, buw::vector3d& offsetViewArea, const std::string& filename);
void createRandomTerrain_Job(buw::DigitalElevationModel::Ptr digitalElevationModel, buw::vector3d& offsetViewArea, const buw::terrainDescription& td);
void importLAS_Job(std::vector<buw::LaserPoint>* pointCloud, int& chachedPointCloudCount, buw::vector3d& minPosPointCloud, buw::vector3d& maxPosPointCloud, const std::string& filename);

void exportIfcRoadTUMProposal_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename);
void exportIfcAlignment_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const buw::ifcAlignmentExportDescription& desc, const std::string & filename);
void exportSVG_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename);
void exportOkstra_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename, const std::string& version);
void export3DAlignmentAsTextfile_Job(buw::AlignmentModel::Ptr alignmentModel, const std::string& filename);
void exportLandXML_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename);


OpenInfraPlatform::DataManagement::Data::Data() : 
BlueFramework::Application::DataManagement::Data(new BlueFramework::Application::DataManagement::NotifiyAfterEachActionOnlyOnce<OpenInfraPlatform::DataManagement::Data>()),
clearColor_(0.3f, 0.5f, 0.9f),
enableGradientClear_(true),
bDrawGrid_(false),
bDrawSkybox_(false),
bShowViewCube_(true),
bShowReferenceCoordinateSystem(true),
alignmentLineWidth_(1.5f),
currentJobID_(-1)
{
	pointCloud_ = new std::vector<buw::LaserPoint>();
	temporaryPointCloud_ = new std::vector<buw::LaserPoint>();
	clear(false);

	AsyncJob::getInstance().jobFinished.connect(boost::bind(&OpenInfraPlatform::DataManagement::Data::jobFinished, this, _1, _2));
}

OpenInfraPlatform::DataManagement::Data::~Data()
{
	delete pointCloud_;
}

void OpenInfraPlatform::DataManagement::Data::save( const std::string & filename )
{
	QDomDocument doc;
	QDomProcessingInstruction header = doc.createProcessingInstruction( "xml", "version=\"1.0\"" );
	doc.appendChild( header );
	QDomElement root = doc.createElement( getApplicationNameXML() );
	root.setAttribute("version", getApplicationVersionString());
	doc.appendChild( root ); 

	// save entity objects
	QDomElement xmlAlignments = doc.createElement("Alignments");

	for (unsigned int i = 0; i < alignmentModel_->getAlignmentCount(); i++)
	{	
		buw::Alignment2DBased3D::Ptr alignment2d = std::static_pointer_cast<buw::Alignment2DBased3D>(alignmentModel_->getAlignment(i));
		QDomElement xmlAlignment2D = doc.createElement("Alignment2D");
		xmlAlignment2D.setAttribute("name", alignment2d->getName().toCString());
		if (alignment2d->hasHorizontalAlignment())
		{
			QDomElement xmlHorizaontal = doc.createElement("Horizontal");
			for (int horizontal_i = 0; horizontal_i < alignment2d->getHorizontalAlignment()->getAlignmentElementCount(); horizontal_i++)
			{
				buw::HorizontalAlignmentElement2D::Ptr horizontalElement = alignment2d->getHorizontalAlignment()->getAlignmentElementByIndex(horizontal_i);
				//std::cout << horizontalElement->getAlignmentType();
				if (horizontalElement->getAlignmentType() == buw::eHorizontalAlignmentType::Line)
				{
					buw::vector2d start, end;
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
					QDomElement xmlAlignmentLine = doc.createElement("Line");
					QDomElement xmlAlignmentLineStart = doc.createElement("Start");
					QDomElement xmlAlignmentLineEnd = doc.createElement("End");
					xmlAlignmentLineStart.setAttribute("startX", start.x() );
					xmlAlignmentLineStart.setAttribute("startY", start.y() );
					xmlAlignmentLineEnd.setAttribute("endX", end.x() );
					xmlAlignmentLineEnd.setAttribute("endY", end.y() );
					xmlAlignmentLine.setAttribute("length", alignment2d->getLength() );
					xmlAlignmentLine.appendChild(xmlAlignmentLineStart);
					xmlAlignmentLine.appendChild(xmlAlignmentLineEnd);
					xmlHorizaontal.appendChild(xmlAlignmentLine);
				}

				else if (horizontalElement->getAlignmentType() == buw::eHorizontalAlignmentType::Arc)
				{
					double radius;
					bool clockwiseBool;
					buw::vector2d center, start, end;
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Center, &center);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Radius, &radius);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise, &clockwiseBool);
					QDomElement xmlAlignmentArc = doc.createElement("Arc");
					QDomElement xmlAlignmentArcStart = doc.createElement("Start");
					QDomElement xmlAlignmentArcEnd = doc.createElement("End");
					xmlAlignmentArc.setAttribute("centerX", center.x());
					xmlAlignmentArc.setAttribute("centerY", center.y());
					xmlAlignmentArc.setAttribute("radius", radius );
					xmlAlignmentArc.setAttribute("clockwise", clockwiseBool );
					xmlAlignmentArcStart.setAttribute("startX", start.x() );
					xmlAlignmentArcStart.setAttribute("startY", start.y() );
					xmlAlignmentArcEnd.setAttribute("endX", end.x() );
					xmlAlignmentArcEnd.setAttribute("endY", end.y() );
					xmlAlignmentArc.appendChild(xmlAlignmentArcStart);
					xmlAlignmentArc.appendChild(xmlAlignmentArcEnd);
					xmlHorizaontal.appendChild(xmlAlignmentArc);
				}

				else if (horizontalElement->getAlignmentType() == buw::eHorizontalAlignmentType::Clothoid)
				{
					double radiusStart, radiusEnd, length;
					bool clockwiseBool;
					buw::vector2d start, end, pi;
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusStart, &radiusStart);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusEnd, &radiusEnd);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise, &clockwiseBool);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PI, &pi);
					horizontalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Length, &length);
					QDomElement xmlAlignmentClothoid = doc.createElement("Clothoid");
					QDomElement xmlAlignmentClothoidStart = doc.createElement("start");
					QDomElement xmlAlignmentClothoidEnd = doc.createElement("end");
					QDomElement xmlAlignmentClothoidPI = doc.createElement("pi");
					xmlAlignmentClothoid.setAttribute("length", length );
					xmlAlignmentClothoid.setAttribute("radiusStart", radiusStart );
					xmlAlignmentClothoid.setAttribute("radiusEnd", radiusEnd );
					xmlAlignmentClothoid.setAttribute("clockwise", clockwiseBool );
					xmlAlignmentClothoidStart.setAttribute("startX", start.x() );
					xmlAlignmentClothoidStart.setAttribute("startY", start.y() );
					xmlAlignmentClothoidEnd.setAttribute("endX", end.x() );
					xmlAlignmentClothoidEnd.setAttribute("endY", end.y() );
					xmlAlignmentClothoidPI.setAttribute("piX", pi.x() );
					xmlAlignmentClothoidPI.setAttribute("piY", pi.y() );
					xmlAlignmentClothoid.appendChild(xmlAlignmentClothoidStart);
					xmlAlignmentClothoid.appendChild(xmlAlignmentClothoidEnd);
					xmlAlignmentClothoid.appendChild(xmlAlignmentClothoidPI);
					xmlHorizaontal.appendChild(xmlAlignmentClothoid);
				}
				else
				{
					std::cout << horizontalElement->getAlignmentType();
				}
			}
			xmlAlignment2D.appendChild(xmlHorizaontal);
		}

		if (alignment2d->hasVerticalAlignment())
		{
			QDomElement xmlVertical = doc.createElement("Vertical");
			std::vector<buw::profAlignElement> list = buw::createProfAlignElements(alignment2d->getVerticalAlignment());

			for (int vertical_i = 0; vertical_i < alignment2d->getVerticalAlignment()->getAlignmentElementCount(); vertical_i++)
			{
				buw::VerticalAlignmentElement2D::Ptr verticalElement = alignment2d->getVerticalAlignment()->getAlignmentElementByIndex(vertical_i);
				if (verticalElement->getAlignmentType() == buw::eVerticalAlignmentType::Parabola)
				{
					buw::vector2d start, end, pvi;
					double inP, startGradient, endGradient;
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::IntersectionPointDistance, &inP);
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PVI, &pvi);
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartGradientAsPlaneAngleMeasure, &startGradient);
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndGradient, &endGradient);
					QDomElement xmlAlignmentParabola = doc.createElement("Parabola");
					QDomElement xmlAlignmentParabolaStart = doc.createElement("start");
					QDomElement xmlAlignmentParabolaEnd = doc.createElement("end");
					QDomElement xmlAlignmentParabolaPVI = doc.createElement("PVI");
					xmlAlignmentParabola.setAttribute("IntersectionPointDistance", inP);
					xmlAlignmentParabola.setAttribute("startGradient", startGradient);
					xmlAlignmentParabola.setAttribute("endGradient", endGradient);
					xmlAlignmentParabolaStart.setAttribute("startX", start.x() );
					xmlAlignmentParabolaStart.setAttribute("startY", start.y() );
					xmlAlignmentParabolaEnd.setAttribute("endX", end.x() );
					xmlAlignmentParabolaEnd.setAttribute("endY", end.y() );
					xmlAlignmentParabolaPVI.setAttribute("pviX", pvi.x() );
					xmlAlignmentParabolaPVI.setAttribute("pviY", pvi.y() );
					xmlAlignmentParabola.appendChild(xmlAlignmentParabolaStart);
					xmlAlignmentParabola.appendChild(xmlAlignmentParabolaEnd);
					xmlAlignmentParabola.appendChild(xmlAlignmentParabolaPVI);
					xmlVertical.appendChild(xmlAlignmentParabola);
				}

				if (verticalElement->getAlignmentType() == buw::eVerticalAlignmentType::Line)
				{
					buw::vector2d start, end;
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
					verticalElement->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
					QDomElement xmlAlignmentLine = doc.createElement("VerticalLine");
					QDomElement xmlAlignmentLineStart = doc.createElement("start");
					QDomElement xmlAlignmentLineEnd = doc.createElement("end");
					xmlAlignmentLineStart.setAttribute("startX", start.x() );
					xmlAlignmentLineStart.setAttribute("startY", start.y() );
					xmlAlignmentLineEnd.setAttribute("endX", end.x() );
					xmlAlignmentLineEnd.setAttribute("endY", end.y() );
					xmlAlignmentLine.appendChild(xmlAlignmentLineStart);
					xmlAlignmentLine.appendChild(xmlAlignmentLineEnd);
					xmlVertical.appendChild(xmlAlignmentLine);
				}
			}
			xmlAlignment2D.appendChild(xmlVertical);
		}
		xmlAlignments.appendChild(xmlAlignment2D);
	}
	root.appendChild(xmlAlignments);

	QFile file( filename.c_str() );
	if( !file.open( QIODevice::WriteOnly ) )
	{
		//return -1;
	}

	QTextStream ts( &file );
	ts << doc.toString();

	file.close();
}

void OpenInfraPlatform::DataManagement::Data::open( const std::string & filename )
{
	if (boost::filesystem::exists(filename))
	{
		buw::String buwstrFilename = filename.c_str();
		if (buwstrFilename.toLower().endsWith(".bic"))
		{
			alignmentModel_ = readBICFile(filename);
			Change(); // Inform observer that new data is available
		}
		else
		{
			import(filename);
		}
		recentFileName = QString::fromUtf8(filename.c_str());
	}
}

OpenInfraPlatform::Infrastructure::AlignmentModel::Ptr OpenInfraPlatform::DataManagement::Data::readBICFile(const std::string & filename)
{
	OpenInfraPlatform::Infrastructure::AlignmentModel::Ptr alignmentModel_ = std::make_shared<OpenInfraPlatform::Infrastructure::AlignmentModel>();
	QDomDocument domDoc;
	QFile xmlFile(filename.c_str());
	if(xmlFile.open(QIODevice::ReadOnly))
	{
		if(domDoc.setContent(&xmlFile))
		{
			QDomElement domElement		= domDoc.documentElement();
			QDomNode rootNode			= domElement.firstChild();
			QDomNodeList alignmentList	= rootNode.childNodes();
			QDomNode domNode			= rootNode.firstChild();

			for(int i=0; i<alignmentList.length(); i++)
			{
				buw::HorizontalAlignment2D::Ptr horizontalAlignment = std::make_shared<buw::HorizontalAlignment2D>();
				buw::VerticalAlignment2D::Ptr verticalAlignment		= std::make_shared<buw::VerticalAlignment2D>();
				buw::Alignment2DBased3D::Ptr alignment2D			= std::make_shared<buw::Alignment2DBased3D>();
				std::string alignmentName;
				if(domNode.isElement())
				{
					QDomElement domElement = domNode.toElement();
					if(!domElement.isNull())
					{
						//std::cout << domElement.tagName().toStdString() + "\n";
						if(domElement.tagName() == "Alignment2D")
						{
							//std::cout << domElement.attribute("name").toStdString() + "\n";
							alignmentName = domElement.attribute("name").toStdString();
							QDomNode		horiNode			= domNode.firstChild();
							QDomNode		verNode				= domNode.lastChild();
							QDomNodeList	horiChildNodes		= horiNode.childNodes();
							QDomNodeList	verChildNodes		= verNode.childNodes();
							QDomNode		domHoriChildNode	= horiNode.firstChild();
							QDomNode		domVerChildNode		= verNode.firstChild();
							
							for(int i=0; i<horiChildNodes.length(); i++)
							{
								QDomElement domChildElement = domHoriChildNode.toElement();
								//std::cout << domChildElement.tagName().toStdString() + "\n";
								if(domChildElement.tagName() == "Arc")
								{
									//std::cout << "Arc Radius : " + domChildElement.attribute("radius").toStdString() + "\n";
									buw::vector2d					center, start, end;
									bool							clockwise;
									start.x()					=	domChildElement.firstChildElement().attribute("startX").toDouble();
									start.y()					=	domChildElement.firstChildElement().attribute("startY").toDouble();
									end.x()						=	domChildElement.lastChildElement().attribute("endX").toDouble();
									end.y()						=	domChildElement.lastChildElement().attribute("endY").toDouble();
									center.x()					=	domChildElement.attribute("centerX").toDouble();
									center.y()					=	domChildElement.attribute("centerY").toDouble();
									clockwise					=	domChildElement.attribute("clockwise").toInt();
									buw::HorizontalAlignmentElement2DArc::Ptr arc			=	std::make_shared<buw::HorizontalAlignmentElement2DArc>(center, start, end, clockwise);
									horizontalAlignment->addElement(arc);
								}
								else if(domChildElement.tagName() == "Line")
								{
									//std::cout << "Line Length : " + domChildElement.attribute("length").toStdString() + "\n";
									//std::cout << domChildElement.firstChildElement().attribute("startX").toDouble();
									buw::vector2d					start;
									buw::vector2d					end;
									start.x()					=	domChildElement.firstChildElement().attribute("startX").toDouble();
									start.y()					=	domChildElement.firstChildElement().attribute("startY").toDouble();
									end.x()						=	domChildElement.lastChildElement().attribute("endX").toDouble();
									end.y()						=	domChildElement.lastChildElement().attribute("endY").toDouble();
									buw::HorizontalAlignmentElement2DLine::Ptr line			=	std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
									horizontalAlignment->addElement(line);
								}
								else
								{
									//std::cout << "Clothoid Length : " + domChildElement.attribute("length").toStdString() + "\n";
									buw::vector2d					start, end, pi;
									double							radiusStart, radiusEnd, length;
									bool							clockwise;
									start.x()					=	domChildElement.firstChildElement().attribute("startX").toDouble();
									start.y()					=	domChildElement.firstChildElement().attribute("startY").toDouble();
									end.x()						=	domChildElement.firstChildElement().nextSiblingElement().attribute("endX").toDouble();
									end.y()						=	domChildElement.firstChildElement().nextSiblingElement().attribute("endY").toDouble();
									pi.x()						=	domChildElement.lastChildElement().attribute("piX").toDouble();
									pi.y()						=	domChildElement.lastChildElement().attribute("piY").toDouble();
									radiusStart					=	domChildElement.attribute("radiusStart").toDouble();
									radiusEnd					=	domChildElement.attribute("radiusEnd").toDouble();
									length						=	domChildElement.attribute("length").toDouble();
									clockwise					=	domChildElement.attribute("clockwise").toInt();

									double startCurvature = 0;
									if (radiusStart != 0 && radiusStart != std::numeric_limits<double>::infinity())
										startCurvature = 1 / radiusStart;

									double endCurvature = 0;
									if (radiusEnd != 0 && radiusEnd != std::numeric_limits<double>::infinity())
										endCurvature = 1 / radiusEnd;

									double startDirection = buw::HorizontalAlignmentElement2DClothoid::computeStartDirection(start, pi);									
									double clothoidConstant = buw::HorizontalAlignmentElement2DClothoid::computeClothoidConstant(length, startCurvature, endCurvature);
									bool entry = buw::HorizontalAlignmentElement2DClothoid::computeEntry(startCurvature, endCurvature);

									buw::HorizontalAlignmentElement2DClothoid::Ptr clothoid = std::make_shared<buw::HorizontalAlignmentElement2DClothoid>(start, startDirection, startCurvature, !clockwise, clothoidConstant, entry, length);
									horizontalAlignment->addElement(clothoid);
								}
								domHoriChildNode = domHoriChildNode.nextSibling();
							}

							for(int i=0; i<verChildNodes.length(); i++)
							{
								QDomElement domChildElement = domVerChildNode.toElement();
								//std::cout << domChildElement.tagName().toStdString() + "\n";
								if(domChildElement.tagName() == "Parabola")
								{
									//std::cout << "Parabola StartX : " + domChildElement.firstChildElement().attribute("startX").toStdString() + "\n";
									buw::vector2d start, end;
									double startGradient=0.0, endGradient=0.0;
									start.x()						=	domChildElement.firstChildElement().attribute("startX").toDouble();
									start.y()						=	domChildElement.firstChildElement().attribute("startY").toDouble();
									end.x()							=	domChildElement.firstChildElement().nextSiblingElement().attribute("endX").toDouble();
									end.y()							=	domChildElement.firstChildElement().nextSiblingElement().attribute("endY").toDouble();
									startGradient					=	domChildElement.attribute("startGradient").toDouble();
									endGradient						=	domChildElement.attribute("endGradient").toDouble();
									buw::VerticalAlignmentElement2DParabola::Ptr parabola		=	std::make_shared<buw::VerticalAlignmentElement2DParabola>(start, end, startGradient, endGradient);
									verticalAlignment->addElement(parabola);
								}
								else
								{
									//std::cout << "VerticalLine StartX : " + domChildElement.firstChildElement().attribute("startX").toStdString() + "\n";
									buw::vector2d start, end;
									start.x()						=	domChildElement.firstChildElement().attribute("startX").toDouble();
									start.y()						=	domChildElement.firstChildElement().attribute("startY").toDouble();
									end.x()							=	domChildElement.lastChildElement().attribute("endX").toDouble();
									end.y()							=	domChildElement.lastChildElement().attribute("endY").toDouble();
									buw::VerticalAlignmentElement2DLine::Ptr vLine	=	std::make_shared<buw::VerticalAlignmentElement2DLine>(start, end);
									verticalAlignment->addElement(vLine);
								}
								domVerChildNode = domVerChildNode.nextSibling();
							}
						}
					}
				}
				alignment2D->setHorizontalAlignment(horizontalAlignment);
				alignment2D->setVerticalAlignment(verticalAlignment);
				std::wstring wstr(alignmentName.begin(), alignmentName.end());
				alignment2D->setName(wstr);
				alignmentModel_->addAlignment(alignment2D);
				domNode = domNode.nextSibling();
			}
		}
		xmlFile.close();
	}
	return alignmentModel_;
}

void OpenInfraPlatform::DataManagement::Data::clear(const bool notifyObservers)
{
	digitalElevationModel_ = std::make_shared<OpenInfraPlatform::Infrastructure::DigitalElevationModel>();
	alignmentModel_ = std::make_shared<OpenInfraPlatform::Infrastructure::AlignmentModel>();
	ifcGeometryModel_ = std::make_shared<IfcGeometryConverter::IfcGeometryModel>();
	
	if (pointCloud_)
		delete pointCloud_;
	pointCloud_ = new std::vector<buw::LaserPoint>();

	temporaryAlignmentModel_ = std::make_shared<buw::AlignmentModel>();
	temporaryDigitalElevationModel_ = std::make_shared<buw::DigitalElevationModel>();
	temporaryIfcGeometryModel_ = std::make_shared<IfcGeometryConverter::IfcGeometryModel>();

	if (temporaryPointCloud_)
		delete temporaryPointCloud_;
	temporaryPointCloud_ = new std::vector<buw::LaserPoint>();

	if (notifyObservers)
	{
		// The notification state is not used here, because a clear is not executed by an action.
		//m_pNotifiactionState->Change();

		Change();

		Clear();
	}
}

void OpenInfraPlatform::DataManagement::Data::clear()
{
	clear(true);
}

void OpenInfraPlatform::DataManagement::Data::import(const std::string & filename, bool async /*=true*/)
{
	BLUE_ASSERT(boost::filesystem::exists(filename))("File does not exist");

	if (boost::filesystem::exists(filename))
	{
		clear(false);

		prepareJob(DataModifierFlag::AlignmentModel_WRITE | DataModifierFlag::DigitalElevationModel_WRITE | DataModifierFlag::IFCGeometry_WRITE);

		if (async)
			currentJobID_ = AsyncJob::getInstance().startJob(&import_Job, temporaryAlignmentModel_, temporaryDigitalElevationModel_, temporaryIfcGeometryModel_, filename);
		else
			import_Job(alignmentModel_, digitalElevationModel_, ifcGeometryModel_, filename);
	}
}

void OpenInfraPlatform::DataManagement::Data::prepareJob(DataModifierFlag flag)
{
	if (flag & DataModifierFlag::AlignmentModel_READ)
		*temporaryAlignmentModel_ = *alignmentModel_;
	if (flag & DataModifierFlag::DigitalElevationModel_READ)
		*temporaryDigitalElevationModel_ = *digitalElevationModel_;
	if (flag & DataModifierFlag::IFCGeometry_READ)
		*temporaryIfcGeometryModel_ = *ifcGeometryModel_;
	if (flag & DataModifierFlag::PointCloud_READ)
	{
		*temporaryPointCloud_ = *pointCloud_;
		temporaryChachedPointCloudCount_ = chachedPointCloudCount_;
		temporaryMinPosPointCloud_ = minPosPointCloud_;
		temporaryMaxPosPointCloud_ = maxPosPointCloud_;
	}

	modifierFlag_ = flag;
}

void OpenInfraPlatform::DataManagement::Data::jobFinished(int jobID, bool completed)
{
	if (currentJobID_ != jobID || !completed)
		return;

	if (modifierFlag_ & DataModifierFlag::AlignmentModel_WRITE)
		*alignmentModel_ = *temporaryAlignmentModel_;
	if (modifierFlag_ & DataModifierFlag::DigitalElevationModel_WRITE)
		*digitalElevationModel_ = *temporaryDigitalElevationModel_;
	if (modifierFlag_ & DataModifierFlag::IFCGeometry_WRITE)
		*ifcGeometryModel_ = *temporaryIfcGeometryModel_;
	if (modifierFlag_ & DataModifierFlag::PointCloud_WRITE)
	{

		*pointCloud_ = *temporaryPointCloud_;
		chachedPointCloudCount_ = temporaryChachedPointCloudCount_;
		minPosPointCloud_ = temporaryMinPosPointCloud_;
		maxPosPointCloud_ = temporaryMaxPosPointCloud_;
	}

	if (modifierFlag_ & (
		DataModifierFlag::AlignmentModel_WRITE |
		DataModifierFlag::DigitalElevationModel_WRITE |
		DataModifierFlag::IFCGeometry_WRITE |
		DataModifierFlag::PointCloud_WRITE))
		Change();
}

void OpenInfraPlatform::DataManagement::Data::exportIfcRoadTUMProposal( const std::string& filename )
{
	prepareJob(DataModifierFlag::AlignmentModel_READ | DataModifierFlag::DigitalElevationModel_READ);

	currentJobID_ = AsyncJob::getInstance().startJob(&exportIfcRoadTUMProposal_Job, temporaryAlignmentModel_, temporaryDigitalElevationModel_, filename);
}

void OpenInfraPlatform::DataManagement::Data::exportIfcAlignment(const buw::ifcAlignmentExportDescription& desc, const std::string & filename)
{
	prepareJob(DataModifierFlag::AlignmentModel_READ | DataModifierFlag::DigitalElevationModel_READ);

	currentJobID_ = AsyncJob::getInstance().startJob(&exportIfcAlignment_Job, temporaryAlignmentModel_, temporaryDigitalElevationModel_, desc, filename);
}

void OpenInfraPlatform::DataManagement::Data::exportSVG( const std::string& filename )
{
	prepareJob(DataModifierFlag::AlignmentModel_READ | DataModifierFlag::DigitalElevationModel_READ);

	currentJobID_ = AsyncJob::getInstance().startJob(&exportSVG_Job, temporaryAlignmentModel_, temporaryDigitalElevationModel_, filename);
}

void OpenInfraPlatform::DataManagement::Data::exportOkstra(const std::string& filename, const std::string& version)
{
	prepareJob(DataModifierFlag::AlignmentModel_READ | DataModifierFlag::DigitalElevationModel_READ);

	currentJobID_ = AsyncJob::getInstance().startJob(&exportOkstra_Job, temporaryAlignmentModel_, temporaryDigitalElevationModel_, filename, version);
}

void OpenInfraPlatform::DataManagement::Data::export3DAlignmentAsTextfile(const std::string& filename)
{
	prepareJob(DataModifierFlag::AlignmentModel_READ | DataModifierFlag::DigitalElevationModel_READ);

	currentJobID_ = AsyncJob::getInstance().startJob(&export3DAlignmentAsTextfile_Job, temporaryAlignmentModel_, filename);
}



void OpenInfraPlatform::DataManagement::Data::exportLandXML(const std::string& filename)
{
	prepareJob(DataModifierFlag::AlignmentModel_READ | DataModifierFlag::DigitalElevationModel_READ);

	currentJobID_ = AsyncJob::getInstance().startJob(&exportLandXML_Job, temporaryAlignmentModel_, temporaryDigitalElevationModel_, filename);
}

void OpenInfraPlatform::DataManagement::Data::addAlignment( buw::IAlignment3D::Ptr alignment )
{
	alignmentModel_->addAlignment(alignment);
	Change();
}

void OpenInfraPlatform::DataManagement::Data::deleteAlignment(buw::IAlignment3D::Ptr alignment)
{
	alignmentModel_->deleteAlignment(alignment);
	Change();
}

void OpenInfraPlatform::DataManagement::Data::addSurface(buw::Surface::Ptr surface)
{
	digitalElevationModel_->addSurface(surface);
	Change();
}

void OpenInfraPlatform::DataManagement::Data::deleteSurface(buw::Surface::Ptr surface)
{
	digitalElevationModel_->deleteSurface(surface);
	Change();
}

void OpenInfraPlatform::DataManagement::Data::setClearColor( const buw::color3f& color )
{
	clearColor_ = color;

	Change();
}

buw::color3f OpenInfraPlatform::DataManagement::Data::getClearColor()
{
	return clearColor_;
}

void OpenInfraPlatform::DataManagement::Data::enableGradientClear( const bool enable )
{
	enableGradientClear_ = enable;

	Change();
}

bool OpenInfraPlatform::DataManagement::Data::isGradientClearEnabled() const
{
	return enableGradientClear_;
}

bool OpenInfraPlatform::DataManagement::Data::isDrawGridEnabled() const
{
	return bDrawGrid_;
}

void OpenInfraPlatform::DataManagement::Data::enableDrawGrid( bool val )
{
	bDrawGrid_ = val;

	Change();
}

const char* OpenInfraPlatform::DataManagement::Data::getApplicationName()
{
	return "TUM Open Infra Platform 2015";
}

const char* OpenInfraPlatform::DataManagement::Data::getApplicationVersionString()
{
	return "RTM";
}

const char* OpenInfraPlatform::DataManagement::Data::getApplicationOpenFileFilter()
{
	return "LandXML (*.xml);;OKSTRA (*.xml; *.cte);;IfcAlignment BuildingSmart P6 Step File (*.ifc);;TUM Open Infra Platform File (*.bic);;IfcRoad (TUM Proposal) ICCBEI 2015 (*.ifc);;IfcBridge Step File (*.stp);;All files (*.*)";
}

const char* OpenInfraPlatform::DataManagement::Data::getApplicationSaveFileFilter()
{
	return "TUM Open Infra Platform File (*.bic);;All files (*.*)";
}

const char* OpenInfraPlatform::DataManagement::Data::getApplicationImportFileFilter()
{
	return "LandXML (*.xml);;All files (*.*)";
}

const char* OpenInfraPlatform::DataManagement::Data::getApplicationNameXML()
{
	return "TUMOpenInfraPlatform";
}

OpenInfraPlatform::Infrastructure::DigitalElevationModel::Ptr 
OpenInfraPlatform::DataManagement::Data::getDigitalElevationModel() const
{
	return digitalElevationModel_;
}

void OpenInfraPlatform::DataManagement::Data::enableShowReferenceCoordinateSystem( bool enable )
{
	bShowReferenceCoordinateSystem = enable;

	Change();
}

bool OpenInfraPlatform::DataManagement::Data::isShowReferenceCoordinateSystemEnabled() const
{
	return bShowReferenceCoordinateSystem;
}

void OpenInfraPlatform::DataManagement::Data::enableSkybox( const bool enable )
{
	bDrawSkybox_ = enable;

	Change();
}

bool OpenInfraPlatform::DataManagement::Data::isSkyboxEnabled() const
{
	return bDrawSkybox_;
}


void OpenInfraPlatform::DataManagement::Data::importXYZ( const std::vector<buw::vector3d>& positions )
{
	prepareJob(DataModifierFlag::DigitalElevationModel_READ | DataModifierFlag::DigitalElevationModel_WRITE);

	currentJobID_ = AsyncJob::getInstance().startJob(&importXYZ_Job, temporaryDigitalElevationModel_, positions);
}

buw::vector3d OpenInfraPlatform::DataManagement::Data::getOffset() const
{
	buw::vector3d minPos;
	buw::vector3d maxPos;		
	digitalElevationModel_->getSurfacesExtend(minPos, maxPos);

	if (alignmentModel_->getAlignmentCount() > 0)
	{
		auto aabb = alignmentModel_->getExtends();

		if (digitalElevationModel_->getSurfaceCount() > 0)
		{
			minPos = getMinimizedVector(minPos, aabb.getMinimum());
			maxPos = getMaximizedVector(maxPos, aabb.getMaximum());
		}
		else
		{
			minPos = aabb.getMinimum();
			maxPos = aabb.getMaximum();
		}
	}

	if (pointCloud_->size() > 0)
	{
		minPos = minPosPointCloud_;
		maxPos = maxPosPointCloud_;
	}

	buw::vector3d offsetViewArea = minPos + 0.5 * (maxPos - minPos);

	return offsetViewArea;
}

void OpenInfraPlatform::DataManagement::Data::createTerrainFromHeightMap(
	const std::string& filename)
{
	prepareJob(DataModifierFlag::DigitalElevationModel_READ | DataModifierFlag::DigitalElevationModel_WRITE);

	currentJobID_ = AsyncJob::getInstance().startJob(&createTerrainFromHeightMap_Job, temporaryDigitalElevationModel_, getOffset(), filename);
}

void OpenInfraPlatform::DataManagement::Data::createRandomTerrain(
	const buw::terrainDescription& td)
{
	prepareJob(DataModifierFlag::DigitalElevationModel_READ | DataModifierFlag::DigitalElevationModel_WRITE);

	currentJobID_ = AsyncJob::getInstance().startJob(&createRandomTerrain_Job, temporaryDigitalElevationModel_, getOffset(), td);
}

void OpenInfraPlatform::DataManagement::Data::showViewCube(const bool enable)
{
	bShowViewCube_ = enable;

	Change();
}

bool OpenInfraPlatform::DataManagement::Data::isViewCubeEnabled()
{
	return bShowViewCube_;
}

void OpenInfraPlatform::DataManagement::Data::computeSurfaceProfile()
{
	buw::IAlignment3D::Ptr a = alignmentModel_->getAlignment(0);

	std::vector<std::pair<double, double>> surfaceProfile = digitalElevationModel_->getSurfaceProfile(a);
}

void OpenInfraPlatform::DataManagement::Data::setAlignmentLineWidth(const int width)
{
	alignmentLineWidth_ = static_cast<float>(width);

	Change();
}

OpenInfraPlatform::Infrastructure::AlignmentModel::Ptr OpenInfraPlatform::DataManagement::Data::getAlignmentModel() const
{
	return alignmentModel_;
}

OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr OpenInfraPlatform::DataManagement::Data::getIfcGeometryModel() const
{ 
	return ifcGeometryModel_;
}

const std::vector<buw::LaserPoint>& OpenInfraPlatform::DataManagement::Data::getPointCloud() const
{
	return *pointCloud_;
}

const int OpenInfraPlatform::DataManagement::Data::getPointCloudPointCount() const
{
	return pointCloud_->size();
}

void OpenInfraPlatform::DataManagement::Data::importLAS(const std::string& filename)
{
	prepareJob(DataModifierFlag::PointCloud_WRITE | DataModifierFlag::PointCloud_READ);
	currentJobID_ = AsyncJob::getInstance().startJob(&importLAS_Job, temporaryPointCloud_, std::ref(temporaryChachedPointCloudCount_), std::ref(temporaryMinPosPointCloud_), std::ref(temporaryMaxPosPointCloud_), filename);
}



void OpenInfraPlatform::DataManagement::Data::setShowFrameTimes(const bool enable)
{
	bShowFrameTime_ = enable;

	Change();
}

bool OpenInfraPlatform::DataManagement::Data::showFrameTimes() const
{
	return bShowFrameTime_;
}





// jobs

void import_Job(buw::AlignmentModel::Ptr alignmentModel, 
	buw::DigitalElevationModel::Ptr digitalElevationModel, 
	OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel, 
	const std::string & filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing ").append(filename));

	buw::String buwstrFilename = filename.c_str();
	if (buwstrFilename.toLower().endsWith(".xml"))
	{
		// could be LandXML or OKSTRA

		// The QDomDocument class represents an XML document.
		QDomDocument xmlBOM;
		// Load xml file as raw data
		QFile f(filename.c_str());
		if (!f.open(QIODevice::ReadOnly))
		{
			// Error while loading file
			std::cerr << "Error while loading file" << std::endl;
			throw std::runtime_error("Error while loading file");
		}

		// Set data into the QDomDocument before processing
		xmlBOM.setContent(&f);
		f.close();

		// Extract the root markup
		QDomElement root = xmlBOM.documentElement();

		// Get root names and attributes
		std::string type = root.tagName().toStdString();

		if (buw::startsWith("Land", type))
		{
			importLandXML_Job(alignmentModel, digitalElevationModel, filename);
		}
		else
		{
			importOKSTRA_Job(alignmentModel, digitalElevationModel, filename);
		}
	}
	else if (buwstrFilename.toLower().endsWith(".cte"))
	{
		importOKSTRA_Job(alignmentModel, digitalElevationModel, filename);
	}
	else if (buwstrFilename.toLower().endsWith(".rnd"))
	{
		importRoadXML_Job(alignmentModel, digitalElevationModel, filename);
	}
	
	/*new*/
	else if (buwstrFilename.toLower().endsWith(".ifczip")) {
		QUuid id = QUuid::createUuid();
		QString tempFilename = QDir::currentPath().append(QString("/").append(id.toString().append(".ifc")));
		
		OpenInfraPlatform::DataManagement::IfcZipper* importZipper = new OpenInfraPlatform::DataManagement::IfcZipper(NULL, QString(filename.data()),tempFilename, INFL);
		//QObject::connect(importZipper, &OpenInfraPlatform::DataManagement::IfcZipper::finished, importZipper, &QObject::deleteLater);
		importZipper->run();		
		import_Job(alignmentModel, digitalElevationModel, ifcGeometryModel, tempFilename.toStdString());
		QObject::connect(&OpenInfraPlatform::AsyncJob::getInstance(), &OpenInfraPlatform::AsyncJob::finished, importZipper, &OpenInfraPlatform::DataManagement::IfcZipper::removeFile);
		QObject::connect(importZipper, &OpenInfraPlatform::DataManagement::IfcZipper::fileDeleted, importZipper, &QObject::deleteLater);
	}

	else if (buwstrFilename.toLower().endsWith(".ifc"))
	{
		using OpenInfraPlatform::IfcGeometryConverter::IfcPeekStepReader;
		IfcPeekStepReader::IfcSchema ifcSchema = IfcPeekStepReader::parseIfcHeader(filename);

		if (ifcSchema == IfcPeekStepReader::IfcSchema::IFC_2)
		{
			importIfcStepFile_Job(ifcGeometryModel, filename);
		}
		else if (ifcSchema == IfcPeekStepReader::IfcSchema::IFC_4x1)
		{
			importIfcAlignment_Job(alignmentModel, digitalElevationModel, filename);
		}
		else if (ifcSchema == IfcPeekStepReader::IfcSchema::IFC_ROAD)
		{
			importIfcRoad_Job(alignmentModel, digitalElevationModel, filename);
		}
		else if (ifcSchema == IfcPeekStepReader::IfcSchema::IFC_BRIDGE)
		{
			importIfcBridge_Job(ifcGeometryModel, filename);
		}
		else
		{
			throw::std::exception("IFC file schema is not support by application.");
		}
	}
	else if (buwstrFilename.toLower().endsWith(".stp"))
	{
		using OpenInfraPlatform::IfcGeometryConverter::IfcPeekStepReader;
		IfcPeekStepReader::IfcSchema ifcSchema = IfcPeekStepReader::parseIfcHeader(filename);

		if (ifcSchema == IfcPeekStepReader::IfcSchema::IFC_BRIDGE)
		{
			importIfcBridge_Job(ifcGeometryModel, filename);
		}
		else
		{
			throw::std::exception("Step file schema is not support by application.");
		}
	}
}
void importLandXML_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing LandXML ").append(filename));

	buw::LandXmlImport parser(filename);

	for (int i = 0; i < parser.getAlignmentCount(); i++)
	{
		buw::IAlignment3D::Ptr a = parser.getAlignments()[i];
		alignmentModel->addAlignment(a);
	}

	if (parser.getDigitalElevationModel())
	{
		for (int i = 0; i < parser.getDigitalElevationModel()->getSurfaceCount(); i++)
		{
			digitalElevationModel->addSurface(parser.getDigitalElevationModel()->getSurface(i));
		}

		for (const std::vector<buw::vector3d>& breakLine : parser.getDigitalElevationModel()->getBreakLines())
		{
			digitalElevationModel->addBreakLine(breakLine);
		}
	}
}
void importOKSTRA_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing Okstra ").append(filename));

	buw::OkstraImport parser(filename);

	for (int i = 0; i < parser.getAlignmentCount(); i++)
	{
		buw::IAlignment3D::Ptr a = parser.getAlignments()[i];
		alignmentModel->addAlignment(a);
	}

	if (parser.getDigitalElevationModel())
	{
		for (int i = 0; i < parser.getDigitalElevationModel()->getSurfaceCount(); i++)
		{
			digitalElevationModel->addSurface(parser.getDigitalElevationModel()->getSurface(i));
		}
	}
}
void importRoadXML_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing RoadXML ").append(filename));

	buw::RoadXMLParser parser(filename.c_str());

	for (int i = 0; i < parser.getAlignmentCount(); i++)
	{
		buw::Alignment2DBased3D::Ptr a = parser.getAlignments()[i];
		alignmentModel->addAlignment(a);
	}
}
void importIfcAlignment_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing IfcAlignment ").append(filename));

	buw::IfcAlignmentImport parser(filename.c_str());

	for (int i = 0; i < parser.getAlignmentCount(); i++)
	{
		buw::Alignment2DBased3D::Ptr a = parser.getAlignments()[i];
		alignmentModel->addAlignment(a);
	}

	for (int i = 0; i < parser.getAlignmentCount3D(); i++)
	{
		buw::Alignment3DBased3D::Ptr a = parser.getAlignments3D()[i];
		alignmentModel->addAlignment(a);
	}

	std::vector<buw::Surface::Ptr> s = parser.getSurfaces();

	for (int i = 0; i < s.size(); i++)
	{
		digitalElevationModel->addSurface(s[i]);
	}
}
void importIfcRoad_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string &filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing IfcRoad ").append(filename));

	buw::IfcRoadImport parser(filename.c_str());

	for (int i = 0; i < parser.getAlignmentCount(); i++)
	{
		buw::Alignment2DBased3D::Ptr a = parser.getAlignments()[i];
		alignmentModel->addAlignment(a);
	}

	std::vector<buw::Surface::Ptr> s = parser.getSurfaces();

	for (int i = 0; i < s.size(); i++)
	{
		digitalElevationModel->addSurface(s[i]);
	}
}
void importStepFile_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing StepFile ").append(filename));

	//buw::TUMIfcAlignmentImport parser(filename.c_str());
	//
	//for (int i = 0; i < parser.getAlignmentCount(); i++)
	//{
	//	buw::Alignment2DBased3D::Ptr a = parser.getAlignments()[i];
	//	alignmentModel_->addAlignment(a);
	//}
}
void importIfcStepFile_Job(OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel, const std::string &filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing IfcStepFile ").append(filename));

	using namespace OpenInfraPlatform::Ifc2x3;
	using namespace OpenInfraPlatform::IfcGeometryConverter;

	IfcImporterT<emt::Ifc2x3EntityTypes, OpenInfraPlatform::Ifc2x3::UnitConverter,
		OpenInfraPlatform::Ifc2x3::Ifc2x3Model, OpenInfraPlatform::Ifc2x3::IfcStepReader,
		OpenInfraPlatform::Ifc2x3::Ifc2x3Exception, OpenInfraPlatform::Ifc2x3::Ifc2x3Entity> importer;

	try
	{
		importer.readStepFile(filename.c_str());

		importer.collectGeometryData();
	}
	catch (std::exception& e)
	{
		throw std::runtime_error(e.what());
	}

	auto& meshDescription = ifcGeometryModel->meshDescription_;
	meshDescription.vertices.clear();
	meshDescription.indices.clear();

	std::map<int, std::shared_ptr<ShapeInputDataT<emt::Ifc2x3EntityTypes>>>& shapeDatas = importer.getShapeDatas();

	ConverterBuwUtil::vertexMap_.clear();
	ConverterBuwUtil::vertexMap_.reserve(10000000);

	for (const auto& shapeData : shapeDatas)
	{
		std::shared_ptr<ShapeInputDataT<emt::Ifc2x3EntityTypes>> inputData = shapeData.second;

		std::shared_ptr<OpenInfraPlatform::Ifc2x3::IfcProduct>& product = inputData->ifc_product;

		for (const auto& itemData : inputData->vec_item_data)
		{
			for (const auto& meshset : itemData->meshsets)
			{
				ConverterBuwT<emt::Ifc2x3EntityTypes>::insertMeshSetIntoBuffers(product, meshset.get(),
					meshDescription.vertices, meshDescription.indices);
			}
		}
	}
}

void importIfcBridge_Job(OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel,
	const std::string &filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing IfcStepFile ").append(filename));

	using namespace OpenInfraPlatform::IfcGeometryConverter;
	using namespace OpenInfraPlatform::IfcBridge;

	IfcImporterT<emt::IfcBridgeEntityTypes, UnitConverter,
		IfcBridgeModel, IfcStepReader,
		IfcBridgeException, IfcBridgeEntity> importer;

	try
	{
		importer.readStepFile(filename.c_str());

		importer.collectGeometryData();
	}
	catch (std::exception& e)
	{
		throw std::runtime_error(e.what());
	}

	auto& meshDescription = ifcGeometryModel->meshDescription_;
	meshDescription.vertices.clear();
	meshDescription.indices.clear();

	auto& polylineDescription = ifcGeometryModel->polylineDescription_;
	polylineDescription.vertices.clear();
	polylineDescription.indices.clear();

	std::map<int, std::shared_ptr<ShapeInputDataT<emt::IfcBridgeEntityTypes>>>& shapeDatas = importer.getShapeDatas();

	ConverterBuwUtil::vertexMap_.clear();
	ConverterBuwUtil::vertexMap_.reserve(10000000);

	for (const auto& shapeData : shapeDatas)
	{
		std::shared_ptr<ShapeInputDataT<emt::IfcBridgeEntityTypes>> inputData = shapeData.second;

		std::shared_ptr<OpenInfraPlatform::IfcBridge::IfcProduct>& product = inputData->ifc_product;

		for (const auto& itemData : inputData->vec_item_data)
		{
			for (const auto& meshset : itemData->meshsets)
			{
				ConverterBuwT<emt::IfcBridgeEntityTypes>::insertMeshSetIntoBuffers(product, meshset.get(),
					meshDescription.vertices, meshDescription.indices);
			}

			uint32_t globalIndex = 0;

			// data for polylines
			for (const auto& polyline : itemData->polylines)
			{
				const size_t vertexCount = polyline->getVertexCount();

				// create vertex buffer for polylines
				for (auto i = 0; i < vertexCount; ++i)
				{
					carve::geom3d::Vector position = polyline->getVertex(i);
					buw::vector3f vertex(position[0], position[1], position[2]);

					polylineDescription.vertices.push_back(vertex);
				}

				// create index buffer for line lists
				for (const auto& line : polyline->polylines)
				{
					std::vector<int> pointIndexList = line.second;

					for (auto i = 0; i < pointIndexList.size() - 1; ++i)
					{
						auto index = pointIndexList[i];
						auto indexNext = pointIndexList[i + 1];

						polylineDescription.indices.push_back(index + globalIndex);
						polylineDescription.indices.push_back(indexNext + globalIndex);
					}
				}

				globalIndex += vertexCount;
			}
		}
	}
}
void importXYZ_Job(buw::DigitalElevationModel::Ptr digitalElevationModel, const std::vector<buw::vector3d>& positions)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus("Importing XYZ data");

	buw::Surface::Ptr surface = buw::createSurfaceFromXYZPoints(positions);
	digitalElevationModel->addSurface(surface);
}

void createTerrainFromHeightMap_Job(buw::DigitalElevationModel::Ptr digitalElevationModel, buw::vector3d& offsetViewArea, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Creating terrain from heightmap ").append(filename));

	buw::Image_4f::Ptr heightmap = buw::loadImageFromFile<buw::Image_4f>(filename.c_str());

	int totalIterations = heightmap->getHeight() * heightmap->getWidth() + (heightmap->getHeight() - 1) * (heightmap->getWidth() - 1);
	int iteration = 0;

	auto dgm = digitalElevationModel;

	buw::Surface::Ptr s = std::make_shared<buw::Surface>();
	s->setName("Random terrain");

	buw::vector3d p;

	int verticesID = 0;

	float tileSize = 1;// td.tileSize;

	for (int y = 0; y < heightmap->getHeight(); y++)
		for (int x = 0; x < heightmap->getWidth(); x++)
		{
		float one = (float)x / 16;
		float two = (float)y / 16;
		float v = heightmap->getPixelColor(x, y).red();

		// Generating the vertex positions
		p = buw::vector3d(x * tileSize, y * tileSize, v * 16) + offsetViewArea;
		s->addPoint(p);

		iteration++;
		}

	// Generating the triangle indicies
	for (int y = 0; y < heightmap->getHeight() - 1; y++)
	{
		for (int x = 0; x < heightmap->getWidth() - 1; x++)
		{
			float a = x + y      * heightmap->getWidth();
			float b = x + (y + 1) * heightmap->getWidth();
			float c = (x + 1) + y	    * heightmap->getWidth();

			buw::vector3i indicies(a, b, c);
			s->addTriangle(indicies);

			a = (x + 1) + y		 * heightmap->getWidth();
			b = x + (y + 1)	 * heightmap->getWidth();
			c = (x + 1) + (y + 1)	 * heightmap->getWidth();

			buw::vector3i indicies2(a, b, c);
			s->addTriangle(indicies2);

			iteration++;
		}
	}

	dgm->addSurface(s);
}
void createRandomTerrain_Job(buw::DigitalElevationModel::Ptr digitalElevationModel, buw::vector3d& offsetViewArea, const buw::terrainDescription& td)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus("Creating random terrain");

	/**
	Creating an instance of Perlin class

	@param octaves the number of octaves forming Perlin noise, it defines how noisy or smooth the function
	is. This is valid between 1 and 16.

	@param freq determines how many changes occur along a unit length, increasing the frequency will
	increase the number of terrain features. Reasonable values ranges from 1 to 8

	@param amp determines the range of output values. Setting it to 1 will return values between -1 and 1.

	@param seed it is the random number seed. This number causes the Perlin instance to be deterministic.
	*/
	buw::Perlin *perlin = new buw::Perlin(td.noOfOctaves, td.noiseFrequency, 1, 94);

	buw::Image_3f::Ptr heightmap = std::make_shared<buw::Image_3f>(td.terrainSize, td.terrainSize);

	int totalIterations = heightmap->getHeight() * heightmap->getWidth() + (heightmap->getHeight() - 1) * (heightmap->getWidth() - 1);
	int iteration = 0;

	auto dgm = digitalElevationModel;

	buw::Surface::Ptr s = std::make_shared<buw::Surface>();
	s->setName("Random terrain");

	buw::vector3d p;

	int verticesID = 0;

	float tileSize = td.tileSize;

	for (int y = 0; y < heightmap->getHeight(); y++)
		for (int x = 0; x < heightmap->getWidth(); x++)
		{
		float one = (float)x / 16;
		float two = (float)y / 16;
		float v = (perlin->perlin_noise_2D(one, two) + 1) / 2;
		heightmap->setPixelColor(x, y, buw::color3f(v, v, v));

		// Generating the vertex positions
		p = buw::vector3d(x * tileSize, y * tileSize, v * 16) + offsetViewArea;
		s->addPoint(p);

		iteration++;
		}

	delete perlin; // free memory

	// Generating the triangle indicies
	for (int y = 0; y < heightmap->getHeight() - 1; y++)
	{
		for (int x = 0; x < heightmap->getWidth() - 1; x++)
		{
			float a = x + y      * heightmap->getWidth();
			float b = x + (y + 1) * heightmap->getWidth();
			float c = (x + 1) + y	    * heightmap->getWidth();

			buw::vector3i indicies(a, b, c);
			s->addTriangle(indicies);

			a = (x + 1) + y		 * heightmap->getWidth();
			b = x + (y + 1)	 * heightmap->getWidth();
			c = (x + 1) + (y + 1)	 * heightmap->getWidth();

			buw::vector3i indicies2(a, b, c);
			s->addTriangle(indicies2);

			iteration++;
		}
	}

	dgm->addSurface(s);
}
void importLAS_Job(std::vector<buw::LaserPoint>* pointCloud, int& chachedPointCloudCount, buw::vector3d& minPosPointCloud, buw::vector3d& maxPosPointCloud, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Importing LAS ").append(filename));

	pointCloud->clear();
	buw::importLASPointCloud(filename.c_str(), *pointCloud);

	chachedPointCloudCount = pointCloud->size();

	buw::vector3d minv(0, 0, 0);
	buw::vector3d maxv(0, 0, 0);

	if (pointCloud->size() > 0)
	{
		minv = (*pointCloud)[0].position;
		maxv = (*pointCloud)[0].position;

		for (int i = 1; i < pointCloud->size(); i++)
		{
			minv = buw::getMinimizedVector(minv, (*pointCloud)[i].position);
			maxv = buw::getMaximizedVector(maxv, (*pointCloud)[i].position);
		}
	}

	minPosPointCloud = minv;
	maxPosPointCloud = maxv;
}

void exportIfcRoadTUMProposal_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Exporting IfcRoad ").append(filename));

	buw::IfcRoadExport sfc;
	buw::IfcRoadExportDescription desc;
	sfc.convert(desc, digitalElevationModel, alignmentModel->getAlignments(), filename);
}
void exportIfcAlignment_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const buw::ifcAlignmentExportDescription& desc, const std::string & filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Exporting IfcAlignment ").append(filename));

	buw::IfcAlignmentExport sfc;
	sfc.convert(desc, digitalElevationModel, alignmentModel->getAlignments(), filename);
}
void exportSVG_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Exporting SVG ").append(filename));

	buw::SVGExport::Ptr conv = std::make_shared<buw::SVGExport>();
	conv->convert(alignmentModel->getAlignments(), digitalElevationModel, filename.c_str());
}
void exportOkstra_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename, const std::string& version)
{
	auto delimiter = version.find(".");
	auto major = version.substr(0, delimiter);
	auto minor = version.substr(delimiter + 1, version.size() - 1);

	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Exporting Okstra ").append(version).append(" ").append(filename));

	buw::OkstraExport oe(filename.c_str(), stoi(major), stoi(minor), alignmentModel->getAlignments(), digitalElevationModel);
}
void export3DAlignmentAsTextfile_Job(buw::AlignmentModel::Ptr alignmentModel, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Exporting Alignment as text file ").append(filename));

	std::ofstream outfile;
	outfile.open(filename.c_str());

	outfile << "Format: X/Y/Z/stationing" << std::endl;

	for (int i = 0; i < alignmentModel->getAlignmentCount(); i++)
	{
		auto a = alignmentModel->getAlignment(i);

		outfile << "--------------------------------------------" << std::endl;
		outfile << "Name         : " << a->getName().toCString() << std::endl;
		outfile << "Start Station: " << a->getStartStation() << std::endl;
		outfile << "End Station  : " << a->getEndStation() << std::endl;

		for (double s = a->getStartStation(); s < a->getEndStation(); s += 1.0)
		{
			buw::vector3d pos = a->getPosition(s);
			outfile << std::fixed << pos << " " << s << std::endl;
		}
	}

	outfile.close();
}

void exportLandXML_Job(buw::AlignmentModel::Ptr alignmentModel, buw::DigitalElevationModel::Ptr digitalElevationModel, const std::string& filename)
{
	OpenInfraPlatform::AsyncJob::getInstance().updateStatus(std::string("Exporting LandXML ").append(filename));

	buw::exportAsLandXML(digitalElevationModel, alignmentModel, filename);
}