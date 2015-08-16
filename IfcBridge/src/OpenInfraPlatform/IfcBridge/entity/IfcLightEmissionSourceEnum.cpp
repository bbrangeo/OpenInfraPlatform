/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcBridgeException.h"
#include "include/IfcLightEmissionSourceEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcLightEmissionSourceEnum 
		IfcLightEmissionSourceEnum::IfcLightEmissionSourceEnum() {}
		IfcLightEmissionSourceEnum::~IfcLightEmissionSourceEnum() {}
		void IfcLightEmissionSourceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLIGHTEMISSIONSOURCEENUM("; }
			if( m_enum == ENUM_COMPACTFLUORESCENT )
			{
				stream << ".COMPACTFLUORESCENT.";
			}
			else if( m_enum == ENUM_FLUORESCENT )
			{
				stream << ".FLUORESCENT.";
			}
			else if( m_enum == ENUM_HIGHPRESSUREMERCURY )
			{
				stream << ".HIGHPRESSUREMERCURY.";
			}
			else if( m_enum == ENUM_HIGHPRESSURESODIUM )
			{
				stream << ".HIGHPRESSURESODIUM.";
			}
			else if( m_enum == ENUM_LIGHTEMITTINGDIODE )
			{
				stream << ".LIGHTEMITTINGDIODE.";
			}
			else if( m_enum == ENUM_LOWPRESSURESODIUM )
			{
				stream << ".LOWPRESSURESODIUM.";
			}
			else if( m_enum == ENUM_LOWVOLTAGEHALOGEN )
			{
				stream << ".LOWVOLTAGEHALOGEN.";
			}
			else if( m_enum == ENUM_MAINVOLTAGEHALOGEN )
			{
				stream << ".MAINVOLTAGEHALOGEN.";
			}
			else if( m_enum == ENUM_METALHALIDE )
			{
				stream << ".METALHALIDE.";
			}
			else if( m_enum == ENUM_TUNGSTENFILAMENT )
			{
				stream << ".TUNGSTENFILAMENT.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcLightEmissionSourceEnum> IfcLightEmissionSourceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLightEmissionSourceEnum>(); }
			shared_ptr<IfcLightEmissionSourceEnum> type_object( new IfcLightEmissionSourceEnum() );
			if( _stricmp( arg.c_str(), ".COMPACTFLUORESCENT." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_COMPACTFLUORESCENT;
			}
			else if( _stricmp( arg.c_str(), ".FLUORESCENT." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_FLUORESCENT;
			}
			else if( _stricmp( arg.c_str(), ".HIGHPRESSUREMERCURY." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_HIGHPRESSUREMERCURY;
			}
			else if( _stricmp( arg.c_str(), ".HIGHPRESSURESODIUM." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_HIGHPRESSURESODIUM;
			}
			else if( _stricmp( arg.c_str(), ".LIGHTEMITTINGDIODE." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_LIGHTEMITTINGDIODE;
			}
			else if( _stricmp( arg.c_str(), ".LOWPRESSURESODIUM." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_LOWPRESSURESODIUM;
			}
			else if( _stricmp( arg.c_str(), ".LOWVOLTAGEHALOGEN." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_LOWVOLTAGEHALOGEN;
			}
			else if( _stricmp( arg.c_str(), ".MAINVOLTAGEHALOGEN." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_MAINVOLTAGEHALOGEN;
			}
			else if( _stricmp( arg.c_str(), ".METALHALIDE." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_METALHALIDE;
			}
			else if( _stricmp( arg.c_str(), ".TUNGSTENFILAMENT." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_TUNGSTENFILAMENT;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLightEmissionSourceEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
