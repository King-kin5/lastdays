#include "Location.h"
#include "../main.cpp"
#include <iostream>

using namespace std;

LocationManager::LocationManager() {
    initializeTowns();
}

void LocationManager::initializeTowns() {
    // TOWN 1: THORNHAVEN - Starting Town
    Location thornhaven;
    thornhaven.townId = 0;
    thornhaven.name = "Thornhaven";
    thornhaven.description = "A peaceful village surrounded by thorn bushes. Your journey begins here.";
    thornhaven.arrivalText = "You stand at the edge of Thornhaven, the sacred jewel weighing heavy in your pack.\n"
                              "The village elder has entrusted you with delivering it to the King in Crown's Peak.\n"
                              "A long and dangerous road lies ahead...";
    thornhaven.areas = {"Village Square", "Elder's House", "Blacksmith", "Tavern", "Forest Path"};
    thornhaven.hasInn = true;
    thornhaven.innCost = 10;
    thornhaven.hasShop = true;
    thornhaven.mainQuestComplete = false;
    
    thornhaven.areaDescriptions["Village Square"] = "The heart of Thornhaven. Villagers go about their daily business.";
    thornhaven.areaDescriptions["Elder's House"] = "A modest home where the village elder resides.";
    thornhaven.areaDescriptions["Blacksmith"] = "The ring of hammer on anvil echoes here. Weapons and armor for sale.";
    thornhaven.areaDescriptions["Tavern"] = "The Rusty Tankard - warm food and cold ale.";
    thornhaven.areaDescriptions["Forest Path"] = "The path leading to Mistwood. Bandits have been spotted here lately.";
    
    towns.push_back(thornhaven);
    
    // TOWN 2: MISTWOOD - Forest of Mysteries
    Location mistwood;
    mistwood.townId = 1;
    mistwood.name = "Mistwood";
    mistwood.description = "A dark forest settlement shrouded in perpetual mist. Bandits rule here.";
    mistwood.arrivalText = "Mist clings to everything as you enter Mistwood.\n"
                           "The trees seem to whisper warnings. This is bandit territory.";
    mistwood.areas = {"Bandit Camp", "Hidden Grove", "Merchant's Cart", "Old Shrine", "Northern Pass"};
    mistwood.hasInn = false;
    mistwood.hasShop = false;
    mistwood.mainQuestComplete = false;
    
    mistwood.areaDescriptions["Bandit Camp"] = "A makeshift camp. You can hear rough laughter and smell woodsmoke.";
    mistwood.areaDescriptions["Hidden Grove"] = "A peaceful clearing. An old hermit lives here.";
    mistwood.areaDescriptions["Merchant's Cart"] = "An overturned cart. Its owner is missing...";
    mistwood.areaDescriptions["Old Shrine"] = "An ancient shrine covered in moss. A riddle is carved into the stone.";
    mistwood.areaDescriptions["Northern Pass"] = "The way to Shadowfen lies beyond.";
    
    towns.push_back(mistwood);
    
    // TOWN 3: SHADOWFEN - Crime and Mystery
    Location shadowfen;
    shadowfen.townId = 2;
    shadowfen.name = "Shadowfen";
    shadowfen.description = "A swamp town plagued by crime. Murder and corruption run rampant.";
    shadowfen.arrivalText = "The stench of the swamp hits you as you arrive in Shadowfen.\n"
                            "A murder has just been committed. The town is in chaos.";
    shadowfen.areas = {"Town Center", "Crime Scene", "Sheriff's Office", "Docks", "Swamp Trail"};
    shadowfen.hasInn = true;
    shadowfen.innCost = 15;
    shadowfen.hasShop = true;
    shadowfen.mainQuestComplete = false;
    
    shadowfen.areaDescriptions["Town Center"] = "Muddy streets and worried faces. People speak in hushed tones.";
    shadowfen.areaDescriptions["Crime Scene"] = "A body lies here. You must investigate to find the killer.";
    shadowfen.areaDescriptions["Sheriff's Office"] = "The sheriff looks overwhelmed. He needs help solving this case.";
    shadowfen.areaDescriptions["Docks"] = "Boats bob in murky water. Smugglers operate from here.";
    shadowfen.areaDescriptions["Swamp Trail"] = "A treacherous path through the swamp to Irongate.";
    
    towns.push_back(shadowfen);
    
    // TOWN 4: IRONGATE - Mountain Fortress
    Location irongate;
    irongate.townId = 3;
    irongate.name = "Irongate";
    irongate.description = "A fortress carved into the mountain. Home to warriors and scholars.";
    irongate.arrivalText = "The mighty gates of Irongate loom before you.\n"
                           "To pass, you must prove your worth through riddles and combat.";
    irongate.areas = {"Main Gate", "Training Grounds", "Library", "Fortress Halls", "Mountain Pass"};
    irongate.hasInn = true;
    irongate.innCost = 20;
    irongate.hasShop = true;
    irongate.mainQuestComplete = false;
    
    irongate.areaDescriptions["Main Gate"] = "Massive iron gates guard the entrance. Guards watch warily.";
    irongate.areaDescriptions["Training Grounds"] = "Warriors spar here. You may challenge them.";
    irongate.areaDescriptions["Library"] = "Ancient tomes hold knowledge and riddles.";
    irongate.areaDescriptions["Fortress Halls"] = "The commander resides here, a stern but fair leader.";
    irongate.areaDescriptions["Mountain Pass"] = "The final stretch to Crown's Peak.";
    
    towns.push_back(irongate);
    
    // TOWN 5: CROWN'S PEAK - Capital City
    Location crownspeak;
    crownspeak.townId = 4;
    crownspeak.name = "Crown's Peak";
    crownspeak.description = "The grand capital. The King awaits your delivery.";
    crownspeak.arrivalText = "At last, you have reached Crown's Peak!\n"
                             "The castle towers above the city. Your quest is nearly complete.\n"
                             "But one final trial awaits...";
    crownspeak.areas = {"City Gates", "Market District", "Noble Quarter", "Castle Courtyard", "Throne Room"};
    crownspeak.hasInn = true;
    crownspeak.innCost = 30;
    crownspeak.hasShop = true;
    crownspeak.mainQuestComplete = false;
    
    crownspeak.areaDescriptions["City Gates"] = "Guards check all who enter the capital.";
    crownspeak.areaDescriptions["Market District"] = "The finest goods from across the realm.";
    crownspeak.areaDescriptions["Noble Quarter"] = "Mansions of the wealthy and powerful.";
    crownspeak.areaDescriptions["Castle Courtyard"] = "Royal guards patrol. The throne room lies beyond.";
    crownspeak.areaDescriptions["Throne Room"] = "The King awaits...";
    
    towns.push_back(crownspeak);
}

Location& LocationManager::getTown(int townId) {
    return towns[townId];
}

void LocationManager::displayTownInfo(int townId) {
    Location& town = towns[townId];
    
    cout << "\n";
    printTitle("╔════════════════════════════════════╗");
    printTitle("║  " + town.name + string(33 - town.name.length(), ' ') + "║");
    printTitle("╚════════════════════════════════════╝");
    cout << "\n";
    
    cout << town.description << "\n\n";
    
    if (!town.arrivalText.empty() && !town.mainQuestComplete) {
        printInfo(town.arrivalText);
        cout << "\n";
    }
}

void LocationManager::displayArea(int townId, const string& areaName) {
    Location& town = towns[townId];
    
    cout << "\n";
    printHeader(">>> " + areaName + " <<<");
    
    auto it = town.areaDescriptions.find(areaName);
    if (it != town.areaDescriptions.end()) {
        cout << it->second << "\n";
    }
    cout << "\n";
}

vector<string> LocationManager::getAvailableAreas(int townId) {
    return towns[townId].areas;
}