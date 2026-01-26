#pragma once
#include "Character/Monster/Monster.h"

class AVampire : public AMonster
{
public:
	AVampire();
	void UseSkill(ACharacter* Target) override;
};

