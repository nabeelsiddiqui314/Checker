#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "PieceManager.h"

enum class Turn {
	RED,
	WHITE
};

class Player
{
public:
	Player(Board* board);
	~Player();
public:
	void SwapTurns();
	void Update(sf::RenderWindow& window);
	void RenderPieces(sf::RenderWindow& window);
private:
	Turn m_player = Turn::RED;
	PieceManager* m_redPieces;
	PieceManager* m_whitePieces;
	PieceManager* m_playerInTurn;
	const std::array<const std::string, 4> m_redFilepaths = {
		"./assets/pieces/red/pawn.png",
		"./assets/pieces/red/pawnSelected.png",
		"./assets/pieces/red/king.png",
		"./assets/pieces/red/kingSelected.png"
	};
	const std::array<const std::string, 4> m_whiteFilepaths = {
		"./assets/pieces/white/pawn.png",
		"./assets/pieces/white/pawnSelected.png",
		"./assets/pieces/white/king.png",
		"./assets/pieces/white/kingSelected.png"
	};
};

