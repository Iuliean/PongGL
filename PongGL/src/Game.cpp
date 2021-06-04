#include "Game.h"
#include "Paddle.h"
#include "Ball.h"

#include <math.h>
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
	glfwTerminate();
}

void Game::Run()
{
	Paddle player1;
	Paddle player2;
	Ball ball;
	
	player1.SetPosition(player1.GetPosition().x - 50, -450);
	player2.SetPosition(player2.GetPosition().x - 50,  450);
	

	pgl::Clock clock;
	while (this->gameWindow.IsOpen())
	{
		float delta = clock.Delta();
		this->gameWindow.PollEvents();
		
		//Player Controll
		if (pgl::Keyboard::isKeyPressed(pgl::Keyboard::Key::A))
			player1.MoveLeft(delta);
		if (pgl::Keyboard::isKeyPressed(pgl::Keyboard::Key::D))
			player1.MoveRight(delta);
		
		if (pgl::Keyboard::isKeyPressed(pgl::Keyboard::Key::J))
			player2.MoveLeft(delta);
		if (pgl::Keyboard::isKeyPressed(pgl::Keyboard::Key::L))
			player2.MoveRight(delta);

		//Collisions
		if (ball.CollidesWith(player1.GetBounds()))
		{
			vec2 playerPosition = player1.GetPosition();
			vec2 ballPosition = ball.GetPosition();

			float distance = std::abs(playerPosition.x + 50 - ballPosition.x);
			float speedModifier = 400 * distance / 50;
			
			ball.SetSpeed(ballPosition.x > playerPosition.x + 50 ? speedModifier : -speedModifier,
							ball.GetSpeed().y * -1);
		}
		
		if (ball.CollidesWith(player2.GetBounds()))
		{
			vec2 playerPosition = player2.GetPosition();
			vec2 ballPosition = ball.GetPosition();

			float distance = std::abs(playerPosition.x + 50 - ballPosition.x);
			float speedModifier = 400 * distance / 50;

			ball.SetSpeed(ballPosition.x > playerPosition.x + 50 ? speedModifier : -speedModifier,
				ball.GetSpeed().y * -1);
		}

		if (ball.GetPosition().x + ball.GetRadius() >= this->gameWindow.GetSize().x || ball.GetPosition().x - ball.GetRadius() <= -this->gameWindow.GetSize().x)
		{
			ball.SetSpeed(-ball.GetSpeed().x, ball.GetSpeed().y);
		}

		if (ball.GetPosition().y + ball.GetRadius() > this->gameWindow.GetSize().y || ball.GetPosition().y - ball.GetRadius() < -this->gameWindow.GetSize().y)
		{
			ball.Reset();
		}

		ball.Move(delta);
				
		this->gameWindow.Clear();
		this->gameWindow.Draw(player1);
		this->gameWindow.Draw(player2);
		this->gameWindow.Draw(ball);
		this->gameWindow.Display();
	}
}