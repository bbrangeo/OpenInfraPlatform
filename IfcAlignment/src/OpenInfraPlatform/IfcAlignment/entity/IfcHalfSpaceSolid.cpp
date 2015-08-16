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
#include "include/IfcBoolean.h"
#include "include/IfcHalfSpaceSolid.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcHalfSpaceSolid 
		IfcHalfSpaceSolid::IfcHalfSpaceSolid() { m_entity_enum = IFCHALFSPACESOLID; }
		IfcHalfSpaceSolid::IfcHalfSpaceSolid( int id ) { m_id = id; m_entity_enum = IFCHALFSPACESOLID; }
		IfcHalfSpaceSolid::~IfcHalfSpaceSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcHalfSpaceSolid::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcHalfSpaceSolid> other = dynamic_pointer_cast<IfcHalfSpaceSolid>(other_entity);
			if( !other) { return; }
			m_BaseSurface = other->m_BaseSurface;
			m_AgreementFlag = other->m_AgreementFlag;
		}
		void IfcHalfSpaceSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCHALFSPACESOLID" << "(";
			if( m_BaseSurface ) { stream << "#" << m_BaseSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AgreementFlag ) { m_AgreementFlag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcHalfSpaceSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcHalfSpaceSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcHalfSpaceSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcHalfSpaceSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BaseSurface, map );
			m_AgreementFlag = IfcBoolean::readStepData( args[1] );
		}
		void IfcHalfSpaceSolid::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcHalfSpaceSolid::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
