#include "Monster.h"

#include <iostream>
#include <algorithm>


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{

}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "크아앙! 이빨로 물어 뜯습니다";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 약점부위를 아프게 이빨로 물어뜯습니다!";
	}

	result.PrintMessage(AttackMessage);
	return result;
}

void AMonster::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10) 
	{
		return;
	}

	Stat.Mp -= 10;

	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;
	
	int Damage = Stat.Atk;

	int FinalDamage = Target->TakeDamage(Damage);

	result.Damage = FinalDamage;
	
	Stat.Hp = min(Stat.Hp + FinalDamage, Stat.MaxHp);

	result.PrintMessage("이(가) 흡혈을 사용합니다!");
	
}