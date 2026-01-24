#include "Player.h"



APlayer::APlayer(std::string NewName)
	: ACharacter(NewName, FUnitStat{ 100, 100, 30, 30, 20, 5, 10 })
{
	Level = 1;
}
	

void APlayer::Attack(ACharacter* Target)
{
	std::cout << "플레이어 " << Name << "(이)가 공격을 했습니다!" << std::endl;

	Target->TakeDamage(Stat.Atk);
}

void APlayer::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10)
	{
		std::cout << "마나가 부족합니다!" << std::endl;
		//early return 참고, 여기서 return 하면 else 제거 가능.
	}
	else
	{
		std::cout << "플레이어 " << Name << "(이)가 회심의 일격을 사용합니다." << std::endl;

		Stat.Mp -= 10;
		int SkillDamage = Stat.Atk * 2;
	
		Target->TakeDamage(SkillDamage);

	}


}