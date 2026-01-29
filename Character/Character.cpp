#include "Character.h"
#include "RandomUtil.h"
#include <random>
#include <algorithm>

using namespace std;

ACharacter::ACharacter(std::string NewName, const FUnitStat& NewStat)
	: Name(NewName),
	Stat(NewStat)
{
	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	bool bCritical = getRandomInt(1, 100) <= Stat.Critical;

	if (bCritical)  
	{
		Damage = static_cast<int>(Stat.Atk * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	int CalcDamage = max(DamageAmount - Stat.Def, 0);

	Stat.Hp = max(Stat.Hp - CalcDamage, 0);

	return CalcDamage;
}

bool ACharacter::IsDead()
{
	return Stat.Hp <= 0;
}


void ACharacter::DoAction(ACharacter* Target)
{
	if (getRandomInt(1,100) < 70)
	{
		Attack(Target);
	}
	else
	{
		if (Stat.Mp < 10)
		{
			cout << "마나가 부족합니다" << endl;
			Attack(Target);
		}
		else
		{
			UseSkill(Target);
		}
	}
	ShowStat();
}

void ACharacter::ShowStat()
{
	cout << "[" << Name << "]" << "HP : " << GetHP() << " / " << GetMaxHP() << "|"
		<< "MP: " << GetMP() << " / " << GetMaxMP() << endl;
}