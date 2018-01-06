#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "templates.h"
#include "Interface.h"

class Piece
{
public:
	Piece(const std::string& filepath, Cell* board[8][8], const sf::Vector2i& pos, int id);
	~Piece();
public:
	const sf::RectangleShape& GetPiece() const;
	void Move(int x, int y, bool firstTime = false);
	bool IsSelected(sf::RenderWindow& window);
	void Deselect();
	void Render(sf::RenderWindow& window);
	int  GetID() const { return m_ID; }
private:
	int   m_ID;
	Rect  m_piece;
	Color m_color;
	Cell* m_board[8][8];
	bool  m_isSelected = false;
};

