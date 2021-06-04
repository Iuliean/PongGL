#include "Engine.h"

class Game
{
private:
	pgl::Window gameWindow{500, 500, "PongGL"};
public:
	Game();
	~Game();

	void Run();
};