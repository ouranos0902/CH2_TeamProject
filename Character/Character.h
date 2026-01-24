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
	//크리티컬도 int로, 100분율로 취급
	float Critical;
};

class ACharacter
{
public:
	//빈 줄 정리 필요
	

	ACharacter(std::string NewName, const FUnitStat& NewStat);
	~ACharacter();

	virtual void Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;

	void TakeDamage(int DamageAmount);
	void DoAction(ACharacter* Target);
	
	//간단한 게터는, 헤더에 구현합시다.
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