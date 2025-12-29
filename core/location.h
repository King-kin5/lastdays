#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <map>

using namespace std;

struct NPC {
    string name;
    string description;
    vector<string> dialogue;
    bool isHostile;
    bool isQuestGiver;
};

struct Location {
    int townId;
    string name;
    string description;
    string arrivalText;
    
    vector<string> areas; // Different areas in town (tavern, market, etc)
    map<string, string> areaDescriptions;
    vector<NPC> npcs;
    
    bool hasInn;
    int innCost;
    bool hasShop;
    
    // Quest/Story flags
    bool mainQuestComplete;
    map<string, bool> sideQuestsComplete;
};

class LocationManager {
private:
    vector<Location> towns;
    void initializeTowns();
    
public:
    LocationManager();
    Location& getTown(int townId);
    void displayTownInfo(int townId);
    void displayArea(int townId, const string& areaName);
    vector<string> getAvailableAreas(int townId);
};

#endif