#include "items.h"
#include "../main.cpp"
#include <iostream>
using namespace std;
Item::Item(string itemId, string itemName, string desc, ItemType itemType, ItemRarity itemRarity) {
    id = itemId;
    name = itemName;
    description = desc;
    type = itemType;
    rarity = itemRarity;
    value = 10;
    isStackable = false;
    stackSize = 1;
    attackBonus = 0;
    defenseBonus = 0;
    healthBonus = 0;
    healAmount = 0;
    damageAmount = 0;
    isQuestItem = false;
    questId = "";
}
string Item::getRarityColor() const {
    switch (rarity) {
        case ItemRarity::COMMON:
            return RESET;
        case ItemRarity::UNCOMMON:
            return GREEN;
        case ItemRarity::RARE:
            return CYAN;
        case ItemRarity::EPIC:
            return YELLOW; 
        case ItemRarity::LEGENDARY:
            return PURPLE ;
        default:
            return RESET;
    }
}
string Item::getTypeString() const {
    switch (type) {
        case ItemType::WEAPON: return "Weapon";
        case ItemType::ARMOR: return "Armor";
        case ItemType::CONSUMABLE: return "Consumable";
        case ItemType::QUEST_ITEM: return "Quest Item";
        case ItemType::TREASURE: return "Treasure";
        case ItemType::KEY: return "Key";
        case ItemType::MATERIAL: return "Material";
        default: return "Unknown";
    }
}
void Item::displayInfo() const {
    string rarityStr;
    switch (rarity) {
        case ItemRarity::COMMON: rarityStr = "Common"; break;
        case ItemRarity::UNCOMMON: rarityStr = "Uncommon"; break;
        case ItemRarity::RARE: rarityStr = "Rare"; break;
        case ItemRarity::EPIC: rarityStr = "Epic"; break;
        case ItemRarity::LEGENDARY: rarityStr = "Legendary"; break;
    }
    cout << getRarityColor();
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║ " << name << string(39 - name.length(), ' ') << "║\n";
    cout << "╚════════════════════════════════════════╝" << RESET << "\n";
    cout << getTypeString() << " | " << getRarityColor() << rarityStr << RESET << "\n";
    cout << description << "\n\n";
    if (attackBonus > 0) {
        cout << GREEN << "Attack: +" << attackBonus << RESET << "\n";
    }
    if (defenseBonus > 0) {
        cout << CYAN << "Defense: +" << defenseBonus << RESET << "\n";
    }
    if (healthBonus > 0) {
        cout << RED << " Health: +" << healthBonus << RESET << "\n";
    }
    if (healAmount > 0) {
        cout << GREEN << "✚ Heals: " << healAmount << " HP" << RESET << "\n";
    }
    if (damageAmount > 0) {
        cout << RED << " Damage: " << damageAmount << RESET << "\n";
    }
    cout << YELLOW << "Value: " << value << " gold" << RESET << "\n";
    if (isQuestItem) {
        cout << CYAN << " Quest Item" << RESET << "\n";
    }
    cout << "\n";
}
