#pragma once

class Player : public MapItem
{
protected:

public:
	Player();
	~Player();
	void do_collision();
};