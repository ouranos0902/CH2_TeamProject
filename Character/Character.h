#pragma once
#include <iostream>
#include <string>

class ACharacter
{
public:

	ACharacter();
	ACharacter(std::string NewName, int NewHP, int NewAtk);
	~ACharacter();

	void Attack();
	void TakeDamage(int DamageAmount);
	
	int GetHP();
	bool IsDead();

protected:

	int HP;
	int Atk;
	std::string Name;

};