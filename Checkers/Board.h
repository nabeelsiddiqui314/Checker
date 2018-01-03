#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

class Board
{
public:
	Board(const sf::Vector2f& cellSize, const sf::Vector2f& startPos);
	~Board();
public:
	void Render(sf::RenderWindow& window);
private:
	void SwapColors();
private:
	Cell* m_board[8][8];
	Color m_color = WHITE;
};

