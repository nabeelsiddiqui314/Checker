#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Rect : public sf::RectangleShape {
	sf::Texture tex;
public:
	Rect(std::string filename) {
		tex.loadFromFile(filename);
		this->setTexture(&tex);
	}
};

class Sound : public sf::Sound {
	sf::SoundBuffer buffer;
public:
	Sound(std::string filename) {
		buffer.loadFromFile(filename);
		this->setBuffer(buffer);
	}
};

class Text : public sf::Text {
	sf::Font font;
public:
	Text(std::string filename) {
		font.loadFromFile(filename);
		this->setFont(font);
	}
};