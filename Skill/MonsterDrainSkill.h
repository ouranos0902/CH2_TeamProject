#pragma once

#include "Character/Character.h"
#include "Skill.h"

class UMonsterDrainSkill : public USkill
{
public:
    UMonsterDrainSkill(ACharacter* Target);
    void Play(ACharacter* Target) override;
};
