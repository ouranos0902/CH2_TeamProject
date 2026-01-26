#include "Vampire.h"

AVampire::AVampire()
	: AMonster("뱀파이어", FUnitStat{ 50, 50, 30, 30, 20, 5, 10 })
{

}

void AVampire::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10) { return; }

	std::cout << Name << "뱀파이어가 흡혈을 합니다!" << std::endl;
	Stat.Mp -= 10;
	Stat.Hp += 10;

	if (Stat.Hp > Stat.MaxHp)
	{
		Stat.Hp = Stat.MaxHp;
	}

	Target->TakeDamage(Stat.Atk);
	std::cout << Name << "가 체력을 회복했습니다!." << std::endl;
}