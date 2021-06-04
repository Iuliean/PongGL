#pragma once
#include "GL/glew.h"

#include <vector>

namespace pgl {
	struct VertexAttribute
	{
		unsigned int type;
		unsigned int count;
		bool		 isNormalised;

		static unsigned int GetTypeSize(const VertexAttribute& attrib)
		{
			switch (attrib.type)
			{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			}
		}
	};

	class VertexLayout
	{
	private:
		std::vector<VertexAttribute> attributes;
		unsigned int stride;
	public:

		VertexLayout() :
			stride(0)
		{

		};

		template<typename T>
		void Push(unsigned int count)
		{
			static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			attributes.push_back({ GL_FLOAT, count, true });
			this->stride += sizeof(float) * count;
		}

		template<>
		void Push<unsigned int>(unsigned int count)
		{
			attributes.push_back({ GL_UNSIGNED_INT, count, false });
			this->stride += sizeof(unsigned int) * count;
		}

		const std::vector<VertexAttribute>& GetAttributes()const
		{
			return this->attributes;
		}

		const unsigned int& GetStride()const
		{
			return this->stride;
		}
	};
}
