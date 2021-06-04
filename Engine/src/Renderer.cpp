#include "Renderer.h"
#include "Gl/glew.h"


namespace pgl 
{
    Renderer::Renderer(float sizeX, float sizeY)
    {
        this->projMat = glm::ortho(-sizeX, sizeX, -sizeY, sizeY);
    }

    void Renderer::Clear()const
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Render(const Object& obj)const
    {
        obj.Bind();
        obj.GetShader().SetUniformMat4("projMat", this->projMat);
        GLCall(glDrawElements(GL_TRIANGLES, obj.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::Swap(GLFWwindow* window)const
    {
        glfwSwapBuffers(window);
    }
}