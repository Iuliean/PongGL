#include "Ball.h"

Ball::Ball()
	:Circle(20)
{

}

void Ball::Move(const float& delta)
{
	this->OffsetPosition(this->speed.x * delta, this->speed.y * delta);
}

void Ball::Reset()
{
	this->SetSpeed(0, 200);
	this->SetPosition(0, 0);
}

const vec2& Ball::GetSpeed()const
{
	return this->speed;
}

void Ball::SetSpeed(float xSpeed, float ySpeed)
{
	this->speed.x = xSpeed;
	this->speed.y = ySpeed;
}