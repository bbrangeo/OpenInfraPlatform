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
#include "include/IfcSizeSelect.h"
#include "include/IfcTextAlignment.h"
#include "include/IfcTextDecoration.h"
#include "include/IfcTextStyleTextModel.h"
#include "include/IfcTextTransformation.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTextStyleTextModel 
		IfcTextStyleTextModel::IfcTextStyleTextModel() { m_entity_enum = IFCTEXTSTYLETEXTMODEL; }
		IfcTextStyleTextModel::IfcTextStyleTextModel( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLETEXTMODEL; }
		IfcTextStyleTextModel::~IfcTextStyleTextModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyleTextModel::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTextStyleTextModel> other = dynamic_pointer_cast<IfcTextStyleTextModel>(other_entity);
			if( !other) { return; }
			m_TextIndent = other->m_TextIndent;
			m_TextAlign = other->m_TextAlign;
			m_TextDecoration = other->m_TextDecoration;
			m_LetterSpacing = other->m_LetterSpacing;
			m_WordSpacing = other->m_WordSpacing;
			m_TextTransform = other->m_TextTransform;
			m_LineHeight = other->m_LineHeight;
		}
		void IfcTextStyleTextModel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTSTYLETEXTMODEL" << "(";
			if( m_TextIndent ) { m_TextIndent->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TextAlign ) { m_TextAlign->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TextDecoration ) { m_TextDecoration->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LetterSpacing ) { m_LetterSpacing->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_WordSpacing ) { m_WordSpacing->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TextTransform ) { m_TextTransform->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LineHeight ) { m_LineHeight->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextStyleTextModel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyleTextModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyleTextModel, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcTextStyleTextModel, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TextIndent = IfcSizeSelect::readStepData( args[0], map );
			m_TextAlign = IfcTextAlignment::readStepData( args[1] );
			m_TextDecoration = IfcTextDecoration::readStepData( args[2] );
			m_LetterSpacing = IfcSizeSelect::readStepData( args[3], map );
			m_WordSpacing = IfcSizeSelect::readStepData( args[4], map );
			m_TextTransform = IfcTextTransformation::readStepData( args[5] );
			m_LineHeight = IfcSizeSelect::readStepData( args[6], map );
		}
		void IfcTextStyleTextModel::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcTextStyleTextModel::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
