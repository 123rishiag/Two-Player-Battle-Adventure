#pragma once

namespace Player
{
    enum class PlayerSelectActionType;
    enum class PlayerType;

    class PlayerController
    {
    private:
        // Base Variables
        int health;
        int baseDamage;

        // Additional Variables
        int healthMax;
        int healMin;
        int healMax;
        int additionalDamageMin;
        int additionalDamageMax;

    public:
        // Constructor
        PlayerController(int _health, int _baseDamage, int _healMin, int _healMax,
            int _additionalDamageMin, int _additionalDamageMax);

        // Virtual Destructor due to dyanamic memory allocation
        virtual ~PlayerController();

        // Getters
        int GetMaxHealth() const;
        int GetHealth() const;
        int GetBaseDamage() const;
        int GetHeal() const;
        int GetAdditionalDamage() const;

        // Information Methods
        void ShowHealth();
        void ShowBaseDamage();
        void ShowHeal();
        void ShowAdditionalDamage();

        // Action methods
        void TakeDamage(int damage, int additionalDamage);
        void HealPlayer(int heal);
        void NormalAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction);

        // Other Methods
        bool IsAlive() const;
        // Pure Virtual Methods for Special Attacks
        virtual void SpecialAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction) = 0;
        // Other Pure Virtual Methods
        virtual PlayerType GetPlayerType() = 0;
    };
}