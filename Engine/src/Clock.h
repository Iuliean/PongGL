#pragma once
#include <chrono>

namespace pgl
{
	class Clock
	{
	private:
		std::chrono::time_point<std::chrono::steady_clock> clockTime;
	public:
		Clock();

		float Delta();
	};
}
