#pragma once
#include "State.h"
#include "Game.h"

class Menu : public State
{
public:
	Menu();
	~Menu();
public:
	void HandleInput(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
private:
	inline void init_backround();
	inline void init_buttons();
private:
	Rect m_backround = Rect("./assets/backrounds/menu.jpeg");
	Rect m_play_button = Rect("./assets/buttons/play.png");

};
