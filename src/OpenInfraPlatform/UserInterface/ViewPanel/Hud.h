/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_Hud_eb53b2d0_c1ef_44f8_a161_363d80d34973_h
#define OpenInfraPlatform_UserInterface_Hud_eb53b2d0_c1ef_44f8_a161_363d80d34973_h

#include <boost/noncopyable.hpp>

#include "buw.BlueImageProcessing.h"
#include "buw.BlueEngine.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class Hud
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(Hud);

			Hud(buw::IRenderSystem::Ptr renderSystem, buw::IRenderContext::Ptr renderContext);

			virtual ~Hud();

			void mouseMoveEvent(const int width, const int height, const int x, const int y);

			void render(const int width, const int height);

		private:
			buw::IBlendState::Ptr				defaultBlendState_;
			buw::IBlendState::Ptr				alphaBlendingState_;

			buw::IRenderSystem::Ptr				renderSystem_;
			buw::IRenderContext::Ptr			renderContext_;

			buw::ITexture2D::Ptr				textureMagnifier_;
			buw::ITexture2D::Ptr				textureMagnifierHoverd_;
			buw::vector2i						sizeMagnifier_;
			buw::rectanglef						sourceRectangleMagnifier_;
			bool								isHoveringMagnifier_;

			buw::SpriteBatch::Ptr				spriteBatch_;
		};
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::Hud;
}

#endif // end define OpenInfraPlatform_UserInterface_Hud_eb53b2d0_c1ef_44f8_a161_363d80d34973_h
