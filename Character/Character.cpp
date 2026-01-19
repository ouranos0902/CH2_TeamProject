#include "Character.h"



ACharacter::ACharacter()
{
	Name = "Unknown";
	HP = 100;
	Atk = 10;

	std::cout << "ACharacter 생성됨: " << Name << " (HP: " << HP << ")" << std::endl;

}

ACharacter::ACharacter(std::string NewName, int NewHP, int NewAtk)
{
	Name = NewName;
	HP = NewHP;
	Atk = NewAtk;

	std::cout << "[생성]" << Name << "가 전장에 나타났습니다! (HP: " << HP << ")" << std::endl;

}

ACharacter::~ACharacter()
{
	std::cout << "ACharacter 소멸됨" << std::endl;
}

void ACharacter::Attack()
{
	std::cout << Name << "가 공격 합니다! (공격력: " << Atk << ")" << std::endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
	HP -= DamageAmount;

	if (HP < 0)
	{
		HP = 0;
	}
	
	std::cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << std::endl;
	std::cout << " ->" << Name << "의 남은 체력 : " << HP << std::endl;
}

int ACharacter::GetHP()
{
	return HP;
}


bool ACharacter::IsDead()
{
	return HP <= 0 ? true : false;
}