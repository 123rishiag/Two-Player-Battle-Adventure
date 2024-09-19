#pragma once
#include "../../../header/Player/PlayerController.h"
namespace Player
{
    namespace Controller
    {
        class GuardianPlayerController : public PlayerController
        {
            // High Health, High Heal, Low Base Damage, High Additional Damage
            // Special Ability: High Heal, Damage
        public:
            GuardianPlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
                int _additionalDamageMin, int _additionalDamageMax);

            void SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction) override;
        };
    }
}