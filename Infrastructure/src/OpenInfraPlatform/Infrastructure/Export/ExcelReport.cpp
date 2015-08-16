/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "ExcelReport.h"

#include "OpenInfraPlatform/Infrastructure/Import/LandXmlImport.h"
#include "OpenInfraPlatform/Infrastructure/Import/IfcAlignmentImport.h"
#include "OpenInfraPlatform/Infrastructure/Export/IfcAlignmentExport.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DLine.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DArc.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/VerticalAlignment/VerticalAlignmentElement2DLine.h"

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Model.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcAlignment/writer/IfcStepWriter.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6Entities.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6Types.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Model.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcAlignmentReader.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcAlignment/model/UnitConverter.h"
#include "OpenInfraPlatform/IfcAlignment/entity/include/IfcCartesianPoint.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"

#include "xlsxdocument.h"
#include "xlsxformat.h"
#include "xlsxcellrange.h"
#include "xlsxworksheet.h"

using namespace OpenInfraPlatform::IfcAlignment;

namespace OpenInfraPlatform 
{
	namespace Infrastructure
	{
		class IfcAlignmentDataBuilder
		{
		public:
			IfcAlignmentDataBuilder() {}

			virtual ~IfcAlignmentDataBuilder() {}

			virtual void createGeoreferencingOffset(const buw::vector3d& offset) {};

			virtual void createIfcAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> alignment) {}

			virtual void createIfcAlignment2DHorizontal(std::shared_ptr<IfcAlignment2DHorizontal> alignment) {}

			virtual void createIfcAlignment2DVertical(std::shared_ptr<IfcAlignment2DVertical> alignment) {}

			//---------------------------------------------------------------------------//
			// Horizontal alignment
			//---------------------------------------------------------------------------//

			virtual void createIfcLineSegment2D(std::shared_ptr<IfcLineSegment2D> segment) {}

			virtual void createIfcCircularArcSegment2D(std::shared_ptr<IfcCircularArcSegment2D> segment) {}

			virtual void createIfcClothoidalArcSegment2D(std::shared_ptr<IfcClothoidalArcSegment2D> segment) {}

			//---------------------------------------------------------------------------//
			// Vertical alignment
			//---------------------------------------------------------------------------//

			virtual void createIfcAlignment2DVerSegLine(std::shared_ptr<IfcAlignment2DVerSegLine> segment) {}

			virtual void createIfcAlignment2DVerSegCircularArc(std::shared_ptr<IfcAlignment2DVerSegCircularArc> segment) {}

			virtual void createIfcAlignment2DVerSegParabolicArc(std::shared_ptr<IfcAlignment2DVerSegParabolicArc> segment) {}
		};

		class IfcAlignmentImportDirector
		{
		public:
			IfcAlignmentImportDirector(const char* filename, IfcAlignmentDataBuilder* builder) :
				builder_(builder)
			{
				shared_ptr<IfcStepReader> m_step_reader = shared_ptr<IfcStepReader>(new IfcStepReader());
				shared_ptr<IfcAlignmentModel> m_ifc_model(new IfcAlignmentModel());

				// open file
				std::ifstream infile;
				infile.open(filename, std::ifstream::in);

				if (!infile.is_open())
				{
					throw buw::FileNotFoundException("Could not open file.");
				}

				// get length of file:
				infile.seekg(0, std::ios::end);
				const int length = infile.tellg();
				infile.seekg(0, std::ios::beg);

				// allocate memory:
				std::string buffer(length, '\0');

				// read data as a block:
				infile.read(&buffer[0], length);
				infile.close();

				m_ifc_model->clearIfcModel();

				int millisecs_read_start = clock();
				m_step_reader->readStreamHeader(buffer, m_ifc_model);
				std::string file_schema_version = m_ifc_model->getFileSchema();
				std::map<int, shared_ptr<IfcAlignmentP6Entity> > map_entities;

				try
				{
					m_step_reader->readStreamData(buffer, map_entities);
				}
				catch (IfcAlignmentP6Exception& e)
				{
					throw buw::Exception(e.what());
				}

				// get offset value!
				offset_ = buw::vector3d(0.0);

				for (auto it = map_entities.begin(); it != map_entities.end(); it++)
				{
					if (it->second->m_entity_enum == IFCMAPCONVERSION)
					{
						std::shared_ptr<IfcMapConversion> mapConversion = std::static_pointer_cast<IfcMapConversion>(it->second);

						BLUE_ASSERT(mapConversion->m_Eastings != nullptr, "Invalid easting.");
						BLUE_ASSERT(mapConversion->m_Northings != nullptr, "Invalid northing.");

						offset_.x() = mapConversion->m_Eastings->m_value;
						offset_.y() = mapConversion->m_Northings->m_value;

						builder_->createGeoreferencingOffset(offset_);
					}
				}

				for (auto it = map_entities.begin(); it != map_entities.end(); it++)
				{
					if (it->second->m_entity_enum == IFCALIGNMENT)
					{
						std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> alignment = 
							std::static_pointer_cast<OpenInfraPlatform::IfcAlignment::IfcAlignment>(it->second);

						builder_->createIfcAlignment(alignment);

						createAlignment(alignment);
					}
				}
			}

		private:
			void createAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
			{
				builder_->createIfcAlignment(ifcAlignment);
				createHorizontalAlignment(ifcAlignment);
				createVerticalAlignment(ifcAlignment);
			}

			void createHorizontalAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
			{
				if (ifcAlignment->m_Horizontal != nullptr)
				{
					builder_->createIfcAlignment2DHorizontal(ifcAlignment->m_Horizontal);

					for (int i = 0; i < ifcAlignment->m_Horizontal->m_Segments.size(); i++)
					{
						std::shared_ptr<IfcCurveSegment2D> curveSegment = ifcAlignment->m_Horizontal->m_Segments[i]->m_CurveGeometry;

						BLUE_ASSERT(curveSegment != nullptr, "Invalid segment.");

						if (strcmp("IfcLineSegment2D", curveSegment->classname()) == 0)
						{
							createHorizontalLine(curveSegment);
							continue;
						}

						if (strcmp("IfcCircularArcSegment2D", curveSegment->classname()) == 0)
						{
							createHorizontalArc(curveSegment);
							continue;
						}

						if (strcmp("IfcClothoidalArcSegment2D", curveSegment->classname()) == 0)
						{
							createHorizontalClothoid(curveSegment);
							continue;
						}
					}
				}
			}

			void createHorizontalLine(std::shared_ptr<IfcCurveSegment2D> curveSegment)
			{
				std::shared_ptr<IfcLineSegment2D> ifcLine = std::static_pointer_cast<IfcLineSegment2D>(curveSegment);
				builder_->createIfcLineSegment2D(ifcLine);
			}

			void createHorizontalArc(std::shared_ptr<IfcCurveSegment2D> curveSegment)
			{
				std::shared_ptr<IfcCircularArcSegment2D> ifcArc = std::static_pointer_cast<IfcCircularArcSegment2D>(curveSegment);
				builder_->createIfcCircularArcSegment2D(ifcArc);
			}

			void createHorizontalClothoid(std::shared_ptr<IfcCurveSegment2D> curveSegment)
			{
				std::shared_ptr<IfcClothoidalArcSegment2D> ifcClothoid = std::static_pointer_cast<IfcClothoidalArcSegment2D>(curveSegment);
				builder_->createIfcClothoidalArcSegment2D(ifcClothoid);
			}

			void createVerticalAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
			{
				if (ifcAlignment->m_Horizontal != nullptr)
				{
					if (ifcAlignment->m_Vertical == nullptr)
						return;

					builder_->createIfcAlignment2DVertical(ifcAlignment->m_Vertical);
					
					for (int i = 0; i < ifcAlignment->m_Vertical->m_Segments.size(); i++)
					{
						shared_ptr<IfcAlignment2DVerticalSegment> vs = ifcAlignment->m_Vertical->m_Segments[i];

						BLUE_ASSERT(vs != nullptr, "Invalid vertical segment.");

						if (strcmp("IfcAlignment2DVerSegLine", vs->classname()) == 0)
						{
							createVerticalAlignmentLine(vs);
						}
						else if (strcmp("IfcAlignment2DVerSegParabolicArc", vs->classname()) == 0)
						{
							createVerticalAlignmentParabola(vs);
						}
						else if (strcmp("IfcAlignment2DVerSegCircularArc", vs->classname()) == 0)
						{
							createVerticalAlignmentSegCircularArc(vs);
						}
						else
						{
							std::string className = vs->classname();
							BLUE_ASSERT(false, "Invalid segment!");
						}
					}
				}
			}

			void createVerticalAlignmentLine(shared_ptr<IfcAlignment2DVerticalSegment> vs)
			{
				std::shared_ptr<IfcAlignment2DVerSegLine> segment = std::static_pointer_cast<IfcAlignment2DVerSegLine>(vs);
				builder_->createIfcAlignment2DVerSegLine(segment);
			}

			void createVerticalAlignmentSegCircularArc(shared_ptr<IfcAlignment2DVerticalSegment> vs)
			{
				std::shared_ptr<IfcAlignment2DVerSegCircularArc> segment = std::static_pointer_cast<IfcAlignment2DVerSegCircularArc>(vs);
				builder_->createIfcAlignment2DVerSegCircularArc(segment);
			}

			void createVerticalAlignmentParabola(shared_ptr<IfcAlignment2DVerticalSegment> vs)
			{
				std::shared_ptr<IfcAlignment2DVerSegParabolicArc> segment = std::static_pointer_cast<IfcAlignment2DVerSegParabolicArc>(vs);
				builder_->createIfcAlignment2DVerSegParabolicArc(segment);
			}
			
		private:
			buw::vector3d				offset_;
			IfcAlignmentDataBuilder*	builder_;
		};

		void constructP6IfcAlignmentData(
			const char* filename,
			IfcAlignmentDataBuilder* builder)
		{
			IfcAlignmentImportDirector director(filename, builder);
		}
	} // end namespace Infrastructure
} // end namespace BlueFramework

class AlignmentExcelSheetReport : public buw::LandXMLDataBuilder, public OpenInfraPlatform::Infrastructure::IfcAlignmentDataBuilder
{
public:
	AlignmentExcelSheetReport(
		const char* excelExportFilename, 
		const OpenInfraPlatform::Infrastructure::LandXMLHorizontalAlignmentReportSettings& LandXMLSettings,
		const OpenInfraPlatform::Infrastructure::P6IfcHorizontalAlignmentReportSettings& ifcP6HorizontalAlignmentSettings,
		const OpenInfraPlatform::Infrastructure::P6IfcVerticalAlignmentReportSettings& ifcP6VerticalAlignmentSettings) :
	excelExportFilename_(excelExportFilename),
	landXMLHorizontalAlignmentReportSettings_(LandXMLSettings),
	P6IfcHorizontalAlignmentSettings_(ifcP6HorizontalAlignmentSettings),
	P6IfcVerticalAlignmentSettings_(ifcP6VerticalAlignmentSettings)
	{
		xlsx_.addSheet("Horizontal alignment elements");
		
		writeLandXMLDataHeaderCell(1, LandXMLStartColumn_, "LandXML");

		createLandXMLHeaderRow(LandXMLSettings);

		writeP6IfcAlignmentDataHeaderCell(1, getLandXMLColumnCount() + 1, "P6 IFC Alignment");

		writeP6IfcAlignmentDataHeaderCell(1, getLandXMLColumnCount() + 3, "Georeferencing");

		writeDerivedDataHeaderHeaderCell(1, getLandXMLColumnCount() + 1 + 11, "Check");

		createP6IfcHorizontalAlignmentHeaderRow(ifcP6HorizontalAlignmentSettings);
	
		xlsx_.addSheet("Vertical alignment elements");
		createP6IfcVerticalAlignmentHeaderRow();
		writeP6IfcAlignmentDataHeaderCell(1, 1, "P6 IFC Alignment");
		writeDerivedDataHeaderHeaderCell(1, 10, "Check");

		xlsx_.selectSheet("Horizontal alignment elements");
	}

	virtual ~AlignmentExcelSheetReport() {}

	void writeIFCOffset()
	{
		xlsx_.selectSheet("Horizontal alignment elements");
		writeP6IfcAlignmentDataCell(1, getLandXMLColumnCount() + 4, P6IfcAlignmentOffset_.x());
		writeP6IfcAlignmentDataCell(1, getLandXMLColumnCount() + 5, P6IfcAlignmentOffset_.y());
	}

	void save()
	{
		// select first sheet
		xlsx_.selectSheet("Horizontal alignment elements");
		xlsx_.saveAs(excelExportFilename_.c_str());
	}

private:
	//---------------------------------------------------------------------------//
	// IFC Alignment
	//---------------------------------------------------------------------------//

	virtual void createIfcAlignment(std::shared_ptr<IfcAlignment> alignment) override
	{
		if (alignment->m_Description != nullptr)
		{
			P6IfcAlignmentName = alignment->m_Description->m_value;
		}
		else
			P6IfcAlignmentName = "";
	}

	virtual void createIfcAlignment2DHorizontal(std::shared_ptr<IfcAlignment2DHorizontal> alignment) override 
	{
		xlsx_.selectSheet("Horizontal alignment elements");
	}

	virtual void createIfcAlignment2DVertical(std::shared_ptr<IfcAlignment2DVertical> alignment) override 
	{
		xlsx_.selectSheet("Vertical alignment elements");
	}

	virtual void createGeoreferencingOffset(const buw::vector3d& offset) 
	{
		P6IfcAlignmentOffset_ = offset;
	}

	virtual void createIfcLineSegment2D(std::shared_ptr<IfcLineSegment2D> segment) override
	{
		int row = P6IfcHorizontalAlignmentCurrentRow_;
		int col = P6IfcHorizontalAlignmentStartColumn_;

		if (P6IfcHorizontalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataCell(row, col, P6IfcAlignmentName.c_str());
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.type)
		{
			writeP6IfcAlignmentDataCell(row, col, "IfcLineSegment2D");
			col++;
		}
		
		if (P6IfcHorizontalAlignmentSettings_.startPosition)
		{
			double x = segment->m_StartPoint->m_Coordinates[0]->m_value;
			double y = segment->m_StartPoint->m_Coordinates[1]->m_value;

			writeP6IfcAlignmentDataCell(row, col, x);
			col++;
			writeP6IfcAlignmentDataCell(row, col, y);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startDirection)
		{
			double value = segment->m_StartDirection->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.segmentLength)
		{
			double value = segment->m_SegmentLength->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.radius)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startRadius)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.isCcw)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.IsEntry)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.ClothoidConstant)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.check)
		{
			{
				std::stringstream ss;
				ss << "=U" << row << "+V1";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=V" << row << "+W1";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}
		}

		P6IfcHorizontalAlignmentCurrentRow_++;
	}

	virtual void createIfcCircularArcSegment2D(std::shared_ptr<IfcCircularArcSegment2D> segment) override
	{
		int row = P6IfcHorizontalAlignmentCurrentRow_;
		int col = P6IfcHorizontalAlignmentStartColumn_;

		if (P6IfcHorizontalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataCell(row, col, P6IfcAlignmentName.c_str());
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.type)
		{
			writeP6IfcAlignmentDataCell(row, col, "IfcCircularArcSegment2D");
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startPosition)
		{
			double x = segment->m_StartPoint->m_Coordinates[0]->m_value;
			double y = segment->m_StartPoint->m_Coordinates[1]->m_value;

			writeP6IfcAlignmentDataCell(row, col, x);
			col++;
			writeP6IfcAlignmentDataCell(row, col, y);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startDirection)
		{
			double value = segment->m_StartDirection->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.segmentLength)
		{
			double value = segment->m_SegmentLength->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.radius)
		{
			const double value = segment->m_Radius->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startRadius)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.isCcw)
		{
			const bool value = segment->m_IsCcw->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.IsEntry)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.ClothoidConstant)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.check)
		{
			{
				std::stringstream ss;
				ss << "=U" << row << "+V1";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=V" << row << "+W1";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}
		}

		P6IfcHorizontalAlignmentCurrentRow_++;
	}

	virtual void createIfcClothoidalArcSegment2D(std::shared_ptr<IfcClothoidalArcSegment2D> segment) override
	{
		int row = P6IfcHorizontalAlignmentCurrentRow_;
		int col = P6IfcHorizontalAlignmentStartColumn_;

		if (P6IfcHorizontalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataCell(row, col, P6IfcAlignmentName.c_str());
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.type)
		{
			writeP6IfcAlignmentDataCell(row, col, "IfcClothoidalArcSegment2D");
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startPosition)
		{
			double x = segment->m_StartPoint->m_Coordinates[0]->m_value;
			double y = segment->m_StartPoint->m_Coordinates[1]->m_value;

			writeP6IfcAlignmentDataCell(row, col, x);
			col++;
			writeP6IfcAlignmentDataCell(row, col, y);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startDirection)
		{
			double value = segment->m_StartDirection->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.segmentLength)
		{
			double value = segment->m_SegmentLength->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.radius)
		{
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.startRadius)
		{
			if (segment->m_StartRadius == nullptr)
			{
				writeP6IfcAlignmentDataCell(row, col, "NIL");
			}
			else
			{
				const double value = segment->m_StartRadius->m_value;
				writeP6IfcAlignmentDataCell(row, col, value);
			}

			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.isCcw)
		{
			const bool value = segment->m_IsCcw->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.IsEntry)
		{
			const bool value = segment->m_IsEntry->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.ClothoidConstant)
		{
			const double value = segment->m_ClothoidConstant->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcHorizontalAlignmentSettings_.check)
		{
			{
				std::stringstream ss;
				ss << "=U" << row << "+V1";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=V" << row << "+W1";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}
		}

		P6IfcHorizontalAlignmentCurrentRow_++;
	}

	virtual void createIfcAlignment2DVerSegLine(std::shared_ptr<IfcAlignment2DVerSegLine> segment) override
	{
		int row = P6IfcVertcialAlignmentCurrentRow_;
		int col = 1;

		if (P6IfcVerticalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataCell(row, col, P6IfcAlignmentName.c_str());
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataCell(row, col, "IfcAlignment2DVerSegLine");
			col++;
		}

		if (true)
		{
			double value = segment->m_StartDistAlong->m_value;
			writeP6IfcAlignmentDataCell(row, col, value/*"StartDistAlong"*/);
			col++;
		}

		if (true)
		{
			double value = segment->m_HorizontalLength->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_StartHeight->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_StartGradient->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			//writeP6IfcAlignmentDataHeaderCell(row, col, "ParabolaConstant");
			col++;
		}

		if (true)
		{
			//writeP6IfcAlignmentDataHeaderCell(row, col, "IsConvex");
			col++;
		}

		if (P6IfcVerticalAlignmentSettings_.check)
		{
			{
				col++;
				std::stringstream ss;
				ss << "=IF(EXACT(\"IfcAlignment2DVerSegLine\", B" << row << "), M" << row << ", O" << row << ")";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=IF(OR(ABS(J" << row << "-E" << (row + 1) << ")<0.001,NOT(EXACT(A" << row << ",A" << (row + 1) << "))),\"\",\"NOT VALID\")";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				col++;
				std::stringstream ss;
				ss << "= D" << row << "*F" << row << " + E" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				col++;
			}

			{
				col++;
			}
		}

		P6IfcVertcialAlignmentCurrentRow_++;
	}

	virtual void createIfcAlignment2DVerSegCircularArc(std::shared_ptr<IfcAlignment2DVerSegCircularArc> segment) override
	{
		int row = P6IfcVertcialAlignmentCurrentRow_;
		int col = 1;

		if (P6IfcVerticalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataCell(row, col, P6IfcAlignmentName.c_str());
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataCell(row, col, "IfcAlignment2DVerSegCircularArc");
			col++;
		}

		if (true)
		{
			double value = segment->m_StartDistAlong->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_HorizontalLength->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_StartHeight->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_StartGradient->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			//writeP6IfcAlignmentDataCell(row, col, "ParabolaConstant");
			col++;
		}

		if (true)
		{
			bool value = segment->m_IsConvex->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcVerticalAlignmentSettings_.check)
		{
			{
				col++;
				std::stringstream ss;
				ss << "=IF(EXACT(\"IfcAlignment2DVerSegLine\", B" << row << "), M" << row << ", O" << row << ")";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=IF(OR(ABS(J" << row << "-E" << (row + 1) << ")<0.001,NOT(EXACT(A" << row << ",A" << (row + 1) << "))),\"\",\"NOT VALID\")";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				col++;
				std::stringstream ss;
				ss << "= D" << row << "*F" << row << " + E" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "= (D" << row << " / G" << row << ") + F" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=D" << row << "*(N" << row << "+F" << row << ")/2+E" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}
		}

		P6IfcVertcialAlignmentCurrentRow_++;
	}

	virtual void createIfcAlignment2DVerSegParabolicArc(std::shared_ptr<IfcAlignment2DVerSegParabolicArc> segment) override
	{
		int row = P6IfcVertcialAlignmentCurrentRow_;
		int col = 1;

		if (P6IfcVerticalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataCell(row, col, P6IfcAlignmentName.c_str());
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataCell(row, col, "IfcAlignment2DVerSegParabolicArc");
			col++;
		}

		if (true)
		{
			double value = segment->m_StartDistAlong->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_HorizontalLength->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_StartHeight->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_StartGradient->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			double value = segment->m_ParabolaConstant->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (true)
		{
			bool value = segment->m_IsConvex->m_value;
			writeP6IfcAlignmentDataCell(row, col, value);
			col++;
		}

		if (P6IfcVerticalAlignmentSettings_.check)
		{
			{
				col++;
				std::stringstream ss;
				ss << "=IF(EXACT(\"IfcAlignment2DVerSegLine\", B" << row << "), M" << row << ", O" << row << ")";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=IF(OR(ABS(J" << row << "-E" << (row + 1) << ")<0.001,NOT(EXACT(A" << row << ",A" << (row + 1) << "))),\"\",\"NOT VALID\")";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				col++;
				std::stringstream ss;
				ss << "= D" << row << "*F" << row << " + E" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss	<< "=IF(EXACT(H" << row << ", TRUE)," 
					<< "(D" << row << " / G" << row << ") + F" << row << ","
					<< "(D" << row << " / -G" << row << ") + F" << row << ")";

				//std::cout << ss.str().c_str() << std::endl;

				//ss << "= (D" << row << " / G" << row << ") + F" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}

			{
				std::stringstream ss;
				ss << "=D" << row << "*(N" << row << "+F" << row << ")/2+E" << row << "";
				writeDerivedDataCell(row, col, ss.str().c_str());
				col++;
			}
		}

		P6IfcVertcialAlignmentCurrentRow_++;
	}

	void createP6IfcHorizontalAlignmentHeaderRow(const OpenInfraPlatform::Infrastructure::P6IfcHorizontalAlignmentReportSettings& settings)
	{
		int row = P6IfcHorizontalAlignmentStartRow_;
		int col = getLandXMLColumnCount() + 1;

		if (settings.alignmentName)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "Description");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.type)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "IfcCurveSegment2D type");
			xlsx_.setColumnWidth(col, 24);
			col++;
		}

		if (settings.startPosition)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartPoint x");
			xlsx_.setColumnWidth(col, 15);
			col++;
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartPoint y");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.startDirection)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartDirection");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.segmentLength)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "SegmentLength");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.radius)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "Radius");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.startRadius)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartRadius");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.isCcw)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "IsCcw");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.IsEntry)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "IsEntry");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}
		
		if (settings.ClothoidConstant)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "ClothoidConstant");
			xlsx_.setColumnWidth(col, 18);
			col++;
		}

		if (settings.check)
		{
			writeDerivedDataHeaderHeaderCell(row, col, "StartPoint x (global)");
			xlsx_.setColumnWidth(col, 18);
			col++;

			writeDerivedDataHeaderHeaderCell(row, col, "StartPoint y (global)");
			xlsx_.setColumnWidth(col, 18);
			col++;
		}

		P6IfcHorizontalAlignmentCurrentRow_ = row + 1;
		P6IfcHorizontalAlignmentStartColumn_ = getLandXMLColumnCount() + 1;
	}

	void createP6IfcVerticalAlignmentHeaderRow()
	{
		int row = P6IfcHorizontalAlignmentStartRow_;
		int col = 1;

		if (P6IfcVerticalAlignmentSettings_.alignmentName)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "Description");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (P6IfcVerticalAlignmentSettings_.type)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "IfcAlignment2DVerticalSegment");
			xlsx_.setColumnWidth(col, 34);
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartDistAlong");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "HorizontalLength");
			xlsx_.setColumnWidth(col, 20);
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartHeight");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "StartGradient");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}
		
		if (true)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "ParabolaConstant");
			xlsx_.setColumnWidth(col, 20);
			col++;
		}

		if (true)
		{
			writeP6IfcAlignmentDataHeaderCell(row, col, "IsConvex");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (P6IfcVerticalAlignmentSettings_.check)
		{
			col++;
			writeDerivedDataHeaderHeaderCell(row, col, "endHeight");
			xlsx_.setColumnWidth(col, 15);
			col++;

			writeDerivedDataHeaderHeaderCell(row, col, "Diff to next startHeight");
			xlsx_.setColumnWidth(col, 15);
			col++;

			col++;
			writeDerivedDataHeaderHeaderCell(row, col, "L endHeith");
			xlsx_.setColumnWidth(col, 15);
			col++;

			writeDerivedDataHeaderHeaderCell(row, col, "g1");
			xlsx_.setColumnWidth(col, 15);
			col++;

			writeDerivedDataHeaderHeaderCell(row, col, "z1");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}
	}

	void writeDerivedDataHeaderHeaderCell(int row, int col, const QString &text)
	{
		QXlsx::Format format;
		format.setFontBold(true);
		format.setPatternBackgroundColor(QColor::fromRgb(196, 215, 155));
		xlsx_.write(row, col, text, format);
	}

	void writeP6IfcAlignmentDataHeaderCell(int row, int col, const QString &text)
	{
		QXlsx::Format format;
		format.setFontBold(true);
		format.setPatternBackgroundColor(QColor::fromRgb(255, 230, 153));
		xlsx_.write(row, col, text, format);
	}

	void writeP6IfcAlignmentDataCell(int row, int col, const QVariant &value)
	{
		QXlsx::Format format;
		format.setPatternBackgroundColor(QColor::fromRgb(255, 242, 204));
		xlsx_.write(row, col, value, format);
	}

	void writeDerivedDataCell(int row, int col, const QVariant &value)
	{
		QXlsx::Format format;
		format.setPatternBackgroundColor(QColor::fromRgb(235, 241, 222));
		xlsx_.write(row, col, value, format);
	}

	//---------------------------------------------------------------------------//
	// LandXML
	//---------------------------------------------------------------------------//

	int getLandXMLColumnCount() const
	{
		int count = 0;

		if (landXMLHorizontalAlignmentReportSettings_.alignmentName)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.type)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.startPosition)
			count += 2;
		if (landXMLHorizontalAlignmentReportSettings_.endPosition)
			count += 2;
		if (landXMLHorizontalAlignmentReportSettings_.centerPosition)
			count += 2;
		if (landXMLHorizontalAlignmentReportSettings_.pi)
			count += 2;
		if (landXMLHorizontalAlignmentReportSettings_.length)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.radius)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.radiusStart)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.radiusEnd)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.dirStart)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.dirEnd)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.rot)
			count += 1;
		if (landXMLHorizontalAlignmentReportSettings_.spiType)
			count += 1;
		
		return count;
	}

	void createLandXMLHeaderRow(const OpenInfraPlatform::Infrastructure::LandXMLHorizontalAlignmentReportSettings& settings)
	{
		int row = LandXMLStartRow_;
		int col = LandXMLStartColumn_;

		if (settings.alignmentName)
		{
			writeLandXMLDataHeaderCell(row, col, "Name");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.type)
		{
			writeLandXMLDataHeaderCell(row, col, "CoordGeom type");
			xlsx_.setColumnWidth(col, 17);
			col++;
		}

		if (settings.startPosition)
		{
			writeLandXMLDataHeaderCell(row, col, "Start x");
			xlsx_.setColumnWidth(col, 15);
			col++;
			writeLandXMLDataHeaderCell(row, col, "Start y");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.endPosition)
		{
			writeLandXMLDataHeaderCell(row, col, "End x");
			xlsx_.setColumnWidth(col, 15);
			col++;
			writeLandXMLDataHeaderCell(row, col, "End y");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.centerPosition)
		{
			writeLandXMLDataHeaderCell(row, col, "Center x");
			xlsx_.setColumnWidth(col, 15);
			col++;
			writeLandXMLDataHeaderCell(row, col, "Center y");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.pi)
		{
			writeLandXMLDataHeaderCell(row, col, "PI x");
			xlsx_.setColumnWidth(col, 15);
			col++;
			writeLandXMLDataHeaderCell(row, col, "PI y");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.length)
		{
			writeLandXMLDataHeaderCell(row, col, "length");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.radius)
		{
			writeLandXMLDataHeaderCell(row, col, "radius");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.radiusStart)
		{
			writeLandXMLDataHeaderCell(row, col, "radiusStart");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.radiusEnd)
		{
			writeLandXMLDataHeaderCell(row, col, "radiusEnd");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.dirStart)
		{
			writeLandXMLDataHeaderCell(row, col, "dirStart");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.dirEnd)
		{
			writeLandXMLDataHeaderCell(row, col, "dirEnd");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.rot)
		{
			writeLandXMLDataHeaderCell(row, col, "rot");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		if (settings.spiType)
		{
			writeLandXMLDataHeaderCell(row, col, "spiType");
			xlsx_.setColumnWidth(col, 15);
			col++;
		}

		LandXMLCurrentRow_ = row + 1;
	}

	virtual void createAlignment(const PropertySet& parameters) 
	{
		if (parameters.contains("name"))
		{
			LandXMLAlignmentName_ = parameters.getWString("name");
		}
		else
		{
			LandXMLAlignmentName_ = L"";
		}
	}

	//! A LandXML horizontal line segment
	virtual void createLine(const PropertySet& parameters) override
	{
		writeHorizontalLandXMLElement("Line", parameters);
	}

	//! A LandXML horizontal arc segment
	virtual void createCurve(const PropertySet& parameters) override
	{
		writeHorizontalLandXMLElement("Curve", parameters);
	}

	//! A LandXML horizontal spiral
	virtual void createSpiral(const PropertySet& parameters) override
	{
		writeHorizontalLandXMLElement("Spiral", parameters);
	}

	void writeHorizontalLandXMLElement(const char* type, const PropertySet &parameters)
	{
		int row = LandXMLCurrentRow_;
		int col = LandXMLStartColumn_;

		if (landXMLHorizontalAlignmentReportSettings_.alignmentName)
		{
			std::string name = buw::String::toStdString(LandXMLAlignmentName_);

			writeLandXMLDataCell(row, col, name.c_str());
			col++;
		}

		if (landXMLHorizontalAlignmentReportSettings_.type)
		{
			writeLandXMLDataCell(row, col, type);
			col++;
		}

		if (landXMLHorizontalAlignmentReportSettings_.startPosition)
		{
			if (parameters.contains("Start"))
			{
				buw::vector2d position = parameters.getVector2d("Start");

				writeLandXMLDataCell(row, col + 0, position.x());
				writeLandXMLDataCell(row, col + 1, position.y());
			}

			col += 2;
		}

		if (landXMLHorizontalAlignmentReportSettings_.endPosition)
		{
			if (parameters.contains("End"))
			{
				buw::vector2d position = parameters.getVector2d("End");

				writeLandXMLDataCell(row, col + 0, position.x());
				writeLandXMLDataCell(row, col + 1, position.y());
			}

			col += 2;
		}

		if (landXMLHorizontalAlignmentReportSettings_.centerPosition)
		{
			if (parameters.contains("Center"))
			{
				buw::vector2d position = parameters.getVector2d("Center");

				writeLandXMLDataCell(row, col + 0, position.x());
				writeLandXMLDataCell(row, col + 1, position.y());
			}

			col += 2;
		}

		if (landXMLHorizontalAlignmentReportSettings_.pi)
		{
			if (parameters.contains("PI"))
			{
				buw::vector2d position = parameters.getVector2d("PI");

				writeLandXMLDataCell(row, col + 0, position.x());
				writeLandXMLDataCell(row, col + 1, position.y());
			}

			col += 2;
		}

		if (landXMLHorizontalAlignmentReportSettings_.length)
		{
			if (parameters.contains("length"))
			{
				double value = parameters.getDouble("length");

				writeLandXMLDataCell(row, col + 0, value);
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.radius)
		{
			if (parameters.contains("radius"))
			{
				double value = parameters.getDouble("radius");

				writeLandXMLDataCell(row, col + 0, value);
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.radiusStart)
		{
			if (parameters.contains("radiusStart"))
			{
				std::string value = parameters.getString("radiusStart");

				writeLandXMLDataCell(row, col + 0, value.c_str());
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.radiusEnd)
		{
			if (parameters.contains("radiusEnd"))
			{
				std::string value = parameters.getString("radiusEnd");

				writeLandXMLDataCell(row, col + 0, value.c_str());
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.dirStart)
		{
			if (parameters.contains("dirStart"))
			{
				double value = parameters.getDouble("dirStart");

				writeLandXMLDataCell(row, col + 0, value);
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.dirEnd)
		{
			if (parameters.contains("dirEnd"))
			{
				double value = parameters.getDouble("dirEnd");

				writeLandXMLDataCell(row, col + 0, value);
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.rot)
		{
			if (parameters.contains("rot"))
			{
				std::string value = parameters.getString("rot");

				writeLandXMLDataCell(row, col + 0, value.c_str());
			}

			col += 1;
		}

		if (landXMLHorizontalAlignmentReportSettings_.spiType)
		{
			if (parameters.contains("spiType"))
			{
				std::string value = parameters.getString("spiType");

				writeLandXMLDataCell(row, col + 0, value.c_str());
			}

			col += 1;
		}

		LandXMLCurrentRow_++;
	}

	void writeLandXMLDataHeaderCell(const int row, const int col, const QString &text)
	{
		QXlsx::Format format;
		format.setFontBold(true);
		format.setPatternBackgroundColor(QColor::fromRgb(204, 192, 218));
		xlsx_.write(row, col, text, format);
	}

	void writeLandXMLDataCell(const int row, const int col, const QVariant &value)
	{
		QXlsx::Format format;
		format.setPatternBackgroundColor(QColor::fromRgb(228, 223, 236));
		xlsx_.write(row, col, value, format);
	}

private:
	std::string				excelExportFilename_;

	buw::P6IfcHorizontalAlignmentReportSettings		P6IfcHorizontalAlignmentSettings_;
	buw::P6IfcVerticalAlignmentReportSettings		P6IfcVerticalAlignmentSettings_;
	int						P6IfcHorizontalAlignmentCurrentRow_ = 2;
	int						P6IfcHorizontalAlignmentStartRow_ = 2;
	int						P6IfcHorizontalAlignmentStartColumn_ = 1;
	int						P6IfcVertcialAlignmentCurrentRow_ = 3;
	buw::vector3d			P6IfcAlignmentOffset_;
	std::string				P6IfcAlignmentName;

	buw::LandXMLHorizontalAlignmentReportSettings	landXMLHorizontalAlignmentReportSettings_;
	std::wstring			LandXMLAlignmentName_;
	int						LandXMLCurrentRow_ = 2;
	int						LandXMLStartRow_ = 2;
	int						LandXMLStartColumn_ = 1;

	QXlsx::Document			xlsx_;
};

class OpenInfraPlatform::Infrastructure::ExcelReport::ExcelReportImpl
{
public:
	ExcelReportImpl(
		const char* excelExportFilename,
		const char* landXMLFilename,
		const char* ifcP6ExportFilename)
	{
		LandXMLHorizontalAlignmentReportSettings settings;
		P6IfcHorizontalAlignmentReportSettings ifcHSettings;
		P6IfcVerticalAlignmentReportSettings ifcVSettings;
		AlignmentExcelSheetReport esk(excelExportFilename, settings, ifcHSettings, ifcVSettings);
		OpenInfraPlatform::Infrastructure::constructLandXMLData(landXMLFilename, &esk);
		OpenInfraPlatform::Infrastructure::constructP6IfcAlignmentData(ifcP6ExportFilename, &esk);
		esk.writeIFCOffset();
		esk.save();
	}
};

OpenInfraPlatform::Infrastructure::ExcelReport::ExcelReport(
	const char* excelExportFilename,
	const char* landXMLFilename,
	const char* ifcP6ExportFilename) :
impl_(new ExcelReportImpl(excelExportFilename, landXMLFilename, ifcP6ExportFilename))
{

}
