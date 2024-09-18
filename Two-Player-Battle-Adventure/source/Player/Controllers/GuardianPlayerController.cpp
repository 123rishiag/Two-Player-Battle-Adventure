#include "../../../header/Player/Controllers/GuardianPlayerController.h"
#include "../../../header/Player/PlayerType.h"
#include<iostream>

namespace Player
{
    namespace Controller
    {
        using namespace std;

        GuardianPlayerController::GuardianPlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
            int _additionalDamageMin, int _additionalDamageMax)
            : PlayerController(_health, _baseDamage, _healMin, _healMax, _additionalDamageMin, _additionalDamageMax) { }

        void GuardianPlayerController::SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction)
        {
            cout << "Special Attack Launched - High Heal, Damage" << endl;
            HealPlayer(2 * GetHeal());
            targetPlayer->TakeDamage(GetBaseDamage(), GetAdditionalDamage());
        }

        PlayerType GuardianPlayerController::GetPlayerType() { return PlayerType::Guardian; }
    }
}