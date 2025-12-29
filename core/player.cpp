#include "Player.h"
#include "../main.cpp" // For color functions
#include <iostream>
#include <algorithm>
Player::Player(string playerName) {
    name = playerName;
    health = 100;
    maxhealth = 100;
    attack = 10;
    defense = 5;
    gold = 50;
    currentTown = 0;
    hasJewel = false;
}
void Player::setHealth(int h) {
    health = h;
    if (health > maxhealth) health = maxhealth;
    if (health < 0) health = 0;
}
void Player::takeDamage(int damage) {
    int actualDamage=damage-defense;
    if (actualDamage < 0) actualDamage = 0;
     health -= actualDamage;
     if (health < 0) health = 0;
     printWarning("You took " + to_string(actualDamage) + " damage!");
}
void Player::heal(int amount) {
    health += amount;
    if (health > maxhealth) health = maxhealth;
    printSuccess("You healed " + to_string(amount) + " HP!");
}
void Player::addItem(const string& item) {
    inventory.push_back(item);
    printSuccess("Added to inventory: " + item);
}
void Player::removeItem(const string& item) {
    auto it = find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
        printInfo("Removed from inventory: " + item);
    }
}
bool Player::hasItem(const string& item) const {
    return find(inventory.begin(), inventory.end(), item) != inventory.end();
}
void Player::showInventory() const {
    cout << "\n";
    printHeader("=== INVENTORY ===");
    if (inventory.empty()) {
        cout << "  Empty\n";
    } else {
        for (size_t i = 0; i < inventory.size(); i++) {
            cout << "  [" << i+1 << "] " << inventory[i] << "\n";
        }
    }
    cout << "\nGold: " << gold << "\n";
    if (hasJewel) {
        printInfo("★ The Sacred Jewel (Quest Item)");
    }
    cout << endl;
}
bool Player::spendGold(int amount) {
    if (gold >= amount) {
        gold -= amount;
        return true;
    }
    printError("Not enough gold!");
    return false;
}
    
void Player::advanceToNextTown() {
    if (currentTown < 4) {
        currentTown++;
        printSuccess("=== Journey continues to the next town ===");
    }
}
void Player::setQuestProgress(const string& questName, int stage) {
    questProgress[questName] = stage;
}
int Player::getQuestProgress(const string& questName) const {
    auto it = questProgress.find(questName);
    if (it != questProgress.end()) {
        return it->second;
    }
    return 0;
}
void Player::markPuzzleSolved(const string& puzzleId) {
    solvedPuzzles[puzzleId] = true;
    printSuccess("Puzzle solved: " + puzzleId);
}
bool Player::isPuzzleSolved(const string& puzzleId) const {
    auto it = solvedPuzzles.find(puzzleId);
    return (it != solvedPuzzles.end() && it->second);
}
void Player::showStats() const {
    cout << "\n";
    printHeader("=== CHARACTER STATS ===");
    cout << "Name:    " << name << "\n";
    cout << "Health:  " << health << "/" << maxhealth << "\n";
    cout << "Attack:  " << attack << "\n";
    cout << "Defense: " << defense << "\n";
    cout << "Gold:    " << gold << "\n";
    cout << "Town:    " << currentTown + 1 << "/5\n";
    cout << endl;
}
void Player::levelUp(int healthBonus, int attackBonus, int defenseBonus) {
    maxhealth += healthBonus;
    health += healthBonus;
    attack += attackBonus;
    defense += defenseBonus;
    printSuccess("\n*** LEVEL UP! ***");
    cout << "Health:  +" << healthBonus << "\n";
    cout << "Attack:  +" << attackBonus << "\n";
    cout << "Defense: +" << defenseBonus << "\n";
    cout << endl;
}