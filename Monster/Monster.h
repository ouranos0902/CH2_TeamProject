#pragma once
#include "Character/Character.h"


class AMonster : public ACharacter
{
public:

	AMonster(std::string NewName, const FUnitStat& NewStat);
	virtual void Attack(ACharacter* Target)override;

};

