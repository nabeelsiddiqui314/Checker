#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"
#include "Interface.h"
#include "Piece.h"

class Board
{
public:
	Board(const sf::Vector2f& cellSize, const sf::Vector2f& startPos);
	~Board();
public:
	void Render(sf::RenderWindow& window);
public:
	Cell* m_board[8][8];
private:
	void SwapColors();
private:
	Color m_color = WHITE;
};

