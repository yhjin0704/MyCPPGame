#pragma once
#include "Part.h"

class Head : public Part
{
public:

protected:
	void Update() override;

private:
	int PrevMove = 0;

	void FollowFront();
	void AllMove(int2 _Dir);
};

