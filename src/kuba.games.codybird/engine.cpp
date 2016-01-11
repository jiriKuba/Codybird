#include "stdafx.h"

//public
Engine::Engine()
{
	//nothing so far
	this->_map = nullptr;
}
Engine::~Engine()
{
	delete this->_game_stat_handler;
	delete this->_map_renderer;		
	delete this->_game_logic;
}
void Engine::init(Map* map)
{
	this->_map = map;
	this->_map_renderer = new MapRenderer();
	this->_game_stat_handler = new GameStatHandler();
	this->_game_logic = new GameLogic();
}

void Engine::start()
{
	//load map
	this->_map_renderer->init();
	this->_game_stat_handler->init();
	this->_game_logic->init();
	//start game loop
	this->_start_game_loop();
}

//private
void Engine::_start_game_loop()
{
	char key{ this->_game_stat_handler->get_game_status() };

	do
	{
		//sleep
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		if (_kbhit() != 0)
		{
			key = _getch();
			
			if (key == 27)//esc to quit
				key = 'Q';
			key = toupper(key);//upper case
			
			this->_game_stat_handler->set_status(key);
		}
		else if(key != this->_game_stat_handler->get_game_status())
		{
			key = this->_game_stat_handler->get_game_status();
		}		
		if (this->_game_stat_handler->is_new_game())
		{
			this->_clear_console();
			this->_game_logic->do_logic(*this->_map, key);
			if (this->_game_logic->is_collision_detected(*this->_map))
			{
				this->_game_stat_handler->set_status('O');//game over
			}
			this->_game_logic->count_points(*this->_map, this->_game_stat_handler);
			this->_map_renderer->renderMap(*this->_map);			
			this->_game_stat_handler->render_stat(*this->_map);
			this->_game_stat_handler->render_help();
		}
		else if (this->_game_stat_handler->is_restart())
		{
			this->_map->restart();
			this->_map_renderer->restart();
			this->_game_stat_handler->restart();
			this->_game_logic->restart();
		}

	} while (!this->_game_stat_handler->is_quit());
	cout << std::endl;
	cout << "Bye";
}

void Engine::_clear_console()
{
	COORD cur { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}