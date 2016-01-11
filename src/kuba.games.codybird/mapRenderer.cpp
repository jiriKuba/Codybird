#include "stdafx.h"

//public
void MapRenderer::renderMap(Map &map)
{
	const int width { map.get_width() };
	const int height { map.get_height() };

	HANDLE  hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = -1; i < height + 1; i++) //row
	{
		for (int j = -1; j < width + 1; j++) //column
		{
			if (j == -1 || i == -1 || i == height || j == width)
			{
				SetConsoleTextAttribute(hConsole, 7);
				cout << "#";
			}
			else
			{
				MapItem* mi = map.get_map_item_by_coordinates(j, i);
				if (mi == nullptr)
				{
					cout << " ";
				}
				else
				{
					int color = mi->get_color();
					if (color != -1)
						SetConsoleTextAttribute(hConsole, color);
					
					cout << mi->get_representer();
					/*
					if (color != "")
						cout << "\]";*/
				}
			}
		}
		cout << std::endl;
	}
}