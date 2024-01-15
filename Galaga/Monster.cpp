#include "Monster.h"

#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>

void Monster::Update()
{
	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);
	EngineCore* Core = GetCore();

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

	std::list<ConsoleObject*> MonsterList = Core->GetUpdateGroup(static_cast<int>(GalagaUpdateType::Monster));
	std::list<ConsoleObject*>::iterator StartIter = MonsterList.begin();
	std::list<ConsoleObject*>::iterator EndIter = MonsterList.end();

	if (0 == (GetPos().Y % 2))
	{
		if (Core->Screen.GetScreenX() == GetPos().X)
		{
			
			for (; StartIter != EndIter; ++StartIter)
			{
				ConsoleObject* MonsterPos = *StartIter;

				if (MonsterPos->GetPos().Y == GetPos().Y)
				{
					MonsterPos->AddPos(Down);
				}
			}
		}
		else
		{
			AddPos(Right);
		}
	}

	if (0 != (GetPos().Y % 2))
	{
		if (0 == GetPos().X)
		{
			for (; StartIter != EndIter; ++StartIter)
			{
				ConsoleObject* MonsterPos = *StartIter;

				if (MonsterPos->GetPos().Y == GetPos().Y)
				{
					MonsterPos->AddPos(Down);
				}
			}
		}
		else
		{
			AddPos(Left);
		}
	}
}