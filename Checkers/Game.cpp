#include "stdafx.h"
#include "Game.h"


Game::Game() {
	m_board = new Board(sf::Vector2f(72, 72), sf::Vector2f(200, 50));
	m_players = new Player(m_board);
}

void Game::HandleInput(sf::RenderWindow& window) {
	
}

void Game::Update(sf::RenderWindow& window) {
	
}

void Game::Render(sf::RenderWindow& window) {
	m_board->Render(window);
	m_players->RenderPieces(window);
}

Game::~Game()
{
}
