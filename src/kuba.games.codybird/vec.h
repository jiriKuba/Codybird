#pragma once

class Vec
{
private:
	int _x, _y;

public:
	Vec();
	int const get_x();
	int const get_y();
	void set_x(int const x);
	void set_y(int const y);
	void set_position(int const x, int const y);
};