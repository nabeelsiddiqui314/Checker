#include "stdafx.h"
#include "Cell.h"


Cell::Cell(const sf::Vector2f& size, const sf::Vector2f& pos, const Color& color) : m_color(color) {
	this->setSize(size);
	this->setPosition(pos);
	this->setFillColor(sf::Color(color, color, color));
}


const Color& Cell::GetColor() const {
	return m_color;
}


Cell::~Cell() {

}
