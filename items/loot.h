#ifndef LOOT_MANAGER_H
#define LOOT_MANAGER_H

#include "items.h"
#include "itemsDatabase.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct LootDrop {
    string itemId;
    int chance; // Percentage 0-100
    int minQuantity;
    int maxQuantity;
};

struct LootTable {
    string tableName;
    vector<LootDrop> drops;
    int goldMin;
    int goldMax;
};

class LootManager {
private:
    ItemDatabase* itemDb;
    map<string, LootTable> lootTables;
    
    void initializeLootTables();

public:
    LootManager(ItemDatabase* database);
    
    // Get specific loot table
    vector<shared_ptr<Item>> rollLootTable(const string& tableName, int& goldDropped);
    
    // Preset loot tables
    vector<shared_ptr<Item>> rollBanditLoot(int& goldDropped);
    vector<shared_ptr<Item>> rollChestLoot(const string& chestType, int& goldDropped);
    vector<shared_ptr<Item>> rollBossLoot(int& goldDropped);
    vector<shared_ptr<Item>> rollCommonEnemyLoot(int& goldDropped);
    
    // Create custom loot
    LootTable createCustomLootTable(const string& name);
    void addDropToTable(const string& tableName, const string& itemId, int chance, int minQty = 1, int maxQty = 1);
};

#endif