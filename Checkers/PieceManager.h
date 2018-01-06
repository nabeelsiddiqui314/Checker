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
	PieceManager(Board* board, PieceManager* other, MoveDir dir);
	~PieceManager();
public:
	void Add(const std::string& filepath, const sf::Vector2i& pos, int id);
	void Update(sf::RenderWindow& window);
	void RenderPieces(sf::RenderWindow& window);
	bool ShouldSwap() const { return m_shouldSwap; }
	std::vector<Piece*>& GetPieces() { return m_pieces; }
private:
	bool IsMovablePawn(int boardX, int boardY);
	inline void SelectClicked(sf::RenderWindow& window);
	void Destroy(int x, int y);
private:
	PieceManager* m_otherPieces;
	std::vector<Piece*> m_pieces;
	Board* m_board;
	Piece* m_selected = nullptr;
	bool   m_shouldSwap = false;
	MoveDir m_moveDir;
};

