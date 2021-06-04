#pragma once

namespace pgl
{
	namespace Keyboard
	{
		enum class Key
		{
			Unknown = -1,
			A = 0,
			D = 1,
			J = 2,
			L = 3
		};

		bool isKeyPressed(Key&& key);
	}
}

