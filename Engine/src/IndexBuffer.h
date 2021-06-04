#pragma once

namespace pgl
{
	class IndexBuffer
	{
	private:
		unsigned int bufferID;
		unsigned int count;
	public:

		IndexBuffer();
		~IndexBuffer();

		void Create(const void* data, const unsigned int count);
		
		void Bind()const;
		void Unbind()const;

		unsigned int GetCount()const;
	};
}