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
#include "include/IfcBoolean.h"
#include "include/IfcCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTrimmedCurve.h"
#include "include/IfcTrimmingPreference.h"
#include "include/IfcTrimmingSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTrimmedCurve 
		IfcTrimmedCurve::IfcTrimmedCurve() { m_entity_enum = IFCTRIMMEDCURVE; }
		IfcTrimmedCurve::IfcTrimmedCurve( int id ) { m_id = id; m_entity_enum = IFCTRIMMEDCURVE; }
		IfcTrimmedCurve::~IfcTrimmedCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTrimmedCurve::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcTrimmedCurve> other = dynamic_pointer_cast<IfcTrimmedCurve>(other_entity);
			if( !other) { return; }
			m_BasisCurve = other->m_BasisCurve;
			m_Trim1 = other->m_Trim1;
			m_Trim2 = other->m_Trim2;
			m_SenseAgreement = other->m_SenseAgreement;
			m_MasterRepresentation = other->m_MasterRepresentation;
		}
		void IfcTrimmedCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTRIMMEDCURVE" << "(";
			if( m_BasisCurve ) { stream << "#" << m_BasisCurve->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Trim1, true );
			stream << ",";
			writeTypeList( stream, m_Trim2, true );
			stream << ",";
			if( m_SenseAgreement ) { m_SenseAgreement->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MasterRepresentation ) { m_MasterRepresentation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTrimmedCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTrimmedCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTrimmedCurve, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTrimmedCurve, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisCurve, map );
			readSelectList( args[1], m_Trim1, map );
			readSelectList( args[2], m_Trim2, map );
			m_SenseAgreement = IfcBoolean::readStepData( args[3] );
			m_MasterRepresentation = IfcTrimmingPreference::readStepData( args[4] );
		}
		void IfcTrimmedCurve::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTrimmedCurve::unlinkSelf()
		{
			IfcBoundedCurve::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
