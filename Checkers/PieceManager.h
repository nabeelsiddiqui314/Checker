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
	void Add(const std::string& filepath, const sf::Vector2i& pos, int id);
	void Update(sf::RenderWindow& window);
	void RenderPieces(sf::RenderWindow& window);
	bool ShouldSwap() const { return m_shouldSwap; }
private:
	std::vector<Piece*> m_pieces;
	Board* m_board;
	Piece* m_selected = nullptr;
	bool   m_shouldSwap = false;
};

