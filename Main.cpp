#include <Windows.h>
#include <iostream>
//#include <conio.h>

#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"


using namespace std;

void WaitForPlayerInput()
{
    system("Pause");
    cout << endl;
}

int main()
{
    cout << "닉네임을 입력해주세요" << endl;
    string name;
    cin >> name;
    ACharacter* Player = new APlayer(name, FUnitStat(200, 50, 30, 5, 10));
    ACharacter* Monster = new AMonster("몬스터", FUnitStat(100, 30, 20, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();
    
    while (!Player->IsDead() && !Monster->IsDead()) 
    {
        Player->PlayTurn(Monster);
        
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }
        
        WaitForPlayerInput();
        Monster->PlayTurn(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        WaitForPlayerInput();
    }

    delete Player;
    delete Monster;
    
    return 0;
}