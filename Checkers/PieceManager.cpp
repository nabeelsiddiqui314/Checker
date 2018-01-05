#include "stdafx.h"
#include "PieceManager.h"


PieceManager::PieceManager(Board* board, MoveDir dir) : m_board(board), m_moveDir(dir) {
	
}


void PieceManager::Add(const std::string& filepath, const sf::Vector2i& pos, int id){
	Piece* piece = new Piece(filepath, m_board->m_board, pos, id);
	m_pieces.push_back(piece);
}

void PieceManager::Update(sf::RenderWindow& window) {
	m_shouldSwap = false;
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		if (m_pieces[i]->IsSelected(window)) {
			m_selected = m_pieces[i];
			//m_pieces[i]->SetColor(sf::Color::Blue);
		}
	}
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
		for (unsigned short int i = 0; i < m_pieces.size(); i++) {
			if (m_pieces[i] != m_selected) {
				m_pieces[i]->Deselect();
				//m_pieces[i]->SetColor(sf::Color::Black);
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

	return (piecePos.y + (cellSize.y * m_moveDir) == cellPos.y) &&
		  (piecePos.x + cellSize.x == cellPos.x ||
		   piecePos.x - cellSize.x == cellPos.x);
}

PieceManager::~PieceManager() {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		delete m_pieces[i];
	}
	m_pieces.clear();
}
