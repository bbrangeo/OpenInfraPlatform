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
#include "include/IfcParameterValue.h"
#include "include/IfcTextureVertex.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTextureVertex 
		IfcTextureVertex::IfcTextureVertex() { m_entity_enum = IFCTEXTUREVERTEX; }
		IfcTextureVertex::IfcTextureVertex( int id ) { m_id = id; m_entity_enum = IFCTEXTUREVERTEX; }
		IfcTextureVertex::~IfcTextureVertex() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextureVertex::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTextureVertex> other = dynamic_pointer_cast<IfcTextureVertex>(other_entity);
			if( !other) { return; }
			m_Coordinates = other->m_Coordinates;
		}
		void IfcTextureVertex::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTUREVERTEX" << "(";
			writeTypeOfRealList( stream, m_Coordinates );
			stream << ");";
		}
		void IfcTextureVertex::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextureVertex::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextureVertex, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcTextureVertex, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList( args[0], m_Coordinates );
		}
		void IfcTextureVertex::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextureVertex::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
