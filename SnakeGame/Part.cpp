#include "Part.h"

//Body�� Back�� Front�� �����ϰ� ��ǥ�� �������ִ� �Լ�
void Part::ConnectBody(Part* _Body)
{
	_Body->SetFront(this);
	this->SetBack(_Body);

	_Body->SetPos(this->GetPrevPos());
}