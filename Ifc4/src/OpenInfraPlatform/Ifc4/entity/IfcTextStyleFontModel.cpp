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
#include "include/IfcFontStyle.h"
#include "include/IfcFontVariant.h"
#include "include/IfcFontWeight.h"
#include "include/IfcLabel.h"
#include "include/IfcSizeSelect.h"
#include "include/IfcTextFontName.h"
#include "include/IfcTextStyleFontModel.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTextStyleFontModel 
		IfcTextStyleFontModel::IfcTextStyleFontModel() { m_entity_enum = IFCTEXTSTYLEFONTMODEL; }
		IfcTextStyleFontModel::IfcTextStyleFontModel( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLEFONTMODEL; }
		IfcTextStyleFontModel::~IfcTextStyleFontModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyleFontModel::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTextStyleFontModel> other = dynamic_pointer_cast<IfcTextStyleFontModel>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_FontFamily = other->m_FontFamily;
			m_FontStyle = other->m_FontStyle;
			m_FontVariant = other->m_FontVariant;
			m_FontWeight = other->m_FontWeight;
			m_FontSize = other->m_FontSize;
		}
		void IfcTextStyleFontModel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTSTYLEFONTMODEL" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_FontFamily );
			stream << ",";
			if( m_FontStyle ) { m_FontStyle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FontVariant ) { m_FontVariant->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FontWeight ) { m_FontWeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FontSize ) { m_FontSize->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextStyleFontModel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyleFontModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyleFontModel, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcTextStyleFontModel, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readTypeList( args[1], m_FontFamily );
			m_FontStyle = IfcFontStyle::readStepData( args[2] );
			m_FontVariant = IfcFontVariant::readStepData( args[3] );
			m_FontWeight = IfcFontWeight::readStepData( args[4] );
			m_FontSize = IfcSizeSelect::readStepData( args[5], map );
		}
		void IfcTextStyleFontModel::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPreDefinedTextFont::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextStyleFontModel::unlinkSelf()
		{
			IfcPreDefinedTextFont::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
