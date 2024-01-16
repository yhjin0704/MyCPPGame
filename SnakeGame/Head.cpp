#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	switch (Select)
	{
	case 'A':
	case 'a':
		if ('d' == PrevPos) 
		{
		}
		else
		{
			PrevPos = 'a';
			AddPos(Left);
		}
		break;
	case 'S':
	case 's':
		if ('w' == PrevPos)
		{
		}
		else
		{
			PrevPos = 's';
			AddPos(Down);
		}
		break;
	case 'W':
	case 'w':
		if ('s' == PrevPos)
		{
		}
		else
		{
			PrevPos = 'w';
			AddPos(Up);
		}
		break;
	case 'D':
	case 'd':
		if ('a' == PrevPos)
		{
		}
		else
		{
			PrevPos = 'd';
			AddPos(Right);
		}
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}
}