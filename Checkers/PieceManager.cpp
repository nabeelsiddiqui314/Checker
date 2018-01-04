#include "stdafx.h"
#include "PieceManager.h"


PieceManager::PieceManager(Board* board) : m_board(board) {
	
}


void PieceManager::Add(const std::string& filepath, const sf::Vector2i& pos){
	Piece* piece = new Piece(filepath, m_board->m_board, pos);
	m_pieces.push_back(piece);
}

void PieceManager::Update(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		if (Interface::isClicked(window, m_pieces[i]->GetPiece())) {
			m_pieces.erase(m_pieces.begin() + i);
		}
	}
	std::cout << m_pieces.size() << std::endl;
}

void PieceManager::RenderPieces(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		window.draw(m_pieces[i]->GetPiece());
	}
}

PieceManager::~PieceManager() {
	for (unsigned short int i = 0; i < m_pieces.size(); i++) {
		delete m_pieces[i];
	}
	m_pieces.clear();
}
