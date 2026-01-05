#include "loot.h"
#include <cstdlib>

LootManager::LootManager(ItemDatabase* database) {
    itemDb = database;
    initializeLootTables();
}

void LootManager::initializeLootTables() {
    // BANDIT LOOT TABLE
    LootTable banditLoot;
    banditLoot.tableName = "bandit";
    banditLoot.goldMin = 5;
    banditLoot.goldMax = 25;
    
    banditLoot.drops.push_back({"rusty_sword", 30, 1, 1});
    banditLoot.drops.push_back({"dagger", 25, 1, 1});
    banditLoot.drops.push_back({"leather_armor", 20, 1, 1});
    banditLoot.drops.push_back({"minor_potion", 40, 1, 2});
    banditLoot.drops.push_back({"bread", 50, 1, 3});
    banditLoot.drops.push_back({"gold_coin", 60, 3, 10});
    banditLoot.drops.push_back({"rusty_key", 5, 1, 1});
    banditLoot.drops.push_back({"cheese", 30, 1, 2});
    banditLoot.drops.push_back({"apple", 35, 1, 3});
    
    lootTables["bandit"] = banditLoot;
    
    // COMMON ENEMY LOOT
    LootTable commonEnemy;
    commonEnemy.tableName = "common_enemy";
    commonEnemy.goldMin = 2;
    commonEnemy.goldMax = 15;
    
    commonEnemy.drops.push_back({"minor_potion", 25, 1, 1});
    commonEnemy.drops.push_back({"bread", 35, 1, 2});
    commonEnemy.drops.push_back({"leather", 20, 1, 3});
    commonEnemy.drops.push_back({"gold_coin", 40, 1, 5});
    commonEnemy.drops.push_back({"apple", 30, 1, 2});
    commonEnemy.drops.push_back({"water", 25, 1, 2});
    
    lootTables["common_enemy"] = commonEnemy;
    
    // BEAST/ANIMAL LOOT
    LootTable beastLoot;
    beastLoot.tableName = "beast";
    beastLoot.goldMin = 0;
    beastLoot.goldMax = 5;
    
    beastLoot.drops.push_back({"leather", 60, 2, 5});
    beastLoot.drops.push_back({"meat", 70, 1, 3});
    beastLoot.drops.push_back({"minor_potion", 15, 1, 1});
    beastLoot.drops.push_back({"gold_coin", 20, 1, 3});
    
    lootTables["beast"] = beastLoot;
    
    // ARCHER/RANGER ENEMY LOOT
    LootTable archerLoot;
    archerLoot.tableName = "archer";
    archerLoot.goldMin = 8;
    archerLoot.goldMax = 30;
    
    archerLoot.drops.push_back({"bow_and_arrow", 45, 1, 1});
    archerLoot.drops.push_back({"dagger", 30, 1, 1});
    archerLoot.drops.push_back({"leather_armor", 35, 1, 1});
    archerLoot.drops.push_back({"minor_potion", 40, 1, 2});
    archerLoot.drops.push_back({"bread", 35, 1, 2});
    archerLoot.drops.push_back({"gold_coin", 50, 5, 15});
    
    lootTables["archer"] = archerLoot;
    
    // WARRIOR/KNIGHT ENEMY LOOT
    LootTable warriorLoot;
    warriorLoot.tableName = "warrior";
    warriorLoot.goldMin = 15;
    warriorLoot.goldMax = 50;
    
    warriorLoot.drops.push_back({"sword", 40, 1, 1});
    warriorLoot.drops.push_back({"axe", 30, 1, 1});
    warriorLoot.drops.push_back({"chainmail", 35, 1, 1});
    warriorLoot.drops.push_back({"shield", 30, 1, 1});
    warriorLoot.drops.push_back({"helmet", 25, 1, 1});
    warriorLoot.drops.push_back({"health_potion", 40, 1, 2});
    warriorLoot.drops.push_back({"gold_coin", 60, 10, 25});
    warriorLoot.drops.push_back({"meat", 25, 1, 2});
    
    lootTables["warrior"] = warriorLoot;
    
    // MAGE/WIZARD ENEMY LOOT
    LootTable mageLoot;
    mageLoot.tableName = "mage";
    mageLoot.goldMin = 20;
    mageLoot.goldMax = 60;
    
    mageLoot.drops.push_back({"staff", 45, 1, 1});
    mageLoot.drops.push_back({"ice_staff", 20, 1, 1});
    mageLoot.drops.push_back({"major_potion", 50, 1, 2});
    mageLoot.drops.push_back({"health_potion", 40, 1, 2});
    mageLoot.drops.push_back({"invisibility_potion", 15, 1, 1});
    mageLoot.drops.push_back({"gold_coin", 70, 15, 35});
    mageLoot.drops.push_back({"silver_ring", 25, 1, 1});
    
    lootTables["mage"] = mageLoot;
    
    // WOODEN CHEST
    LootTable woodenChest;
    woodenChest.tableName = "wooden_chest";
    woodenChest.goldMin = 10;
    woodenChest.goldMax = 50;
    
    woodenChest.drops.push_back({"health_potion", 50, 1, 2});
    woodenChest.drops.push_back({"sword", 15, 1, 1});
    woodenChest.drops.push_back({"chainmail", 15, 1, 1});
    woodenChest.drops.push_back({"silver_ring", 25, 1, 1});
    woodenChest.drops.push_back({"gold_coin", 70, 5, 15});
    woodenChest.drops.push_back({"rusty_key", 10, 1, 1});
    woodenChest.drops.push_back({"bread", 40, 2, 5});
    woodenChest.drops.push_back({"leather", 30, 2, 4});
    
    lootTables["wooden_chest"] = woodenChest;
    
    // IRON CHEST
    LootTable ironChest;
    ironChest.tableName = "iron_chest";
    ironChest.goldMin = 50;
    ironChest.goldMax = 150;
    
    ironChest.drops.push_back({"major_potion", 60, 1, 3});
    ironChest.drops.push_back({"axe", 30, 1, 1});
    ironChest.drops.push_back({"warhammer", 25, 1, 1});
    ironChest.drops.push_back({"plate_armor", 25, 1, 1});
    ironChest.drops.push_back({"shield", 35, 1, 1});
    ironChest.drops.push_back({"gold_necklace", 20, 1, 1});
    ironChest.drops.push_back({"health_potion", 50, 2, 4});
    ironChest.drops.push_back({"gauntlets", 30, 1, 1});
    ironChest.drops.push_back({"boots", 30, 1, 1});
    ironChest.drops.push_back({"cellar_key", 15, 1, 1});
    ironChest.drops.push_back({"iron_ore", 40, 2, 5});
    
    lootTables["iron_chest"] = ironChest;
    
    // LEGENDARY CHEST
    LootTable legendaryChest;
    legendaryChest.tableName = "legendary_chest";
    legendaryChest.goldMin = 200;
    legendaryChest.goldMax = 500;
    
    legendaryChest.drops.push_back({"elixir", 80, 2, 5});
    legendaryChest.drops.push_back({"katana", 25, 1, 1});
    legendaryChest.drops.push_back({"two_blade_sword", 25, 1, 1});
    legendaryChest.drops.push_back({"excalibur", 10, 1, 1});
    legendaryChest.drops.push_back({"titanium_plate", 30, 1, 1});
    legendaryChest.drops.push_back({"full-plate", 35, 1, 1});
    legendaryChest.drops.push_back({"agies", 10, 1, 1});
    legendaryChest.drops.push_back({"ruby", 40, 1, 2});
    legendaryChest.drops.push_back({"ancient_crown", 15, 1, 1});
    legendaryChest.drops.push_back({"dragon_tooth", 20, 1, 3});
    legendaryChest.drops.push_back({"warhammer", 20, 1, 1});
    legendaryChest.drops.push_back({"flaming_sword", 18, 1, 1});
    legendaryChest.drops.push_back({"ice_staff", 18, 1, 1});
    legendaryChest.drops.push_back({"fortress_key", 12, 1, 1});
    
    lootTables["legendary_chest"] = legendaryChest;
    
    // BOSS LOOT
    LootTable bossLoot;
    bossLoot.tableName = "boss";
    bossLoot.goldMin = 100;
    bossLoot.goldMax = 300;
    
    bossLoot.drops.push_back({"major_potion", 100, 2, 4}); // Guaranteed
    bossLoot.drops.push_back({"katana", 40, 1, 1});
    bossLoot.drops.push_back({"flaming_sword", 30, 1, 1});
    bossLoot.drops.push_back({"warhammer", 25, 1, 1});
    bossLoot.drops.push_back({"dragon", 25, 1, 1});
    bossLoot.drops.push_back({"titanium_plate", 30, 1, 1});
    bossLoot.drops.push_back({"ruby", 35, 1, 1});
    bossLoot.drops.push_back({"health_potion", 50, 2, 3});
    bossLoot.drops.push_back({"ancient_crown", 10, 1, 1});
    bossLoot.drops.push_back({"dragon_tooth", 30, 1, 2});
    bossLoot.drops.push_back({"gold_necklace", 25, 1, 1});
    
    lootTables["boss"] = bossLoot;
    
    // ELITE BOSS LOOT (Dragons, Ancient Warriors, etc.)
    LootTable eliteBossLoot;
    eliteBossLoot.tableName = "elite_boss";
    eliteBossLoot.goldMin = 300;
    eliteBossLoot.goldMax = 800;
    
    eliteBossLoot.drops.push_back({"elixir", 100, 3, 6}); // Guaranteed
    eliteBossLoot.drops.push_back({"excalibur", 25, 1, 1});
    eliteBossLoot.drops.push_back({"katana", 50, 1, 1});
    eliteBossLoot.drops.push_back({"flaming_sword", 45, 1, 1});
    eliteBossLoot.drops.push_back({"ice_staff", 40, 1, 1});
    eliteBossLoot.drops.push_back({"warhammer", 40, 1, 1});
    eliteBossLoot.drops.push_back({"dragon", 30, 1, 1});
    eliteBossLoot.drops.push_back({"titanium_plate", 45, 1, 1});
    eliteBossLoot.drops.push_back({"full-plate", 40, 1, 1});
    eliteBossLoot.drops.push_back({"agies", 20, 1, 1});
    eliteBossLoot.drops.push_back({"ruby", 60, 2, 3});
    eliteBossLoot.drops.push_back({"ancient_crown", 35, 1, 1});
    eliteBossLoot.drops.push_back({"dragon_tooth", 70, 3, 8});
    eliteBossLoot.drops.push_back({"two_blade_sword", 35, 1, 1});
    
    lootTables["elite_boss"] = eliteBossLoot;
    
    // FISHING LOOT
    LootTable fishingLoot;
    fishingLoot.tableName = "fishing";
    fishingLoot.goldMin = 0;
    fishingLoot.goldMax = 10;
    
    fishingLoot.drops.push_back({"fish", 80, 1, 3});
    fishingLoot.drops.push_back({"water", 60, 1, 2});
    fishingLoot.drops.push_back({"gold_coin", 15, 1, 5});
    fishingLoot.drops.push_back({"silver_ring", 5, 1, 1});
    fishingLoot.drops.push_back({"rusty_key", 3, 1, 1});
    
    lootTables["fishing"] = fishingLoot;
    
    // FORAGING/GATHERING LOOT
    LootTable foragingLoot;
    foragingLoot.tableName = "foraging";
    foragingLoot.goldMin = 0;
    foragingLoot.goldMax = 5;
    
    foragingLoot.drops.push_back({"apple", 70, 2, 5});
    foragingLoot.drops.push_back({"bread", 30, 1, 2});
    foragingLoot.drops.push_back({"cheese", 25, 1, 2});
    foragingLoot.drops.push_back({"minor_potion", 20, 1, 1});
    foragingLoot.drops.push_back({"leather", 15, 1, 2});
    
    lootTables["foraging"] = foragingLoot;
    
    // DWARVEN ENEMY LOOT
    LootTable dwarvenLoot;
    dwarvenLoot.tableName = "dwarf_enemy";
    dwarvenLoot.goldMin = 25;
    dwarvenLoot.goldMax = 80;
    
    dwarvenLoot.drops.push_back({"dwarven_hammer", 35, 1, 1});
    dwarvenLoot.drops.push_back({"dwarven_axe", 35, 1, 1});
    dwarvenLoot.drops.push_back({"plate_armor", 30, 1, 1});
    dwarvenLoot.drops.push_back({"major_potion", 45, 1, 2});
    dwarvenLoot.drops.push_back({"iron_ore", 60, 3, 8});
    dwarvenLoot.drops.push_back({"gold_coin", 70, 20, 50});
    dwarvenLoot.drops.push_back({"gold_necklace", 20, 1, 1});
    
    lootTables["dwarf_enemy"] = dwarvenLoot;
    
    // TREASURE HOARD (Hidden treasures)
    LootTable treasureHoard;
    treasureHoard.tableName = "treasure_hoard";
    treasureHoard.goldMin = 100;
    treasureHoard.goldMax = 400;
    
    treasureHoard.drops.push_back({"gold_coin", 100, 50, 100}); // Guaranteed
    treasureHoard.drops.push_back({"ruby", 60, 1, 3});
    treasureHoard.drops.push_back({"ancient_crown", 30, 1, 1});
    treasureHoard.drops.push_back({"gold_necklace", 70, 2, 4});
    treasureHoard.drops.push_back({"silver_ring", 80, 3, 6});
    treasureHoard.drops.push_back({"dragon_tooth", 25, 1, 2});
    
    lootTables["treasure_hoard"] = treasureHoard;
    
    // SHRINE/ALTAR LOOT
    LootTable shrineLoot;
    shrineLoot.tableName = "shrine";
    shrineLoot.goldMin = 0;
    shrineLoot.goldMax = 30;
    
    shrineLoot.drops.push_back({"elixir", 40, 1, 2});
    shrineLoot.drops.push_back({"major_potion", 60, 1, 3});
    shrineLoot.drops.push_back({"invisibility_potion", 25, 1, 1});
    shrineLoot.drops.push_back({"shrine_key", 50, 1, 1});
    shrineLoot.drops.push_back({"ancient_crown", 15, 1, 1});
    shrineLoot.drops.push_back({"silver_ring", 35, 1, 1});
    
    lootTables["shrine"] = shrineLoot;
}

vector<shared_ptr<Item>> LootManager::rollLootTable(const string& tableName, int& goldDropped) {
    vector<shared_ptr<Item>> loot;
    
    auto it = lootTables.find(tableName);
    if (it == lootTables.end()) {
        goldDropped = 0;
        return loot;
    }
    
    LootTable& table = it->second;
    
    // Roll gold
    goldDropped = table.goldMin + (rand() % (table.goldMax - table.goldMin + 1));
    
    // Roll each possible drop
    for (const auto& drop : table.drops) {
        int roll = rand() % 100;
        
        if (roll < drop.chance) {
            // Item dropped!
            int quantity = drop.minQuantity;
            if (drop.maxQuantity > drop.minQuantity) {
                quantity += rand() % (drop.maxQuantity - drop.minQuantity + 1);
            }
            
            // Add items (respecting quantity)
            for (int i = 0; i < quantity; i++) {
                auto item = itemDb->getItem(drop.itemId);
                if (item) {
                    loot.push_back(item);
                }
            }
        }
    }
    
    return loot;
}

vector<shared_ptr<Item>> LootManager::rollBanditLoot(int& goldDropped) {
    return rollLootTable("bandit", goldDropped);
}

vector<shared_ptr<Item>> LootManager::rollChestLoot(const string& chestType, int& goldDropped) {
    string tableKey;
    
    if (chestType == "wooden") tableKey = "wooden_chest";
    else if (chestType == "iron") tableKey = "iron_chest";
    else if (chestType == "legendary") tableKey = "legendary_chest";
    else tableKey = "wooden_chest"; // Default
    
    return rollLootTable(tableKey, goldDropped);
}

vector<shared_ptr<Item>> LootManager::rollBossLoot(int& goldDropped) {
    return rollLootTable("boss", goldDropped);
}

vector<shared_ptr<Item>> LootManager::rollCommonEnemyLoot(int& goldDropped) {
    return rollLootTable("common_enemy", goldDropped);
}

LootTable LootManager::createCustomLootTable(const string& name) {
    LootTable table;
    table.tableName = name;
    table.goldMin = 0;
    table.goldMax = 0;
    return table;
}

void LootManager::addDropToTable(const string& tableName, const string& itemId, int chance, int minQty, int maxQty) {
    auto it = lootTables.find(tableName);
    if (it != lootTables.end()) {
        LootDrop drop;
        drop.itemId = itemId;
        drop.chance = chance;
        drop.minQuantity = minQty;
        drop.maxQuantity = maxQty;
        it->second.drops.push_back(drop);
    }
}