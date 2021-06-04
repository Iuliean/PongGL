#pragma once
#include "Log.h"
#include "Object.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

namespace pgl
{
	class Renderer
	{
	private:
		mat4 projMat;
	
	protected:
		Renderer(float sizeX, float sizeY);

		void Swap(GLFWwindow* window)const;
		void Render(const Object& obj)const;
	
	public:

		void Clear()const;
	};
}