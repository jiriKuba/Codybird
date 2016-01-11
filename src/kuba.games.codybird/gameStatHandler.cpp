#include "stdafx.h"
//private 
void GameStatHandler::save_record()
{
	ofstream saveFile("record.txt");

	saveFile << this->_user_record;

	saveFile.close();
}

//public
GameStatHandler::GameStatHandler()
{
	this->_allowed_statuses = "NOPQR";//N = new, O = game over, P = pause, Q = quit, R = restart
	this->_game_status = 'N';
	this->_level_points = 0;
	this->_user_record = 0;
}

GameStatHandler::~GameStatHandler()
{
}

void GameStatHandler::render_help()
{
	cout << std::endl;
	cout << "SPACE = jump, R = restart, P = pause, Q = quit";
}

void GameStatHandler::render_stat(Map &map)
{
	cout << "Total distance: ";
	cout.fill('0');
	cout.width(5);
	cout << map.get_total_distance();
	cout << std::endl;

	cout << "Points: ";
	cout.fill('0');
	cout.width(5);
	cout << this->_level_points;
	cout << std::endl;

	cout << "Record: ";
	cout.fill('0');
	cout.width(5);
	cout << this->_user_record;
}

char GameStatHandler::get_game_status()
{
	return this->_game_status;
}

bool GameStatHandler::is_pause()
{
	return this->_game_status == 'P';
}

bool GameStatHandler::is_quit()
{
	return this->_game_status == 'Q';
}

bool GameStatHandler::is_new_game()
{
	return this->_game_status == 'N';
}

bool GameStatHandler::is_restart()
{
	return this->_game_status == 'R';
}

bool GameStatHandler::is_game_over()
{
	return this->_game_status == 'O';
}

void GameStatHandler::set_status(const char key)
{
	std::size_t found = this->_allowed_statuses.find(key);
	if (found != std::string::npos)
	{
		if (!this->is_game_over() && key == 'O' && this->_level_points > this->_user_record)
		{
			this->_user_record = this->_level_points;
			this->save_record();
		}

		if(this->is_pause() && key == 'P')
			this->_game_status = 'N';
		else 
			this->_game_status = key;		
	}
}

void GameStatHandler::add_level_points()
{
	this->_level_points++;
}

void GameStatHandler::restart()
{
	this->_game_status = 'N';
	this->_level_points = 0;
}

void GameStatHandler::init()
{
	//load record
	ifstream loadFile{};
	string result = "";
	loadFile.open("record.txt", ifstream::in);

	while (loadFile.good()) {
		result += (char)loadFile.get();
	}

	loadFile.close();

	if(result != "")
		this->_user_record = atoi(result.c_str());
}