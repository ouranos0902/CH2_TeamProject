#pragma once
#include <iostream>
#include <string>

class ACharacter
{
public:

	ACharacter();
	~ACharacter();

	void Attack();
	void TakeDamage(int DamageAmount);
	
	

protected:

	int HP;
	int Atk;
	std::string Name;

};