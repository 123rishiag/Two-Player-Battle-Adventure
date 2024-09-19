#include "../../../header/Player/Controllers/BerserkerPlayerController.h"
#include "../../../header/Player/PlayerType.h"
#include<iostream>

namespace Player
{
    namespace Controller
    {
        using namespace std;

        BerserkerPlayerController::BerserkerPlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
            int _additionalDamageMin, int _additionalDamageMax)
            : PlayerController(_health, _baseDamage, _healMin, _healMax, _additionalDamageMin, _additionalDamageMax,
                PlayerType::Berserker) { }

        void BerserkerPlayerController::SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction)
        {
            if (GetHealth() <= GetMaxHealth() / 3) 
            {
                cout << "Special Attack Launched - High Heal, Critical Hit (When Low on Health)" << endl;
                HealPlayer(2 * GetHeal());
                targetPlayer->TakeDamage(GetBaseDamage(), targetPlayer->GetHealth() * .8);
            }
            else 
            {
                NormalAbility(targetPlayer, selectedAction);
            }
        }
    }
}