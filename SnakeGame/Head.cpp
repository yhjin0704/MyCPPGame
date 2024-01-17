#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"
#include "ContentsEnum.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

void Head::Update()
{
	int InputCount = _kbhit();

	if (0 != InputCount)
	{

		int Select = _getch();

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
				FollowFront();
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
				FollowFront();
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
				FollowFront();
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
				FollowFront();
			}
			break;
		case '1':
			GetCore()->EngineEnd();
			break;
		default:
			break;
		}
	}
	else 
	{
		if ('a' == PrevMove)
		{
			PrevPos = GetPos();
			AddPos(Left);
			FollowFront();
		}
		else if ('s' == PrevMove)
		{
			PrevPos = GetPos();
			AddPos(Down);
			FollowFront();
		}
		else if ('w' == PrevMove)
		{
			PrevPos = GetPos();
			AddPos(Up);
			FollowFront();
		}
		else if ('d' == PrevMove)
		{
			PrevPos = GetPos();
			AddPos(Right);
			FollowFront();
		}
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
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
		else if (0 > HeadPos.Y)
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
			// BackCheck == ù �ٵ��� Back
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

// �� Part�� ���󰡴� �Լ�
void Head::FollowFront()
{
	Part* NextBody = GetBack();
	while (nullptr != NextBody)
	{
		NextBody->SetPrevPos(NextBody->GetPos());
		NextBody->SetPos((NextBody->GetFront())->GetPrevPos());
		NextBody = NextBody->GetBack();
	}
}