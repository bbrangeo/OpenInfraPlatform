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
#include "include/IfcClassification.h"
#include "include/IfcClassificationReference.h"
#include "include/IfcDate.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcRelAssociatesClassification.h"
#include "include/IfcText.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcClassification 
		IfcClassification::IfcClassification() { m_entity_enum = IFCCLASSIFICATION; }
		IfcClassification::IfcClassification( int id ) { m_id = id; m_entity_enum = IFCCLASSIFICATION; }
		IfcClassification::~IfcClassification() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClassification::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcClassification> other = dynamic_pointer_cast<IfcClassification>(other_entity);
			if( !other) { return; }
			m_Source = other->m_Source;
			m_Edition = other->m_Edition;
			m_EditionDate = other->m_EditionDate;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Location = other->m_Location;
			m_ReferenceTokens = other->m_ReferenceTokens;
		}
		void IfcClassification::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLASSIFICATION" << "(";
			if( m_Source ) { m_Source->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Edition ) { m_Edition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EditionDate ) { m_EditionDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_ReferenceTokens );
			stream << ");";
		}
		void IfcClassification::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClassification::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClassification, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcClassification, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Source = IfcLabel::readStepData( args[0] );
			m_Edition = IfcLabel::readStepData( args[1] );
			m_EditionDate = IfcDate::readStepData( args[2] );
			m_Name = IfcLabel::readStepData( args[3] );
			m_Description = IfcText::readStepData( args[4] );
			m_Location = IfcURIReference::readStepData( args[5] );
			readTypeList( args[6], m_ReferenceTokens );
		}
		void IfcClassification::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcExternalInformation::setInverseCounterparts( ptr_self_entity );
		}
		void IfcClassification::unlinkSelf()
		{
			IfcExternalInformation::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
