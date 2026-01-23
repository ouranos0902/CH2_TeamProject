#include <iostream>
#include "Character/Character.h"
#include "Player/Player.h"
#include "Vampire/Vampire.h"
#include<Windows.h>

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender) 
{
    Attacker->DoAction(Defender);

    if (Defender->IsDead())
    {
        return true;
    }

    return false;
}


int main()
{
    std::string name;
    std::cout << "이름을 정해주세요" << std::endl;
    std::cin >> name;

    ACharacter* Player = new APlayer(name);
    ACharacter* Monster = new AVampire("뱀파이어", FUnitStat{ 50, 20, 20, 5, 10 });

    
    std::cout << " === 데스매치 시작! ===" << std::endl;
    Sleep(1000);

    while (true)
    {
        if (BattleTurn(Player, Monster) == true)
        {
            break;
        }
        
        Sleep(500);

        if (BattleTurn(Monster, Player) == true)
        {
            break;
        }
        
        Sleep(1000);
    }
   
    delete Player;
    delete Monster;
    Player = nullptr;
    Monster = nullptr;

    return 0;
}