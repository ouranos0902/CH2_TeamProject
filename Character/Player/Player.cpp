#include "Player.h"
using namespace std;

APlayer::APlayer(std::string NewName)
	: ACharacter(NewName, FUnitStat{ 100, 100, 30, 30, 20, 5, 10 })
{
	Level = 1;
	MaxLevel = 10;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);

	string AttackMessage = " 이(가) 검을 휘두릅니다.";

	if (result.bCritical)
	{
		AttackMessage = " 이(가) 급소를 공격했습니다!";
	}

	cout << "플레이어" << Name << AttackMessage << "데미지 : " << result.Damage << endl;
	cout << "[" << Target->GetName() << "]" << " " << Target->GetHP() << endl;
	

	return result;

}

void APlayer::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10) { return; }

		std::cout << Name << "(이)가 회심의 일격을 사용합니다." << std::endl;
		Stat.Mp -= 10;
		int SkillDamage = Stat.Atk * 2;
		
		Target->TakeDamage(SkillDamage);
}

void APlayer::LevelUp()
{
	while(Exp >= 100 && Level < 10)
	{
		Level++;
		Stat.MaxHp += Level * 20;
		Stat.Atk += Level * 5;
		Stat.Hp = Stat.MaxHp;
	    Exp -= 100;
	}
}

void APlayer::GainExp(int ExpAmount)
{
	if (Level != 10)
	{
		Exp += ExpAmount;
		LevelUp();
	}
}