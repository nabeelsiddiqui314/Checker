#include "stdafx.h"
#include "Game.h"


Game::Game() {
	m_board = new Board(sf::Vector2f(60, 60), sf::Vector2f(50, 50));
}

void Game::HandleInput(sf::RenderWindow& window) {
	
}

void Game::Update(sf::RenderWindow& window) {
	
}

void Game::Render(sf::RenderWindow& window) {
	m_board->Render(window);
}

Game::~Game()
{
}
