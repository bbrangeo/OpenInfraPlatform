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
#include "include/IfcAnnotationSurface.h"
#include "include/IfcLabel.h"
#include "include/IfcSimpleValue.h"
#include "include/IfcTextureCoordinateGenerator.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTextureCoordinateGenerator 
		IfcTextureCoordinateGenerator::IfcTextureCoordinateGenerator() { m_entity_enum = IFCTEXTURECOORDINATEGENERATOR; }
		IfcTextureCoordinateGenerator::IfcTextureCoordinateGenerator( int id ) { m_id = id; m_entity_enum = IFCTEXTURECOORDINATEGENERATOR; }
		IfcTextureCoordinateGenerator::~IfcTextureCoordinateGenerator() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextureCoordinateGenerator::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTextureCoordinateGenerator> other = dynamic_pointer_cast<IfcTextureCoordinateGenerator>(other_entity);
			if( !other) { return; }
			m_Mode = other->m_Mode;
			m_Parameter = other->m_Parameter;
		}
		void IfcTextureCoordinateGenerator::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTURECOORDINATEGENERATOR" << "(";
			if( m_Mode ) { m_Mode->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Parameter, true );
			stream << ");";
		}
		void IfcTextureCoordinateGenerator::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextureCoordinateGenerator::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextureCoordinateGenerator, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTextureCoordinateGenerator, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Mode = IfcLabel::readStepData( args[0] );
			readSelectList( args[1], m_Parameter, map );
		}
		void IfcTextureCoordinateGenerator::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcTextureCoordinate::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextureCoordinateGenerator::unlinkSelf()
		{
			IfcTextureCoordinate::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
