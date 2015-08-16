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
#include "IfcStructuralConnectionCondition.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcForceMeasure;
		//ENTITY
		class IfcFailureConnectionCondition : public IfcStructuralConnectionCondition
		{
		public:
			IfcFailureConnectionCondition();
			IfcFailureConnectionCondition( int id );
			~IfcFailureConnectionCondition();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcFailureConnectionCondition"; }


			// IfcStructuralConnectionCondition -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcFailureConnectionCondition -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcForceMeasure>					m_TensionFailureX;			//optional
			shared_ptr<IfcForceMeasure>					m_TensionFailureY;			//optional
			shared_ptr<IfcForceMeasure>					m_TensionFailureZ;			//optional
			shared_ptr<IfcForceMeasure>					m_CompressionFailureX;		//optional
			shared_ptr<IfcForceMeasure>					m_CompressionFailureY;		//optional
			shared_ptr<IfcForceMeasure>					m_CompressionFailureZ;		//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

