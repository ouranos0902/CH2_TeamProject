#include "Character.h"
#include <random>


int getRandomInt()
{
	static std::random_device rd;
    static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);

	return dis(gen);
}


/*ACharacter::ACharacter(std::string NewName, int NewHp, int NewAtk, int NewDef, int NewCri)
{
	Name = NewName;
	Hp = NewHp;
	Atk = NewAtk;
	Def = NewDef;
	Critical = NewCri;

	std::cout << "[생성]" << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << std::endl;

}
*/


ACharacter::ACharacter(std::string NewName, const FUnitStat& NewStat)
	: Name(NewName),Stat(NewStat)
{
}


ACharacter::~ACharacter()
{
	std::cout << "ACharacter 소멸됨" << std::endl;
}

void ACharacter::Attack(ACharacter* Target)
{
	
	

	if (getRandomInt() <= Stat.Critical) //크리티컬이면
	{

		float CriticalDamage = Stat.Atk * 1.5f;//데미지를 1.5배해라 
		
		std::cout << Name << "가 치명타 공격 합니다! (공격력: " << CriticalDamage << ")" << std::endl;

		Target->TakeDamage(CriticalDamage);
	}

	else
	{
		std::cout << Name << "가 공격 합니다! (공격력: " << Stat.Atk << ")" << std::endl;

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
	
	std::cout << Name << "가 " << RealDamage << "의 피해를 입었습니다." << std::endl;
	std::cout << " ->" << Name << "의 남은 체력 : " << Stat.Hp << std::endl;
}

int ACharacter::GetHP()
{
	return Stat.Hp;
}


bool ACharacter::IsDead()
{
	return Stat.Hp <= 0 ? true : false;
}