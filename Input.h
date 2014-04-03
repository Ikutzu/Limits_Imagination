#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Input
{
public:
	static void UpdateState();
	static bool IsKeyDown(Keyboard::Key key);
	static bool IsKeyUp(Keyboard::Key key);
	static bool IsKeyPressed(Keyboard::Key key);
	static bool IsKeyReleased(Keyboard::Key key);
	static bool IsButtonDown(Mouse::Button button);
	static bool IsButtonUp(Mouse::Button button);
	static bool IsButtonPressed(Mouse::Button button);
	static bool IsButtonReleased(Mouse::Button button);
	static Vector2i MousePosition();

private:

	static Keyboard k_state, k_state_old;
	static Mouse m_state, m_state_old;
};

