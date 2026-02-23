#include "MonsterDrainSkill.h"
#include <algorithm>


UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* Target) : USkill(Owner)
{
    
}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;
	
    int Damage = Owner->GetStat().Atk;
    int FinalDamage = Target->TakeDamage(Damage);
    result.Damage = FinalDamage;
	
	Owner->Heal(FinalDamage);
	
    result.PrintMessage("이(가) 흡혈을 사용합니다!");
}