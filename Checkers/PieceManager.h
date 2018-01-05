#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <vector>

enum MoveDir {
	UP = -1,
	DOWN = 1
};

class PieceManager
{
public:
	PieceManager(Board* board, MoveDir dir);
	~PieceManager();
public:
	void Add(const std::string& filepath, const sf::Vector2i& pos, int id);
	void Update(sf::RenderWindow& window);
	void RenderPieces(sf::RenderWindow& window);
	bool ShouldSwap() const { return m_shouldSwap; }
private:
	bool IsMovablePawn(int boardX, int boardY);
private:
	std::vector<Piece*> m_pieces;
	Board* m_board;
	Piece* m_selected = nullptr;
	bool   m_shouldSwap = false;
	MoveDir m_moveDir;
};

