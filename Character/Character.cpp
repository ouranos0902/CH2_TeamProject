#include "Character.h"
#include "RandomUtil.h"
#include <random>


ACharacter::ACharacter(std::string NewName, const FUnitStat& NewStat)
	: Name(NewName),
	Stat(NewStat)
{
	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;
}


ACharacter::~ACharacter()
{
	std::cout << "ACharacter 소멸됨" << std::endl;
}

void ACharacter::Attack(ACharacter* Target)
{
	
	

	if (getRandomInt(0,100) <= Stat.Critical) //크리티컬이면
	{
		
		float CriticalDamage = Stat.Atk * 1.5f;//데미지를 1.5배해라 
		
		std::cout << Name << "(이)가 치명타 공격 합니다! (공격력: " << CriticalDamage << ")" << std::endl;

		Target->TakeDamage(CriticalDamage);
	}

	else
	{
		std::cout << Name << "(이)가 공격 합니다! (공격력: " << Stat.Atk << ")" << std::endl;

		Target->TakeDamage(Stat.Atk);
	}
	

}

void ACharacter::TakeDamage(int DamageAmount)
{

	int RealDamage = DamageAmount - Stat.Def;
	

	if (RealDamage < 0)
	{
		RealDamage = 0;
	}

	Stat.Hp -= RealDamage;

	if (Stat.Hp < 0)
	{
		Stat.Hp = 0;
	}
	
	std::cout << Name << "(이)가 " << RealDamage << "의 피해를 입었습니다." << std::endl;
	std::cout << " ->" << Name << "의 남은 체력 : " << GetHP() << std::endl;
}

int ACharacter::GetHP()
{
	return Stat.Hp;
}

int  ACharacter::GetMaxHP()
{
	return Stat.MaxHp;
}

int  ACharacter::GetMP()
{
	return Stat.Mp;
}

int  ACharacter::GetMaxMP()
{
	return Stat.MaxMp;
}

bool ACharacter::IsDead()
{
	return Stat.Hp <= 0 ? true : false;
}


void ACharacter::DoAction(ACharacter* Target)
{
	if (getRandomInt() < 70)
	{
		Attack(Target);
		
	}
	else
	{
		
		if (Stat.Mp < 10)
		{
			std::cout << "마나가 부족합니다" << std::endl;
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
	std::cout << "[" << Name << "]" << "HP : " << GetHP() << " / " << GetMaxHP() << "|"
		<< "MP: " << GetMP() << " / " << GetMaxMP() << std::endl;

}