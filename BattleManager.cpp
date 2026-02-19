#include <iostream>

#include "BattleManager.h"
#include <Character/Character.h>


void ABattleManager::RunBattle(ACharacter* Player, ACharacter* Monster)
{
    if (!Player || !Monster) return;
        
    while (true)
    {
        if (BattleTurn(Player, Monster))
        {
            cout << "승리" << endl;
            break;
        }
            
        if (BattleTurn(Monster, Player))
        {
            cout << "패배" << endl;
            break;
        }
    }
}
void ABattleManager::WaitForPlayerInput()
{
    system("Pause");
    cout << endl;
}

bool ABattleManager::BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
    Attacker->PlayTurn(Defender);
    
    Attacker->ShowStat();
    Defender->ShowStat();
        
    bool bIsDead = Defender -> IsDead();
    
    if (bIsDead)
    {
        cout << Defender ->GetName() << "이(가) 쓰러졌습니다." << endl;
            
    }
    WaitForPlayerInput();//한 번만 호출 할 수 있도록 수정
        
    return bIsDead;
}