#pragma once
#include "../../../header/Player/PlayerController.h"
namespace Player
{
    namespace Controller
    {
        class BerserkerPlayerController : public PlayerController
        {
            // Low Health, Very High Heal, High Base Damage, Very High Additional Damage
            // Special Ability(if health is low): High Heal, Critical Hit
        public:
            BerserkerPlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
                int _additionalDamageMin, int _additionalDamageMax);

            void SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction) override;
        };
    }
}