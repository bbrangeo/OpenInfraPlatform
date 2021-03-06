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
#include "include/IfcBoolean.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRectangularTrimmedSurface.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRectangularTrimmedSurface 
		IfcRectangularTrimmedSurface::IfcRectangularTrimmedSurface() { m_entity_enum = IFCRECTANGULARTRIMMEDSURFACE; }
		IfcRectangularTrimmedSurface::IfcRectangularTrimmedSurface( int id ) { m_id = id; m_entity_enum = IFCRECTANGULARTRIMMEDSURFACE; }
		IfcRectangularTrimmedSurface::~IfcRectangularTrimmedSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRectangularTrimmedSurface::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRectangularTrimmedSurface> other = dynamic_pointer_cast<IfcRectangularTrimmedSurface>(other_entity);
			if( !other) { return; }
			m_BasisSurface = other->m_BasisSurface;
			m_U1 = other->m_U1;
			m_V1 = other->m_V1;
			m_U2 = other->m_U2;
			m_V2 = other->m_V2;
			m_Usense = other->m_Usense;
			m_Vsense = other->m_Vsense;
		}
		void IfcRectangularTrimmedSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRECTANGULARTRIMMEDSURFACE" << "(";
			if( m_BasisSurface ) { stream << "#" << m_BasisSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_U1 ) { m_U1->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_V1 ) { m_V1->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_U2 ) { m_U2->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_V2 ) { m_V2->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if (m_Usense == false) { stream << ".F."; }
			else if (m_Usense == true) { stream << ".T."; }
			stream << ",";
			if (m_Vsense == false) { stream << ".F."; }
			else if (m_Vsense == true) { stream << ".T."; }
			stream << ");";
		}
		void IfcRectangularTrimmedSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRectangularTrimmedSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRectangularTrimmedSurface, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRectangularTrimmedSurface, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisSurface, map );
			m_U1 = IfcParameterValue::readStepData( args[1] );
			m_V1 = IfcParameterValue::readStepData( args[2] );
			m_U2 = IfcParameterValue::readStepData( args[3] );
			m_V2 = IfcParameterValue::readStepData( args[4] );
			if (_stricmp(args[5].c_str(), ".F.") == 0) { m_Usense = false; }
			else if (_stricmp(args[5].c_str(), ".T.") == 0) { m_Usense = true; }
			if (_stricmp(args[6].c_str(), ".F.") == 0) { m_Vsense = false; }
			else if (_stricmp(args[6].c_str(), ".T.") == 0) { m_Vsense = true; }
		}
		void IfcRectangularTrimmedSurface::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcBoundedSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRectangularTrimmedSurface::unlinkSelf()
		{
			IfcBoundedSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
