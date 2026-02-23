#pragma once

#include "Character/Character.h"
#include "Skill.h"

class UMonsterAttackSkill : public USkill
{
public:
    UMonsterAttackSkill(ACharacter* Target);
    void Play(ACharacter* Target) override;
};
