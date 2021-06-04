#include "Circle.h"

#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>


namespace pgl
{
	Circle::Circle(float otherRadius)
	{
		this->x = 0.0f;
		this->y = 0.0f;

		this->radius = otherRadius;

		VertexLayout layout;
		layout.Push<float>(2);

		std::vector<float> points;
		std::vector<unsigned int> indices;
		
		points.push_back(0.0f);
		points.push_back(0.0f);
		
		for (int i = 0; i < 360; i++)
		{
			float converter = M_PI / 180;
			float x = cos(i * converter);
			float y = sin(i * converter);

			points.push_back(x * this->radius);
			points.push_back(y * this->radius);
		}

		for (int i = 0; i <= 360; i++)
		{
			indices.push_back(0);
			indices.push_back(i);
			indices.push_back(i + 1 == 361 ? 1 : i+1);
		}

	
		this->vb.Create(points.data(), points.size() * sizeof(float));
		this->ib.Create(indices.data(), indices.size());

		this->va.AddLayout(this->vb, layout);

		this->shader.Create("res/shaders/Basic.shader");
		this->shader.SetUniform4f("pos", 0.0f, 0.0f, 0.0f, 0.0f);
		this->SetColorRGB(1.0f, 1.0f, 1.0f);

	}

	float Circle::GetRadius()const
	{
		return this->radius;
	}

	vec2 Circle::GetPosition()const
	{
		return vec2(this->x, this->y);
	}

	void Circle::SetPosition(float newX, float newY)
	{
		this->x = newX;
		this->y = newY;

		this->shader.SetUniform4f("pos", this->x, this->y, 0.0f, 0.0f);
	}

	void Circle::OffsetPosition(float Xoffest, float Yoffset)
	{
		this->x += Xoffest;
		this->y += Yoffset;
		
		this->SetPosition(this->x, this->y);
	}

	RectPoints Circle::GetBounds()
	{
		RectPoints bounds;
		bounds.BL = vec2(this->x - this->radius, this->y - this->radius);
		bounds.BR = vec2(this->x + this->radius, this->y - this->radius);
		bounds.TR = vec2(this->x + this->radius, this->y + this->radius);
		bounds.TL = vec2(this->x - this->radius, this->y + this->radius);
		return bounds;
	}
}