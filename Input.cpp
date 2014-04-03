#include "Input.h"

Keyboard Input::k_state;
Keyboard Input::k_state_old;
Mouse Input::m_state;
Mouse Input::m_state_old;

void Input::UpdateState()
{
	k_state;
	m_state;
}

bool Input::IsKeyDown(Keyboard::Key key)
{
	return k_state.isKeyPressed(key);
}

bool Input::IsKeyUp(Keyboard::Key key)
{
	return !k_state.isKeyPressed(key);
}

bool Input::IsKeyPressed(Keyboard::Key key)
{

	return k_state.isKeyPressed(key) && !k_state_old.isKeyPressed(key);
}

bool Input::IsKeyReleased(Keyboard::Key key)
{
	return !k_state.isKeyPressed(key) && k_state_old.isKeyPressed(key);
}

bool Input::IsButtonDown(Mouse::Button button)
{
	return m_state.isButtonPressed(button);
}

bool Input::IsButtonUp(Mouse::Button button)
{
	return !m_state.isButtonPressed(button);
}

bool Input::IsButtonPressed(Mouse::Button button)
{
	return m_state.isButtonPressed(button) && !m_state_old.isButtonPressed(button);
}

bool Input::IsButtonReleased(Mouse::Button button)
{
	return !m_state.isButtonPressed(button) && m_state_old.isButtonPressed(button);
}

Vector2i Input::MousePosition()
{
	return m_state.getPosition();
}