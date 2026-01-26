#pragma once
#include "Character/Character.h"


class APlayer : public ACharacter
{
public:
	APlayer(std::string NewName);

	virtual void Attack(ACharacter* Target) override;
	virtual void UseSkill(ACharacter* Target)override;

	void LevelUp();
	void GainExp(int ExpAmount);

	int GetLevel()
	{
		return Level;
	}

private:
	int Level;
	int MaxLevel;
	int Exp;
};

