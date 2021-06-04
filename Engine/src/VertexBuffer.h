#pragma once


namespace pgl
{
	class VertexBuffer
	{
	private:
		unsigned int bufferID;
	public:
		VertexBuffer();
		~VertexBuffer();

		void Create(const void* data, const unsigned int size);
		void Bind()const;
		void Unbind()const;

		void UpdateData(const void* data, unsigned int size);
	};
}