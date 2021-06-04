#include "Window.h"

#include <iostream>

static bool GLFWini()
{
    static bool isInit = false;

    if (!isInit)
    {
        if (!glfwInit())
        {
            std::cout << "Cannot init\n";
            return false;
        }
        else
        {
            isInit = true;
            return true;
        }
    }
    else
        return true;
}

static bool GLEWini()
{
    static bool isInit = false;

    if (!isInit)
    {
        if (glewInit() != GLEW_OK)
        {
            std::cout << "Cannot init\n";
            return false;
        }
        else
        {
            isInit = true;
            return true;
        }
    }
    else
        return true;
}

namespace pgl
{
    Window::Window(float sizeX, float sizeY, const std::string& title)
        :Renderer(sizeX, sizeY)
	{
        this->size = vec2(sizeX, sizeY);
        /* Initialize the library */
        if (GLFWini())
        {
            this->window = glfwCreateWindow(sizeX, sizeY, title.c_str(), NULL, NULL);
            this->title = title;
        }

        /* Create a windowed mode window and its OpenGL context */
        glfwSetWindowUserPointer(this->window, this);
        if (!this->window)
        {
            glfwTerminate();
            std::cout << "Window terminated\n";
        }

        /* Make the window's context current */
        this->MakeCurrentContext();

        if (!GLEWini())
            std::cout << "Cannot init glew";
	}

    const vec2& Window::GetSize()const
    {
        return this->size;
    }

	void Window::MakeCurrentContext()const
	{
		glfwMakeContextCurrent(this->window);
	}

    void Window::Display()const
    {
        this->Swap(this->window);
    }

    void Window::Draw(const Object& obj)const
    {
        this->MakeCurrentContext();
        this->Render(obj);
    }

    bool Window::IsOpen()const
    {
        this->MakeCurrentContext();
        return !glfwWindowShouldClose(this->window);
    }

    void Window::PollEvents()
    {
        glfwPollEvents(); 
    }
}