#include "IndexBuffer.h"
#include "GL/glew.h"
#include "Log.h"


namespace pgl
{
    IndexBuffer::IndexBuffer()
    {
        this->bufferID = 0;
        this->count = 0;
    }

    void IndexBuffer::Create(const void* data, const unsigned int count)
    {
        this->count = count;
        GLCall(glGenBuffers(1, &this->bufferID));
        this->Bind();
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    }

    IndexBuffer::~IndexBuffer()
    {
        GLCall(glDeleteBuffers(1, &this->bufferID));
    }

    void IndexBuffer::Bind()const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->bufferID));
    }

    void IndexBuffer::Unbind()const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

    unsigned int IndexBuffer::GetCount()const
    {
        return this->count;
    }
}