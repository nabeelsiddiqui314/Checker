#include "stdafx.h"
#include "Board.h"


Board::Board(const sf::Vector2f& cellSize, const sf::Vector2f& startPos) {
	for (unsigned short int x = 0; x < 8; x++) {
		SwapColors();
		for (unsigned short int y = 0; y < 8; y++) {
			SwapColors();
			m_board[x][y] = new Cell(cellSize, sf::Vector2f(startPos.x + (cellSize.x * x), startPos.y + (cellSize.y * y)), m_color);
		}
	}
}


void Board::Render(sf::RenderWindow& window) {
	for (unsigned short int x = 0; x < 8; x++) {
		for (unsigned short int y = 0; y < 8; y++) {
			window.draw(*m_board[x][y]);
		}
	}
}

void Board::SwapColors() {
	if (m_color == BLACK) {
		m_color = WHITE;
	}
	else {
		m_color = BLACK;
	}
}

Board::~Board() {
	delete[] m_board;
}
