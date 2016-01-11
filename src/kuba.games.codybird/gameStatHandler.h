#pragma once

class GameStatHandler : public EngineComponent
{
private:
	std::string _allowed_statuses;//N = new, O = game over, P = pause, Q = quit, R = restart
	char _game_status;
	int _level_points, _user_record;
	void save_record();
public:
	GameStatHandler();
	~GameStatHandler();
	void render_stat(Map &map);
	void render_help();
	void set_status(const char key);
	void add_level_points();
	char get_game_status();
	bool is_pause();
	bool is_quit();
	bool is_restart();
	bool is_new_game();
	bool is_game_over();
	void init() override;
	void restart() override;
};