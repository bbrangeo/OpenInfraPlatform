/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcConversionBasedUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcReal;
		//ENTITY
		class IfcConversionBasedUnitWithOffset : public IfcConversionBasedUnit
		{
		public:
			IfcConversionBasedUnitWithOffset();
			IfcConversionBasedUnitWithOffset( int id );
			~IfcConversionBasedUnitWithOffset();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcConversionBasedUnitWithOffset"; }


			// IfcNamedUnit -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDimensionalExponents>			m_Dimensions;
			//  shared_ptr<IfcUnitEnum>						m_UnitType;

			// IfcConversionBasedUnit -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;
			//  shared_ptr<IfcMeasureWithUnit>				m_ConversionFactor;
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;

			// IfcConversionBasedUnitWithOffset -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcReal>							m_ConversionOffset;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

