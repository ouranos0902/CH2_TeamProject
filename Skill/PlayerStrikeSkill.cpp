#include "PlayerStrikeSkill.h"
#include "RandomUtil.h"


UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* Target) : USkill(Owner)
{
}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{
    
    int Damage = Owner -> GetStat().Atk * 2;
    int FinalDamage = Target->TakeDamage(Damage * 2);
    
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;
    
    result.Damage = FinalDamage;

    result.PrintMessage("-필살기- 회심의 일격...!");
}