#include "stdafx.h"
#include "Player.h"


Player::Player(Board* board) {
	m_redPieces = new PieceManager(board);
	m_whitePieces = new PieceManager(board);

	int skip = 0;
	for (unsigned short int i = 0; i < 12; i++) {
		if (i < 4) {
			m_redPieces->Add("./assets/pieces/red.png", sf::Vector2i(i + skip, 5));
		}
		else if (i < 8) {
			m_redPieces->Add("./assets/pieces/red.png", sf::Vector2i(i - 7 + skip, 6));
		}
		else if (i < 12) {
			m_redPieces->Add("./assets/pieces/red.png", sf::Vector2i(i - 16 + skip, 7));
		}
		skip++;
	}
	skip = 0;
	for (unsigned short int i = 0; i < 12; i++) {
		if (i < 4) {
			m_whitePieces->Add("./assets/pieces/white.png", sf::Vector2i(i + 1 + skip, 2));
		}
		else if (i < 8) {
			m_whitePieces->Add("./assets/pieces/white.png", sf::Vector2i(i - 8 + skip, 1));
		}
		else if (i < 12) {
			m_whitePieces->Add("./assets/pieces/white.png", sf::Vector2i(i - 15 + skip, 0));
		}
		skip++;
	}
}

void Player::SwapTurns() {
	
}

void Player::Update(sf::RenderWindow& window) {
	m_redPieces->Update(window);
	m_whitePieces->Update(window);
}

void Player::RenderPieces(sf::RenderWindow& window) {
	m_redPieces->RenderPieces(window);
	m_whitePieces->RenderPieces(window);
}


Player::~Player() {
	
}
