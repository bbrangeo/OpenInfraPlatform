/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"
#include "IfcObjectReferenceSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcLabel;
		class IfcText;
		class IfcAppliedValueSelect;
		class IfcMeasureWithUnit;
		class IfcDateTimeSelect;
		class IfcReferencesValueDocument;
		class IfcAppliedValueRelationship;
		//ENTITY
		class IfcAppliedValue : public IfcObjectReferenceSelect, public Ifc2x3Entity
		{
		public:
			IfcAppliedValue();
			IfcAppliedValue( int id );
			~IfcAppliedValue();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAppliedValue"; }


			// IfcAppliedValue -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>									m_Name;						//optional
			shared_ptr<IfcText>									m_Description;				//optional
			shared_ptr<IfcAppliedValueSelect>					m_AppliedValue;				//optional
			shared_ptr<IfcMeasureWithUnit>						m_UnitBasis;				//optional
			shared_ptr<IfcDateTimeSelect>						m_ApplicableDate;			//optional
			shared_ptr<IfcDateTimeSelect>						m_FixedUntilDate;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcReferencesValueDocument> >	m_ValuesReferenced_inverse;
			std::vector<weak_ptr<IfcAppliedValueRelationship> >	m_ValueOfComponents_inverse;
			std::vector<weak_ptr<IfcAppliedValueRelationship> >	m_IsComponentIn_inverse;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

