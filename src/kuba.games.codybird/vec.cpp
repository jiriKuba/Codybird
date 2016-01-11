#include "stdafx.h"


//public
Vec::Vec()
{
	this->_x = 0;
	this->_y = 0;
}

int const Vec::get_x()
{
	return this->_x;
}
int const Vec::get_y()
{
	return this->_y;
}
void Vec::set_x(int const x)
{
	this->_x = x;
}
void Vec::set_y(int const y)
{
	this->_y = y;
}
void Vec::set_position(int const x, int const y)
{
	this->_x = x;
	this->_y = y;
}