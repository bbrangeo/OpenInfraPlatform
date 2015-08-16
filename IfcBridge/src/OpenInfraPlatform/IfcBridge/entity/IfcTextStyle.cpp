/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcCharacterStyleSelect.h"
#include "include/IfcLabel.h"
#include "include/IfcTextFontSelect.h"
#include "include/IfcTextStyle.h"
#include "include/IfcTextStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTextStyle 
		IfcTextStyle::IfcTextStyle() { m_entity_enum = IFCTEXTSTYLE; }
		IfcTextStyle::IfcTextStyle( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLE; }
		IfcTextStyle::~IfcTextStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyle::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcTextStyle> other = dynamic_pointer_cast<IfcTextStyle>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_TextCharacterAppearance = other->m_TextCharacterAppearance;
			m_TextStyle = other->m_TextStyle;
			m_TextFontStyle = other->m_TextFontStyle;
		}
		void IfcTextStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTSTYLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TextCharacterAppearance ) { m_TextCharacterAppearance->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TextStyle ) { m_TextStyle->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TextFontStyle ) { m_TextFontStyle->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyle, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcTextStyle, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_TextCharacterAppearance = IfcCharacterStyleSelect::readStepData( args[1], map );
			m_TextStyle = IfcTextStyleSelect::readStepData( args[2], map );
			m_TextFontStyle = IfcTextFontSelect::readStepData( args[3], map );
		}
		void IfcTextStyle::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
