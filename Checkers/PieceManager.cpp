#include "stdafx.h"
#include "PieceManager.h"


PieceManager::PieceManager(Board* board, MoveDir dir) : m_board(board), m_moveDir(dir) {

}


void PieceManager::Add(const std::array<const std::string, 4> filepath, const sf::Vector2i& pos, int id){
	Piece* piece = new Piece(filepath, m_board->m_board, pos, id);
	m_pieces.push_back(piece);
}

void PieceManager::SetOther(PieceManager* other) {
	m_otherPieces = other;
}

inline void PieceManager::PieceIterator(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		CheckKing(*m_pieces[i]);
		for (unsigned short int j = 0; j < m_pieces.size(); j++) {
			if (m_selected != m_pieces[j]) {
				m_pieces[j]->Deselect();
				if (m_pieces[j]->IsKing()) m_pieces[j]->SetMode(KING);
				else m_pieces[j]->SetMode(PAWN);
			}
		}
		if (m_pieces[i]->IsSelected(window)) {
			m_selected = m_pieces[i];
			if (m_selected->IsKing()) m_selected->SetMode(KING_SELECTED);
			else m_selected->SetMode(PAWN_SELECTED);
		}
	}
}

void PieceManager::Update(sf::RenderWindow& window) {
	m_shouldSwap = false;
	PieceIterator(window);
	if (m_selected != nullptr) {
		for (unsigned short int x = 0; x < 8; x++) {
			for (unsigned short int y = 0; y < 8; y++) {
				if (Interface::isClicked(window, m_board->m_board[x][y]->GetCell()) && IsValidCell(x, y)) {
					if (IsMovable(x, y)) {
						m_selected->Move(x, y, true);
						m_shouldSwap = true;
						if (m_selected->IsKing()) m_selected->SetMode(KING);
						else m_selected->SetMode(PAWN);
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

void PieceManager::CheckKing(Piece& piece) {
	switch (m_moveDir) {
	case UP:
		if (piece.GetPiece().getPosition().y == m_board->m_board[0][0]->GetCell().getPosition().y) {
			piece.MakeKing();
			piece.SetMode(KING);
		}
		break;
	case DOWN:
		if (piece.GetPiece().getPosition().y == m_board->m_board[0][7]->GetCell().getPosition().y) {
			piece.MakeKing();
			piece.SetMode(KING);
		}
		break;
	}
}

bool PieceManager::IsValidCell(int boardX, int boardY) {
	return m_board->m_board[boardX][boardY]->GetCell().getPosition() != m_selected->GetPiece().getPosition() &&
		   m_board->m_board[boardX][boardY]->GetID() == 0;
}

bool PieceManager::IsMovable(int boardX, int boardY) {
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
	if (m_selected->IsKing()) {
		if ((piecePos.y + (cellSize.y * -m_moveDir * 2) == cellPos.y)) {
			if (piecePos.x + cellSize.x * 2 == cellPos.x &&
				m_board->m_board[boardX - 1][boardY + m_moveDir]->GetID() > 0 &&
				m_board->m_board[boardX - 1][boardY + m_moveDir]->GetID() != m_pieces[0]->GetID()) {
				m_otherPieces->Destroy(boardX - 1, boardY + m_moveDir);
				return true;
			}
			if (piecePos.x - cellSize.x * 2 == cellPos.x &&
				m_board->m_board[boardX + 1][boardY + m_moveDir]->GetID() > 0 &&
				m_board->m_board[boardX + 1][boardY + m_moveDir]->GetID() != m_pieces[0]->GetID()) {
				m_otherPieces->Destroy(boardX + 1, boardY + m_moveDir);
				return true;
			}
		}
	}
	return (piecePos.y + (cellSize.y * m_moveDir) == cellPos.y || piecePos.y + (cellSize.y * -m_moveDir) == cellPos.y) &&
		(piecePos.x + cellSize.x == cellPos.x || piecePos.x - cellSize.x == cellPos.x);
}

void PieceManager::Destroy(int x, int y) {
	m_board->m_board[x][y]->SetID(0);
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		if (m_board->m_board[x][y]->GetCell().getPosition() == m_pieces[i]->GetPiece().getPosition()) {
			m_pieces.erase(m_pieces.begin() + i);
		}
	}
}

PieceManager::~PieceManager() {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		delete m_pieces[i];
	}
	m_pieces.clear();
}
