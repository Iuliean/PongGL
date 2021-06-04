#pragma once
#include "Object.h"
#include "GLMDef.h"

namespace pgl
{
	class Circle: public Object
	{
	private:
		float x;
		float y;
		float radius;
	public:
		Circle(float otherRadius);

		float GetRadius()const;
		vec2 GetPosition()const;
		void SetPosition(float newX, float newY);
		void OffsetPosition(float Xoffset, float Yoffset);
		RectPoints GetBounds()override;
	};
}

