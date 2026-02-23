#include "PlayerAttackSkill.h"
#include "RandomUtil.h"

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* Target) : USkill(Owner)
{
}

void UPlayerAttackSkill::Play(ACharacter* Target)
{
    int Damage = Owner->GetAtk();
    bool bCritical = getRandomInt(1,100) < Owner->GetCritical();
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }
	
    FDamageResult result;
    int FinalDamage = Target->TakeDamage(Damage);
    result.Attacker = Owner;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;
    
    
    string AttackMessage = "이(가) 대검으로 공격합니다.";
    if (result.bCritical)
    {
        AttackMessage = "이(가) 치명적인 공격을 가합니다.";
    }
    result.PrintMessage(AttackMessage);
}