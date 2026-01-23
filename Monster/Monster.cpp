#include "Monster.h"


AMonster::AMonster(std::string NewName, const FUnitStat& NewStat)
	: ACharacter(NewName,NewStat)
{

}

void AMonster::Attack(ACharacter* Target)
{
	std::cout << "몬스터 " << Name << "이(가) 이빨로 물어 뜯습니다!" << std::endl;
	
	Target->TakeDamage(Stat.Atk);
}