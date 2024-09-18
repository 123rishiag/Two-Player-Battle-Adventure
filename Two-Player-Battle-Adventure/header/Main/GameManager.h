#pragma once
#include "../../header/Player/PlayerController.h"
#include <memory>   // For Smart Pointers
namespace Main
{
    class GameManager 
    {
    private:
        std::unique_ptr<Player::PlayerController> player1;
        std::unique_ptr<Player::PlayerController> player2;

        void ShowGameDetails(); // Function to Print Game Details
        void InitializePlayers(); // Function to Initialize Players
        std::unique_ptr<Player::PlayerController> CreatePlayer(); // Function to create a Player Object based on the Player Type
        void DisplayPlayerStats(); // To Display Information About Players
        void PlayerPerformAction(Player::PlayerController* player1, Player::PlayerController* player2); // Function to Choose Player Actions

    public:
        GameManager(); // Game Manager Constructor
        void StartGame(); // Function to Start Game
    };
}