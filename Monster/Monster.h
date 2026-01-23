#pragma once
#include "Character/Character.h"


class AMonster : public ACharacter
{
public:
	virtual void Attack(ACharacter* Target)override
};

