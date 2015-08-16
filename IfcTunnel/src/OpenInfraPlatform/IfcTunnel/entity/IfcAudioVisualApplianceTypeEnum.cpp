/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcAudioVisualApplianceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcAudioVisualApplianceTypeEnum 
		IfcAudioVisualApplianceTypeEnum::IfcAudioVisualApplianceTypeEnum() {}
		IfcAudioVisualApplianceTypeEnum::~IfcAudioVisualApplianceTypeEnum() {}
		void IfcAudioVisualApplianceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCAUDIOVISUALAPPLIANCETYPEENUM("; }
			if( m_enum == ENUM_AMPLIFIER )
			{
				stream << ".AMPLIFIER.";
			}
			else if( m_enum == ENUM_CAMERA )
			{
				stream << ".CAMERA.";
			}
			else if( m_enum == ENUM_DISPLAY )
			{
				stream << ".DISPLAY.";
			}
			else if( m_enum == ENUM_MICROPHONE )
			{
				stream << ".MICROPHONE.";
			}
			else if( m_enum == ENUM_PLAYER )
			{
				stream << ".PLAYER.";
			}
			else if( m_enum == ENUM_PROJECTOR )
			{
				stream << ".PROJECTOR.";
			}
			else if( m_enum == ENUM_RECEIVER )
			{
				stream << ".RECEIVER.";
			}
			else if( m_enum == ENUM_SPEAKER )
			{
				stream << ".SPEAKER.";
			}
			else if( m_enum == ENUM_SWITCHER )
			{
				stream << ".SWITCHER.";
			}
			else if( m_enum == ENUM_TELEPHONE )
			{
				stream << ".TELEPHONE.";
			}
			else if( m_enum == ENUM_TUNER )
			{
				stream << ".TUNER.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAudioVisualApplianceTypeEnum> IfcAudioVisualApplianceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAudioVisualApplianceTypeEnum>(); }
			shared_ptr<IfcAudioVisualApplianceTypeEnum> type_object( new IfcAudioVisualApplianceTypeEnum() );
			if( _stricmp( arg.c_str(), ".AMPLIFIER." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_AMPLIFIER;
			}
			else if( _stricmp( arg.c_str(), ".CAMERA." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_CAMERA;
			}
			else if( _stricmp( arg.c_str(), ".DISPLAY." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_DISPLAY;
			}
			else if( _stricmp( arg.c_str(), ".MICROPHONE." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_MICROPHONE;
			}
			else if( _stricmp( arg.c_str(), ".PLAYER." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_PLAYER;
			}
			else if( _stricmp( arg.c_str(), ".PROJECTOR." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_PROJECTOR;
			}
			else if( _stricmp( arg.c_str(), ".RECEIVER." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_RECEIVER;
			}
			else if( _stricmp( arg.c_str(), ".SPEAKER." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_SPEAKER;
			}
			else if( _stricmp( arg.c_str(), ".SWITCHER." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_SWITCHER;
			}
			else if( _stricmp( arg.c_str(), ".TELEPHONE." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_TELEPHONE;
			}
			else if( _stricmp( arg.c_str(), ".TUNER." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_TUNER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAudioVisualApplianceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
