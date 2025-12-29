#ifndef ITEM_DATABASE_H
#define ITEM_DATABASE_H
#include "items.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

class ItemDatabase {
private:
    map<string, shared_ptr<Item>> items;
    
    void initializeWeapons();
    void initializeArmor();
    void initializeConsumables();
    void initializeQuestItems();
    void initializeTreasures();
    void initializeKeys();
    void initializeMaterials();

public:
    ItemDatabase();
    
    shared_ptr<Item> getItem(const string& itemId);
    vector<string> getAllItemIds() const;
    vector<shared_ptr<Item>> getItemsByType(ItemType type) const;
    vector<shared_ptr<Item>> getItemsByRarity(ItemRarity rarity) const;
    
    // Random loot generation
    shared_ptr<Item> generateRandomLoot(ItemRarity minRarity = ItemRarity::COMMON);
    shared_ptr<Item> generateRandomWeapon();
    shared_ptr<Item> generateRandomArmor();
    shared_ptr<Item> generateRandomConsumable();
    shared_ptr<Item> generateRandomTreasure();
};

#endif