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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcNamedUnit.h"
#include "include/IfcPhysicalComplexQuantity.h"
#include "include/IfcQuantityLength.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcQuantityLength 
		IfcQuantityLength::IfcQuantityLength() { m_entity_enum = IFCQUANTITYLENGTH; }
		IfcQuantityLength::IfcQuantityLength( int id ) { m_id = id; m_entity_enum = IFCQUANTITYLENGTH; }
		IfcQuantityLength::~IfcQuantityLength() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcQuantityLength::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcQuantityLength> other = dynamic_pointer_cast<IfcQuantityLength>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Unit = other->m_Unit;
			m_LengthValue = other->m_LengthValue;
			m_Formula = other->m_Formula;
		}
		void IfcQuantityLength::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCQUANTITYLENGTH" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Unit ) { stream << "#" << m_Unit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LengthValue ) { m_LengthValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Formula ) { m_Formula->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcQuantityLength::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcQuantityLength::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcQuantityLength, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcQuantityLength, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_Unit, map );
			m_LengthValue = IfcLengthMeasure::readStepData( args[3] );
			m_Formula = IfcLabel::readStepData( args[4] );
		}
		void IfcQuantityLength::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPhysicalSimpleQuantity::setInverseCounterparts( ptr_self_entity );
		}
		void IfcQuantityLength::unlinkSelf()
		{
			IfcPhysicalSimpleQuantity::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform