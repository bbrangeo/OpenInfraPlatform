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
#include "IfcPhysicalSimpleQuantity.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcMassMeasure;
		class IfcLabel;
		//ENTITY
		class IfcQuantityWeight : public IfcPhysicalSimpleQuantity
		{
		public:
			IfcQuantityWeight();
			IfcQuantityWeight( int id );
			~IfcQuantityWeight();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcQuantityWeight"; }


			// IfcPhysicalQuantity -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;
			//  shared_ptr<IfcText>							m_Description;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
			//  std::vector<weak_ptr<IfcPhysicalComplexQuantity> >	m_PartOfComplex_inverse;

			// IfcPhysicalSimpleQuantity -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcNamedUnit>						m_Unit;						//optional

			// IfcQuantityWeight -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMassMeasure>					m_WeightValue;
			shared_ptr<IfcLabel>							m_Formula;					//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

