#include "Object.h"

#include <iostream>

namespace pgl
{
	void RectPoints::Print()
	{
		std::cout << "BL: " << this->BL.x << ' ' << this->BL.y<< '\n';
		std::cout << "BR: " << this->BR.x << ' ' << this->BR.y<< '\n';
		std::cout << "TL: " << this->TL.x << ' ' << this->TL.y<< '\n';
		std::cout << "TR: " << this->TR.x << ' ' << this->TR.y<< '\n';
	}

	//Object
	Object::Object()
	{
	}

	Object::~Object()
	{

	}

	void Object::Bind()const
	{
		this->va.Bind();
		//this->vb.Bind();
		this->ib.Bind();
		this->shader.Bind();
	}

	void Object::Unbind()const
	{
		this->va.Unbind();
		//this->vb.Unbind();
		this->ib.Unbind();
		this->shader.Unbind();
	}

	void Object::SetColorRGB(float r, float g, float b)
	{
		this->shader.SetUniform4f("u_color", r, g, b, 1.0f);
	}

	//Check if a collision happened on the y axis
	bool Object::CollidesWith(const RectPoints& collider)
	{
		RectPoints selfRect = this->GetBounds();
		
		//DONT'T EVEN TRY TO UNDERSTAND. it's very badly done anyways
		
		bool top = selfRect.TL.y > collider.BL.y && selfRect.TL.y < collider.TL.y && 
				  (selfRect.TL.x < collider.BR.x && selfRect.TL.x > collider.BL.x ||
				   selfRect.TR.x < collider.BR.x && selfRect.TR.x > collider.BL.x ||
				   selfRect.TL.x < collider.BR.x&& selfRect.TL.x > collider.BL.x && selfRect.TR.x < collider.BR.x&& selfRect.TR.x > collider.BL.x);

		bool bottom = selfRect.BL.y > collider.BL.y && selfRect.BL.y < collider.TL.y &&
					 (selfRect.BL.x < collider.TR.x&& selfRect.BL.x > collider.TL.x ||
					  selfRect.BR.x < collider.TR.x&& selfRect.BR.x > collider.TL.x ||
					  selfRect.BL.x < collider.TR.x&& selfRect.BL.x > collider.TL.x && selfRect.BR.x < collider.TR.x&& selfRect.BR.x > collider.TL.x);
			          

		return top || bottom;
	}

	const IndexBuffer& Object::GetIndexBuffer()const
	{
		return this->ib;
	}

	const Shader& Object::GetShader()const
	{
		return this->shader;
	}
}