#include "MonsterAttackSkill.h"
#include "RandomUtil.h"

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* Target) : USkill(Owner)
{
}

void UMonsterAttackSkill::Play(ACharacter* Target)
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
    
    
    string AttackMessage = "크아앙! 이빨로 물어 뜯습니다!";
    if (result.bCritical)
    {
        AttackMessage = "이(가) 약점부위를 아프게 이빨로 물어뜯습니다!";
    }
    result.PrintMessage(AttackMessage);
}