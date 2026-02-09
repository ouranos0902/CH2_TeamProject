#pragma once

#include <string>

using namespace std;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;
	int Atk;
	int Def;
	int Critical;
	
	int Hp = 0;
	int Mp = 0;
	
	FUnitStat()
	{
	}
	
	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;
		
		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};

class ACharacter;

struct FDamageResult
{
	int Damage;
	bool bCritical;
	ACharacter* Attacker;
	ACharacter* Target;
	void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& UnitStat);
	virtual ~ACharacter();
	

protected:
	string Name;
	FUnitStat Stat;

public:
	const string& GetName() { return Name; }
	int GetHp() const { return Stat.Hp; }
	int GetMaxHp() const { return Stat.MaxHp; }
	bool IsDead() const { return Stat.Hp <= 0; }
	
	virtual FDamageResult Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;
	int TakeDamage(int DamageAmount);
	void PrintName();
	void Heal(int Amount);
	void PlayTurn(ACharacter* Target);
};
