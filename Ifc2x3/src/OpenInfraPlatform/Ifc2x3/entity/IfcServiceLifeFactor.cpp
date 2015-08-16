/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcMeasureValue.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcServiceLifeFactor.h"
#include "include/IfcServiceLifeFactorTypeEnum.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcServiceLifeFactor 
		IfcServiceLifeFactor::IfcServiceLifeFactor() { m_entity_enum = IFCSERVICELIFEFACTOR; }
		IfcServiceLifeFactor::IfcServiceLifeFactor( int id ) { m_id = id; m_entity_enum = IFCSERVICELIFEFACTOR; }
		IfcServiceLifeFactor::~IfcServiceLifeFactor() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcServiceLifeFactor::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcServiceLifeFactor> other = dynamic_pointer_cast<IfcServiceLifeFactor>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_PredefinedType = other->m_PredefinedType;
			m_UpperValue = other->m_UpperValue;
			m_MostUsedValue = other->m_MostUsedValue;
			m_LowerValue = other->m_LowerValue;
		}
		void IfcServiceLifeFactor::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSERVICELIFEFACTOR" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UpperValue ) { m_UpperValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_MostUsedValue ) { m_MostUsedValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_LowerValue ) { m_LowerValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcServiceLifeFactor::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcServiceLifeFactor::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcServiceLifeFactor, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcServiceLifeFactor, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_PredefinedType = IfcServiceLifeFactorTypeEnum::readStepData( args[4] );
			m_UpperValue = IfcMeasureValue::readStepData( args[5], map );
			m_MostUsedValue = IfcMeasureValue::readStepData( args[6], map );
			m_LowerValue = IfcMeasureValue::readStepData( args[7], map );
		}
		void IfcServiceLifeFactor::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcPropertySetDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcServiceLifeFactor::unlinkSelf()
		{
			IfcPropertySetDefinition::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
