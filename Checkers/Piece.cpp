#include "stdafx.h"
#include "Piece.h"

Piece::Piece(const std::string& filepath, Cell* board[8][8], const sf::Vector2i& pos) : m_piece(filepath)
{
	for (unsigned short int x = 0; x < 8; x++) {
		for (unsigned short int y = 0; y < 8; y++) {
			m_board[x][y] = board[x][y];
		}
	}
	m_piece.setSize(m_board[0][0]->GetCell().getSize());
	m_piece.setPosition(m_board[pos.x][pos.y]->GetCell().getPosition());
}


const sf::RectangleShape& Piece::GetPiece() const {
	return m_piece;
}

void Piece::Move(int x, int y) {
	m_piece.setPosition(m_board[x][y]->GetCell().getPosition());
}

void Piece::Render(sf::RenderWindow& window) {
	window.draw(m_piece);
}


Piece::~Piece()
{
}
