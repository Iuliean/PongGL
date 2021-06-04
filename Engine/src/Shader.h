#pragma once
#include "GLMDef.h"

#include<string>


namespace pgl
{
	class VertexShader
	{
	private:
		unsigned int shaderID;
	public:

		VertexShader(const std::string& source);
		~VertexShader();

		unsigned int GetID()const;
	};

	class FragmentShader
	{
	private:
		unsigned int shaderID;
	public:
		FragmentShader(const std::string& source);
		~FragmentShader();

		unsigned int GetID()const;
	};

	class Shader
	{
	private:
		unsigned int shaderID;

		unsigned int GetUniformLocation(const std::string& uniformName)const;
	public:

		Shader();
		~Shader();

		void Create(const std::string& path);
		void Bind()const;
		void Unbind()const;

		void SetUniform1f(const std::string& uniformName, float value)const;
		void SetUniform4f(const std::string& uniformName, float f1, float f2, float f3, float f4)const;
		void SetUniformMat4(const std::string& uniformName, const mat4& matrix)const;
	};
}