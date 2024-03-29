#pragma once
#include <SFML/Graphics.hpp>
#include "Variables.h"
#include "State.h"
#include "Menu.h"

class Application
{
public:
	Application();
	~Application();
public:
	void Run();
private:
	sf::RenderWindow m_mainWindow;
	sf::Clock        m_clock;
	sf::Time         m_accumulator = sf::Time::Zero;
	sf::Time         m_ups = sf::seconds(1.f / 60.f);
};

