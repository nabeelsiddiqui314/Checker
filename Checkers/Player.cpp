#include "stdafx.h"
#include "Player.h"


Player::Player(Board* board) {
	int skip = 0;
	for (unsigned short int i = 0; i < m_redPieces.size(); i++) {
		if (i < 4) {
			m_redPieces[i] = new Piece("./assets/pieces/red.png", board->m_board, sf::Vector2i(i+skip, 5));
		}
		else if (i < 8) {
			m_redPieces[i] = new Piece("./assets/pieces/red.png", board->m_board, sf::Vector2i(i-7 + skip, 6));
		}
		else if (i < 12) {
			m_redPieces[i] = new Piece("./assets/pieces/red.png", board->m_board, sf::Vector2i(i-16 + skip, 7));
		}
		skip++;
	}
	skip = 0;
	for (unsigned short int i = 0; i < m_whitePieces.size(); i++) {
		if (i < 4) {
			m_whitePieces[i] = new Piece("./assets/pieces/white.png", board->m_board, sf::Vector2i(i+1 + skip, 2));
		}
		else if (i < 8) {
			m_whitePieces[i] = new Piece("./assets/pieces/white.png", board->m_board, sf::Vector2i(i-8 + skip, 1));
		}
		else if (i < 12) {
			m_whitePieces[i] = new Piece("./assets/pieces/white.png", board->m_board, sf::Vector2i(i-15 + skip, 0));
		}
		skip++;
	}
}

void Player::SwapTurns() {
	if (m_currentPiece == &m_redPieces) {
		m_currentPiece = &m_whitePieces;
	}
	else {
		m_currentPiece = &m_redPieces;
	}
}

void Player::RenderPieces(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_redPieces.size(); i++) {
		m_redPieces[i]->Render(window);
	}
	for (unsigned short int i = 0; i < m_whitePieces.size(); i++) {
		m_whitePieces[i]->Render(window);
	}
}


Player::~Player() {
	for (unsigned short int i = 0; i < m_redPieces.size(); i++) {
		delete m_redPieces[i];
	}
	for (unsigned short int i = 0; i < m_whitePieces.size(); i++) {
		delete m_whitePieces[i];
	}
}
