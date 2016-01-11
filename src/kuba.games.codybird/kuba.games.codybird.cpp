// kuba.games.codybird.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Map m {};
	m.load();
	Map* m_ptr = &m;
	Engine en {};
	en.init(m_ptr);
	en.start();
	return 0;
}

