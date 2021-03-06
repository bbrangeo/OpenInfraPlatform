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
#include "include/IfcLabel.h"
#include "include/IfcReal.h"
#include "include/IfcSurfaceTexture.h"
#include "include/IfcTextureCoordinateGenerator.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTextureCoordinateGenerator 
		IfcTextureCoordinateGenerator::IfcTextureCoordinateGenerator() { m_entity_enum = IFCTEXTURECOORDINATEGENERATOR; }
		IfcTextureCoordinateGenerator::IfcTextureCoordinateGenerator( int id ) { m_id = id; m_entity_enum = IFCTEXTURECOORDINATEGENERATOR; }
		IfcTextureCoordinateGenerator::~IfcTextureCoordinateGenerator() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextureCoordinateGenerator::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcTextureCoordinateGenerator> other = dynamic_pointer_cast<IfcTextureCoordinateGenerator>(other_entity);
			if( !other) { return; }
			m_Maps = other->m_Maps;
			m_Mode = other->m_Mode;
			m_Parameter = other->m_Parameter;
		}
		void IfcTextureCoordinateGenerator::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTURECOORDINATEGENERATOR" << "(";
			writeEntityList( stream, m_Maps );
			stream << ",";
			if( m_Mode ) { m_Mode->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList( stream, m_Parameter );
			stream << ");";
		}
		void IfcTextureCoordinateGenerator::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextureCoordinateGenerator::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextureCoordinateGenerator, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTextureCoordinateGenerator, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Maps, map );
			m_Mode = IfcLabel::readStepData( args[1] );
			readTypeOfRealList( args[2], m_Parameter );
		}
		void IfcTextureCoordinateGenerator::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcTextureCoordinate::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextureCoordinateGenerator::unlinkSelf()
		{
			IfcTextureCoordinate::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
