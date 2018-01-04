#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "PieceManager.h"

enum class Turn {
	RED,
	WHITE
};

class Player
{
public:
	Player(Board* board);
	~Player();
public:
	void SwapTurns();
	void Update(sf::RenderWindow& window);
	void RenderPieces(sf::RenderWindow& window);
private:
	Turn m_player = Turn::RED;
	PieceManager* m_redPieces;
	PieceManager* m_whitePieces;
};

