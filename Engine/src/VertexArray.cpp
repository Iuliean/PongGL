#include "VertexArray.h"
#include "VertexLayout.h"
#include "GL/glew.h"
#include "Log.h"

namespace pgl 
{
	VertexArray::VertexArray()
	{
		GLCall(glGenVertexArrays(1, &this->objectID));
	}

	VertexArray::~VertexArray()
	{
		GLCall(glDeleteVertexArrays(1, &this->objectID));
	}

	void VertexArray::AddLayout(const VertexBuffer& vb, const VertexLayout& layout)
	{
		this->Bind();
		vb.Bind();
		
		auto& attributes = layout.GetAttributes();
		unsigned int offset = 0;
		
		for (int i = 0; i < attributes.size(); i++)
		{
			auto& attribute = attributes[i];
			GLCall(glVertexAttribPointer(i, attribute.count, attribute.type, attribute.isNormalised ? false : true, layout.GetStride(), (const void*)offset));
			GLCall(glEnableVertexAttribArray(i));
			
			offset += attribute.count * VertexAttribute::GetTypeSize(attribute);
		}
	}

	void VertexArray::Bind()const
	{
		GLCall(glBindVertexArray(this->objectID));
	}

	void VertexArray::Unbind()const
	{
		GLCall(glBindVertexArray(0));
	}
}