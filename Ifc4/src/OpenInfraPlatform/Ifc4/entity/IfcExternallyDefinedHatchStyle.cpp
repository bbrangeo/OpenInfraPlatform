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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcExternallyDefinedHatchStyle.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcExternallyDefinedHatchStyle 
		IfcExternallyDefinedHatchStyle::IfcExternallyDefinedHatchStyle() { m_entity_enum = IFCEXTERNALLYDEFINEDHATCHSTYLE; }
		IfcExternallyDefinedHatchStyle::IfcExternallyDefinedHatchStyle( int id ) { m_id = id; m_entity_enum = IFCEXTERNALLYDEFINEDHATCHSTYLE; }
		IfcExternallyDefinedHatchStyle::~IfcExternallyDefinedHatchStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExternallyDefinedHatchStyle::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcExternallyDefinedHatchStyle> other = dynamic_pointer_cast<IfcExternallyDefinedHatchStyle>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
		}
		void IfcExternallyDefinedHatchStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTERNALLYDEFINEDHATCHSTYLE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcExternallyDefinedHatchStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExternallyDefinedHatchStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcExternallyDefinedHatchStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcExternallyDefinedHatchStyle, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcURIReference::readStepData( args[0] );
			m_Identification = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcExternallyDefinedHatchStyle::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
		}
		void IfcExternallyDefinedHatchStyle::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
