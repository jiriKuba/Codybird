#include "stdafx.h"


//public
Map::Map()
{
	this->_was_loaded = false;
	this->_height = 1;
	this->_width = 1;
}

Map::~Map()
{
	delete this->_map_items;
}

void Map::init()
{
	//mock

	this->_height = 10;
	this->_width = 14;
	this->_obstacle_rate = 9;
	this->_total_distance = 0;
}

void Map::restart()
{
	this->_total_distance = 0;

	std::list<MapItem*>::iterator i = this->_map_items->begin();
	while (i != this->_map_items->end())
	{
		delete *i;
		i = this->_map_items->erase(i++);
	}
}

void Map::load()
{
	if (!this->_was_loaded)
	{
		this->_map_items = new list<MapItem*>;
		//mock
		this->init();
		this->_was_loaded = true;
	}
}
void Map::iterate_total_distance()
{
	this->_total_distance++;
}

MapItem* Map::get_map_item_by_coordinates(int x, int y) const
{
	if (this->_map_items == nullptr || this->_map_items->size() == 0)
	{
		return nullptr;
	}
	else
	{
		for (std::list<MapItem*>::iterator iterator = this->_map_items->begin(), end = this->_map_items->end(); iterator != end; ++iterator)
		{
			MapItem* it = *iterator;

			Vec* position = it->get_position();
			if (position->get_x() == x && position->get_y() == y)
				return it;
		}
		return nullptr;
	}
}

void Map::get_map_items_by_coordinates(int x, int y, std::list<MapItem*>* out_list)
{
	if (this->_map_items == nullptr || this->_map_items->size() == 0)
	{
		//return nullptr; -> nothing
	}
	else
	{
		for (std::list<MapItem*>::iterator iterator = this->_map_items->begin(), end = this->_map_items->end(); iterator != end; ++iterator)
		{
			MapItem* it = *iterator;
			Vec* position = it->get_position();
			if (position->get_x() == x && position->get_y() == y)
				out_list->push_back(it);
		}
	}
}

int const Map::get_width()
{
	return this->_width;
}

int const Map::get_height()
{
	return this->_height;
}

int const Map::get_total_distance()
{
	return this->_total_distance;
}

int const Map::get_obstacle_rate()
{
	return this->_obstacle_rate;
}

std::list<MapItem*>* Map::get_map_items()
{
	return this->_map_items;
}