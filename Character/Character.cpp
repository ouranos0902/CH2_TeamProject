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

void ACharacter::Attack(ACharacter* Target)
{
	int CalcDamage = Stat.Atk;
	string CriticalAttackMsg;

	if (getRandomInt(0,100) <= Stat.Critical) 
	{
		CalcDamage = static_cast<int>(Stat.Atk * 1.5f);
		CriticalAttackMsg = "(이)가 치명타 공격을 합니다!";
		cout << Name << CriticalAttackMsg << CalcDamage << endl;
	}
		
		Target->TakeDamage(CalcDamage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
	int FinalDamage = max(DamageAmount - Stat.Def, 0);

	Stat.Hp = max(Stat.Hp - FinalDamage, 0);

	cout << Name << "(이)가 " << FinalDamage << "의 피해를 입었습니다." << endl;
	cout << " ->" << Name << "의 남은 체력 : " << GetHP() << endl;
}

bool ACharacter::IsDead()
{
	return Stat.Hp <= 0;
}


void ACharacter::DoAction(ACharacter* Target)
{
	if (getRandomInt(0,100) < 70)
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