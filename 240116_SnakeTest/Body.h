#pragma once
#include "Part.h"

class Body : public Part
{
public:
	Body();

protected:
	void Update() override;
};

