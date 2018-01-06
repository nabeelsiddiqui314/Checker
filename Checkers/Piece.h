#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "templates.h"
#include "Interface.h"
#include <array>

enum Modes {
	PAWN,
	PAWN_SELECTED,
	KING,
	KING_SELECTED
};

class Piece
{
public:
	Piece(const std::array<const std::string, 4> filepath, Cell* board[8][8], const sf::Vector2i& pos, int id);
	~Piece();
public:
	const sf::RectangleShape& GetPiece() const;
	void Move(int x, int y, bool firstTime = false);
	bool IsSelected(sf::RenderWindow& window);
	void Deselect();
	void SetMode(const Modes& mode);
	void Render(sf::RenderWindow& window);
	int  GetID() const;
	void MakeKing();
	bool IsKing() const;
private:
	sf::RectangleShape m_piece;
	std::vector<sf::Texture> m_textures;

	int   m_ID;
	Color m_color;
	Cell* m_board[8][8];
	bool  m_isSelected = false;
	bool  m_isKing = false;
};

