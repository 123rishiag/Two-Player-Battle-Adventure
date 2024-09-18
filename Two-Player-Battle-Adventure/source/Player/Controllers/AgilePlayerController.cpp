#include "../../../header/Player/Controllers/AgilePlayerController.h"
#include "../../../header/Player/PlayerType.h"
#include<iostream>

namespace Player
{
    namespace Controller
    {
        using namespace std;

        AgilePlayerController::AgilePlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
            int _additionalDamageMin, int _additionalDamageMax)
            : PlayerController(_health, _baseDamage, _healMin, _healMax, _additionalDamageMin, _additionalDamageMax) { }

        void AgilePlayerController::SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction)
        {
            cout << "Special Attack Launched - Heal, Double Damage" << endl;
            HealPlayer(GetHeal());
            targetPlayer->TakeDamage(2 * GetBaseDamage(), 2 * GetAdditionalDamage());
        }

        PlayerType AgilePlayerController::GetPlayerType() { return PlayerType::Agile; }
    }
}