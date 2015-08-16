/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcSIPrefix.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSIPrefix 
		IfcSIPrefix::IfcSIPrefix() {}
		IfcSIPrefix::~IfcSIPrefix() {}
		void IfcSIPrefix::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSIPREFIX("; }
			if( m_enum == ENUM_EXA )
			{
				stream << ".EXA.";
			}
			else if( m_enum == ENUM_PETA )
			{
				stream << ".PETA.";
			}
			else if( m_enum == ENUM_TERA )
			{
				stream << ".TERA.";
			}
			else if( m_enum == ENUM_GIGA )
			{
				stream << ".GIGA.";
			}
			else if( m_enum == ENUM_MEGA )
			{
				stream << ".MEGA.";
			}
			else if( m_enum == ENUM_KILO )
			{
				stream << ".KILO.";
			}
			else if( m_enum == ENUM_HECTO )
			{
				stream << ".HECTO.";
			}
			else if( m_enum == ENUM_DECA )
			{
				stream << ".DECA.";
			}
			else if( m_enum == ENUM_DECI )
			{
				stream << ".DECI.";
			}
			else if( m_enum == ENUM_CENTI )
			{
				stream << ".CENTI.";
			}
			else if( m_enum == ENUM_MILLI )
			{
				stream << ".MILLI.";
			}
			else if( m_enum == ENUM_MICRO )
			{
				stream << ".MICRO.";
			}
			else if( m_enum == ENUM_NANO )
			{
				stream << ".NANO.";
			}
			else if( m_enum == ENUM_PICO )
			{
				stream << ".PICO.";
			}
			else if( m_enum == ENUM_FEMTO )
			{
				stream << ".FEMTO.";
			}
			else if( m_enum == ENUM_ATTO )
			{
				stream << ".ATTO.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSIPrefix> IfcSIPrefix::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSIPrefix>(); }
			shared_ptr<IfcSIPrefix> type_object( new IfcSIPrefix() );
			if( _stricmp( arg.c_str(), ".EXA." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_EXA;
			}
			else if( _stricmp( arg.c_str(), ".PETA." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_PETA;
			}
			else if( _stricmp( arg.c_str(), ".TERA." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_TERA;
			}
			else if( _stricmp( arg.c_str(), ".GIGA." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_GIGA;
			}
			else if( _stricmp( arg.c_str(), ".MEGA." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_MEGA;
			}
			else if( _stricmp( arg.c_str(), ".KILO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_KILO;
			}
			else if( _stricmp( arg.c_str(), ".HECTO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_HECTO;
			}
			else if( _stricmp( arg.c_str(), ".DECA." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_DECA;
			}
			else if( _stricmp( arg.c_str(), ".DECI." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_DECI;
			}
			else if( _stricmp( arg.c_str(), ".CENTI." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_CENTI;
			}
			else if( _stricmp( arg.c_str(), ".MILLI." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_MILLI;
			}
			else if( _stricmp( arg.c_str(), ".MICRO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_MICRO;
			}
			else if( _stricmp( arg.c_str(), ".NANO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_NANO;
			}
			else if( _stricmp( arg.c_str(), ".PICO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_PICO;
			}
			else if( _stricmp( arg.c_str(), ".FEMTO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_FEMTO;
			}
			else if( _stricmp( arg.c_str(), ".ATTO." ) == 0 )
			{
				type_object->m_enum = IfcSIPrefix::ENUM_ATTO;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
