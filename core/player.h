#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Player{
public:
     string name;
     int health;
     int maxhealth;
     int attack;
     int defense;
     int gold;
     int currentTown;
     bool hasJewel;
     vector<string> inventory;
     map<string, int> questProgress; // Track quest stages
     map<string, bool> solvedPuzzles;
public:
// Constructor
    Player(string playerName);
    
    // Getters
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxhealth; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getGold() const { return gold; }
    int getCurrentTown() const { return currentTown; }
    bool hasTheJewel() const { return hasJewel; }
    
    // Setters
    void setHealth(int h);
    void setAttack(int a) { attack = a; }
    void setDefense(int d) { defense = d; }
    
    // Health management
    void takeDamage(int damage);
    void heal(int amount);
    bool isAlive() const { return health > 0; }
    
    // Inventory
    void addItem(const string& item);
    void removeItem(const string& item);
    bool hasItem(const string& item) const;
    void showInventory() const;
    int getInventorySize() const { return inventory.size(); }
    
    // Gold management
    void addGold(int amount) { gold += amount; }
    bool spendGold(int amount);
    
    // Progression
    void advanceToNextTown();
    void receiveJewel() { hasJewel = true; }
    void deliverJewel() { hasJewel = false; }

    // Quest tracking
    void setQuestProgress(const string& questName, int stage);
    int getQuestProgress(const string& questName) const;
    
    // Puzzle tracking
    void markPuzzleSolved(const string& puzzleId);
    bool isPuzzleSolved(const string& puzzleId) const;
    
    // Display
    void showStats() const;
    void levelUp(int healthBonus, int attackBonus, int defenseBonus);
};
#endif