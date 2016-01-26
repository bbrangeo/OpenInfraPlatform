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
#include "include/IfcBoundedCurve.h"
#include "include/IfcCenterLineProfileDef.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCenterLineProfileDef 
		IfcCenterLineProfileDef::IfcCenterLineProfileDef() { m_entity_enum = IFCCENTERLINEPROFILEDEF; }
		IfcCenterLineProfileDef::IfcCenterLineProfileDef( int id ) { m_id = id; m_entity_enum = IFCCENTERLINEPROFILEDEF; }
		IfcCenterLineProfileDef::~IfcCenterLineProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCenterLineProfileDef::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCenterLineProfileDef> other = dynamic_pointer_cast<IfcCenterLineProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Curve = other->m_Curve;
			m_Thickness = other->m_Thickness;
		}
		void IfcCenterLineProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCENTERLINEPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Curve ) { stream << "#" << m_Curve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Thickness ) { m_Thickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCenterLineProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCenterLineProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCenterLineProfileDef, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcCenterLineProfileDef, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Curve, map );
			m_Thickness = IfcPositiveLengthMeasure::readStepData( args[3] );
		}
		void IfcCenterLineProfileDef::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcArbitraryOpenProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCenterLineProfileDef::unlinkSelf()
		{
			IfcArbitraryOpenProfileDef::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
