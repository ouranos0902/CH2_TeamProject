#pragma once

#include "Character/Character.h" 
#include "Skill.h"

class UPlayerStrikeSkill : public USkill
{
public:
    UPlayerStrikeSkill(ACharacter* Target);
    void Play(ACharacter* Target) override;
};
