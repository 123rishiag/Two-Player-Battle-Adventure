#pragma once
#include <iostream> // For Standard IO Operations

namespace Player
{
    // Create enum for all types of Player Selections
    enum class PlayerSelectActionType { Damage, Heal, None };

    // Create enum for all types of Players
    enum class PlayerType { Guardian = 1, Agile, Berserker, Last, None };

    // Function to convert Player Types to String
    inline std::string PlayerTypeToString(PlayerType playerType)
    {
        switch (playerType) 
        {
        case PlayerType::Guardian:
            return "Guardian";
        case PlayerType::Agile:
            return "Agile";
        case PlayerType::Berserker:
            return "Berserker";
        default:
            return "Unknown";
        }
    }

    // Function to Select Action
    inline PlayerSelectActionType PlayerSelectAction(char selectAction)
    {
        switch (selectAction) 
        {
        case 'D':
        case 'd':
            return PlayerSelectActionType::Damage;
        case 'H':
        case 'h':
            return PlayerSelectActionType::Heal;
        default:
            return PlayerSelectActionType::None;
        }
    }
}