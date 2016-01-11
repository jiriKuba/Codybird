#include "stdafx.h"

//public
Obstacle::Obstacle()
{
	this->_representer = '#';
	this->_is_effected_by_gravity = false;
	this->_is_x_static = false;
	this->_is_set_to_delete = false;
	this->_color = 2;
	this->_position = new Vec();
}
Obstacle::~Obstacle()
{
	//delete this->_position; -> mapitem deleting this
}