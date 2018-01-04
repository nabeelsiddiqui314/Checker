#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <vector>

class PieceManager
{
public:
	PieceManager(Board* board);
	~PieceManager();
public:
	void Add(const std::string& filepath, const sf::Vector2i& pos);
	void Update(sf::RenderWindow& window);
	void RenderPieces(sf::RenderWindow& window);
private:
	std::vector<Piece*> m_pieces;
	Board* m_board;
};

