#include "Log.h"
#include "GL/glew.h"

#include <iostream>

void ClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

bool LogErrors(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL error] (" << error << ") " << function << " " << file << " " << line << '\n';
		return false;
	}
	return true;
}