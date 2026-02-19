#pragma once

class ACharacter;

class ABattleManager
{
public:
    void RunBattle(ACharacter* Player, ACharacter* Monster);
    void WaitForPlayerInput();
    
    
private:
    bool BattleTurn(ACharacter* Attacker, ACharacter* Defender);
};
