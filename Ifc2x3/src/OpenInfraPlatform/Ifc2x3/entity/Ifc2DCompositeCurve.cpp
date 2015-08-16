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
#include "include/Ifc2DCompositeCurve.h"
#include "include/IfcCompositeCurveSegment.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY Ifc2DCompositeCurve 
		Ifc2DCompositeCurve::Ifc2DCompositeCurve() { m_entity_enum = IFC2DCOMPOSITECURVE; }
		Ifc2DCompositeCurve::Ifc2DCompositeCurve( int id ) { m_id = id; m_entity_enum = IFC2DCOMPOSITECURVE; }
		Ifc2DCompositeCurve::~Ifc2DCompositeCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void Ifc2DCompositeCurve::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<Ifc2DCompositeCurve> other = dynamic_pointer_cast<Ifc2DCompositeCurve>(other_entity);
			if( !other) { return; }
			m_Segments = other->m_Segments;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void Ifc2DCompositeCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFC2DCOMPOSITECURVE" << "(";
			writeEntityList( stream, m_Segments );
			stream << ",";
			if( m_SelfIntersect == false ) { stream << ".F."; }
			else if( m_SelfIntersect == true ) { stream << ".T."; }
			stream << ");";
		}
		void Ifc2DCompositeCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void Ifc2DCompositeCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity Ifc2DCompositeCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity Ifc2DCompositeCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Segments, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_SelfIntersect = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_SelfIntersect = true; }
		}
		void Ifc2DCompositeCurve::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcCompositeCurve::setInverseCounterparts( ptr_self_entity );
		}
		void Ifc2DCompositeCurve::unlinkSelf()
		{
			IfcCompositeCurve::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
