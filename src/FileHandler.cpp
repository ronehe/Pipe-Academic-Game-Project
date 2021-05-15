#include "FileHandler.h"
#include<stdlib.h>
//--------------------------------------------------
/*
distractor closing file.
*/
FileHandler::~FileHandler() {
	file_close();
}
//--------------------------------------------------

//-
/*
closing the txt file being open while the
progrem runs.
*/
void FileHandler::file_close() {
	(m_Cf).close();
}
//--------------------------------------------------

/*
constractor defult for game board
m_cf:file pointer.
*/
FileHandler::FileHandler()
{
	m_Cf.open("map.txt");
	//set_Size();
	set_Map();
}
//--------------------------------------------------
/*
*sets the size of the vector.
*m_size:size of the vector.
*/
bool FileHandler::set_Size() {
	//if(!m_Cf.eof())
	m_Cf >> m_Size.y >> m_Size.x >> m_Time;
	return (!m_Cf.fail());

}
//--------------------------------------------------
/*
*set the map
* m_board : the vector for the map.
* cur:local var for each string .
*/
void FileHandler::set_Map() {
	std::string temp;
	
	int i = 0;
	auto cur = std::string();
	for (i; i < MAP_SIZE; i++) {
		std::getline(m_Cf, cur);

		m_fileHandler.push_back(cur);
	}
}
//--------------------------------------------------
/*
*changing specific location at the vector
* change:location to change.
* request: requestd char to change to
*/
void FileHandler::change_Map(const sf::Vector2i change, const char request) {
	m_fileHandler[change.x][change.y] = request;
}
//--------------------------------------------------
/*
* prints the board
*/
void FileHandler::print_Map() {

	std::system("cls");
	unsigned int i = 0;
	while (i <= m_Size.x) {
		std::cout << m_fileHandler[i++] << '\n';
	}

}
//--------------------------------------------------
/*
*return the amount of lines in the vector
*/
sf::Vector2i FileHandler::get_Size() const {

	return m_Size;
}
//--------------------------------------------------
/*
* returns charector in requestd location
* requestd: location from which to return
*/

char FileHandler::what_In_Location(const sf::Vector2i cur_Loc)const {
	return m_fileHandler[cur_Loc.x][cur_Loc.y];
}
//--------------------------------------------------

//--------------------------------------------------
/*
* loading new map for each lvl
*/
bool FileHandler::rebuild_Map() {
	m_fileHandler.clear();

	if (set_Size()) {
		set_Map();
		return true;
	}
	else
		return false;
}

//--------------------------------------------------


