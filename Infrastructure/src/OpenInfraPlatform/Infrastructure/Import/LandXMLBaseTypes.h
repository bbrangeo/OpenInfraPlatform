/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_LandXMLBaseTypes_b8936503_0da8_4a8a_a3cf_18346a7b1bcf_h
#define OpenInfraPlatform_Infrastructure_LandXMLBaseTypes_b8936503_0da8_4a8a_a3cf_18346a7b1bcf_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/Math/vector.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		enum class eProfAlignType
		{
			CircCurve,
			PVI,
			ParaCurve
		};

		struct BLUEINFRASTRUCTURE_API profAlignElement
		{
			profAlignElement()
			{
				length = 0;
				type = eProfAlignType::PVI;
			}

			eProfAlignType			type;

			// ParaCurve data
			double					length;
			buw::vector2d			position;

			// CircCurve data
			double					radius;
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::eProfAlignType;
	using OpenInfraPlatform::Infrastructure::profAlignElement;
}

#endif // end define OpenInfraPlatform_Infrastructure_LandXMLBaseTypes_b8936503_0da8_4a8a_a3cf_18346a7b1bcf_h