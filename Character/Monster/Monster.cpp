#include "Monster.h"
#include "RandomUtil.h"
#include <random>
using namespace std;

// Stat.MaxHp = Level * getRandomInt(10, 20); 체력
// Stat.Atk = Level * getRandomInt(5, 10); 공격력

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName,NewStat)
{
}

FDamageResult AMonster::Attack(ACharacter* Target)
{

	FDamageResult result = ACharacter::Attack(Target);

	string AttackMessage = " 이(가) 이빨로 물어 뜯습니다.";
	
	if (result.bCritical)
	{
		AttackMessage = " 이(가) 급소를 물어 뜯습니다!";
	}

	cout << "몬스터" << Name << AttackMessage << "데미지 : " << result.Damage << endl;
	cout <<"[" << Target->GetName() << "]" << " " << Target->GetHP() << endl;

	return result;
}

