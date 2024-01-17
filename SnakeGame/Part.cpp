#include "Part.h"

//Body의 Back과 Front를 설정하고 좌표를 설정해주는 함수
void Part::ConnectBody(Part* _Body)
{
	_Body->SetFront(this);
	this->SetBack(_Body);

	_Body->SetPos(this->GetPrevPos());
}