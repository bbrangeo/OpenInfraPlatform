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
#include "include/IfcColour.h"
#include "include/IfcTextStyleForDefinedFont.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcTextStyleForDefinedFont 
		IfcTextStyleForDefinedFont::IfcTextStyleForDefinedFont() { m_entity_enum = IFCTEXTSTYLEFORDEFINEDFONT; }
		IfcTextStyleForDefinedFont::IfcTextStyleForDefinedFont( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLEFORDEFINEDFONT; }
		IfcTextStyleForDefinedFont::~IfcTextStyleForDefinedFont() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyleForDefinedFont::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcTextStyleForDefinedFont> other = dynamic_pointer_cast<IfcTextStyleForDefinedFont>(other_entity);
			if( !other) { return; }
			m_Colour = other->m_Colour;
			m_BackgroundColour = other->m_BackgroundColour;
		}
		void IfcTextStyleForDefinedFont::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTSTYLEFORDEFINEDFONT" << "(";
			if( m_Colour ) { m_Colour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_BackgroundColour ) { m_BackgroundColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextStyleForDefinedFont::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyleForDefinedFont::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyleForDefinedFont, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTextStyleForDefinedFont, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Colour = IfcColour::readStepData( args[0], map );
			m_BackgroundColour = IfcColour::readStepData( args[1], map );
		}
		void IfcTextStyleForDefinedFont::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextStyleForDefinedFont::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
