#include "stdafx.h"


//public
MapItem::MapItem()
{
	this->_position = new Vec();
	this->_color = -1;
}
MapItem::~MapItem()
{
	delete this->_position;
}
char MapItem::get_representer()
{
	return this->_representer;
}
bool MapItem::is_effected_by_gravity()
{
	return this->_is_effected_by_gravity;
}
bool MapItem::is_x_static()
{
	return this->_is_x_static;
}

void MapItem::set_position(int const x, int const y)
{
	this->_position->set_position(x,y);;
}

bool MapItem::is_set_to_delete()
{
	return this->_is_set_to_delete;
}

void MapItem::set_to_delete()
{
	this->_is_set_to_delete = true;
}

Vec* MapItem::get_position()
{
	return this->_position;
}

int MapItem::get_color()
{
	return this->_color;
}