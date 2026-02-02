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
	
	int bSKill = getRandomInt(1, 100);

		if (bSKill < 30)
		{
			UseSkill(Target);
		}
	
	FDamageResult result;
	int FinalDamage = Target->TakeDamage(Damage);
	result.Attacker = this;
	result.Target = Target;
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

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	cout << "-------------------------------------------------" << endl;
	Attacker->PrintName();
	cout << AttackMessage << '\n';

	Target->PrintName();
	cout << "'받은 데미지': " << Damage << " -> '남은 HP': " << Target->GetHp() << "/" << Target->GetMaxHp() << endl;
	cout << "-------------------------------------------------" << endl;
}

void ACharacter::PrintName()
{
	cout << "[" << Name << "]";
}

void ACharacter::Heal(int Amount)
{
	int PrevHp = Stat.Hp;
	Stat.Hp = Amount;
	Stat.Hp = min(Stat.MaxHp, Stat.Hp);

	int ActualHeal = Stat.Hp - PrevHp;

	PrintName();
	cout << ActualHeal << "HP를 회복했습니다...!" << endl;
}