#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerType.h"
#include "../../header/Utility/Random.h"

namespace Player
{
    using namespace std;
    using namespace Utility;

    PlayerController::PlayerController(int _health, int _baseDamage, int _healMin, int _healMax, int _additionalDamageMin, 
        int _additionalDamageMax, PlayerType _playerType)
        : health(_health), baseDamage(_baseDamage), healMin(_healMin), healMax(_healMax), 
        additionalDamageMin(_additionalDamageMin), additionalDamageMax(_additionalDamageMax), playerType(_playerType)
    {
        Random::Init(); // Seed the random number generator
        healthMax = health;
    }

    PlayerController::~PlayerController() {};

    int PlayerController::GetMaxHealth() const { return healthMax; }
    int PlayerController::GetHealth() const { return health; }
    int PlayerController::GetBaseDamage() const { return baseDamage; }
    int PlayerController::GetHeal() const { return Random::GetRandomNumber(healMin, healMax); }
    int PlayerController::GetAdditionalDamage() const { return Random::GetRandomNumber(additionalDamageMin, additionalDamageMax); }

    void PlayerController::ShowHealth()
    {
        cout << PlayerTypeToString(GetPlayerType()) << "\'s Health is " << GetHealth() << "." << endl;
    }
    void PlayerController::ShowBaseDamage()
    {
        cout << PlayerTypeToString(GetPlayerType()) << "\'s Base Damage Points are " << GetBaseDamage() << "." << endl;
    }
    void PlayerController::ShowHeal()
    {
        cout << PlayerTypeToString(GetPlayerType()) << "\'s Heal Points can be in the range of " << healMin << " and "
            << healMax << "." << endl;
    }
    void PlayerController::ShowAdditionalDamage()
    {
        cout << PlayerTypeToString(GetPlayerType()) << "\'s Additional Damage Points can be in the range of "
            << additionalDamageMin << " and " << additionalDamageMax << "." << endl;
    }

    void PlayerController::TakeDamage(int damage, int additionalDamage)
    {
        int totalDamage = damage + additionalDamage;
        health -= totalDamage;
        if (health < 0) 
        {
            health = 0;
        }
        cout << PlayerTypeToString(GetPlayerType()) << " takes Damage of " << damage << " points & Additional Damage of " 
            << additionalDamage << " points. Total Damage taken: " << totalDamage << "." << endl;
    }

    void PlayerController::HealPlayer(int heal)
    {
        health += heal;
        if (health > healthMax) 
        {
            health = healthMax;
        }
        cout << PlayerTypeToString(GetPlayerType()) << " heals by " << heal << " points." << endl;
    }

    void PlayerController::NormalAbility(PlayerController* targetPlayer, PlayerSelectActionType selectedAction)
    {
        if (selectedAction == PlayerSelectActionType::Heal) 
        {
            HealPlayer(GetHeal());
        }
        else 
        {
            targetPlayer->TakeDamage(GetBaseDamage(), GetAdditionalDamage());
        }
    }

    bool PlayerController::IsAlive() const
    {
        bool isAlive = true;
        if (health == 0) 
        {
            isAlive = false;
        }
        return isAlive;
    }

    PlayerType PlayerController::GetPlayerType() { return playerType; }
}