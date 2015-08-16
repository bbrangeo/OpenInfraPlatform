/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcTextFontSelect.h"
#include "include/IfcTextStyle.h"
#include "include/IfcTextStyleForDefinedFont.h"
#include "include/IfcTextStyleTextModel.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcTextStyle 
		IfcTextStyle::IfcTextStyle() { m_entity_enum = IFCTEXTSTYLE; }
		IfcTextStyle::IfcTextStyle( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLE; }
		IfcTextStyle::~IfcTextStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyle::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcTextStyle> other = dynamic_pointer_cast<IfcTextStyle>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_TextCharacterAppearance = other->m_TextCharacterAppearance;
			m_TextStyle = other->m_TextStyle;
			m_TextFontStyle = other->m_TextFontStyle;
			m_ModelOrDraughting = other->m_ModelOrDraughting;
		}
		void IfcTextStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTSTYLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TextCharacterAppearance ) { stream << "#" << m_TextCharacterAppearance->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TextStyle ) { stream << "#" << m_TextStyle->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TextFontStyle ) { m_TextFontStyle->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ModelOrDraughting == false ) { stream << ".F."; }
			else if( m_ModelOrDraughting == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcTextStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyle, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTextStyle, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_TextCharacterAppearance, map );
			readEntityReference( args[2], m_TextStyle, map );
			m_TextFontStyle = IfcTextFontSelect::readStepData( args[3], map );
			if( _stricmp( args[4].c_str(), ".F." ) == 0 ) { m_ModelOrDraughting = false; }
			else if( _stricmp( args[4].c_str(), ".T." ) == 0 ) { m_ModelOrDraughting = true; }
		}
		void IfcTextStyle::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
