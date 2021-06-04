#include "VertexBuffer.h"
#include "GL/glew.h"
#include "Log.h"

namespace pgl
{
    VertexBuffer::VertexBuffer()
    {
        this->bufferID = 0;
    }
   
    VertexBuffer::~VertexBuffer()
    {
        GLCall(glDeleteBuffers(1, &this->bufferID));
    }


    void VertexBuffer::Create(const void* data, const unsigned int size)
    {
        GLCall(glGenBuffers(1, &this->bufferID));
        this->Bind();
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    void VertexBuffer::Bind()const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, this->bufferID));
    }

    void VertexBuffer::Unbind()const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }
    
    void VertexBuffer::UpdateData(const void* data, unsigned int size)
    {
        this->Bind();
        GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
    }
}