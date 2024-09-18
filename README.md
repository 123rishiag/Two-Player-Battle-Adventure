# Two-Player Battle Adventure

Welcome to **Two-Player Battle Adventure**, an exciting text-based multiplayer game developed in C++ that showcases object-oriented design principles. This project is designed to demonstrate dynamic memory management, polymorphism, and efficient resource handling, while offering an engaging battle experience with different player types.

## Features

### Player Types:
The game features three distinct player types:

- **Guardian Player**: Known for high health and healing capabilities, but with low base damage. It compensates for this with high additional damage. The Guardian's special ability offers both high healing and damage, making it a durable and versatile option in battle.
  
- **Agile Player**: This player type has moderate health and base damage but excels in healing. The Agile Player’s special ability can either heal or deal double damage, giving it a balanced mix of offense and defense.
  
- **Berserker Player**: A high-risk, high-reward character with low health but very high base damage and healing potential. The Berserker’s special ability triggers when its health is low, allowing for critical hits and high healing, making it a formidable yet risky choice.

### Core Mechanics:
- **Smart Pointers**: Leveraged throughout the game to manage dynamic memory safely and efficiently.
- **Polymorphism**: Used to manage different player types, allowing each to have unique behaviors and abilities.
- **Enums**: Simplifies player state and type management.
- **Virtual Functions**: Enables flexible, reusable code for player actions and abilities.

## Learning Outcomes
- **Memory Management**: Gained hands-on experience with smart pointers, ensuring efficient memory allocation and deallocation.
- **OOP Principles**: Strengthened understanding of object-oriented programming concepts like inheritance, encapsulation, and polymorphism.
- **Problem Solving**: Learned to debug, optimize, and enhance code performance, making the game responsive and scalable.
- **Game Mechanics**: Designed and implemented game mechanics that allow for fluid player interaction and balance between different player types.

## Project Structure

### Headers:
- **Game Management**:
  - `GameManager`: Manages game flow and core logic.
- **Player**:
  - `PlayerType`: Defines different player types (Guardian, Agile, Berserker).
  - `PlayerController`: Manages player actions and inputs.
    - **Sub Controllers**: `GuardianPlayerController`, `AgilePlayerController`, `BerserkerPlayerController`
- **Utility**:
  - `Random`: Provides random number generation for various game mechanics.
  
### Source Files:
- **Main**: 
  - `main.cpp`: Entry point of the game.

## How to Play

This is a text-based, multiplayer game where two players take turns. Each player can either inflict damage on their opponent or heal themselves. Players use simple keyboard commands to make their moves:
- **Heal**: Press `H` to heal.
- **Damage**: Press `D` to inflict damage on the opponent.

The goal is to either bring the opponent’s health to zero or be the last player standing. Each player’s special ability has a 20% chance of activation, which could significantly impact the outcome of the game.

## Rules

1. Each player has only one turn at a time.
2. Players have different abilities, such as damage, healing, additional effects, and a special ability that has a 20% chance of activation.
3. If a player's health drops below zero, they lose the game.
4. The second player can only select a character that has not already been chosen by the first player.

## Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/123rishiag/Two-Player-Battle-Adventure.git
   ```

2. Build the project using your preferred C++ compiler.

3. Run the executable in your terminal to start the game.

## Video Demo
Check out the [Video Demo](#) to see the gameplay in action!