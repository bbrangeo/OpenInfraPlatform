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
#include "include/IfcElementAssemblyTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcElementAssemblyTypeEnum 
		IfcElementAssemblyTypeEnum::IfcElementAssemblyTypeEnum() {}
		IfcElementAssemblyTypeEnum::~IfcElementAssemblyTypeEnum() {}
		void IfcElementAssemblyTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELEMENTASSEMBLYTYPEENUM("; }
			if( m_enum == ENUM_ACCESSORY_ASSEMBLY )
			{
				stream << ".ACCESSORY_ASSEMBLY.";
			}
			else if( m_enum == ENUM_ARCH )
			{
				stream << ".ARCH.";
			}
			else if( m_enum == ENUM_BEAM_GRID )
			{
				stream << ".BEAM_GRID.";
			}
			else if( m_enum == ENUM_BRACED_FRAME )
			{
				stream << ".BRACED_FRAME.";
			}
			else if( m_enum == ENUM_GIRDER )
			{
				stream << ".GIRDER.";
			}
			else if( m_enum == ENUM_REINFORCEMENT_UNIT )
			{
				stream << ".REINFORCEMENT_UNIT.";
			}
			else if( m_enum == ENUM_RIGID_FRAME )
			{
				stream << ".RIGID_FRAME.";
			}
			else if( m_enum == ENUM_SLAB_FIELD )
			{
				stream << ".SLAB_FIELD.";
			}
			else if( m_enum == ENUM_TRUSS )
			{
				stream << ".TRUSS.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcElementAssemblyTypeEnum> IfcElementAssemblyTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElementAssemblyTypeEnum>(); }
			shared_ptr<IfcElementAssemblyTypeEnum> type_object( new IfcElementAssemblyTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACCESSORY_ASSEMBLY." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_ACCESSORY_ASSEMBLY;
			}
			else if( _stricmp( arg.c_str(), ".ARCH." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_ARCH;
			}
			else if( _stricmp( arg.c_str(), ".BEAM_GRID." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_BEAM_GRID;
			}
			else if( _stricmp( arg.c_str(), ".BRACED_FRAME." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_BRACED_FRAME;
			}
			else if( _stricmp( arg.c_str(), ".GIRDER." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_GIRDER;
			}
			else if( _stricmp( arg.c_str(), ".REINFORCEMENT_UNIT." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_REINFORCEMENT_UNIT;
			}
			else if( _stricmp( arg.c_str(), ".RIGID_FRAME." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_RIGID_FRAME;
			}
			else if( _stricmp( arg.c_str(), ".SLAB_FIELD." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_SLAB_FIELD;
			}
			else if( _stricmp( arg.c_str(), ".TRUSS." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_TRUSS;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
