#include "Keyboard.h"

#include <Windows.h>
namespace pgl
{
	namespace Keyboard
	{
		bool isKeyPressed(Key&& key)
		{
			int wkey = 0;
			switch (key)
			{
			case Key::A:
				wkey = 'A';
				break;
			case Key::D:
				wkey = 'D';
				break;
			case Key::J:
				wkey = 'J';
				break;
			case Key::L:
				wkey = 'L';
			}
			/* Note to self
			returns a short with the most significant bit set if the key is down
			and if the least the significant bit is set the key was pressed after the previous call.

			0x8000 is the max short value
			if anded bitwise it the expression is 1 is the most significant bit is set*/
			return (GetAsyncKeyState(wkey) & 0x8000) != 0;
		}
	}
}