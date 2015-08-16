/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "RoadXMLParser.h"

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include <buw.BlueCore.h>
#include <QtXml>
#include <QtXmlPatterns>
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct eRoadXMLParserState
		{
			enum Enum
			{
				CircleArc,
				ClothoArc,
				Segment,
				Track,
				XYCurve
			};
		};

		//! \class RoadXMLParser
		//! \brief brief description
		class QRoadXMLParser : public QXmlDefaultHandler
		{
		public:
			//! Default constructor.
			QRoadXMLParser()
			{

			}

			//! Virtual destructor.
			virtual ~QRoadXMLParser()
			{
			}

			bool startElement(const QString & /* unused */, const QString &name,
				const QString& /* unused */, const QXmlAttributes &attr)
			{
				if (name == "CircleArc")
				{
					state.push(eRoadXMLParserState::CircleArc);

					// properties
					double curvature = attr.value("curvature").toDouble();
					double length = attr.value("length").toDouble();

					CircleArcProperties.clear();
					CircleArcProperties.setDouble("curvature", curvature);
					CircleArcProperties.setDouble("length", length);
				}

				if (name == "ClothoArc")
				{
					state.push(eRoadXMLParserState::ClothoArc);

					// properties
					double length = attr.value("length").toDouble();
					double endCurvature = attr.value("endCurvature").toDouble();
					double startCurvature = attr.value("startCurvature").toDouble();

					ClothoArcProperties.clear();
					ClothoArcProperties.setDouble("length", length);
					ClothoArcProperties.setDouble("endCurvature", endCurvature);
					ClothoArcProperties.setDouble("startCurvature", startCurvature);
				}

				if (name == "Segment")
				{
					state.push(eRoadXMLParserState::Segment);

					// properties
					double length = attr.value("length").toDouble();

					SegmentProperties.clear();
					SegmentProperties.setDouble("length", length);
				}

				if (name == "Track")
				{
					state.push(eRoadXMLParserState::Track);
				}

				if (name == "XYCurve")
				{
					state.push(eRoadXMLParserState::XYCurve);

					// properties
					double x = attr.value("x").toDouble();
					double y = attr.value("y").toDouble();
					double direction = attr.value("direction").toDouble();

					XYCurveProperties.clear();
					XYCurveProperties.setDouble("x", x);
					XYCurveProperties.setDouble("y", y);
					XYCurveProperties.setDouble("direction", direction);
				}

				return true;
			}

			bool characters(const QString& ch)
			{
				return true;
			}

			bool endElement(const QString & /* unused */, const QString &name,
				const QString& /* unused */)
			{
				if (name == "CircleArc")
				{
					BLUE_ASSERT(state.top() == eRoadXMLParserState::CircleArc, "Invalid state.");
					state.pop();

					double radius = std::abs(1.0 / CircleArcProperties.getDouble("curvature"));

					bool clockwise = radius < 0 ? true : false;
					buw::vector2d start = buw::vector2d(XYCurveProperties.getDouble("x"), XYCurveProperties.getDouble("y"));

					//------------------------------------------------------------------------
					/*
					double e = GetEndAngle();
					double s = GetStartAngle();
					double d = e - s;

					double x = 0.0;
					double y = 0.0;
					double offset = 0.0;
					if(d < 0.0) {
					offset = PI;
					}
					x = (GetPosition().GetX() + std::cos(((s + e) / 2.0) + offset) * GetRadius());
					y = (GetPosition().GetY() + -std::sin(((s + e) / 2.0) + offset) * GetRadius());

					*/
					/*
					buw::Arc::Ptr arc = std::make_shared<buw::Arc>(
					center_,
					start_,
					end_,
					clockwise_);
					*/

					std::cout << radius << std::endl;
				}

				if (name == "ClothoArc")
				{
					BLUE_ASSERT(state.top() == eRoadXMLParserState::ClothoArc, "Invalid state.");
					state.pop();
				}

				if (name == "Segment")
				{
					BLUE_ASSERT(state.top() == eRoadXMLParserState::Segment, "Invalid state.");
					state.pop();
				}

				if (name == "Track")
				{
					BLUE_ASSERT(state.top() == eRoadXMLParserState::Track, "Invalid state.");
					state.pop();
				}

				if (name == "XYCurve")
				{
					BLUE_ASSERT(state.top() == eRoadXMLParserState::XYCurve, "Invalid state.");
					state.pop();
				}

				return true;
			}

			std::vector<buw::Alignment2DBased3D::Ptr> getAlignments()
			{
				return alignments_;
			}

			int	getAlignmentCount()
			{
				return static_cast<int>(alignments_.size());
			}

		private:
			buw::PropertySet XYCurveProperties;
			buw::PropertySet CircleArcProperties;
			buw::PropertySet SegmentProperties;
			buw::PropertySet ClothoArcProperties;

			std::stack<eRoadXMLParserState::Enum> state;
			std::vector<buw::Alignment2DBased3D::Ptr> alignments_;
		}; // end class QRoadXMLParser

		int RoadXMLParser::getAlignmentCount()
		{
			return static_cast<int>(alignments_.size());
		}

		std::vector<buw::Alignment2DBased3D::Ptr> RoadXMLParser::getAlignments()
		{
			return alignments_;
		}

		RoadXMLParser::RoadXMLParser(const std::string& filename)
		{
			QRoadXMLParser parser;

			//QFile schemaFile("C:/dev/OpenInfraPlatform/schema/LandXML-1.2.xsd");
			//QXmlSchema schema;

			//XmlSchemaVerificationMessageHandler handler;
			//schema.setMessageHandler(&handler);
			//if (!schemaFile.open(QIODevice::ReadOnly))
			//	throw buw::Exception("Unable to open the XML schema!");
			//if (!schema.load(schemaFile.readAll()))
			//	throw buw::Exception("Unable to parse the XML schema!");

			//QXmlSchemaValidator validator(schema);
			QFile file(filename.c_str());
			if (!file.open(QIODevice::ReadOnly))
				throw buw::Exception("Unable to open the file.");
			//if (!validator.validate(&file))
			//	throw buw::Exception("Unable to validate the file.");

			QXmlInputSource source(&file);
			file.seek(0);
			QXmlSimpleReader reader;
			reader.setContentHandler(&parser);
			if (!reader.parse(source))
				throw buw::Exception("Unable to parse the file.");

			for (int i = 0; i < parser.getAlignmentCount(); i++)
			{
				alignments_.push_back(parser.getAlignments()[i]);
			}
		}

	}
}