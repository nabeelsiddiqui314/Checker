#include "stdafx.h"
#include "Game.h"

inline void Game::init_buttons() {
	m_menu_button.setSize(sf::Vector2f(120, 50));
	m_menu_button.setPosition(570, 5);

	m_pause_button.setSize(sf::Vector2f(120, 50));
	m_pause_button.setPosition(60, 5);

	m_play_again.setSize(sf::Vector2f(260, 120));
	m_play_again.setPosition((SCREEN_WIDTH / 2) - (m_play_again.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.5) - (m_play_again.getGlobalBounds().height / 2));
}

inline void Game::init_rects() {
	m_tint.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_tint.setPosition(0, 0);
	m_tint.setFillColor(sf::Color(5, 5, 5, 180));

	m_backround.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_backround.setPosition(0, 0);
}

Game::Game() {
	this->init_buttons();
	this->init_rects();

	m_board = new Board(sf::Vector2f(80, 80), sf::Vector2f(60, 60));
	m_players = new Player(m_board);
}

void Game::HandleInput(sf::RenderWindow& window) {
	if (m_gameOver) {
		if (Interface::isClicked(window, m_play_again)) {
			stateManager.SetState(new Game());
		}
	}
	else {
		if (Interface::isClicked(window, m_pause_button) && m_pauseLimit.getElapsedTime().asMilliseconds() > 200) {
			m_paused = !m_paused;
			m_pauseLimit.restart();
		}
		if(Interface::isClicked(window, m_menu_button)) {
			stateManager.SetState(new Menu());
		}
	}
}

void Game::Update(sf::RenderWindow& window) {
	if(!m_gameOver && !m_paused) m_players->Update(window);
}

void Game::Render(sf::RenderWindow& window) {
	window.draw(m_backround);
	m_board->Render(window);
	m_players->RenderPieces(window);
	window.draw(m_menu_button);
	
	if (m_paused) window.draw(m_tint);
	window.draw(m_pause_button);

	if (m_gameOver) window.draw(m_tint);

	if (m_players->IsGameOver(window)) {
		m_gameOver = true;
		window.draw(m_play_again);
	}
}

Game::~Game() {
	delete m_players;
	delete m_board;
}
