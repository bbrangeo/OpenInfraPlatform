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
#include "include/IfcCoordinateReferenceSystem.h"
#include "include/IfcCoordinateReferenceSystemSelect.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcMapConversion.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcMapConversion 
		IfcMapConversion::IfcMapConversion() { m_entity_enum = IFCMAPCONVERSION; }
		IfcMapConversion::IfcMapConversion( int id ) { m_id = id; m_entity_enum = IFCMAPCONVERSION; }
		IfcMapConversion::~IfcMapConversion() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMapConversion::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcMapConversion> other = dynamic_pointer_cast<IfcMapConversion>(other_entity);
			if( !other) { return; }
			m_SourceCRS = other->m_SourceCRS;
			m_TargetCRS = other->m_TargetCRS;
			m_Eastings = other->m_Eastings;
			m_Northings = other->m_Northings;
			m_OrthogonalHeight = other->m_OrthogonalHeight;
			m_XAxisAbscissa = other->m_XAxisAbscissa;
			m_XAxisOrdinate = other->m_XAxisOrdinate;
			m_Scale = other->m_Scale;
		}
		void IfcMapConversion::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMAPCONVERSION" << "(";
			if( m_SourceCRS ) { m_SourceCRS->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TargetCRS ) { stream << "#" << m_TargetCRS->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Eastings ) { m_Eastings->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Northings ) { m_Northings->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OrthogonalHeight ) { m_OrthogonalHeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_XAxisAbscissa == m_XAxisAbscissa ){ stream << m_XAxisAbscissa; }
			else { stream << "$"; }
			stream << ",";
			if( m_XAxisOrdinate == m_XAxisOrdinate ){ stream << m_XAxisOrdinate; }
			else { stream << "$"; }
			stream << ",";
			if( m_Scale == m_Scale ){ stream << m_Scale; }
			else { stream << "$"; }
			stream << ");";
		}
		void IfcMapConversion::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMapConversion::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMapConversion, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcMapConversion, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SourceCRS = IfcCoordinateReferenceSystemSelect::readStepData( args[0], map );
			readEntityReference( args[1], m_TargetCRS, map );
			m_Eastings = IfcLengthMeasure::readStepData( args[2] );
			m_Northings = IfcLengthMeasure::readStepData( args[3] );
			m_OrthogonalHeight = IfcLengthMeasure::readStepData( args[4] );
			readRealValue( args[5], m_XAxisAbscissa );
			readRealValue( args[6], m_XAxisOrdinate );
			readRealValue( args[7], m_Scale );
		}
		void IfcMapConversion::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCoordinateOperation::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMapConversion::unlinkSelf()
		{
			IfcCoordinateOperation::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
