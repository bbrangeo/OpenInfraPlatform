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
#include "include/IfcFillAreaStyle.h"
#include "include/IfcFillStyleSelect.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcFillAreaStyle 
		IfcFillAreaStyle::IfcFillAreaStyle() { m_entity_enum = IFCFILLAREASTYLE; }
		IfcFillAreaStyle::IfcFillAreaStyle( int id ) { m_id = id; m_entity_enum = IFCFILLAREASTYLE; }
		IfcFillAreaStyle::~IfcFillAreaStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFillAreaStyle::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcFillAreaStyle> other = dynamic_pointer_cast<IfcFillAreaStyle>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_FillStyles = other->m_FillStyles;
			m_ModelorDraughting = other->m_ModelorDraughting;
		}
		void IfcFillAreaStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFILLAREASTYLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_FillStyles, true );
			stream << ",";
			if( m_ModelorDraughting == false ) { stream << ".F."; }
			else if( m_ModelorDraughting == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcFillAreaStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFillAreaStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFillAreaStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcFillAreaStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readSelectList( args[1], m_FillStyles, map );
			if( _stricmp( args[2].c_str(), ".F." ) == 0 ) { m_ModelorDraughting = false; }
			else if( _stricmp( args[2].c_str(), ".T." ) == 0 ) { m_ModelorDraughting = true; }
		}
		void IfcFillAreaStyle::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFillAreaStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
