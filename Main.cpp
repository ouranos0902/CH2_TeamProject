#include <Windows.h>
#include <iostream>
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

using namespace std;

void WaitForPlayerInput()
{
    system("Pause");
    cout << endl;
}

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
    Attacker->PlayTurn(Defender);
    
    Attacker->ShowStat();
    Defender->ShowStat();
    
    WaitForPlayerInput();//한 번만 호출 할 수 있도록 수정
    
    bool bIsDead = Defender -> IsDead();
    
    if (bIsDead)
    {
        cout << Defender ->GetName() << "이(가) 쓰러졌습니다." << endl;
        return bIsDead;
    }
    
}

int main()
{
    cout << "닉네임을 입력해주세요" << endl;
    string name;
    cin >> name;
    ACharacter* Player = new APlayer(name, FUnitStat(200, 50, 30, 5, 10));
    ACharacter* Monster = new AMonster("몬스터", FUnitStat(150, 30, 20, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput(); 
    
    while (true) 
    {
       if (BattleTurn(Player, Monster))
       {
           cout << "전투 종료" << endl;
           break;
       }
        
        if (BattleTurn(Monster, Player))
        {
            cout << "전투에서 패배하였습니다." << endl;
            break;
        }
    }

    delete Player;
    delete Monster;
    
    return 0;
}