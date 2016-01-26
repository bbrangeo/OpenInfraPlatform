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
#include "include/IfcColourRgbList.h"
#include "include/IfcNormalisedRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcColourRgbList 
		IfcColourRgbList::IfcColourRgbList() { m_entity_enum = IFCCOLOURRGBLIST; }
		IfcColourRgbList::IfcColourRgbList( int id ) { m_id = id; m_entity_enum = IFCCOLOURRGBLIST; }
		IfcColourRgbList::~IfcColourRgbList() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcColourRgbList::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcColourRgbList> other = dynamic_pointer_cast<IfcColourRgbList>(other_entity);
			if( !other) { return; }
			m_ColourList = other->m_ColourList;
		}
		void IfcColourRgbList::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOLOURRGBLIST" << "(";
			writeTypeList2D( stream, m_ColourList );
			stream << ");";
		}
		void IfcColourRgbList::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcColourRgbList::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcColourRgbList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcColourRgbList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList2D( args[0], m_ColourList, map );
		}
		void IfcColourRgbList::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcColourRgbList::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
