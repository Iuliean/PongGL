#pragma once
#include "VertexBuffer.h"
#include "VertexLayout.h"

namespace pgl
{
	class VertexArray
	{
	private:
		unsigned int objectID;
	public:

		VertexArray();
		~VertexArray();

		void AddLayout(const VertexBuffer& vb, const VertexLayout& layout);

		void Bind()const;
		void Unbind()const;
	};
}
