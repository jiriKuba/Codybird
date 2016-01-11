#include "stdafx.h"

//public
Player::Player()
{
	this->_representer = '@';
	this->_is_effected_by_gravity = true;
	this->_is_x_static = true;
	this->_is_set_to_delete = false;
	this->_color = 6;
	this->_position = new Vec();
}

Player::~Player()
{
	//delete[] this->_position; -> mapitem deleting this
}

void Player::do_collision()
{
	this->_representer = '*';
}