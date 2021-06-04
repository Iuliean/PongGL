#include "Clock.h"

namespace pgl
{
        Clock::Clock()
        {
            this->clockTime = std::chrono::steady_clock::now();
        }

        float Clock::Delta()
        {
            std::chrono::time_point<std::chrono::steady_clock> newTime = std::chrono::steady_clock::now();
            float delta = std::chrono::duration<float>(newTime - this->clockTime).count();

            this->clockTime = newTime;
            return delta;
        }
}