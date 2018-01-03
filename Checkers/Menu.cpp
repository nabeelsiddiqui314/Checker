#include "stdafx.h"
#include "Menu.h"

inline void Menu::init_backround() {
	m_backround.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_backround.setPosition(0, 0);
}

inline void Menu::init_buttons() {
	m_play_button.setSize(sf::Vector2f(250, 70));
	m_play_button.setPosition((SCREEN_WIDTH/2) - (m_play_button.getGlobalBounds().width /2), (SCREEN_HEIGHT/1.5) - (m_play_button.getGlobalBounds().height /2));
}

Menu::Menu() {
	init_backround();
	init_buttons();
}

void Menu::HandleInput(sf::RenderWindow& window) {
	if (Interface::isClicked(window, m_play_button)) {
		stateManager.SetState(new Game());
	}
}

void Menu::Update(sf::RenderWindow& window) {

}

void Menu::Render(sf::RenderWindow& window) {
	window.draw(m_backround);
	window.draw(m_play_button);
}

Menu::~Menu() {

}
