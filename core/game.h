#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Location.h"
#include <string>

using namespace std;

class Game {
private:
    Player* player;
    LocationManager* locationManager;
    bool isRunning;
    bool gameWon;
    // Menu functions
    void displayMainMenu();
    void displayTownMenu();
    void displayAreaMenu(const string& currentArea);
    void displayPauseMenu();
    // Game flow
    void startNewGame();
    void loadGame(); // For future save system
    void saveGame();  // For future save system
    // Town exploration
    void exploreTown();
    void exploreArea(const string& areaName);
    void talkToNPC(const string& areaName);
    void handleTownEvents();
    // Actions
    void rest();
    void visitShop();
    void checkInventory();
    void checkStats();
    void travelToNextTown();
    // Game state
    void checkGameOver();
    void checkVictory();
    void displayGameOver();
    void displayVictory();
    // Utilities
    void waitForEnter();
    void clearScreen();
    int getPlayerChoice(int minChoice, int maxChoice);
public:
    Game();
    ~Game();
    void run(); // Main game loop
    void initialize();
    void shutdown();
};

#endif