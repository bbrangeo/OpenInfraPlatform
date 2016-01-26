/*! \verbatim
 *  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief		This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once
#ifndef BlueFramework_GraphicsEngine_BlueMap_89d0ecd9_c7bb_42aa_87a1_f2b355d8cf2c_h
#define BlueFramework_GraphicsEngine_BlueMap_89d0ecd9_c7bb_42aa_87a1_f2b355d8cf2c_h

#include "BlueFramework/Rasterizer/IRenderSystem.h"
#include "buw.BlueEngine.TextureRepository.h"
#include "BlueFramework/Engine/Mesh/Quad2.h"
#include "BlueFramework/Core/PropertySet.h"
#include <boost/noncopyable.hpp>
#include <string>
#include <thread>

namespace BlueFramework
{
	namespace Engine
	{
		struct eTileStatus
		{
			enum Enum
			{
				NotRequestedYet,
				Loaded
			};
		};

		struct mapTile
		{
			eTileStatus::Enum		status;
			buw::vector2i			position;
			buw::ReferenceCounted<buw::ITexture2D>	texture;
		};

		class BlueMap : private boost::noncopyable
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(BlueMap);
			std::thread t1;

			BlueMap(buw::ReferenceCounted<buw::IRenderSystem> renderSystem, buw::ReferenceCounted<buw::IRenderContext> renderContext_);

			virtual ~BlueMap();

			void addTile(const buw::vector2i& position);

			void draw(const int width, const int height);

			void applyProperties(const buw::PropertySet& ps);

			void setTileSize(const int size);

		private:
			void loadTextures();

		private:	
			buw::vector2i				start_;
			int							mapSizeInPixels_;

			bool						stopThread_;
			buw::vector2i				offset;

			buw::ReferenceCounted<buw::Quad2>				quad_;
			buw::ReferenceCounted<buw::IShader>			quadShader_;
			buw::ReferenceCounted<buw::TextureRepository>	textureRepository_;

			buw::ReferenceCounted<buw::IRenderSystem>		renderSystem_;
			buw::ReferenceCounted<buw::IRenderContext>	renderContext_;
			buw::ReferenceCounted<buw::ITexture2D>		loading_;
			std::vector<mapTile>		tiles_;
		}; // end class BlueMap
	} // end namespace GraphicsEngine
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Engine::BlueMap;
}

#endif // end define BlueFramework_GraphicsEngine_BlueMap_89d0ecd9_c7bb_42aa_87a1_f2b355d8cf2c_h