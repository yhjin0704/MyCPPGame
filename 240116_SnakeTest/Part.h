#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	Part* GetFront()
	{
		return Front;
	}

	Part* GetBack()
	{
		return Back;
	}

	int2 GetPrevPos()
	{
		return PrevPos;
	}

	void SetFront(Part* _Part)
	{
		Front = _Part;
	}

	void SetBack(Part* _Part)
	{
		Back = _Part;
	}

	void SetPrevPos(int2 _Pos)
	{
		PrevPos = _Pos;
	}

	void FollowFront(Part* _Part);
	void ConnectBody(Part* _Body);

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
	int2 PrevPos = {};

private:
};

