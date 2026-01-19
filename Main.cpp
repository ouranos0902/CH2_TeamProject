#include <iostream>
#include "Character/Character.h"
#include<Windows.h>


int main()
{
    
    ACharacter* Player = new ACharacter("용사", 200,20);
    ACharacter* Monster = new ACharacter("오크", 150,10);

    
    std::cout << " === 데스매치 시작! ===" << std::endl;
    Sleep(1000);

    while(!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack();
        Monster->TakeDamage(20);


        if (Monster->IsDead())
        {
            std::cout << "몬스터가 쓰러졌습니다! 승리!" << std::endl;
            break;
        }

        Sleep(500);

        Monster->Attack();
        Player->TakeDamage(10);

        if (Player->IsDead())
        {
            std::cout << "플레이어가 쓰러졌습니다...패배..." << std::endl;
        }

    }
   
    delete Player;
    delete Monster;
    Player = nullptr;
    Monster = nullptr;

    return 0;
}