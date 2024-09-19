#pragma once
#include "../../../header/Player/PlayerController.h"
namespace Player
{
    namespace Controller
    {
        class AgilePlayerController : public PlayerController
        {
            // Moderate Health, High Heal, Moderate Base Damage, Moderate Additional
            // Damage Damage Special Ability: Heal, Double Damage
        public:
            AgilePlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
                int _additionalDamageMin, int _additionalDamageMax);

            void SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction) override;
        };
    }
}