/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcExternallyDefinedTextFont.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcExternallyDefinedTextFont 
		IfcExternallyDefinedTextFont::IfcExternallyDefinedTextFont() { m_entity_enum = IFCEXTERNALLYDEFINEDTEXTFONT; }
		IfcExternallyDefinedTextFont::IfcExternallyDefinedTextFont( int id ) { m_id = id; m_entity_enum = IFCEXTERNALLYDEFINEDTEXTFONT; }
		IfcExternallyDefinedTextFont::~IfcExternallyDefinedTextFont() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExternallyDefinedTextFont::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcExternallyDefinedTextFont> other = dynamic_pointer_cast<IfcExternallyDefinedTextFont>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
		}
		void IfcExternallyDefinedTextFont::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTERNALLYDEFINEDTEXTFONT" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcExternallyDefinedTextFont::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExternallyDefinedTextFont::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcExternallyDefinedTextFont, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcExternallyDefinedTextFont, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcURIReference::readStepData( args[0] );
			m_Identification = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcExternallyDefinedTextFont::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
		}
		void IfcExternallyDefinedTextFont::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
