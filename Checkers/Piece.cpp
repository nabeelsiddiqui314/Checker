#include "stdafx.h"
#include "Piece.h"

Piece::Piece(const std::array<const std::string, 4> filepath, Cell* board[8][8], const sf::Vector2i& pos, int id) : m_ID(id)
{
	for (unsigned short int i = 0; i < filepath.size(); i++) {
		sf::Texture tex;
		tex.loadFromFile(filepath[i]);
		m_textures.push_back(tex);
	}
	for (unsigned short int x = 0; x < 8; x++) {
		for (unsigned short int y = 0; y < 8; y++) {
			m_board[x][y] = board[x][y];
		}
	}
	m_piece.setSize(m_board[0][0]->GetCell().getSize());
	Move(pos.x, pos.y);
	SetMode(PAWN);
}


const sf::RectangleShape& Piece::GetPiece() const {
	return m_piece;
}

void Piece::Move(int x, int y, bool firstTime) {
	int currentX = ((m_piece.getPosition().x - m_board[0][0]->GetCell().getPosition().x) / m_board[0][0]->GetCell().getSize().x);
	int currentY = ((m_piece.getPosition().y - m_board[0][0]->GetCell().getPosition().y) / m_board[0][0]->GetCell().getSize().y);

	if (firstTime) {
		m_board[currentX][currentY]->SetID(0);
	}

	m_piece.setPosition(m_board[x][y]->GetCell().getPosition());
	m_board[x][y]->SetID(m_ID);
}

bool Piece::IsSelected(sf::RenderWindow& window) {
	if (Interface::isClicked(window, m_piece)) {
		m_isSelected = true;
	}
	return m_isSelected;
}

void Piece::Deselect() {
	m_isSelected = false;
}

int  Piece::GetID() const { 
	return m_ID;
}

void Piece::MakeKing() {
	m_isKing = true;
}

bool Piece::IsKing() const {
	return m_isKing;
}

void Piece::SetMode(const Modes& mode) {
	m_piece.setTexture(&m_textures[mode]);
}

void Piece::Render(sf::RenderWindow& window) {
	window.draw(m_piece);
}

Piece::~Piece()
{
}
