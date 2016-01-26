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
#include "include/IfcLabel.h"
#include "include/IfcSurfaceSide.h"
#include "include/IfcSurfaceStyle.h"
#include "include/IfcSurfaceStyleElementSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSurfaceStyle 
		IfcSurfaceStyle::IfcSurfaceStyle() { m_entity_enum = IFCSURFACESTYLE; }
		IfcSurfaceStyle::IfcSurfaceStyle( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLE; }
		IfcSurfaceStyle::~IfcSurfaceStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyle::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcSurfaceStyle> other = dynamic_pointer_cast<IfcSurfaceStyle>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Side = other->m_Side;
			m_Styles = other->m_Styles;
		}
		void IfcSurfaceStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACESTYLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Side ) { m_Side->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Styles, true );
			stream << ");";
		}
		void IfcSurfaceStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Side = IfcSurfaceSide::readStepData( args[1] );
			readSelectList( args[2], m_Styles, map );
		}
		void IfcSurfaceStyle::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
