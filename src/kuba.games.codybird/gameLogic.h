#pragma once

class GameLogic : public EngineComponent
{
private:
	bool _was_player_added;
	Player* _player;
	void _add_random_obstacle_column(Map &map);
	std::list<int>* _obstacle_distances;
public:
	GameLogic();
	~GameLogic();
	void do_logic(Map &map, char key);
	void make_next_step(Map &map);
	void handle_player(Map &map, char key);
	void count_points(Map &map, GameStatHandler* stat_handler);
	bool is_collision_detected(Map &map);
	bool was_player_added();
	void restart() override;
};