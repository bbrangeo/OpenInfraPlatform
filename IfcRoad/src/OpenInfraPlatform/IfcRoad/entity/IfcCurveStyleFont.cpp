/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcCurveStyleFont.h"
#include "include/IfcCurveStyleFontPattern.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCurveStyleFont 
		IfcCurveStyleFont::IfcCurveStyleFont() { m_entity_enum = IFCCURVESTYLEFONT; }
		IfcCurveStyleFont::IfcCurveStyleFont( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLEFONT; }
		IfcCurveStyleFont::~IfcCurveStyleFont() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveStyleFont::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCurveStyleFont> other = dynamic_pointer_cast<IfcCurveStyleFont>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_PatternList = other->m_PatternList;
		}
		void IfcCurveStyleFont::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVESTYLEFONT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_PatternList );
			stream << ");";
		}
		void IfcCurveStyleFont::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveStyleFont::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveStyleFont, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCurveStyleFont, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReferenceList( args[1], m_PatternList, map );
		}
		void IfcCurveStyleFont::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveStyleFont::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
