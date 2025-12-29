#include "Game.h"
#include "../main.cpp"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

Game::Game() {
    player = nullptr;
    locationManager = nullptr;
    isRunning = false;
    gameWon = false;
}

Game::~Game() {
    shutdown();
}

void Game::initialize() {
    locationManager = new LocationManager();
    printSuccess("Game initialized!");
}

void Game::shutdown() {
    if (player != nullptr) {
        delete player;
        player = nullptr;
    }
    if (locationManager != nullptr) {
        delete locationManager;
        locationManager = nullptr;
    }
}

void Game::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::waitForEnter() {
    cout << "\n";
    printInfo("Press ENTER to continue...");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int Game::getPlayerChoice(int minChoice, int maxChoice) {
    int choice;
    while (true) {
        cout << "\nYour choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printError("Invalid input! Please enter a number.");
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (choice >= minChoice && choice <= maxChoice) {
            return choice;
        } else {
            printError("Please choose between " + to_string(minChoice) + " and " + to_string(maxChoice));
        }
    }
}

void Game::displayMainMenu() {
    clearScreen();
    
    cout << "\n";
    printTitle("╔═══════════════════════════════════════════╗");
    printTitle("║                                           ║");
    printTitle("║           L A S T   D A Y S               ║");
    printTitle("║                                           ║");
    printTitle("║      A Tale of Warriors and Jewels        ║");
    printTitle("║                                           ║");
    printTitle("╚═══════════════════════════════════════════╝");
    cout << "\n";
    
    cout << "  1. Start New Game\n";
    cout << "  2. Load Game (Coming Soon)\n";
    cout << "  3. Credits\n";
    cout << "  4. Exit\n";
}

void Game::run() {
    isRunning = true;
    
    while (isRunning) {
        displayMainMenu();
        int choice = getPlayerChoice(1, 4);
        
        switch (choice) {
            case 1:
                startNewGame();
                break;
            case 2:
                printWarning("\nSave/Load system coming soon!");
                waitForEnter();
                break;
            case 3:
                clearScreen();
                printTitle("\n=== CREDITS ===\n");
                cout << "Last Days - A Text Adventure Game\n";
                cout << "Created with passion and code\n";
                cout << "\nThank you for playing!\n";
                waitForEnter();
                break;
            case 4:
                printInfo("\nThanks for playing! Farewell, warrior.");
                isRunning = false;
                break;
        }
    }
}

void Game::startNewGame() {
    clearScreen();
    
    // Introduction
    printTitle("\n=== THE BEGINNING ===\n");
    typeText("In a realm on the brink of darkness...", 40);
    typeText("A sacred jewel holds the power to save the kingdom.", 40);
    typeText("You are a warrior, chosen to deliver this jewel to the King.", 40);
    typeText("", 40);
    typeText("Five towns stand between you and your destiny.", 40);
    typeText("Bandits, mysteries, and ancient riddles await.", 40);
    typeText("", 40);
    
    // Get player name
    cout << "\n";
    printHeader("What is your name, warrior?");
    cout << "Name: ";
    string playerName;
    getline(cin, playerName);
    
    if (playerName.empty()) {
        playerName = "Wanderer";
    }
    
    // Create player
    player = new Player(playerName);
    player->receiveJewel();
    
    clearScreen();
    printSuccess("\nWelcome, " + playerName + "!");
    cout << "\n";
    typeText("The village elder hands you a worn leather satchel.", 40);
    typeText("Inside, wrapped in silk, lies the Sacred Jewel of Eternity.", 40);
    typeText("Its soft glow pulses like a heartbeat.", 40);
    typeText("", 40);
    
    printWarning("\"Take this to the King in Crown's Peak,\" the elder whispers.");
    printWarning("\"Our last days depend on you...\"");
    
    waitForEnter();
    
    // Start main game loop
    while (isRunning && !gameWon && player->isAlive()) {
        exploreTown();
        checkGameOver();
        checkVictory();
    }
}

void Game::displayTownMenu() {
    Location& currentTown = locationManager->getTown(player->getCurrentTown());
    
    cout << "\n";
    printHeader("=== WHAT WOULD YOU LIKE TO DO? ===");
    cout << "  1. Explore areas\n";
    cout << "  2. Check inventory\n";
    cout << "  3. Check stats\n";
    
    if (currentTown.hasInn) {
        cout << "  4. Rest at inn (" << currentTown.innCost << " gold)\n";
    }
    if (currentTown.hasShop) {
        cout << "  5. Visit shop\n";
    }
    
    cout << "  6. Travel to next town\n";
    cout << "  7. Save & Quit\n";
}

void Game::exploreTown() {
    clearScreen();
    
    Location& currentTown = locationManager->getTown(player->getCurrentTown());
    locationManager->displayTownInfo(player->getCurrentTown());
    
    // Town-specific intro events
    handleTownEvents();
    
    bool inTown = true;
    
    while (inTown && player->isAlive()) {
        displayTownMenu();
        
        int maxChoice = 7;
        int choice = getPlayerChoice(1, maxChoice);
        
        switch (choice) {
            case 1: { // Explore areas
                clearScreen();
                printHeader("=== AREAS TO EXPLORE ===");
                vector<string> areas = locationManager->getAvailableAreas(player->getCurrentTown());
                
                for (size_t i = 0; i < areas.size(); i++) {
                    cout << "  " << i + 1 << ". " << areas[i] << "\n";
                }
                cout << "  " << areas.size() + 1 << ". Go back\n";
                
                int areaChoice = getPlayerChoice(1, areas.size() + 1);
                
                if (areaChoice <= (int)areas.size()) {
                    exploreArea(areas[areaChoice - 1]);
                }
                break;
            }
            case 2:
                clearScreen();
                player->showInventory();
                waitForEnter();
                break;
                
            case 3:
                clearScreen();
                player->showStats();
                waitForEnter();
                break;
                
            case 4: // Rest
                if (currentTown.hasInn) {
                    rest();
                } else {
                    printError("No inn available in this area!");
                    waitForEnter();
                }
                break;
                
            case 5: // Shop
                if (currentTown.hasShop) {
                    visitShop();
                } else {
                    printError("No shop available in this area!");
                    waitForEnter();
                }
                break;
                
            case 6: // Travel
                travelToNextTown();
                inTown = false;
                break;
                
            case 7: // Quit
                clearScreen();
                printWarning("\nAre you sure you want to quit?");
                cout << "1. Yes\n2. No\n";
                int quitChoice = getPlayerChoice(1, 2);
                if (quitChoice == 1) {
                    printInfo("Game saved! (Feature coming soon)");
                    isRunning = false;
                    inTown = false;
                }
                break;
        }
    }
}

void Game::exploreArea(const string& areaName) {
    clearScreen();
    locationManager->displayArea(player->getCurrentTown(), areaName);
    
    // Area-specific content will be handled here
    // For now, just show options
    
    cout << "\n";
    printHeader("What do you want to do?");
    cout << "  1. Look around\n";
    cout << "  2. Talk to someone\n";
    cout << "  3. Search for items\n";
    cout << "  4. Leave area\n";
    
    int choice = getPlayerChoice(1, 4);
    
    switch (choice) {
        case 1:
            printInfo("\nYou carefully observe your surroundings...");
            printMessage("(More details coming as we add content!)");
            waitForEnter();
            break;
        case 2:
            talkToNPC(areaName);
            break;
        case 3:
            printInfo("\nYou search the area...");
            printMessage("(Item search system coming soon!)");
            waitForEnter();
            break;
        case 4:
            // Return to town menu
            break;
    }
}

void Game::talkToNPC(const string& areaName) {
    printInfo("\nYou approach someone to talk...");
    printMessage("(Dialogue system will be added next!)");
    waitForEnter();
}

void Game::handleTownEvents() {
    int townId = player->getCurrentTown();
    Location& town = locationManager->getTown(townId);
    
    // Special first-time events for each town
    if (!town.mainQuestComplete) {
        switch (townId) {
            case 0: // Thornhaven
                printInfo("The villagers wish you well on your journey.");
                break;
            case 1: // Mistwood
                printWarning("You hear rustling in the trees. Stay alert!");
                break;
            case 2: // Shadowfen
                printError("A crowd has gathered around something...");
                break;
            case 3: // Irongate
                printInfo("Guards eye you suspiciously as you approach.");
                break;
            case 4: // Crown's Peak
                printSuccess("You've made it to the capital! The castle awaits.");
                break;
        }
        cout << "\n";
    }
}

void Game::rest() {
    Location& currentTown = locationManager->getTown(player->getCurrentTown());
    
    clearScreen();
    printHeader("=== INN ===");
    cout << "Rest here for " << currentTown.innCost << " gold?\n";
    cout << "You will restore all health.\n\n";
    cout << "1. Yes\n2. No\n";
    
    int choice = getPlayerChoice(1, 2);
    
    if (choice == 1) {
        if (player->spendGold(currentTown.innCost)) {
            player->setHealth(player->getMaxHealth());
            cout << "\n";
            typeText("You sleep soundly in a warm bed...", 50);
            typeText("Morning comes, and you feel refreshed!", 50);
            printSuccess("\nHealth fully restored!");
            waitForEnter();
        }
    }
}

void Game::visitShop() {
    clearScreen();
    printHeader("=== SHOP ===");
    cout << "\nYour gold: " << player->getGold() << "\n\n";
    
    cout << "  1. Health Potion (20 gold) - Restore 30 HP\n";
    cout << "  2. Strength Elixir (50 gold) - +2 Attack permanently\n";
    cout << "  3. Iron Shield (40 gold) - +2 Defense permanently\n";
    cout << "  4. Leave shop\n";
    
    int choice = getPlayerChoice(1, 4);
    
    switch (choice) {
        case 1:
            if (player->spendGold(20)) {
                player->addItem("Health Potion");
                printSuccess("Purchased Health Potion!");
            }
            waitForEnter();
            break;
        case 2:
            if (player->spendGold(50)) {
                player->setAttack(player->getAttack() + 2);
                printSuccess("Attack increased by 2!");
            }
            waitForEnter();
            break;
        case 3:
            if (player->spendGold(40)) {
                player->setDefense(player->getDefense() + 2);
                printSuccess("Defense increased by 2!");
            }
            waitForEnter();
            break;
        case 4:
            break;
    }
}

void Game::travelToNextTown() {
    clearScreen();
    
    Location& currentTown = locationManager->getTown(player->getCurrentTown());
    
    if (!currentTown.mainQuestComplete) {
        printWarning("\nYou haven't completed the main objective here yet!");
        cout << "Are you sure you want to leave?\n";
        cout << "1. Yes, leave anyway\n2. Stay\n";
        
        int choice = getPlayerChoice(1, 2);
        if (choice == 2) {
            return;
        }
    }
    
    if (player->getCurrentTown() >= 4) {
        printError("\nYou are already at the final destination!");
        waitForEnter();
        return;
    }
    
    cout << "\n";
    typeText("You gather your belongings and set out on the road...", 40);
    typeText("The journey is long and dangerous...", 40);
    
    player->advanceToNextTown();
    
    typeText("After days of travel, you see your destination ahead.", 40);
    waitForEnter();
}

void Game::checkGameOver() {
    if (!player->isAlive()) {
        displayGameOver();
        isRunning = false;
    }
}

void Game::checkVictory() {
    if (player->getCurrentTown() == 4 && 
        locationManager->getTown(4).mainQuestComplete &&
        !player->hasTheJewel()) {
        gameWon = true;
        displayVictory();
        isRunning = false;
    }
}

void Game::displayGameOver() {
    clearScreen();
    cout << "\n\n";
    printError("╔═══════════════════════════════════════╗");
    printError("║                                       ║");
    printError("║          G A M E   O V E R            ║");
    printError("║                                       ║");
    printError("╚═══════════════════════════════════════╝");
    cout << "\n";
    typeText("You have fallen...", 50);
    typeText("The sacred jewel remains undelivered...", 50);
    typeText("The kingdom's last days have come...", 50);
    cout << "\n";
    waitForEnter();
}

void Game::displayVictory() {
    clearScreen();
    cout << "\n\n";
    printSuccess("╔═══════════════════════════════════════╗");
    printSuccess("║                                       ║");
    printSuccess("║          V I C T O R Y !              ║");
    printSuccess("║                                       ║");
    printSuccess("╚═══════════════════════════════════════╝");
    cout << "\n";
    typeText("You kneel before the King and present the Sacred Jewel.", 50);
    typeText("Its glow fills the throne room with hope...", 50);
    typeText("", 50);
    typeText("\"You have saved us all, brave warrior,\" the King declares.", 50);
    typeText("\"Your name will be remembered forever!\"", 50);
    typeText("", 50);
    printSuccess("Congratulations, " + player->getName() + "!");
    printSuccess("You have completed Last Days!");
    cout << "\n";
    waitForEnter();
}