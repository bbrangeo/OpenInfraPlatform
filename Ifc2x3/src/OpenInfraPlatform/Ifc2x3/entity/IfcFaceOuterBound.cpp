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
#include "include/IfcFaceOuterBound.h"
#include "include/IfcLoop.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcFaceOuterBound 
		IfcFaceOuterBound::IfcFaceOuterBound() { m_entity_enum = IFCFACEOUTERBOUND; }
		IfcFaceOuterBound::IfcFaceOuterBound( int id ) { m_id = id; m_entity_enum = IFCFACEOUTERBOUND; }
		IfcFaceOuterBound::~IfcFaceOuterBound() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFaceOuterBound::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcFaceOuterBound> other = dynamic_pointer_cast<IfcFaceOuterBound>(other_entity);
			if( !other) { return; }
			m_Bound = other->m_Bound;
			m_Orientation = other->m_Orientation;
		}
		void IfcFaceOuterBound::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACEOUTERBOUND" << "(";
			if( m_Bound ) { stream << "#" << m_Bound->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Orientation == false ) { stream << ".F."; }
			else if( m_Orientation == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcFaceOuterBound::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFaceOuterBound::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFaceOuterBound, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcFaceOuterBound, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Bound, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_Orientation = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_Orientation = true; }
		}
		void IfcFaceOuterBound::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcFaceBound::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFaceOuterBound::unlinkSelf()
		{
			IfcFaceBound::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
