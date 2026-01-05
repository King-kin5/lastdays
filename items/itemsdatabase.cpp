#include "itemsDatabase.h"
#include "items.h"
#include <cstdlib>
#include <ctime>
#include <memory>

ItemDatabase::ItemDatabase() {
    srand(time(nullptr));
    
    initializeWeapons();
    initializeArmor();
    initializeConsumables();
    initializeQuestItems();
    initializeTreasures();
    initializeKeys();
    initializeMaterials();
}
void ItemDatabase::initializeWeapons() {
    // COMMON WEAPONS
    auto rustySword = make_shared<Item>("rusty_sword", "Rusty Sword", 
        "An old blade covered in rust. Better than nothing.", 
        ItemType::WEAPON, ItemRarity::COMMON);
    rustySword->setAttackBonus(2);
    rustySword->setValue(5);
    items["rusty_sword"] = rustySword;
    
    auto BowandArrow=make_shared<Item>("bow_and_arrow","A Bow and Arrow ","Fight from a far range and win",
        ItemType::WEAPON,ItemRarity::COMMON);
    BowandArrow->setAttackBonus(10);
    BowandArrow->setValue(6);
    items["bow_and_arrow"]=BowandArrow;
    
    auto Spare=make_shared<Item>("ordinary_spare"," A Spare","Helps fight a reasonble distance ",
        ItemType::WEAPON,ItemRarity::COMMON);
    Spare->setAttackBonus(10);
    Spare->setValue(5);
    items["ordinary_spare"]=Spare;
    
    auto Katana=make_shared<Item>("katana","A Katana","A katana is a Japanese sword that is used in martial arts",
        ItemType::WEAPON,ItemRarity::EPIC);
    Katana->setAttackBonus(15);
    Katana->setValue(15);
    items["katana"]=Katana;
    
    auto Sword=make_shared<Item>("sword","A Sword","A sword is a weapon used in combat",
        ItemType::WEAPON,ItemRarity::COMMON);
    Sword->setAttackBonus(10);
    Sword->setValue(10);
    items["sword"]=Sword;
    
    auto Dagger=make_shared<Item>("dagger","A Dagger","A dagger is a small knife used for stabbing",
        ItemType::WEAPON,ItemRarity::COMMON);
    Dagger->setAttackBonus(5);
    Dagger->setValue(5);
    items["dagger"]=Dagger;
    
    auto Axe=make_shared<Item>("axe","An Axe","An axe is a weapon used for chopping",
        ItemType::WEAPON,ItemRarity::COMMON);
    Axe->setAttackBonus(12);
    Axe->setValue(8);
    items["axe"]=Axe;
    
    auto whip=make_shared<Item>("whip","A Whip","A whip is a weapon used for striking",
        ItemType::WEAPON,ItemRarity::COMMON);
    whip->setAttackBonus(7);
    whip->setValue(7);
    items["whip"]=whip;
    
    auto flail=make_shared<Item>("flail","A Flail","A flail is a weapon used for striking",
        ItemType::WEAPON,ItemRarity::COMMON);
    flail->setAttackBonus(9);
    flail->setValue(9);
    items["flail"]=flail;
    
    auto staff=make_shared<Item>("staff","A Staff","A staff is a weapon used for striking",
        ItemType::WEAPON,ItemRarity::COMMON);
    staff->setAttackBonus(6);
    staff->setValue(6);
    items["staff"]=staff;
   
    auto twoBladeSword=make_shared<Item>("two_blade_sword","Two-Blade Sword","A sword with two blades that deals damage",
        ItemType::WEAPON,ItemRarity::RARE);
    twoBladeSword->setAttackBonus(20);
    twoBladeSword->setValue(15);
    items["two_blade_sword"]=twoBladeSword;
    
    auto machete=make_shared<Item>("machete","Machete","A machete that deals damage",
        ItemType::WEAPON,ItemRarity::COMMON);
    machete->setAttackBonus(10);
    machete->setValue(10);
    items["machete"]=machete;
    
    auto morningStar=make_shared<Item>("morning_star","Morning Star","A morning star that deals damage",
        ItemType::WEAPON,ItemRarity::RARE);
    morningStar->setAttackBonus(10);
    morningStar->setValue(10);
    items["morning_star"]=morningStar;
    
    auto DwarvenHammer=make_shared<Item>("dwarven_hammer","Dwarven Hammer","A dwarven hammer that deals damage",
        ItemType::WEAPON,ItemRarity::RARE);
    DwarvenHammer->setAttackBonus(15);
    DwarvenHammer->setValue(15);
    items["dwarven_hammer"]=DwarvenHammer;
    
    auto DwarvenAxe=make_shared<Item>("dwarven_axe","Dwarven Axe","A dwarven axe that deals damage",
        ItemType::WEAPON,ItemRarity::RARE);
    DwarvenAxe->setAttackBonus(15);
    DwarvenAxe->setValue(15);
    items["dwarven_axe"]=DwarvenAxe;
    
    
    auto spikedGauntlet=make_shared<Item>("spiked_gauntlet","Spiked Gauntlet","A spiked gauntlet that deals damage",
        ItemType::WEAPON,ItemRarity::EPIC);
    spikedGauntlet->setAttackBonus(15);
    spikedGauntlet->setValue(15);
    items["spiked_gauntlet"]=spikedGauntlet;
    auto warhammer=make_shared<Item>("warhammer","Warhammer","A warhammer that deals damage",
        ItemType::WEAPON,ItemRarity::LEGENDARY);
    warhammer->setAttackBonus(20);
    warhammer->setValue(20);
    items["warhammer"]=warhammer;
    
    // EPIC WEAPONS
    auto flamingSword=make_shared<Item>("flaming_sword","Flaming Sword","A flaming sword that deals damage",
        ItemType::WEAPON,ItemRarity::EPIC);
    flamingSword->setAttackBonus(15);
    flamingSword->setValue(15);
    items["flaming_sword"]=flamingSword;
    auto iceStaff=make_shared<Item>("ice_staff","Ice Staff","An ice staff that deals damage",
        ItemType::WEAPON,ItemRarity::EPIC);
    iceStaff->setAttackBonus(15);
    iceStaff->setValue(15);
    items["ice_staff"]=iceStaff;
    
    //LEGENDARY WEAPONS
    auto excalibur=make_shared<Item>("excalibur","Excalibur","A legendary sword of the kings.Its power is unlimited",
        ItemType::WEAPON,ItemRarity::LEGENDARY);
    excalibur->setAttackBonus(25);
    excalibur->setDefenseBonus(10);
    excalibur->setHealthBonus(50);
    excalibur->setValue(25);
    items["excalibur"]=excalibur;
}
void ItemDatabase::initializeArmor(){
    auto LeatherArmor=make_shared<Item>("leather_armor","Leather Armor","A leather armor that protects the wearer",
        ItemType::ARMOR,ItemRarity::COMMON);
    LeatherArmor->setDefenseBonus(5);
    LeatherArmor->setValue(5);
    items["leather_armor"]=LeatherArmor;
    
    auto Chainmail=make_shared<Item>("chainmail","Chainmail","A chainmail that protects the wearer",
        ItemType::ARMOR,ItemRarity::COMMON);
    Chainmail->setDefenseBonus(10);
    Chainmail->setValue(10);
    items["chainmail"]=Chainmail;
    
    auto PlateArmor=make_shared<Item>("plate_armor","Plate Armor","A plate armor that protects the wearer",
        ItemType::ARMOR,ItemRarity::RARE);
    PlateArmor->setDefenseBonus(15);
    PlateArmor->setValue(15);
    items["plate_armor"]=PlateArmor;
    
    auto Helmet=make_shared<Item>("helmet","Helmet","A helmet that protects the wearer",
        ItemType::ARMOR,ItemRarity::COMMON);
    Helmet->setDefenseBonus(5);
    Helmet->setValue(5);
    items["helmet"]=Helmet;
    
    auto Boots=make_shared<Item>("boots","Boots","A pair of boots that protects the wearer",
        ItemType::ARMOR,ItemRarity::COMMON);
    Boots->setDefenseBonus(5);
    Boots->setValue(5);
    items["boots"]=Boots;
    
    auto Shield=make_shared<Item>("shield","Shield","A shield that protects the wearer",
        ItemType::ARMOR,ItemRarity::COMMON);
    Shield->setDefenseBonus(5);
    Shield->setValue(5);
    items["shield"]=Shield;
    
    auto Gauntlets=make_shared<Item>("gauntlets","Gauntlets","A pair of gauntlets that protects the wearer",
        ItemType::ARMOR,ItemRarity::UNCOMMON);
    Gauntlets->setDefenseBonus(7);
    Gauntlets->setValue(5);
    items["gauntlets"]=Gauntlets;
    
    auto invisibilityPotion=make_shared<Item>("invisibility_potion","Invisibility Potion","A potion that makes the wearer invisible",
        ItemType::CONSUMABLE,ItemRarity::RARE);
    invisibilityPotion->setDefenseBonus(0);
    invisibilityPotion->setValue(10);
    items["invisibility_potion"]=invisibilityPotion;
    
    auto fullplate=make_shared<Item>("full-plate","Full Plate","A full plate that protects the wearer",
        ItemType::ARMOR,ItemRarity::RARE);
    fullplate->setDefenseBonus(20);
    fullplate->setValue(100);
    fullplate->setHealthBonus(20);
    items["full-plate"]=fullplate;  
    
    auto dragon=make_shared<Item>("dragon","Dragon","A dragon that protects the wearer",
        ItemType::ARMOR,ItemRarity::LEGENDARY);
    dragon->setDefenseBonus(20);
    dragon->setValue(20);
    dragon->setHealthBonus(50);
    items["dragon"]=dragon;  
    
    auto titaniumPlate=make_shared<Item>("titanium_plate","Titanium Plate","A titanium plate forged from rare Titanium ore ",
        ItemType::ARMOR,ItemRarity::EPIC);
    titaniumPlate->setDefenseBonus(15);
    titaniumPlate->setHealthBonus(30);
    titaniumPlate->setValue(600);
    items["titanium_plate"]=titaniumPlate;  
    
    auto agies=make_shared<Item>("agies","Agies","The divine armor.That grants the protection of the gods",
        ItemType::ARMOR,ItemRarity::UNCOMMON);
    agies->setDefenseBonus(50);
    agies->setHealthBonus(49);
    agies->setValue(1500);
    items["agies"]=agies;
    
}

void ItemDatabase::initializeConsumables(){
    auto minorPotion=make_shared<Item>("minor_potion","Minor Potion","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    minorPotion->setHealthAmount(100);
    minorPotion->setValue(50);
    minorPotion->setStackable(true,99);
    items["minor_potion"]=minorPotion;
    
    auto majorPotion=make_shared<Item>("major_potion","Major Potion","Restores large amount of health",
        ItemType::CONSUMABLE,ItemRarity::RARE);
    majorPotion->setHealthAmount(600);
    majorPotion->setValue(1000);
    majorPotion->setStackable(true,99);
    items["major_potion"]=majorPotion;
    
    auto healthPotion=make_shared<Item>("health_potion","Health Potion","Restores medium amount of health",
        ItemType::CONSUMABLE,ItemRarity::UNCOMMON);
    healthPotion->setHealthAmount(350);
    healthPotion->setValue(750);
    healthPotion->setStackable(true,99);
    items["health_potion"]=healthPotion;
    
    auto exlixir=make_shared<Item>("elixir","Elixir","Restores full amount of health",
        ItemType::CONSUMABLE,ItemRarity::LEGENDARY);
    exlixir->setHealthAmount(999);
    exlixir->setValue(1500);
    exlixir->setStackable(true,10);
    items["elixir"]=exlixir;
    //FOOD
    auto bread=make_shared<Item>("bread","Bread","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    bread->setHealthAmount(20);
    bread->setValue(25);
    bread->setStackable(true,99);
    items["bread"]=bread;
    
    auto cheese=make_shared<Item>("cheese","Cheese","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    cheese->setHealthBonus( 10);
    cheese->setValue(5);
    cheese->setStackable(true,99);
    items["cheese"]=cheese;
    
    auto apple=make_shared<Item>("apple","Apple","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    apple->setHealthBonus(6);
    apple->setValue(2);
    apple->setStackable(true,99);
    items["apple"]=apple;
    
    auto meat=make_shared<Item>("meat","Meat","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    meat->setHealthBonus(20);
    meat->setValue(10);
    meat->setStackable(true,99);
    items["meat"]=meat;
    
    auto fish=make_shared<Item>("fish","Fish","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    fish->setHealthBonus(15);
    fish->setValue(8);
    fish->setStackable(true,99);
    items["fish"]=fish;
    
    auto water=make_shared<Item>("water","Water","Restores small amount of health",
        ItemType::CONSUMABLE,ItemRarity::COMMON);
    water->setHealthBonus(10);
    water->setValue(1);
    water->setStackable(true,99);
    items["water"]=water;
}



void ItemDatabase::initializeTreasures() {
    auto goldCoin = make_shared<Item>("gold_coin", "Gold Coin", 
        "A shiny gold coin.", 
        ItemType::TREASURE, ItemRarity::COMMON);
    goldCoin->setValue(10);
    goldCoin->setStackable(true, 999);
    items["gold_coin"] = goldCoin;
    
    auto silverRing = make_shared<Item>("silver_ring", "Silver Ring", 
        "A simple silver ring.", 
        ItemType::TREASURE, ItemRarity::UNCOMMON);
    silverRing->setValue(50);
    items["silver_ring"] = silverRing;
    
    auto goldNecklace = make_shared<Item>("gold_necklace", "Gold Necklace", 
        "An ornate golden necklace.", 
        ItemType::TREASURE, ItemRarity::RARE);
    goldNecklace->setValue(150);
    items["gold_necklace"] = goldNecklace;
    
    auto ruby = make_shared<Item>("ruby", "Ruby", 
        "A flawless red ruby.", 
        ItemType::TREASURE, ItemRarity::EPIC);
    ruby->setValue(300);
    items["ruby"] = ruby;
    
    auto crown = make_shared<Item>("ancient_crown", "Ancient Crown", 
        "A crown from a long-lost kingdom.", 
        ItemType::TREASURE, ItemRarity::LEGENDARY);
    crown->setValue(1000);
    items["ancient_crown"] = crown;
}

void ItemDatabase::initializeKeys() {
    auto rustKey = make_shared<Item>("rusty_key", "Rusty Key", 
        "An old rusty key. What does it unlock?", 
        ItemType::KEY, ItemRarity::COMMON);
    rustKey->setValue(0);
    items["rusty_key"] = rustKey;
    
    auto cellarKey = make_shared<Item>("cellar_key", "Cellar Key", 
        "Opens the tavern cellar in Thornhaven.", 
        ItemType::KEY, ItemRarity::COMMON);
    cellarKey->setValue(0);
    items["cellar_key"] = cellarKey;
    
    auto shrineKey = make_shared<Item>("shrine_key", "Shrine Key", 
        "Opens the old shrine in Mistwood.", 
        ItemType::KEY, ItemRarity::UNCOMMON);
    shrineKey->setValue(0);
    items["shrine_key"] = shrineKey;
    
    auto fortressKey = make_shared<Item>("fortress_key", "Fortress Key", 
        "A heavy iron key to Irongate's inner chambers.", 
        ItemType::KEY, ItemRarity::RARE);
    fortressKey->setValue(0);
    items["fortress_key"] = fortressKey;
}

void ItemDatabase::initializeMaterials() {
    auto leather = make_shared<Item>("leather", "Leather", 
        "Cured animal hide. Useful for crafting.", 
        ItemType::MATERIAL, ItemRarity::COMMON);
    leather->setValue(5);
    leather->setStackable(true, 99);
    items["leather"] = leather;
    
    auto ironOre = make_shared<Item>("iron_ore", "Iron Ore", 
        "Raw iron ore. Can be smelted.", 
        ItemType::MATERIAL, ItemRarity::UNCOMMON);
    ironOre->setValue(15);
    ironOre->setStackable(true, 99);
    items["iron_ore"] = ironOre;
    
    auto dragonTooth = make_shared<Item>("dragon_tooth", "Dragon Tooth", 
        "A massive tooth from a dragon. Extremely rare.", 
        ItemType::MATERIAL, ItemRarity::EPIC);
    dragonTooth->setValue(200);
    dragonTooth->setStackable(true, 10);
    items["dragon_tooth"] = dragonTooth;
}

shared_ptr<Item> ItemDatabase::getItem(const string& itemId) {
    auto it = items.find(itemId);
    if (it != items.end()) {
        return it->second;
    }
    return nullptr;
}

vector<string> ItemDatabase::getAllItemIds() const {
    vector<string> ids;
    for (const auto& pair : items) {
        ids.push_back(pair.first);
    }
    return ids;
}

vector<shared_ptr<Item>> ItemDatabase::getItemsByType(ItemType type) const {
    vector<shared_ptr<Item>> result;
    for (const auto& pair : items) {
        if (pair.second->getType() == type) {
            result.push_back(pair.second);
        }
    }
    return result;
}
vector<shared_ptr<Item>> ItemDatabase::getItemsByRarity(ItemRarity rarity) const {
    vector<shared_ptr<Item>> result;
    for (const auto& pair : items) {
        if (pair.second->getRarity() == rarity) {
            result.push_back(pair.second);
        }
    }
    return result;
}
shared_ptr<Item> ItemDatabase::generateRandomLoot(ItemRarity minRarity) {
    // Random rarity roll
    int roll = rand() % 100;
    ItemRarity rarity;
    if (roll < 50) rarity = ItemRarity::COMMON;
    else if (roll < 75) rarity = ItemRarity::UNCOMMON;
    else if (roll < 90) rarity = ItemRarity::RARE;
    else if (roll < 98) rarity = ItemRarity::EPIC;
    else rarity = ItemRarity::LEGENDARY;
    
    // Apply minimum rarity
    if (rarity < minRarity) {
        rarity = minRarity;
    }
    auto itemsOfRarity = getItemsByRarity(rarity);
    if (itemsOfRarity.empty()) {
        return nullptr;
    }   
    int index = rand() % itemsOfRarity.size();
    return itemsOfRarity[index];
}
shared_ptr<Item> ItemDatabase::generateRandomWeapon() {
    auto weapons = getItemsByType(ItemType::WEAPON);
    if (weapons.empty()) return nullptr;
    return weapons[rand() % weapons.size()];
}
shared_ptr<Item> ItemDatabase::generateRandomArmor() {
    auto armor = getItemsByType(ItemType::ARMOR);
    if (armor.empty()) return nullptr;
    return armor[rand() % armor.size()];
}
shared_ptr<Item> ItemDatabase::generateRandomConsumable() {
    auto consumables = getItemsByType(ItemType::CONSUMABLE);
    if (consumables.empty()) return nullptr;
    return consumables[rand() % consumables.size()];
    
}shared_ptr<Item> ItemDatabase::generateRandomTreasure() {
    auto treasures = getItemsByType(ItemType::TREASURE);
    if (treasures.empty()) return nullptr;
    return treasures[rand() % treasures.size()];
}