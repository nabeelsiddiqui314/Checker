#pragma once
#include "State.h"
#include "Board.h"
#include "Player.h"
#include "Menu.h"

class Game : public State
{
public:
	Game();
	~Game();
public:
	void HandleInput(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
private:
	inline void init_buttons();
	inline void init_rects();
private:
	Board*  m_board;
	Player* m_players;
	Rect    m_play_again = Rect("./assets/buttons/play_again.png");
	Rect    m_menu_button = Rect("./assets/buttons/menu.png");
	Rect    m_pause_button = Rect("./assets/buttons/pause.png");
	Rect    m_backround = Rect("./assets/backrounds/menu.jpeg");
	sf::RectangleShape m_tint;
	bool    m_gameOver = false;
	bool    m_paused = false;
	sf::Clock m_pauseLimit;
};

