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
#include "include/IfcLabel.h"
#include "include/IfcPreDefinedCurveFont.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcPreDefinedCurveFont 
		IfcPreDefinedCurveFont::IfcPreDefinedCurveFont() { m_entity_enum = IFCPREDEFINEDCURVEFONT; }
		IfcPreDefinedCurveFont::IfcPreDefinedCurveFont( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDCURVEFONT; }
		IfcPreDefinedCurveFont::~IfcPreDefinedCurveFont() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedCurveFont::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcPreDefinedCurveFont> other = dynamic_pointer_cast<IfcPreDefinedCurveFont>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcPreDefinedCurveFont::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDCURVEFONT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPreDefinedCurveFont::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedCurveFont::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPreDefinedCurveFont, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPreDefinedCurveFont, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcPreDefinedCurveFont::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcPreDefinedItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedCurveFont::unlinkSelf()
		{
			IfcPreDefinedItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
