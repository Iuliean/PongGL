#include "Rectangle.h"
#include "Log.h"
#include "GL/glew.h"

namespace pgl
{
	Rectangle::Rectangle(float otherWidth, float otherHeight)
	{
        this->x = 0;
        this->y = 0;

        this->width = otherWidth;
        this->height = otherHeight;

        float vertices[] = {
               0.0f,         0.0f, 
        this->width,         0.0f, 
        this->width, this->height, 
               0.0f, this->height 
        };
        
        this->vb.Create(vertices, sizeof(vertices) * sizeof(float));
  
        unsigned int indices[] =
        {
            0,1,2,
            0,2,3
        };  
        this->ib.Create(indices, sizeof(indices));
        
        VertexLayout layout;
        layout.Push<float>(2);

        this->va.AddLayout(this->vb, layout);
        this->shader.Create("res/shaders/Basic.shader");
        this->SetColorRGB(1.0f, 1.0f, 1.0f);
	}

    vec2 Rectangle::GetPosition()const
    {
        return glm::vec2(this->x, this->y);
    }

    void Rectangle::SetPosition(float newX, float newY)
    {
        this->x = newX;
        this->y = newY;

        this->shader.SetUniform4f("pos", this->x, this->y, 0.0f, 0.0f);
    }

    void Rectangle::OffsetPosition(float Xoffset, float Yoffset)
    {
        this->x = this->x + Xoffset;
        this->y = this->y + Yoffset;

        this->SetPosition(this->x, this->y);
    }

    RectPoints Rectangle::GetBounds()
    {
        RectPoints bounds;
        
        bounds.BL = vec2(this->x, this->y);
        bounds.BR = vec2(this->x + this->width, this->y);
        bounds.TL = vec2(this->x, this->y + this->height);
        bounds.TR = vec2(this->x + this->width, this->y + this->height);

        return bounds;
    }
}