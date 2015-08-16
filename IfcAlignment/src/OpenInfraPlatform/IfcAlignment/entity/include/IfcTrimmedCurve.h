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
#include "IfcBoundedCurve.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcCurve;
		class IfcTrimmingSelect;
		class IfcBoolean;
		class IfcTrimmingPreference;
		//ENTITY
		class IfcTrimmedCurve : public IfcBoundedCurve
		{
		public:
			IfcTrimmedCurve();
			IfcTrimmedCurve( int id );
			~IfcTrimmedCurve();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTrimmedCurve"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcCurve -----------------------------------------------------------

			// IfcBoundedCurve -----------------------------------------------------------

			// IfcTrimmedCurve -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCurve>							m_BasisCurve;
			std::vector<shared_ptr<IfcTrimmingSelect> >	m_Trim1;
			std::vector<shared_ptr<IfcTrimmingSelect> >	m_Trim2;
			shared_ptr<IfcBoolean>						m_SenseAgreement;
			shared_ptr<IfcTrimmingPreference>			m_MasterRepresentation;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

