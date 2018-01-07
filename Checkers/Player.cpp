#include "stdafx.h"
#include "Player.h"

inline void Player::init_text() {
	m_winnerText.setCharacterSize(200u);
	m_winnerText.setOutlineColor(sf::Color::Black);
	m_winnerText.setOutlineThickness(10);
}

Player::Player(Board* board) {
	this->init_text();

	m_redPieces = new PieceManager(board, UP);
	m_whitePieces = new PieceManager(board, DOWN);

	m_redPieces->SetOther(m_whitePieces);
	m_whitePieces->SetOther(m_redPieces);

	int skip = 0;
	for (unsigned short int i = 0; i < 12; i++) {
		if (i < 4) {
			m_redPieces->Add(m_redFilepaths, sf::Vector2i(i + skip, 5), 1);
		}
		else if (i < 8) {
			m_redPieces->Add(m_redFilepaths, sf::Vector2i(i - 7 + skip, 6), 1);
		}
		else if (i < 12) {
			m_redPieces->Add(m_redFilepaths, sf::Vector2i(i - 16 + skip, 7), 1);
		}
		skip++;
	}
	skip = 0;
	for (unsigned short int i = 0; i < 12; i++) {
		if (i < 4) {
			m_whitePieces->Add(m_whiteFilepaths, sf::Vector2i(i + 1 + skip, 2), 2);
		}
		else if (i < 8) {
			m_whitePieces->Add(m_whiteFilepaths, sf::Vector2i(i - 8 + skip, 1), 2);
		}
		else if (i < 12) {
			m_whitePieces->Add(m_whiteFilepaths, sf::Vector2i(i - 15 + skip, 0), 2);
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

	if (m_redPieces->IsWinner()) {
		m_winnerText.setFillColor(sf::Color::Red);
		m_winnerText.setString("Red Wins!");
		m_winnerText.setPosition((SCREEN_WIDTH / 2) - (m_winnerText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 4) - (m_winnerText.getGlobalBounds().height / 2));
		m_gameOver = true;
	}
	else if (m_whitePieces->IsWinner()) {
		m_winnerText.setFillColor(sf::Color(222, 222, 222));
		m_winnerText.setString("White Wins!");
		m_winnerText.setPosition((SCREEN_WIDTH / 2) - (m_winnerText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 4) - (m_winnerText.getGlobalBounds().height / 2));
		m_gameOver = true;
	}
}

void Player::RenderPieces(sf::RenderWindow& window) {
	m_redPieces->RenderPieces(window);
	m_whitePieces->RenderPieces(window);
}

bool Player::IsGameOver(sf::RenderWindow& window) {
	if (m_gameOver) {
		window.draw(m_winnerText);
	}
	return m_gameOver;
}

Player::~Player() {
	
}
