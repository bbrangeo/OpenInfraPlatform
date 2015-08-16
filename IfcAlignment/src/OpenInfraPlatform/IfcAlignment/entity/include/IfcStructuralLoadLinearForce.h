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
#include "IfcStructuralLoadStatic.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcLinearForceMeasure;
		class IfcLinearMomentMeasure;
		//ENTITY
		class IfcStructuralLoadLinearForce : public IfcStructuralLoadStatic
		{
		public:
			IfcStructuralLoadLinearForce();
			IfcStructuralLoadLinearForce( int id );
			~IfcStructuralLoadLinearForce();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcStructuralLoadLinearForce"; }


			// IfcStructuralLoad -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcStructuralLoadOrResult -----------------------------------------------------------

			// IfcStructuralLoadStatic -----------------------------------------------------------

			// IfcStructuralLoadLinearForce -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLinearForceMeasure>			m_LinearForceX;				//optional
			shared_ptr<IfcLinearForceMeasure>			m_LinearForceY;				//optional
			shared_ptr<IfcLinearForceMeasure>			m_LinearForceZ;				//optional
			shared_ptr<IfcLinearMomentMeasure>			m_LinearMomentX;			//optional
			shared_ptr<IfcLinearMomentMeasure>			m_LinearMomentY;			//optional
			shared_ptr<IfcLinearMomentMeasure>			m_LinearMomentZ;			//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

