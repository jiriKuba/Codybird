#pragma once
class MapItem
{
protected:
	char _representer;
	bool _is_effected_by_gravity, _is_x_static, _is_set_to_delete;
	int _color;
	Vec* _position;
public:
	MapItem();
	virtual ~MapItem();
	char get_representer();
	bool is_effected_by_gravity();
	bool is_x_static();
	bool is_set_to_delete();
	Vec* get_position();
	void set_position(int const x, int const y);
	int get_color();
	void set_to_delete();
};