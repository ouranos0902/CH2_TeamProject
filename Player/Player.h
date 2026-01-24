#pragma once
#include "Character/Character.h"

//플레이어 몬스터 모두 Character 폴더에 넣어둡시다.

class APlayer : public ACharacter
{
public:

	APlayer(std::string NewName);

	virtual void Attack(ACharacter* Target) override;
	
	// 코드 자동 정렬 단축키로 띄어쓰기 정리합시다.
	virtual void UseSkill(ACharacter* Target)override;

private:
	//빈 줄 정리
	int Level;

};

