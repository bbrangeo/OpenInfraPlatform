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

			Hud(buw::ReferenceCounted<buw::IRenderSystem> renderSystem, buw::ReferenceCounted<buw::IRenderContext> renderContext);

			virtual ~Hud();

			void mouseMoveEvent(const int width, const int height, const int x, const int y);

			void render(const int width, const int height);

		private:
			buw::ReferenceCounted<buw::IBlendState>				defaultBlendState_;
			buw::ReferenceCounted<buw::IBlendState>				alphaBlendingState_;

			buw::ReferenceCounted<buw::IRenderSystem>				renderSystem_;
			buw::ReferenceCounted<buw::IRenderContext>			renderContext_;

			buw::ReferenceCounted<buw::ITexture2D>				textureMagnifier_;
			buw::ReferenceCounted<buw::ITexture2D>				textureMagnifierHoverd_;
			buw::vector2i						sizeMagnifier_;
			buw::rectanglef						sourceRectangleMagnifier_;
			bool								isHoveringMagnifier_;

			buw::ReferenceCounted<buw::SpriteBatch>				spriteBatch_;
		};
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::Hud;
}

#endif // end define OpenInfraPlatform_UserInterface_Hud_eb53b2d0_c1ef_44f8_a161_363d80d34973_h
