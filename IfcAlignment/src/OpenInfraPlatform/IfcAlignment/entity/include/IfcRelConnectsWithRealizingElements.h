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
#include "IfcRelConnectsElements.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcElement;
		class IfcLabel;
		//ENTITY
		class IfcRelConnectsWithRealizingElements : public IfcRelConnectsElements
		{
		public:
			IfcRelConnectsWithRealizingElements();
			IfcRelConnectsWithRealizingElements( int id );
			~IfcRelConnectsWithRealizingElements();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelConnectsWithRealizingElements"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelConnectsElements -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcConnectionGeometry>			m_ConnectionGeometry;		//optional
			//  shared_ptr<IfcElement>						m_RelatingElement;
			//  shared_ptr<IfcElement>						m_RelatedElement;

			// IfcRelConnectsWithRealizingElements -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcElement> >			m_RealizingElements;
			shared_ptr<IfcLabel>							m_ConnectionType;			//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

