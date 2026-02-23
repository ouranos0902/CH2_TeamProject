#pragma once

#include "Character/Character.h"
#include "Skill.h"

class UPlayerHealSkill : public USkill
{
public:
    UPlayerHealSkill(ACharacter* Target);
    void Play(ACharacter* Target)override;
};
