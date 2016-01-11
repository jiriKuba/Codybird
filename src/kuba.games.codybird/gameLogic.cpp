#include "stdafx.h"
//private
void GameLogic::_add_random_obstacle_column(Map &map)
{
	std::list<MapItem*>* items = map.get_map_items();
	int const random_space = (rand() % (int)(map.get_height() - 1));
	int unsigned height = map.get_height();
	for (size_t i = 0; i < height; i++)
	{
		if (i != random_space && i != random_space + 1)
		{
			Obstacle* o = new Obstacle();
			o->set_position(map.get_width() - 1, i);
			items->push_back(o);
		}
	}

	this->_obstacle_distances->push_back(map.get_total_distance());
}

//public
GameLogic::GameLogic()
{
	this->_was_player_added = false;
	this->_player = new Player();
	this->_obstacle_distances = new std::list<int>();
}

GameLogic::~GameLogic()
{
	delete this->_player; //-> is deleted with map items
	delete this->_obstacle_distances; //error there -> end of application anyway
}

void GameLogic::do_logic(Map &map, char key)
{	
	this->make_next_step(map);
	this->handle_player(map, key);
	int const total_distance = map.get_total_distance();
	if (total_distance > map.get_width())//let it ride a little
	{
		if (total_distance % map.get_obstacle_rate() == 0)
		{
			this->_add_random_obstacle_column(map);			
		}
	}
}

void GameLogic::count_points(Map &map, GameStatHandler* stat_handler)
{
	int const total_distance = map.get_total_distance();
	if (total_distance > map.get_width() && this->_obstacle_distances->size()>0)//main condition
	{
		if (this->_obstacle_distances->front() == total_distance - map.get_width() + this->_player->get_position()->get_x())
		{
			stat_handler->add_level_points();
			this->_obstacle_distances->remove(this->_obstacle_distances->front());
		}
	}
}

void GameLogic::make_next_step(Map &map)
{
	map.iterate_total_distance();
	std::list<MapItem*>* items = map.get_map_items();	
	//iterate list -> move everithing to left except 
	
	if (items != nullptr && items->size() > 0)
	{
		for (std::list<MapItem*>::iterator iterator = items->begin(), end = items->end(); iterator != end; ++iterator) 
		{
			MapItem* it = *iterator;
			Vec* position = it->get_position();
			if (it->is_effected_by_gravity())
			{
				position->set_y((position->get_y() + 1));
			}

			if (!it->is_x_static())
			{
				position->set_x(position->get_x() - 1);
			}

			if (position->get_x() < 0)
			{
				it->set_to_delete();
			}
		}

		//delete old items
		std::list<MapItem*>::iterator i = items->begin();
		while (i != items->end())
		{
			bool is_set_to_del = (*i)->is_set_to_delete();
			if (is_set_to_del)
			{
				delete *i;
				i = items->erase(i++); 
			}
			else
			{
				++i;
			}
		}
	}
}

void GameLogic::handle_player(Map &map, char key)
{
	//debuging
	//cout << key;
	//cout << std::endl;
	if (!this->_was_player_added)
	{
		this->_player->set_position(2, map.get_height() / 2);
		map.get_map_items()->push_back(this->_player);
		this->_was_player_added = true;
	}

	if (key == ' ')
	{
		//handle player not run above border
		if(this->_player->get_position()->get_y() == 1)
			this->_player->get_position()->set_y(this->_player->get_position()->get_y() - 1);//just stay in position (gravity will handle that)
		else
		{
			this->_player->get_position()->set_y(this->_player->get_position()->get_y() - 2);
			//cout << "jump "<<key;
		}
	}
	/*
	else
	{
		cout << "nump " << key;
	}*/
}

bool GameLogic::is_collision_detected(Map &map)
{	
	if (this->_player->get_position()->get_y() >= map.get_height()-1)
	{
		this->_player->do_collision();
		return true;
	}

	bool result = false;
	
	std::list<MapItem*> mis{};
	std::list<MapItem*>* mis_ptr = &mis;
	map.get_map_items_by_coordinates(this->_player->get_position()->get_x(), this->_player->get_position()->get_y(), mis_ptr);
	if (mis.size() > 0)
	{
		
		for (std::list<MapItem*>::iterator iterator = mis.begin(), end = mis.end(); iterator != end; ++iterator)
		{
			MapItem* it = *iterator;
			if (it != this->_player)
			{
				result = true;
				break;
			}
		}

		if(result)
			this->_player->do_collision();		
	}

	//delete[] mis;

	return result;
}

bool GameLogic::was_player_added()
{
	return this->_was_player_added;
}

void GameLogic::restart()
{
	//delete[] this->_player; deleted by map
	this->_player = new Player();
	this->_was_player_added = false;
	this->_obstacle_distances->clear();
}
