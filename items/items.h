#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

using namespace std;

// Item types
enum class ItemType {
    WEAPON,
    ARMOR,
    CONSUMABLE,
    QUEST_ITEM,
    TREASURE,
    KEY,
    MATERIAL
};

enum class ItemRarity {
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY
};

class Item {
private:
    string id;
    string name;
    string description;
    ItemType type;
    ItemRarity rarity;
    int value; // Gold value
    bool isStackable;
    int stackSize;
    
    // Stats (for weapons/armor)
    int attackBonus;
    int defenseBonus;
    int healthBonus;
    
    // Consumable effects
    int healAmount;
    int damageAmount;
    
    // Quest flags
    bool isQuestItem;
    string questId;

public:
    Item(string itemId, string itemName, string desc, ItemType itemType, ItemRarity itemRarity);
    
    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    ItemType getType() const { return type; }
    ItemRarity getRarity() const { return rarity; }
    int getValue() const { return value; }
    bool getIsStackable() const { return isStackable; }
    int getStackSize() const { return stackSize; }
    int getAttackBonus() const { return attackBonus; }
    int getDefenseBonus() const { return defenseBonus; }
    int getHealthBonus() const { return healthBonus; }
    int getHealAmount() const { return healAmount; }
    int getDamageAmount() const { return damageAmount; }
    bool getIsQuestItem() const { return isQuestItem; }
    
    // Setters
    void setValue(int v) { value = v; }
    void setStackable(bool s, int size = 1) { isStackable = s; stackSize = size; }
    void setAttackBonus(int a) { attackBonus = a; }
    void setDefenseBonus(int d) { defenseBonus = d; }
    void setHealthBonus(int h) { healthBonus = h; }
    void setHealAmount(int h) { healAmount = h; }
    void setDamageAmount(int d) { damageAmount = d; }
    void setQuestItem(bool q, string qId = "") { isQuestItem = q; questId = qId; }
    
    // Display
    string getRarityColor() const;
    string getTypeString() const;
    void displayInfo() const;
};
#endif