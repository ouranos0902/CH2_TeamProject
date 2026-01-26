#pragma once
#include "Character/Character.h"
using namespace std;

class AMonster : public ACharacter
{
public:
	AMonster(const string& NewName, const FUnitStat& NewStat);
	virtual void Attack(ACharacter* Target)override;


private:

};

