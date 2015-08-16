/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <map>
#include "../model/shared_ptr.h"
#include "../model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "include/IfcAmountOfSubstanceMeasure.h"
#include "include/IfcAreaMeasure.h"
#include "include/IfcComplexNumber.h"
#include "include/IfcContextDependentMeasure.h"
#include "include/IfcCountMeasure.h"
#include "include/IfcDescriptiveMeasure.h"
#include "include/IfcElectricCurrentMeasure.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcLuminousIntensityMeasure.h"
#include "include/IfcMassMeasure.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcNumericMeasure.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPositivePlaneAngleMeasure.h"
#include "include/IfcPositiveRatioMeasure.h"
#include "include/IfcRatioMeasure.h"
#include "include/IfcSolidAngleMeasure.h"
#include "include/IfcThermodynamicTemperatureMeasure.h"
#include "include/IfcTimeMeasure.h"
#include "include/IfcVolumeMeasure.h"
#include "include/IfcValue.h"
#include "include/IfcMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcMeasureValue 
		IfcMeasureValue::IfcMeasureValue() {}
		IfcMeasureValue::~IfcMeasureValue() {}
		shared_ptr<IfcMeasureValue> IfcMeasureValue::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcMeasureValue>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcBridgeEntity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcMeasureValue> type_object = dynamic_pointer_cast<IfcMeasureValue>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw IfcBridgeException( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcMeasureValue>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcMeasureValue>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCAMOUNTOFSUBSTANCEMEASURE")== 0 )
				{
					return IfcAmountOfSubstanceMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCAREAMEASURE")== 0 )
				{
					return IfcAreaMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCCOMPLEXNUMBER")== 0 )
				{
					return IfcComplexNumber::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCCONTEXTDEPENDENTMEASURE")== 0 )
				{
					return IfcContextDependentMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCCOUNTMEASURE")== 0 )
				{
					return IfcCountMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCDESCRIPTIVEMEASURE")== 0 )
				{
					return IfcDescriptiveMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCELECTRICCURRENTMEASURE")== 0 )
				{
					return IfcElectricCurrentMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCLENGTHMEASURE")== 0 )
				{
					return IfcLengthMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCLUMINOUSINTENSITYMEASURE")== 0 )
				{
					return IfcLuminousIntensityMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCMASSMEASURE")== 0 )
				{
					return IfcMassMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCNONNEGATIVELENGTHMEASURE")== 0 )
				{
					return IfcNonNegativeLengthMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCNORMALISEDRATIOMEASURE")== 0 )
				{
					return IfcNormalisedRatioMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCNUMERICMEASURE")== 0 )
				{
					return IfcNumericMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCPARAMETERVALUE")== 0 )
				{
					return IfcParameterValue::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCPLANEANGLEMEASURE")== 0 )
				{
					return IfcPlaneAngleMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCPOSITIVELENGTHMEASURE")== 0 )
				{
					return IfcPositiveLengthMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCPOSITIVEPLANEANGLEMEASURE")== 0 )
				{
					return IfcPositivePlaneAngleMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCPOSITIVERATIOMEASURE")== 0 )
				{
					return IfcPositiveRatioMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCRATIOMEASURE")== 0 )
				{
					return IfcRatioMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCSOLIDANGLEMEASURE")== 0 )
				{
					return IfcSolidAngleMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCTHERMODYNAMICTEMPERATUREMEASURE")== 0 )
				{
					return IfcThermodynamicTemperatureMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCTIMEMEASURE")== 0 )
				{
					return IfcTimeMeasure::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCVOLUMEMEASURE")== 0 )
				{
					return IfcVolumeMeasure::readStepData( inline_arg );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC2X4::IfcMeasureValue::readStepData" << std::endl;
				throw IfcBridgeException( strs.str() );
			}
			return shared_ptr<IfcMeasureValue>();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
