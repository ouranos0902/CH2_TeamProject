#pragma once

#include "Character/Character.h" 
#include "Skill.h"

class UPlayerAttackSkill : public USkill
{
public:
    UPlayerAttackSkill(ACharacter* Target);
    void Play(ACharacter* Target) override;
};
