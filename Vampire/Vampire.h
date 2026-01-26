#pragma once
#include "Monster/Monster.h"

class AVampire : public AMonster
{

public:
	AVampire();
	void UseSkill(ACharacter* Target) override;
};

