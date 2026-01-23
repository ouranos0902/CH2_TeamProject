#pragma once
#include "Monster/Monster.h"

class AVampire : public AMonster
{

public:
	AVampire(std::string NewName, const FUnitStat NewStat);
	void UseSkill(ACharacter* Target) override;
};

