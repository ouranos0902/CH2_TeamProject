#include <Windows.h>
#include <iostream>
#include <memory>
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include "BattleManager.h"

using namespace std;

int main()
{
    cout << "닉네임을 입력해주세요" << endl;
    string name;
    cin >> name;
    
    //unique_ptr<ABattleManager> Manager = make_unique<ABattleManager>();
    auto Manager = make_unique<ABattleManager>();
    unique_ptr<APlayer> Player = make_unique<APlayer>(name, FUnitStat(200, 50, 30, 5, 10));
    unique_ptr<AMonster> Monster = make_unique<AMonster>("몬스터", FUnitStat(150, 30, 20, 3, 10));
    
    cout << "===  데스매치 시작!  ===" << endl;
    
    Manager->WaitForPlayerInput(); 
    
    Manager->RunBattle(Player.get(), Monster.get());
    
    return 0;
}