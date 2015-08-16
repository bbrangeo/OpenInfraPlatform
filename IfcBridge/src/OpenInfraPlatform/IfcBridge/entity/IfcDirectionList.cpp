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
#include "include/IfcDirectionList.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcDirectionList 
		IfcDirectionList::IfcDirectionList() { m_entity_enum = IFCDIRECTIONLIST; }
		IfcDirectionList::IfcDirectionList( int id ) { m_id = id; m_entity_enum = IFCDIRECTIONLIST; }
		IfcDirectionList::~IfcDirectionList() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDirectionList::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcDirectionList> other = dynamic_pointer_cast<IfcDirectionList>(other_entity);
			if( !other) { return; }
			m_DirectionList = other->m_DirectionList;
		}
		void IfcDirectionList::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDIRECTIONLIST" << "(";
			writeTypeOfRealList2D( stream, m_DirectionList );
			stream << ");";
		}
		void IfcDirectionList::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDirectionList::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDirectionList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcDirectionList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList2D( args[0], m_DirectionList );
		}
		void IfcDirectionList::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDirectionList::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
