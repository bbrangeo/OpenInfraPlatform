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
#include "IfcMetricValueSelect.h"
#include "IfcObjectReferenceSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcTableRow;
		class IfcTableColumn;
		//ENTITY
		class IfcTable : public IfcMetricValueSelect, public IfcObjectReferenceSelect, public IfcBridgeEntity
		{
		public:
			IfcTable();
			IfcTable( int id );
			~IfcTable();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTable"; }


			// IfcTable -----------------------------------------------------------
			// attributes:
			std::string									m_Name;
			std::vector<shared_ptr<IfcTableRow> >		m_Rows;
			std::vector<shared_ptr<IfcTableColumn> >		m_Columns;					//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

