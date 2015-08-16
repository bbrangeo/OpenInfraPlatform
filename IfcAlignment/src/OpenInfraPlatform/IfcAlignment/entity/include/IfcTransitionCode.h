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

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcTransitionCode = ENUMERATION OF	(DISCONTINUOUS	,CONTINUOUS	,CONTSAMEGRADIENT	,CONTSAMEGRADIENTSAMECURVATURE);
		class IfcTransitionCode : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcTransitionCodeEnum
			{
				ENUM_DISCONTINUOUS,
				ENUM_CONTINUOUS,
				ENUM_CONTSAMEGRADIENT,
				ENUM_CONTSAMEGRADIENTSAMECURVATURE
			};

			IfcTransitionCode();
			IfcTransitionCode( IfcTransitionCodeEnum e ) { m_enum = e; }
			~IfcTransitionCode();
			virtual const char* classname() const { return "IfcTransitionCode"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTransitionCode> readStepData( std::string& arg );
			IfcTransitionCodeEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

