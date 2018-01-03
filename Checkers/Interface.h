#pragma once
#include <SFML/Graphics.hpp>

class Interface
{
public:
	Interface();
	~Interface();
public:
	static bool isHovered(const sf::RenderWindow& window, const sf::RectangleShape& button);
	static void SetPointer(sf::RenderWindow& window, sf::RectangleShape& pointer, const bool hideMouse);
	static bool isClicked(const sf::RenderWindow& window, const sf::RectangleShape& button);
	static bool isMouseInWindow(const sf::RenderWindow& window);
};
