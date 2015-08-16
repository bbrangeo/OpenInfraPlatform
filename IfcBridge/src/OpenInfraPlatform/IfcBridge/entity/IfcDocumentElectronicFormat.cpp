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
#include "include/IfcDocumentElectronicFormat.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcDocumentElectronicFormat 
		IfcDocumentElectronicFormat::IfcDocumentElectronicFormat() { m_entity_enum = IFCDOCUMENTELECTRONICFORMAT; }
		IfcDocumentElectronicFormat::IfcDocumentElectronicFormat( int id ) { m_id = id; m_entity_enum = IFCDOCUMENTELECTRONICFORMAT; }
		IfcDocumentElectronicFormat::~IfcDocumentElectronicFormat() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDocumentElectronicFormat::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcDocumentElectronicFormat> other = dynamic_pointer_cast<IfcDocumentElectronicFormat>(other_entity);
			if( !other) { return; }
			m_FileExtension = other->m_FileExtension;
			m_MimeContentType = other->m_MimeContentType;
			m_MimeSubtype = other->m_MimeSubtype;
		}
		void IfcDocumentElectronicFormat::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDOCUMENTELECTRONICFORMAT" << "(";
			if( m_FileExtension ) { m_FileExtension->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MimeContentType ) { m_MimeContentType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MimeSubtype ) { m_MimeSubtype->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDocumentElectronicFormat::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDocumentElectronicFormat::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDocumentElectronicFormat, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcDocumentElectronicFormat, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_FileExtension = IfcLabel::readStepData( args[0] );
			m_MimeContentType = IfcLabel::readStepData( args[1] );
			m_MimeSubtype = IfcLabel::readStepData( args[2] );
		}
		void IfcDocumentElectronicFormat::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcDocumentElectronicFormat::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
