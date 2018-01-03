#pragma once
#include <SFML/Graphics.hpp>

enum Color {
	BLACK = 50,
	WHITE = 255
};

class Cell : public sf::RectangleShape
{
public:
	Cell(const sf::Vector2f& size, const sf::Vector2f& pos, const Color& color);
	~Cell();
public:
	const Color& GetColor() const;
private:
	Color m_color;
};

