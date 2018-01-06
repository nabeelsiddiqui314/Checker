#include "stdafx.h"
#include "Cell.h"


Cell::Cell(const sf::Vector2f& size, const sf::Vector2f& pos, const Color& color) : m_color(color) {
	m_cell.setSize(size);
	m_cell.setPosition(pos);
	m_cell.setFillColor(sf::Color(color, color, color));
}

const sf::RectangleShape& Cell::GetCell() const {
	return m_cell;
}

void Cell::Render(sf::RenderWindow& window) {
	window.draw(m_cell);
}

Cell::~Cell() {

}
