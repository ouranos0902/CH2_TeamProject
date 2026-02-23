#include "PlayerHealSkill.h"

UPlayerHealSkill::UPlayerHealSkill(ACharacter* Target) : USkill(Owner)
{
    
}

void UPlayerHealSkill::Play(ACharacter* Target)
{
    FDamageResult result;
    int HealAmount = 30;
    Owner->Heal(HealAmount);
    
    result.PrintMessage("이(가) 신성한 힘으로 회복합니다!");
}