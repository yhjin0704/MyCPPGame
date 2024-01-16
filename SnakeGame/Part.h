#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{

protected:
	Part* Prev = nullptr;
	Part* Next = nullptr;
};

