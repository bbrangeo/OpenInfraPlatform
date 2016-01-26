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
#include "include/IfcLabel.h"
#include "include/IfcPhysicalComplexQuantity.h"
#include "include/IfcPhysicalQuantity.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPhysicalQuantity 
		IfcPhysicalQuantity::IfcPhysicalQuantity() { m_entity_enum = IFCPHYSICALQUANTITY; }
		IfcPhysicalQuantity::IfcPhysicalQuantity( int id ) { m_id = id; m_entity_enum = IFCPHYSICALQUANTITY; }
		IfcPhysicalQuantity::~IfcPhysicalQuantity() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPhysicalQuantity::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPhysicalQuantity> other = dynamic_pointer_cast<IfcPhysicalQuantity>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
		}
		void IfcPhysicalQuantity::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPHYSICALQUANTITY" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPhysicalQuantity::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPhysicalQuantity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPhysicalQuantity, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPhysicalQuantity, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
		}
		void IfcPhysicalQuantity::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcPhysicalQuantity::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
