/*! \verbatim
 *  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief		This file is part of the BlueFramework.
 *	\endverbatim
 */

#include "BlueMap.h"


#include "buw.BlueEngine.resources.h"

//#define USA

BlueFramework::Engine::BlueMap::BlueMap( buw::ReferenceCounted<buw::IRenderSystem> renderSystem, buw::ReferenceCounted<buw::IRenderContext> renderContext_ ) :
	renderSystem_(renderSystem),
	renderContext_(renderContext_),
	stopThread_(false),
	mapSizeInPixels_(256)
{
	textureRepository_ = std::make_shared<buw::TextureRepository>();

	quadShader_ = renderSystem_->createShader("Shader/drawQuad.be");
	quad_ = std::make_shared<buw::Quad2>(renderSystem_, quadShader_, buw::eFilter::None);

	loading_ = buw::loadTexture(renderSystem, "Data/textures/loading.png");

#ifdef USA
	start_ = buw::vector2i(5240, 12661);
#else
	start_ = buw::vector2i(139495, 90962);
	start_ = buw::vector2i(34873-3, 22740);
#endif 
	
	for (int x = 0; x < 50; x++)
		for(int y = 0; y < 30; y++)
		{
			addTile( start_ + buw::vector2i(x, y) );
		}

	t1 = std::thread(&BlueMap::loadTextures, this);
}

BlueFramework::Engine::BlueMap::~BlueMap()
{
	stopThread_ = true;
	t1.join();
}

void BlueFramework::Engine::BlueMap::addTile( const buw::vector2i& position )
{
	mapTile tile;
	tile.status		= eTileStatus::NotRequestedYet;
	tile.position	= position;
	tile.texture	= nullptr;

	tiles_.push_back(tile);
}

void BlueFramework::Engine::BlueMap::draw( const int width, const int height )
{
	for( mapTile &t : tiles_)
	{
		// draw quad
		const int tileSizeInPixels = mapSizeInPixels_;//64;//256;

		float offset_x = ( t.position.x() - start_.x() ) * tileSizeInPixels;
		float offset_y = ( t.position.y() - start_.y() ) * tileSizeInPixels;

		if(t.texture == nullptr)
		{
			quadShader_->setValue("texQuadMap", loading_);
		}
		else
		{
			quadShader_->setValue("texQuadMap", t.texture);
		}

		quad_->setScreenResolution(width, height);
		quad_->draw(offset_x, height-offset_y-1, tileSizeInPixels, tileSizeInPixels, quadShader_);
	}
}

void BlueFramework::Engine::BlueMap::loadTextures()
{
	for( mapTile &t : tiles_)
	{
		if (stopThread_)
		{
			return;
		}

		std::stringstream ss;

#ifdef USA
		ss << "http://otile1.mqcdn.com/tiles/1.0.0/sat/15/" << t.position.x() << "/" << t.position.y() << ".jpg";
#else
		//ss << "http://tile.openstreetmap.org/18/" << t.position.x() << "/" << t.position.y() << ".png";

		// http://services.opengeoserver.org/tiles/1.0.0/globe.aerial_EPSG3857/16/34873/22740.png?origin=nw
		ss << "http://services.opengeoserver.org/tiles/1.0.0/globe.aerial_EPSG3857/16/" << t.position.x() << "/" << t.position.y() << ".png?origin=nw";
#endif 

		t.texture = buw::createTextureFromImage(renderSystem_, textureRepository_->getImage(ss.str(), "cache"));
	}
}

void BlueFramework::Engine::BlueMap::applyProperties( const buw::PropertySet& ps )
{
	if (ps.contains("size"))
	{
		int size = ps.getInteger("size");
		setTileSize(size);
	}
}

void BlueFramework::Engine::BlueMap::setTileSize( const int size )
{
	mapSizeInPixels_ = size;
}