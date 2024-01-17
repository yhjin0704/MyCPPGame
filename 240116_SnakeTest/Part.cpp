#include "Part.h"

// 앞 Part를 따라가는 함수
void Part::FollowFront(Part* _Part)
{
	Part* NextBody = _Part->Back;
	while (nullptr != NextBody)
	{
		NextBody->SetPrevPos(NextBody->GetPos());
		NextBody->SetPos((NextBody->GetFront())->GetPrevPos());
		NextBody = NextBody->Back;
	}
}

void Part::ConnectBody(Part* _Body)
{
	_Body->SetFront(this);
	this->SetBack(_Body);

	_Body->SetPos(this->GetPrevPos());
}