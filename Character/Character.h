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
    int Critical;
};

struct FDamageResult
{
	int Damage;
	bool bCritical;
};

class ACharacter
{
public:
	ACharacter(std::string NewName, const FUnitStat& NewStat);
	~ACharacter();
	virtual FDamageResult Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;
	int TakeDamage(int DamageAmount);
	void DoAction(ACharacter* Target);
	bool IsDead();
	void ShowStat();
	int GetHP(){return Stat.Hp;}
	int GetMaxHP(){	return Stat.MaxHp;}
	int GetMP(){return Stat.Mp;}
	int GetMaxMP(){return Stat.MaxMp;}
	std::string GetName(){ return Name; }

protected:
	std::string Name;
	FUnitStat Stat;
};