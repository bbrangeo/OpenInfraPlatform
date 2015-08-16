/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcLabel.h"
#include "include/IfcTextFontSelect.h"
#include "include/IfcTextStyle.h"
#include "include/IfcTextStyleForDefinedFont.h"
#include "include/IfcTextStyleTextModel.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTextStyle 
		IfcTextStyle::IfcTextStyle() { m_entity_enum = IFCTEXTSTYLE; }
		IfcTextStyle::IfcTextStyle( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLE; }
		IfcTextStyle::~IfcTextStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyle::setEntity( shared_ptr<IfcRoadEntity> other_entity )
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
			if( m_ModelOrDraughting ) { m_ModelOrDraughting->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyle, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTextStyle, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_TextCharacterAppearance, map );
			readEntityReference( args[2], m_TextStyle, map );
			m_TextFontStyle = IfcTextFontSelect::readStepData( args[3], map );
			m_ModelOrDraughting = IfcBoolean::readStepData( args[4] );
		}
		void IfcTextStyle::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
