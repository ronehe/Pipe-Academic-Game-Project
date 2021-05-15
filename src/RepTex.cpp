#include "RepTex.h"
#include "Textures.h"
#pragma once
RepTex::RepTex() {
	//creates a basic tile table without texture
	m_tiles.resize(8);
	for (unsigned int i = 0; i < MAP_SIZE; i++) {
		for (unsigned int j = 0; j < MAP_SIZE; j++) {
			m_tiles[i].push_back(Tile(sf::Vector2f(100, 100), sf::Vector2f(board_Start.x + j * 100.f, board_Start.y + (i * 100.f))));
		}
	}	
	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void addTextureToTile(sf::Vector2u loc, sf::texture tex) {

}
//drawing the board on requested screen..
void Board::drawBoard(sf::RenderWindow& game_Window) {
	m_board[1][1].setTexture(Textures::instance().get_Textures(straightPipe_t));
	m_board[2][1].setTexture(Textures::instance().get_Textures(curvedPipe_t));
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			m_board[i][j].drawTile(game_Window);
			m_board[i][j].setTexture(Textures::instance().get_Textures(curvedPipe_t));
		}
	}
}

//rotation function
void Board::rotateTile(const sf::Vector2i &posTile, float degrees) {
	m_board[posTile.x][posTile.y].rotate(degrees);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//returns  a tile in location on board ..
Tile& Board::getTile(sf::Vector2i pos) {
	return m_board[pos.x][pos.y];

	//return m_Board[int(pos.y/100)][int(pos.x/100)];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
