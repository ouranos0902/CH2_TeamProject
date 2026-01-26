#include "Vampire.h"

//���⵵ �÷��̾�ó�� ������ ���� �ʿ�
AVampire::AVampire()
	: AMonster("�����̾�", FUnitStat{ 50, 50, 30, 30, 20, 5, 10 })
{

}

void AVampire::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10)
	{
		std::cout << Name <<"�� ������ �����մϴ�!" << std::endl;
		//early return
	}
	else 
	{
		std::cout << Name << "�� ������ �����մϴ�!" << std::endl;
		
		// ����ó�� �Ĳ��� ���Դϴ�.
		Stat.Mp -= 10;
		Stat.Hp += 10;
		if (Stat.Hp > Stat.MaxHp)
		{
			Stat.Hp = Stat.MaxHp;
		}
		
		Target->TakeDamage(Stat.Atk);
		std::cout << Name << "�� �����߽��ϴ�." << std::endl;
	}
}