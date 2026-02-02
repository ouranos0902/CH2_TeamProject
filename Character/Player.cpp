#include "Player.h"

#include <iostream>

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이(가) 대검으로 공격합니다.";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 치명적인 공격을 가합니다.";
	}
	result.PrintMessage(AttackMessage);
	return result;
}

void APlayer::LevelUp()
{

}

void APlayer::UseItem()
{

}

void APlayer::UseSkill(ACharacter* Target)
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
	
	int FinalDamage = Target->TakeDamage(Stat.Atk * 2);
	result.Damage = FinalDamage;

    result.PrintMessage("-필살기- 회심의 일격...!");
}