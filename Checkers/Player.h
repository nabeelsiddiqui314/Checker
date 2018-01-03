#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <array>

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
	void RenderPieces(sf::RenderWindow& window);
private:
	std::array<Piece*, 12> m_redPieces;
	std::array<Piece*, 12> m_whitePieces;

	std::array<Piece*, 12>* m_currentPiece = &m_redPieces;

	Turn m_player = Turn::RED;
};

