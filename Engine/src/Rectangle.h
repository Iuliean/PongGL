#pragma once
#include "Object.h"
#include "glm/glm.hpp"

namespace pgl
{
	class Rectangle: public Object
	{
	private:
		float x;
		float y;
		float height;
		float width;
	public:
		Rectangle(float otherWidth, float otherHeight);

		vec2 GetPosition()const;

		void SetPosition(float newX, float newY);
		void OffsetPosition(float Xoffset, float Yoffset);
		RectPoints GetBounds()override;
	};
}
