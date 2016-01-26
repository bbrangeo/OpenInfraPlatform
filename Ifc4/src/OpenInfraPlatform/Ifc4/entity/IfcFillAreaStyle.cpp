/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcFillAreaStyle.h"
#include "include/IfcFillStyleSelect.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcFillAreaStyle 
		IfcFillAreaStyle::IfcFillAreaStyle() { m_entity_enum = IFCFILLAREASTYLE; }
		IfcFillAreaStyle::IfcFillAreaStyle( int id ) { m_id = id; m_entity_enum = IFCFILLAREASTYLE; }
		IfcFillAreaStyle::~IfcFillAreaStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFillAreaStyle::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
			if( m_ModelorDraughting ) { m_ModelorDraughting->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFillAreaStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFillAreaStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFillAreaStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcFillAreaStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readSelectList( args[1], m_FillStyles, map );
			m_ModelorDraughting = IfcBoolean::readStepData( args[2] );
		}
		void IfcFillAreaStyle::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFillAreaStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
