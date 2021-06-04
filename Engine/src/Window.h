#pragma once
#include "Renderer.h"
#include "Object.h"
#include "GLFW/glfw3.h"

#include <string>


namespace pgl
{
	class Window : public Renderer
	{
	private:
		GLFWwindow* window;
		std::string title;
		vec2 size;

		void MakeCurrentContext()const;
	public:
		Window(float sizeX, float sizeY, const std::string& title);

		const vec2& GetSize()const;

		void Display()const;
		void Draw(const Object& obj)const;
		
		bool IsOpen()const;
		void PollEvents();
		
	};
}