
#pragma once

#include "BlueFramework/Engine/ResourceManagment/ResourcePool.h"
#include "BlueFramework/Engine/BlueEngine.h"
#include "BlueFramework/Rasterizer/IRenderSystem.h"
#include "BlueFramework/ImageProcessing/color.h"
#include "BlueFramework/Core/class.h"
#include "BlueFramework/Core/Noncopyable.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		template<typename TVertexType>
		class VertexCacheLineT
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(VertexCacheLineT<TVertexType>);
			typedef TVertexType VertexType;


			VertexCacheLineT(buw::ReferenceCounted<buw::IRenderSystem> renderSystem,
				const int maxVertices = 100000) :
				renderSystem_(renderSystem),
				currentIndex_(0),
				maxVertices_(maxVertices)
			{
				pVertexData_ = nullptr;
			}

			VertexCacheLineT(buw::ReferenceCounted<buw::IRenderSystem> renderSystem,
				buw::ReferenceCounted<buw::IShader> shader,
				const int maxVertices = 100000) :
				renderSystem_(renderSystem),
				currentIndex_(0),
				maxVertices_(maxVertices)
			{
				
				createLayoutandBuffer(shader);
				pVertexData_ = nullptr;
			}

			void createLayoutandBuffer(buw::ReferenceCounted<buw::IShader> shader)
			{
				// create vertex layout
				const buw::vertexAttributeDescription *vld = TVertexType::getVertexLayoutDescription();
				int vertexLayoutElementCount = TVertexType::getVertexLayoutElementCount();

				layout_ = renderSystem_->createVertexLayout(vld, vertexLayoutElementCount, shader);

				// create vertex buffer
				dynamicCPUWriteVertexBuffer_ = renderSystem_->createVertexBuffer(
					sizeof(VertexType),
					maxVertices_,
					BlueFramework::Rasterizer::eBufferUsage::Dynamic,
					nullptr);
			}

			int getMaxVertexCount() const
			{
				return maxVertices_;
			}

			int getCurrentVertexCount()
			{
				return currentIndex_;
			}

			void drawLineUnsave(const VertexType& start, const VertexType& end)
			{
				if (!pVertexData_)
				{
					BLUE_ASSERT(renderSystem_.get() != nullptr, "renderer is null");

					if (currentIndex_ == 0)
					{
						dynamicCPUWriteVertexBuffer_->map(
							renderSystem_.get(),
							reinterpret_cast<void**>(&pVertexData_),
							buw::eRenderResourceAccessMode::CpuWrite,
							buw::eRenderResourceMapFlags::Discard
							);
					}
					else
					{
						dynamicCPUWriteVertexBuffer_->map(
							renderSystem_.get(),
							reinterpret_cast<void**>(&pVertexData_),
							buw::eRenderResourceAccessMode::CpuWrite,
							buw::eRenderResourceMapFlags::NoOverwrite
							);
					}
				}

				BLUE_ASSERT(pVertexData_ != nullptr, "vertex data pointer is null");
				BLUE_ASSERT(currentIndex_ >= 0, "current index must be greater or equal 0");

				pVertexData_[currentIndex_] = start;
				pVertexData_[currentIndex_ + 1] = end;

				currentIndex_ += 2;
			}

			void drawLine(const VertexType& start, const VertexType& end)
			{
				if (currentIndex_ + 2 >= maxVertices_)
				{
					throw buw::Exception("VertexCacheLine is to small to hold the current line.");
				}

				drawLineUnsave(start, end);
			}

			void flush(buw::ReferenceCounted<buw::IShader> shader)
			{
				if (pVertexData_)
				{
					dynamicCPUWriteVertexBuffer_->unmap(renderSystem_.get());
					pVertexData_ = nullptr;
				}

				buw::drawCommand dc;
				dc.indexOffset = 0;
				dc.primitveType = buw::ePrimitveType::LineList;
				dc.vertexCount = currentIndex_;
				dc.setVertexBuffer(dynamicCPUWriteVertexBuffer_);
				dc.setVertexLayout(layout_);

				renderSystem_->getImmediateContext()->bind(shader);
				renderSystem_->getImmediateContext()->draw(dc);
				renderSystem_->getImmediateContext()->unbind(shader);
			}

			//! Clears vertex cache.
			void clear()
			{
				currentIndex_ = 0;
			}

		private:
			VertexType*					pVertexData_;
			int							currentIndex_;
			int							maxVertices_;

			buw::ReferenceCounted<buw::IRenderSystem>	renderSystem_;
			buw::ReferenceCounted<buw::IVertexLayout>	layout_;
			buw::ReferenceCounted<buw::IVertexBuffer>	dynamicCPUWriteVertexBuffer_;
		};
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::VertexCacheLineT;
}
