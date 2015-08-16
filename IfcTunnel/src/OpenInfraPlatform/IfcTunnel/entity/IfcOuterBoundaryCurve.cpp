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
#include "include/IfcCompositeCurveSegment.h"
#include "include/IfcOuterBoundaryCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcOuterBoundaryCurve 
		IfcOuterBoundaryCurve::IfcOuterBoundaryCurve() { m_entity_enum = IFCOUTERBOUNDARYCURVE; }
		IfcOuterBoundaryCurve::IfcOuterBoundaryCurve( int id ) { m_id = id; m_entity_enum = IFCOUTERBOUNDARYCURVE; }
		IfcOuterBoundaryCurve::~IfcOuterBoundaryCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOuterBoundaryCurve::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcOuterBoundaryCurve> other = dynamic_pointer_cast<IfcOuterBoundaryCurve>(other_entity);
			if( !other) { return; }
			m_Segments = other->m_Segments;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void IfcOuterBoundaryCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOUTERBOUNDARYCURVE" << "(";
			writeEntityList( stream, m_Segments );
			stream << ",";
			if( m_SelfIntersect == false ) { stream << ".F."; }
			else if( m_SelfIntersect == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcOuterBoundaryCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOuterBoundaryCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOuterBoundaryCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcOuterBoundaryCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Segments, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_SelfIntersect = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_SelfIntersect = true; }
		}
		void IfcOuterBoundaryCurve::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcBoundaryCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOuterBoundaryCurve::unlinkSelf()
		{
			IfcBoundaryCurve::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
