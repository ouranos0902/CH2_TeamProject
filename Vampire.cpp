#include "Vampire.h"


AVampire::AVampire(std::string NewName, const FUnitStat NewStat)
	: AMonster("뱀파이어", FUnitStat{ 50, 50, 30, 30, 20, 5, 10 })
{

}

void AVampire::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10)
	{
		std::cout << Name <<"의 마나가 부족합니다!" << std::endl;
	}
	else 
	{
		std::cout << Name << "가 흡혈을 사용합니다!" << std::endl;

		Stat.Mp -= 10;
		Stat.Hp += 10;
		if (Stat.Hp > Stat.MaxHp)
		{
			Stat.Hp = Stat.MaxHp;
		}
		
		Target->TakeDamage(Stat.Atk);
		std::cout << Name << "가 흡혈했습니다." << std::endl;
	}
}