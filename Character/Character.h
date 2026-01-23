#pragma once
#include <iostream>
#include <string>

struct FUnitStat
{
	int Hp;
	int Atk;
	int Def;
	float Critical;
};

class ACharacter
{
public:

	
	//ACharacter(std::string NewName, int NewHp, int NewAtk, int NewDef, int NewCri);
	ACharacter(std::string NewName, const FUnitStat& NewStat);
	~ACharacter();

	virtual void Attack(ACharacter* Target);
	void TakeDamage(int DamageAmount);
	
	int GetHP();
	bool IsDead();

	

protected:

	std::string Name;
	
	FUnitStat Stat;
	
	/*int Hp;
	int Atk;
	int Def
	int Critical;
	*/


};