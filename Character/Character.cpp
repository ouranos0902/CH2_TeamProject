#include "Character.h"

ACharacter::ACharacter()
{
	Name = "Unknown";
	HP = 100;
	Atk = 10;

	std::cout << "ACharacter 생성됨: " << Name << " (HP: " << HP << ")" << std::endl;

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
	std::cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << std::endl;
}