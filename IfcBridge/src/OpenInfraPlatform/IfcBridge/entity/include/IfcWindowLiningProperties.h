/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"
#include "IfcPreDefinedPropertySet.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcPositiveLengthMeasure;
		class IfcNormalisedRatioMeasure;
		class IfcShapeAspect;
		class IfcLengthMeasure;
		//ENTITY
		class IfcWindowLiningProperties : public IfcPreDefinedPropertySet
		{
		public:
			IfcWindowLiningProperties();
			IfcWindowLiningProperties( int id );
			~IfcWindowLiningProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcWindowLiningProperties"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcPropertyDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDeclares> >		m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

			// IfcPropertySetDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcTypeObject> >		m_DefinesType_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByTemplate> >	m_IsDefinedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_DefinesOccurrence_inverse;

			// IfcPreDefinedPropertySet -----------------------------------------------------------

			// IfcWindowLiningProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_LiningDepth;				//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_LiningThickness;			//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_TransomThickness;			//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_MullionThickness;			//optional
			shared_ptr<IfcNormalisedRatioMeasure>		m_FirstTransomOffset;		//optional
			shared_ptr<IfcNormalisedRatioMeasure>		m_SecondTransomOffset;		//optional
			shared_ptr<IfcNormalisedRatioMeasure>		m_FirstMullionOffset;		//optional
			shared_ptr<IfcNormalisedRatioMeasure>		m_SecondMullionOffset;		//optional
			shared_ptr<IfcShapeAspect>					m_ShapeAspectStyle;			//optional
			shared_ptr<IfcLengthMeasure>					m_LiningOffset;				//optional
			shared_ptr<IfcLengthMeasure>					m_LiningToPanelOffsetX;		//optional
			shared_ptr<IfcLengthMeasure>					m_LiningToPanelOffsetY;		//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

