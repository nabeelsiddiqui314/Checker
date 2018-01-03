#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "templates.h"

class Piece
{
public:
	Piece(const std::string& filepath, Cell* board[8][8], const sf::Vector2i& pos);
	~Piece();
public:
	const sf::RectangleShape& GetPiece() const;
	void Move(int x, int y);
	void Render(sf::RenderWindow& window);
private:
	Rect  m_piece;
	Color m_color;
	Cell* m_board[8][8];
};

