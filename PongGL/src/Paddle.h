#pragma once
#include "Engine.h"

class Paddle : public pgl::Rectangle
{
private:
	float speed;
public:
	Paddle();

	void MoveLeft(const float& delta);
	void MoveRight(const float& delta);

};

