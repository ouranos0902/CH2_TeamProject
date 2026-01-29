#include "Character.h"
#include <iostream>
#include "RandomUtil.h"



using namespace std;

ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
	Name = NewName;
	Stat = UnitStat;
	
	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

	cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	bool bCritical = getRandomInt(1,100) < Stat.Critical;
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}
	
	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount = DamageAmount - Stat.Def;
	DamageAmount = std::max(DamageAmount, 0);
	
	Stat.Hp = Stat.Hp - DamageAmount;
	Stat.Hp = std::max(Stat.Hp, 0);
	return DamageAmount; 
}