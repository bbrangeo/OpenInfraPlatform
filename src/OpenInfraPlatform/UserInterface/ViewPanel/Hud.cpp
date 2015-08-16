/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "Hud.h"

void OpenInfraPlatform::UserInterface::Hud::render( const int width, const int height )
{
	spriteBatch_->setScreenResolution(width, height);

	buw::vector2i position(	width - sizeMagnifier_.x(), height - sizeMagnifier_.y());

	buw::vector4f vblendFactor(0.0f);

	renderContext_->setBlendState(alphaBlendingState_, &vblendFactor[0] );

	if (isHoveringMagnifier_)
	{
		spriteBatch_->draw(
			textureMagnifierHoverd_,
			position, 
			sizeMagnifier_, 
			sourceRectangleMagnifier_);
	}
	else
	{
		spriteBatch_->draw(
			textureMagnifier_,
			position, 
			sizeMagnifier_, 
			sourceRectangleMagnifier_);
	}


	spriteBatch_->flush();

	renderContext_->setBlendState(defaultBlendState_, &vblendFactor[0] );
}

void OpenInfraPlatform::UserInterface::Hud::mouseMoveEvent( const int width, const int height, const int x, const int y )
{
	if (x > width - sizeMagnifier_.x() &&
		height-y-1 > height - sizeMagnifier_.y())
	{
		isHoveringMagnifier_ = true;
	}
	else
	{
		isHoveringMagnifier_ = false;
	}
}

OpenInfraPlatform::UserInterface::Hud::~Hud()
{

}

OpenInfraPlatform::UserInterface::Hud::Hud( buw::IRenderSystem::Ptr renderSystem, buw::IRenderContext::Ptr renderContext ) :
	renderSystem_(renderSystem),
	renderContext_(renderContext)
{
	// create a sprite patch manager
	spriteBatch_ = std::make_shared<buw::SpriteBatch>(
		renderSystem_, 
		"Shader/SpriteBatch.be");

	// load crosshairs
	buw::Image_4b::Ptr imageCrosshairs = buw::loadImageFromFile<buw::Image_4b>("Data/zoomicons.png");
	textureMagnifier_ = buw::loadTexture(renderSystem_, imageCrosshairs);
	sizeMagnifier_.x() = imageCrosshairs->getWidth();
	sizeMagnifier_.y() = imageCrosshairs->getHeight();

	textureMagnifierHoverd_ = buw::loadTexture(renderSystem_, "Data/zoomicons_hover.png");

	sourceRectangleMagnifier_ = buw::rectanglef(0, 1, 1, 0);

	// create blend states for alpha blending
	buw::blendStateDescription default_bsd;
	defaultBlendState_ = renderSystem_->createBlendState(default_bsd);

	buw::blendStateDescription bsd;
	bsd.AlphaToCoverageEnable = false;
	bsd.IndependentBlendEnable = false;
	bsd.RenderTarget[0].BlendEnable				= true;
	bsd.RenderTarget[0].SourceBlend				= buw::eBlendOption::SourceAlpha;
	bsd.RenderTarget[0].DestinationBlend		= buw::eBlendOption::InverseSourceAlpha;
	bsd.RenderTarget[0].BlendOperation			= buw::eBlendOperation::Add;
	bsd.RenderTarget[0].SourceBlendAlpha		= buw::eBlendOption::Zero;
	bsd.RenderTarget[0].DestinationBlendAlpha	= buw::eBlendOption::Zero;
	bsd.RenderTarget[0].BlendOperationAlpha		= buw::eBlendOperation::Add;
	bsd.RenderTarget[0].RenderTargetWriteMask	= 0x0F;//buw::eColorWriteEnable::COLOR_WRITE_ENABLE_ALL;
	alphaBlendingState_ = renderSystem_->createBlendState(bsd);

	isHoveringMagnifier_ = false;
}
