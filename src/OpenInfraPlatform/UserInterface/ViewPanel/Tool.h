#pragma once

#include "buw.BlueEngine.h"
#include <QMouseEvent>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class Tool
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(Tool);

			virtual void mousePressEvent(QMouseEvent *event) = 0;
			virtual void mouseMoveEvent(QMouseEvent *event) = 0;
			virtual void setTargetPoint(const buw::vector3f& targetPoint) = 0;
		};

		class ToolManager
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(ToolManager);

			ToolManager(buw::ReferenceCounted<buw::VertexCachePoint> vcp);

			void setCurrentTool(buw::ReferenceCounted<Tool> tool);

			void mousePressEvent(QMouseEvent *event);

			void mouseMoveEvent(QMouseEvent *event);

			void setTargetPoint(buw::vector3f targetPoint_);

		private:
			buw::ReferenceCounted<Tool>			tool_;
			buw::vector3f		targetPoint_;
		};
	}
}