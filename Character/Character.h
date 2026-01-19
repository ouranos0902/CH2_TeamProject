#pragma once
#include <iostream>
#include <string>

class ACharacter
{
public:

	ACharacter(std::string NewName, int NewHP, int NewAtk);
	~ACharacter();

	void Attack(ACharacter* Target);
	void TakeDamage(int DamageAmount);
	
	int GetHP();
	bool IsDead();

protected:

	int HP;
	int Atk;
	std::string Name;

};