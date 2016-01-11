#pragma once

class Map : public EngineComponent
{
private:
	int _width, _height, _total_distance, _obstacle_rate;
	bool _was_loaded;
	std::list<MapItem*>* _map_items;

public:
	Map();
	~Map();
	int const get_width();
	int const get_height();
	int const get_total_distance();
	int const get_obstacle_rate();
	std::list<MapItem*>* get_map_items();
	void load();
	void iterate_total_distance();
	MapItem* get_map_item_by_coordinates(int x, int y) const;
	void get_map_items_by_coordinates(int x, int y, std::list<MapItem*>* out_list);
	void init() override;
	void restart() override;
};