#include "stdafx.h"
#include "PieceManager.h"


PieceManager::PieceManager(Board* board, PieceManager* other, MoveDir dir) : m_board(board), m_moveDir(dir), m_otherPieces(other) {
	
}


void PieceManager::Add(const std::string& filepath, const sf::Vector2i& pos, int id){
	Piece* piece = new Piece(filepath, m_board->m_board, pos, id);
	m_pieces.push_back(piece);
}

inline void PieceManager::SelectClicked(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		for (unsigned short int j = 0; j < m_pieces.size(); j++) {
			if (m_selected != m_pieces[j]) {
				m_pieces[j]->Deselect();
			}
		}
		if (m_pieces[i]->IsSelected(window)) {
			m_selected = m_pieces[i];
		}
	}
}

void PieceManager::Update(sf::RenderWindow& window) {
	m_shouldSwap = false;
	SelectClicked(window);
	if (m_selected != nullptr) {
		for (unsigned short int x = 0; x < 8; x++) {
			for (unsigned short int y = 0; y < 8; y++) {
				if (Interface::isClicked(window, m_board->m_board[x][y]->GetCell()) && 
					m_board->m_board[x][y]->GetCell().getPosition() != m_selected->GetPiece().getPosition() && 
					m_board->m_board[x][y]->GetID() == 0) {
					if (IsMovablePawn(x, y)) {
						m_selected->Move(x, y, true);
						m_shouldSwap = true;
						m_selected = nullptr;
					}
				}
			}
		}
	}
}

void PieceManager::RenderPieces(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		m_pieces[i]->Render(window);
	}
}

bool PieceManager::IsMovablePawn(int boardX, int boardY) {
	sf::Vector2f cellPos = { m_board->m_board[boardX][boardY]->GetCell().getPosition() };
	sf::Vector2f cellSize = { m_board->m_board[boardX][boardY]->GetCell().getSize() };
	sf::Vector2f piecePos = { m_selected->GetPiece().getPosition() };

	if ((piecePos.y + (cellSize.y * m_moveDir * 2) == cellPos.y)) {
		if (piecePos.x + cellSize.x * 2 == cellPos.x && 
			m_board->m_board[boardX - 1][boardY - m_moveDir]->GetID() > 0 &&
			m_board->m_board[boardX - 1][boardY - m_moveDir]->GetID() != m_pieces[0]->GetID()) {
			m_otherPieces->Destroy(boardX - 1, boardY - m_moveDir);
			return true;
		}
		if (piecePos.x - cellSize.x * 2 == cellPos.x &&
			m_board->m_board[boardX + 1][boardY - m_moveDir]->GetID() > 0 &&
			m_board->m_board[boardX + 1][boardY - m_moveDir]->GetID() != m_pieces[0]->GetID()) {
			m_otherPieces->Destroy(boardX + 1, boardY - m_moveDir);
			return true;
		}
	}
	return (piecePos.y + (cellSize.y * m_moveDir) == cellPos.y) &&
		(piecePos.x + cellSize.x == cellPos.x || piecePos.x - cellSize.x == cellPos.x);
}

void PieceManager::Destroy(int x, int y) {
	/*for (unsigned short int i = 0; i < m_otherPieces->GetPieces().size(); i++) {
		if (m_otherPieces->GetPieces()[i]->GetPiece().getPosition() == m_board->m_board[x][y]->GetCell().getPosition()) {
			m_otherPieces->GetPieces().erase(m_otherPieces->GetPieces().begin() + i);
		}
	}*/
}

PieceManager::~PieceManager() {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		delete m_pieces[i];
	}
	m_pieces.clear();
}
