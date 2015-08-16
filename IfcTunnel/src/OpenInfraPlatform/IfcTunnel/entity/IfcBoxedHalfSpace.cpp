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
#include "include/IfcBoundingBox.h"
#include "include/IfcBoxedHalfSpace.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcBoxedHalfSpace 
		IfcBoxedHalfSpace::IfcBoxedHalfSpace() { m_entity_enum = IFCBOXEDHALFSPACE; }
		IfcBoxedHalfSpace::IfcBoxedHalfSpace( int id ) { m_id = id; m_entity_enum = IFCBOXEDHALFSPACE; }
		IfcBoxedHalfSpace::~IfcBoxedHalfSpace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoxedHalfSpace::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcBoxedHalfSpace> other = dynamic_pointer_cast<IfcBoxedHalfSpace>(other_entity);
			if( !other) { return; }
			m_BaseSurface = other->m_BaseSurface;
			m_AgreementFlag = other->m_AgreementFlag;
			m_Enclosure = other->m_Enclosure;
		}
		void IfcBoxedHalfSpace::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOXEDHALFSPACE" << "(";
			if( m_BaseSurface ) { stream << "#" << m_BaseSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AgreementFlag == false ) { stream << ".F."; }
			else if( m_AgreementFlag == true ) { stream << ".T."; }
			stream << ",";
			if( m_Enclosure ) { stream << "#" << m_Enclosure->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoxedHalfSpace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoxedHalfSpace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoxedHalfSpace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcBoxedHalfSpace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BaseSurface, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_AgreementFlag = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_AgreementFlag = true; }
			readEntityReference( args[2], m_Enclosure, map );
		}
		void IfcBoxedHalfSpace::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcHalfSpaceSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoxedHalfSpace::unlinkSelf()
		{
			IfcHalfSpaceSolid::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
