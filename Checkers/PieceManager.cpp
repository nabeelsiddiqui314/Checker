#include "stdafx.h"
#include "PieceManager.h"


PieceManager::PieceManager(Board* board) : m_board(board) {
	
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
		}
	}
	if (m_selected != nullptr) {
		for (unsigned short int x = 0; x < 8; x++) {
			for (unsigned short int y = 0; y < 8; y++) {
				if (Interface::isClicked(window, m_board->m_board[x][y]->GetCell()) && 
					m_board->m_board[x][y]->GetCell().getPosition() != m_selected->GetPiece().getPosition() && 
					m_board->m_board[x][y]->GetID() == 0) {
					m_selected->Move(x, y);
					m_shouldSwap = true;
					m_selected = nullptr;
				}
			}
		}
		for (unsigned short int i = 0; i < m_pieces.size(); i++) {
			if (m_pieces[i] != m_selected) {
				m_pieces[i]->Deselect();
			}
		}
	}
}

void PieceManager::RenderPieces(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		m_pieces[i]->Render(window);
	}
}

PieceManager::~PieceManager() {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		delete m_pieces[i];
	}
	m_pieces.clear();
}
