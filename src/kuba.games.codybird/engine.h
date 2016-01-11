#pragma once

class Engine
{
private:
	MapRenderer* _map_renderer;
	GameStatHandler* _game_stat_handler;
	GameLogic* _game_logic;
	Map* _map;
	void _start_game_loop();
	void _clear_console();

public:
	Engine();
	~Engine();
	void init(Map* map);
	void start();
};