#include "Shader.h"
#include "Log.h"
#include "GL/glew.h"


#include <iostream>
#include <fstream>
#include <sstream>

namespace pgl
{
	//VertexShader
	VertexShader::VertexShader(const std::string& source)
	{
		GLCall(this->shaderID = glCreateShader(GL_VERTEX_SHADER));
		const char* src = source.c_str();
		GLCall(glShaderSource(this->shaderID, 1, &src, nullptr));
		GLCall(glCompileShader(this->shaderID));

		int result;
		glGetShaderiv(this->shaderID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(this->shaderID, GL_INFO_LOG_LENGTH, &length);

			char* message = (char*)alloca(length * sizeof(char));

			glGetShaderInfoLog(this->shaderID, length, &length, message);
			std::cout << message << " [VertexShader]" << '\n';
			this->~VertexShader();
		}
	}

	VertexShader::~VertexShader()
	{
		GLCall(glDeleteShader(this->shaderID))
	}

	unsigned int VertexShader::GetID()const
	{
		return this->shaderID;
	}

	//FragmentShader
	FragmentShader::FragmentShader(const std::string& source)
	{
		GLCall(this->shaderID = glCreateShader(GL_FRAGMENT_SHADER));
		const char* src = source.c_str();
		GLCall(glShaderSource(this->shaderID, 1, &src, nullptr));
		GLCall(glCompileShader(this->shaderID));

		int result;
		glGetShaderiv(this->shaderID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(this->shaderID, GL_INFO_LOG_LENGTH, &length);

			char* message = (char*)alloca(length * sizeof(char));

			glGetShaderInfoLog(this->shaderID, length, &length, message);
			std::cout << message << " [FragmentShader]" << '\n';
			this->~FragmentShader();
		}
	}

	FragmentShader::~FragmentShader()
	{
		GLCall(glDeleteShader(this->shaderID))
	}

	unsigned int FragmentShader::GetID()const
	{
		return this->shaderID;
	}

	//Shader
	Shader::Shader()
	{
		this->shaderID = 0;
	}

	void Shader::Create(const std::string& path)
	{
		this->shaderID = glCreateProgram();

		std::ifstream file(path);

		enum class ShaderType
		{
			NONE = -1,
			VERTEX = 0,
			FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
		while (getline(file, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					type = ShaderType::VERTEX;
				}
				else if (line.find("fragment"))
				{
					type = ShaderType::FRAGMENT;
				}
			}
			else
			{
				ss[(int)type] << line << '\n';
			}
		}

		VertexShader vs(ss[0].str());
		FragmentShader fs(ss[1].str());

		GLCall(glAttachShader(this->shaderID, vs.GetID()));
		GLCall(glAttachShader(this->shaderID, fs.GetID()));
		GLCall(glLinkProgram(this->shaderID));
		GLCall(glValidateProgram(this->shaderID));
	}


	Shader::~Shader()
	{
		GLCall(glDeleteProgram(this->shaderID));
	}

	unsigned int Shader::GetUniformLocation(const std::string& uniformName)const
	{
		GLCall(unsigned int location = glGetUniformLocation(this->shaderID, uniformName.c_str()));
		return location;
	}

	void Shader::Bind()const
	{
		GLCall(glUseProgram(this->shaderID));
	}

	void Shader::Unbind()const
	{
		GLCall(glUseProgram(0));
	}

	//---------------------
	// UNIFORMS
	//---------------------

	void Shader::SetUniform1f(const std::string& uniformName, float value)const
	{
		this->Bind();
		GLCall(glUniform1f(this->GetUniformLocation(uniformName), value));
	}

	void Shader::SetUniform4f(const std::string& uniformName, float f1, float f2, float f3, float f4)const
	{
		this->Bind();
		GLCall(glUniform4f(this->GetUniformLocation(uniformName), f1, f2, f3, f4));
	}

	void Shader::SetUniformMat4(const std::string& uniformName, const mat4& matrix)const
	{
		this->Bind();
		GLCall(glUniformMatrix4fv(this->GetUniformLocation(uniformName), 1, GL_FALSE, &matrix[0][0]));
	}
}