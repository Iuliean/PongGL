#pragma once
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "GLMDef.h"

namespace pgl
{
	struct RectPoints
	{	
		vec2 BL;
		vec2 BR;
		vec2 TL;
		vec2 TR;

		void Print();
	};

	class Object
	{
	protected:
		VertexArray  va;
		VertexBuffer vb;
		IndexBuffer  ib;
		Shader		 shader;

	public:

		Object();
		~Object();

		void Bind()const;
		void Unbind()const;
		
		virtual RectPoints GetBounds() = 0;
		void SetColorRGB(float r, float g, float b);
		bool CollidesWith(const RectPoints& collider);
		const IndexBuffer& GetIndexBuffer()const;
		const Shader& GetShader()const;
	};
}