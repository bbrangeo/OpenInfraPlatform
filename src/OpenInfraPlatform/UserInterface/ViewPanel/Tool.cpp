#include "Tool.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class SketchBasedAlignment : public Tool
		{
		public:
			SketchBasedAlignment(buw::ReferenceCounted<buw::VertexCachePoint> vcp) :
				vertexCachePoint_(vcp)
			{

			}

			void mousePressEvent(QMouseEvent *event) override
			{
				if (event->button() & Qt::LeftButton)
				{
					if (event->modifiers() & Qt::SHIFT)
					{
						m_ConstructionPoints.clear();

						vertexCachePoint_->clear();
					}
				}
			}

			void mouseMoveEvent(QMouseEvent *event) override
			{
				if (event->buttons())
				{
					if (event->modifiers() & Qt::SHIFT)
					{
						buw::vector3f lastTargetPoint = targetPoint_;

						vertexCachePoint_->drawPoint(targetPoint_);

						m_ConstructionPoints.push_back(lastTargetPoint);
					}
				}
			}

			void setTargetPoint(const buw::vector3f& targetPoint) override
			{
				targetPoint_ = targetPoint;
			}

		private:
			buw::vector3f targetPoint_;

			std::vector<buw::vector3f> m_ConstructionPoints;

			// Drawing
			buw::ReferenceCounted<buw::VertexCachePoint>	vertexCachePoint_;
		};
	}
}

void OpenInfraPlatform::UserInterface::ToolManager::setTargetPoint(buw::vector3f targetPoint_)
{
	tool_->setTargetPoint(targetPoint_);
}

void OpenInfraPlatform::UserInterface::ToolManager::mouseMoveEvent(QMouseEvent *event)
{
	tool_->mouseMoveEvent(event);
}

void OpenInfraPlatform::UserInterface::ToolManager::mousePressEvent(QMouseEvent *event)
{
	tool_->mousePressEvent(event);
}

void OpenInfraPlatform::UserInterface::ToolManager::setCurrentTool(buw::ReferenceCounted<Tool> tool)
{
	tool_ = tool;
}

OpenInfraPlatform::UserInterface::ToolManager::ToolManager(buw::ReferenceCounted<buw::VertexCachePoint> vcp)
{
	tool_ = std::make_shared<SketchBasedAlignment>(vcp);
}

