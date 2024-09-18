#include "../../header/Main/GameManager.h"
#include "../../header/Player/PlayerType.h"
#include "../../header/Utility/Random.h"
#include "../../header/Player/Controllers/GuardianPlayerController.h"
#include "../../header/Player/Controllers/AgilePlayerController.h"
#include "../../header/Player/Controllers/BerserkerPlayerController.h"

namespace Main
{
    using namespace std;
    using namespace Utility;
    using namespace Player;
    using namespace Controller;

    GameManager::GameManager()
    {
        Random::Init(); // Seed the random number generator
        ShowGameDetails();
        InitializePlayers();
    }

    void GameManager::ShowGameDetails()
    {
        cout << "Welcome to the 2 Player Battle Adventure Game:\n\n";
        cout << "Rules:\n";
        cout << "1) Each player has only one turn at a time.\n";
        cout << "2) Each player has different abilities: damages, heals, "
            "additional effects, and a SPECIAL ABILITY.\n";
        cout << "   - Each Special ability has a 20% probability of activation.\n";
        cout << "3) If a player's health drops below 0, they lose the game.\n";
        cout << "4) Players can choose between two options on their turn: to "
            "inflict damage on the opponent or to heal themselves.\n";
        cout << "   - Press H to heal and D to damage.\n";
        cout << "5) Second player can choose only those players which are not "
            "already selected by first player.\n\n";

        cout << "There are three distinct player types in our game:\n\n";

        cout << "1) Guardian Player:\n";
        cout << "   - High Health\n";
        cout << "   - High Heal\n";
        cout << "   - Low Base Damage\n";
        cout << "   - High Additional Damage\n";
        cout << "   - Special Ability: High Heal, Damage\n\n";

        cout << "2) Agile Player:\n";
        cout << "   - Moderate Health\n";
        cout << "   - High Heal\n";
        cout << "   - Moderate Base Damage\n";
        cout << "   - Moderate Additional Damage\n";
        cout << "   - Special Ability: Heal, Double Damage\n\n";

        cout << "3) Berserker Player:\n";
        cout << "   - Low Health\n";
        cout << "   - Very High Heal\n";
        cout << "   - High Base Damage\n";
        cout << "   - Very High Additional Damage\n";
        cout
            << "   - Special Ability (if health is low): High Heal, Critical Hit\n";
        cout << endl << endl;
    }

    void GameManager::InitializePlayers()
    {
        // Players Selection
        // Select Player1
        cout << "Types of Players Available: " << endl;
        for (int i = 1; i < static_cast<int>(PlayerType::Last); i++)
        {
            cout << i << " -> " << PlayerTypeToString(static_cast<PlayerType>(i)) << endl;
        }
        cout << endl;
        cout << "Select Player 1 Type: " << endl;
        player1 = CreatePlayer();

        // Select Player2
        cout << "Select Player 2 Type(should be different than Player 1 Type Selection): " << endl;

        do
        {
            player2 = CreatePlayer();
            if (player1->GetPlayerType() == player2->GetPlayerType())
            {
                cout << "(Note: Player 2 Type Selection is same as Player 1 Type Selection. It should be different.)" << endl;
            }
        } while (player1->GetPlayerType() == player2->GetPlayerType());
        cout << endl;
        DisplayPlayerStats();
    }

    unique_ptr<PlayerController> GameManager::CreatePlayer()
    {
        unique_ptr<PlayerController> player = unique_ptr<PlayerController>();
        do {
            int selectPlayer;
            cin >> selectPlayer;
            PlayerType playerType = static_cast<PlayerType>(selectPlayer);
            switch (playerType) 
            {
            case PlayerType::Guardian:
                player =
                    make_unique<GuardianPlayerController>(750, // Health
                        50,  // Base Damage
                        150, // healMin
                        200, // healMax
                        70,  // additionalDamageMin
                        100  // additionalDamageMax
                    );
                break;
            case PlayerType::Agile:
                player = make_unique<AgilePlayerController>(500, // Health
                    75,  // Base Damage
                    150, // healMin
                    200, // healMax
                    30,  // additionalDamageMin
                    70   // additionalDamageMax
                );
                break;
            case PlayerType::Berserker:
                player =
                    make_unique<BerserkerPlayerController>(250, // Health
                        100, // Base Damage
                        200, // healMin
                        250, // healMax
                        100, // additionalDamageMin
                        130  // additionalDamageMax
                    );
                break;
            default:
                cout << "Invalid Player Type Selected. Select Again" << endl;
                player = unique_ptr<PlayerController>();
                break;
            }
        } while (player == nullptr);
        return player;
    }

    void GameManager::DisplayPlayerStats()
    {
        // Information about the Player1
        cout << "Player 1: " << PlayerTypeToString(player1->GetPlayerType())
            << endl;
        player1->ShowHealth();
        player1->ShowHeal();
        player1->ShowBaseDamage();
        player1->ShowAdditionalDamage();
        cout << endl;

        // Information about the Player2
        cout << "Player 2: " << PlayerTypeToString(player2->GetPlayerType())
            << endl;
        player2->ShowHealth();
        player2->ShowHeal();
        player2->ShowBaseDamage();
        player2->ShowAdditionalDamage();
        cout << endl;
    }

    void GameManager::PlayerPerformAction(PlayerController* player1, PlayerController* player2)
    {
        // To Selection Player Action
        char action;
        cout << PlayerTypeToString(player1->GetPlayerType()) << "\'s turn:" << endl;
        cout << "Select D to Damage or H to Heal" << endl;
        cin >> action;
        PlayerSelectActionType selectedAction = PlayerSelectAction(action);
        cout << endl;

        // To achieve 20 % probability
        int randomNumber = Random::GetRandomNumber(0, 99);
        bool isSpecialAttack = (randomNumber < 20);

        // Performing Action Based on Selection
        if (selectedAction == PlayerSelectActionType::None)
        {
            cout << "Turn Missed!!!: (Select D to Damage or H to Heal)" << endl;
        }
        else if (isSpecialAttack)
        {
            player1->SpecialAbility(player2, selectedAction);
        }
        else
        {
            player1->NormalAbility(player2, selectedAction);
        }
        // Show Player's Updated Health
        player1->ShowHealth();
        player2->ShowHealth();
        cout << endl;
    }

    void GameManager::StartGame() 
    {
        // Game Loop to Run Game until any Player is Dead....
        int turn = 0;
        do {
            if (turn % 2 == 0) 
            {
                PlayerPerformAction(player1.get(), player2.get());
            }
            else 
            {
                PlayerPerformAction(player2.get(), player1.get());
            }
            turn += 1;
        } while (player1->IsAlive() && player2->IsAlive());

        // Game Over
        if (player1->IsAlive()) 
        {
            cout << PlayerTypeToString(player1->GetPlayerType()) << " Wins!" << endl;
        }
        else 
        {
            cout << PlayerTypeToString(player2->GetPlayerType()) << " Wins!" << endl;
        }
        cout << "Game Over.......";
        cout << endl;
    }
}