#pragma once
#include <iostream>
#include <string>

struct FUnitStat
{
	int Hp;
	int MaxHp;
	int Mp;
	int MaxMp;
	int Atk;
	int Def;
	float Critical;

};

class ACharacter
{
public:

	

	ACharacter(std::string NewName, const FUnitStat& NewStat);
	~ACharacter();

	virtual void Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;

	void TakeDamage(int DamageAmount);
	void DoAction(ACharacter* Target);
	
	int GetHP();
	int GetMaxHP();
	int GetMP();
	int GetMaxMP();
	bool IsDead();

	void ShowStat();
	

protected:

	std::string Name;
	
	FUnitStat Stat;
	


};