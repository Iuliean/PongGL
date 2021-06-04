#pragma once
#include "Engine.h"

class Ball : public pgl::Circle
{
private:
	vec2 speed{ 0, 200 };


public:

	Ball();

	void Move(const float& delta);
	void Reset();

	const vec2& GetSpeed()const;
	void SetSpeed(float xSpeed, float ySpeed);
};

