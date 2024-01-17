#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"
#include "ContentsEnum.h"

// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

void Head::Update()
{
	int InputCount = _kbhit();

	if (0 != InputCount)
	{

		int Select = _getch();

		// InputCount = _kbhit();

		// X Y
		// 1 0

		switch (Select)
		{
		case 'A':
		case 'a':
			if ('d' == PrevMove)
			{
			}
			else
			{
				PrevMove = 'a';
				PrevPos = GetPos();
				AddPos(Left);
				FollowFront(this);
			}
			break;
		case 'S':
		case 's':
			if ('w' == PrevMove)
			{
			}
			else
			{
				PrevMove = 's';
				PrevPos = GetPos();
				AddPos(Down);
				FollowFront(this);
			}
			break;
		case 'W':
		case 'w':
			if ('s' == PrevMove)
			{
			}
			else
			{
				PrevMove = 'w';
				PrevPos = GetPos();
				AddPos(Up);
				FollowFront(this);
			}
			break;
		case 'D':
		case 'd':
			if ('a' == PrevMove)
			{
			}
			else
			{
				PrevMove = 'd';
				PrevPos = GetPos();
				AddPos(Right);
				FollowFront(this);
			}
			break;
		case '1':
			GetCore()->EngineEnd();
			break;
		default:
			break;
		}
	}

	if ('a' == PrevMove)
	{
		PrevPos = GetPos();
		AddPos(Left);
		FollowFront(this);
	}
	else if ('s' == PrevMove)
	{
		PrevPos = GetPos();
		AddPos(Down);
		FollowFront(this);
	}
	else if ('w' == PrevMove)
	{
		PrevPos = GetPos();
		AddPos(Up);
		FollowFront(this);
	}
	else if ('d' == PrevMove)
	{
		PrevPos = GetPos();
		AddPos(Right);
		FollowFront(this);
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	{
		int ScreenX = GetCore()->Screen.GetScreenX();
		int ScreenY = GetCore()->Screen.GetScreenY();

		int2 HeadPos = GetPos();
		if (0 > HeadPos.X)
		{
			printf_s("Game Over");
			GetCore()->EngineEnd();
		}
		else if (ScreenX <= HeadPos.X)
		{
			printf_s("Game Over");
			GetCore()->EngineEnd();
		}
		else if (0 >= HeadPos.Y)
		{
			printf_s("Game Over");
			GetCore()->EngineEnd();
		}
		else if (ScreenY <= HeadPos.Y)
		{
			printf_s("Game Over");
			GetCore()->EngineEnd();
		}
		if (nullptr != Back)
		{
			Part* CollideBody = Back;

			while (nullptr != CollideBody->GetBack())
			{
				if (CollideBody->GetPos() == HeadPos)
				{
					printf_s("Game Over");
					GetCore()->EngineEnd();
				}
				CollideBody = CollideBody->GetBack();
			}
		}
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		Body* NewBody = CurBody;
		BodyManager::ResetBody();
		if (nullptr == Back)
		{
			ConnectBody(NewBody);
		}
		else
		{
			// BackCheck == 첫 바디의 Back
			Part* BackCheck = Back;
			while (nullptr != BackCheck->GetBack())
			{
				BackCheck = BackCheck->GetBack();
			}
			BackCheck->ConnectBody(NewBody);
		}
	}
	return;
}