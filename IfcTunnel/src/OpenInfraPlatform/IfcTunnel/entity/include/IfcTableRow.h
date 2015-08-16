/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcValue;
		class IfcTable;
		//ENTITY
		class IfcTableRow : public IfcTunnelEntity
		{
		public:
			IfcTableRow();
			IfcTableRow( int id );
			~IfcTableRow();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTableRow"; }


			// IfcTableRow -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcValue> >			m_RowCells;					//optional
			bool											m_IsHeading;				//optional
			// inverse attributes:
			weak_ptr<IfcTable>							m_OfTable_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

