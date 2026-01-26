#pragma once

#include "Character/Character.h"


class AMonster : public ACharacter
{
public:
	//string -> const string&
	AMonster(std::string NewName, const FUnitStat& NewStat);
	virtual void Attack(ACharacter* Target)override;


private:

};

