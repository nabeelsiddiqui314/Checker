#include "stdafx.h"
#include "Menu.h"

inline void Menu::init_backround() {
	m_backround.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_backround.setPosition(0, 0);
}

inline void Menu::init_buttons() {
	m_play_button.setSize(sf::Vector2f(250, 120));
	m_play_button.setPosition((SCREEN_WIDTH/2) - (m_play_button.getGlobalBounds().width /2), 350);

	m_quit_button.setSize(sf::Vector2f(250, 120));
	m_quit_button.setPosition((SCREEN_WIDTH / 2) - (m_quit_button.getGlobalBounds().width / 2), 
		m_play_button.getPosition().y + 140);
}

inline void Menu::init_title() {
	m_title.setCharacterSize(200u);
	m_title.setString("Checkers");
	m_title.setFillColor(sf::Color::White);
	m_title.setOutlineColor(sf::Color::Black);
	m_title.setOutlineThickness(10);
	m_title.setPosition((SCREEN_WIDTH / 2) - (m_title.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 4) - (m_title.getGlobalBounds().height / 2));
}

Menu::Menu() {
	init_backround();
	init_buttons();
	init_title();
}

void Menu::HandleInput(sf::RenderWindow& window) {
	if (Interface::isClicked(window, m_play_button)) {
		stateManager.SetState(new Game());
	}
	if (Interface::isClicked(window, m_quit_button)) {
		window.close();
	}
}

void Menu::Update(sf::RenderWindow& window) {

}

void Menu::Render(sf::RenderWindow& window) {
	window.draw(m_backround);
	window.draw(m_play_button);
	window.draw(m_quit_button);
	window.draw(m_title);
}

Menu::~Menu() {

}
