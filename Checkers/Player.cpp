#include "stdafx.h"
#include "Player.h"


Player::Player(Board* board) {
	m_redPieces = new PieceManager(board, m_whitePieces, UP);
	m_whitePieces = new PieceManager(board, m_redPieces, DOWN);

	int skip = 0;
	for (unsigned short int i = 0; i < 12; i++) {
		if (i < 4) {
			m_redPieces->Add("./assets/pieces/red.png", sf::Vector2i(i + skip, 5), 1);
		}
		else if (i < 8) {
			m_redPieces->Add("./assets/pieces/red.png", sf::Vector2i(i - 7 + skip, 6), 1);
		}
		else if (i < 12) {
			m_redPieces->Add("./assets/pieces/red.png", sf::Vector2i(i - 16 + skip, 7), 1);
		}
		skip++;
	}
	skip = 0;
	for (unsigned short int i = 0; i < 12; i++) {
		if (i < 4) {
			m_whitePieces->Add("./assets/pieces/white.png", sf::Vector2i(i + 1 + skip, 2), 2);
		}
		else if (i < 8) {
			m_whitePieces->Add("./assets/pieces/white.png", sf::Vector2i(i - 8 + skip, 1), 2);
		}
		else if (i < 12) {
			m_whitePieces->Add("./assets/pieces/white.png", sf::Vector2i(i - 15 + skip, 0), 2);
		}
		skip++;
	}
	m_playerInTurn = m_redPieces;
}

void Player::SwapTurns() {
	if (m_playerInTurn == m_redPieces) {
		m_playerInTurn = m_whitePieces;
	}
	else {
		m_playerInTurn = m_redPieces;
	}
}

void Player::Update(sf::RenderWindow& window) {
	if (m_playerInTurn->ShouldSwap()) {
		SwapTurns();
	}
	m_playerInTurn->Update(window);
}

void Player::RenderPieces(sf::RenderWindow& window) {
	m_redPieces->RenderPieces(window);
	m_whitePieces->RenderPieces(window);
}


Player::~Player() {
	
}
