#pragma once
#include "State.h"
#include "Board.h"
#include "Player.h"

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
	Board*  m_board;
	Player* m_players;
};

