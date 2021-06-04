#include "Paddle.h"

Paddle::Paddle()
	:Rectangle(100, 10)
{
	this->speed = 700;
}

void Paddle::MoveLeft(const float& delta)
{
	this->OffsetPosition(-this->speed * delta, 0.0f);
}

void Paddle::MoveRight(const float& delta)
{
	this->OffsetPosition(this->speed * delta, 0.0f);
}