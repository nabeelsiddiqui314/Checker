#pragma once
#include <SFML/Graphics.hpp>

enum Color {
	BLACK = 50,
	WHITE = 255
};

class Cell
{
public:
	Cell(const sf::Vector2f& size, const sf::Vector2f& pos, const Color& color);
	~Cell();
public:
	const sf::Color& GetColor() const;
	const sf::RectangleShape& GetCell() const;
	void SetID(int id) { m_contentID = id; }
	int  GetID() const { return m_contentID; }
	void Render(sf::RenderWindow& window);
private:
	sf::RectangleShape m_cell;
	Color m_color;
	int m_contentID = 0;
};

