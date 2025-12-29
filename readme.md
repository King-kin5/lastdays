# Last Days - Text Adventure Game
## Project Structure

```
LastDays/
│
├── main.cpp                 # Entry point
├── utils.h                  # Color codes & utility functions (already exists)
│
├── core/
│   ├── Game.h              # Main game loop & state manager
│   ├── Game.cpp
│   ├── Player.h            # Player stats, inventory, position
│   ├── Player.cpp
│   ├── Location.h          # Location/Town class
│   └── Location.cpp
│
├── systems/
│   ├── Combat.h            # Combat system
│   ├── Combat.cpp
│   ├── Puzzle.h            # Puzzle/riddle system
│   ├── Puzzle.cpp
│   ├── Inventory.h         # Inventory management
│   └── Inventory.cpp
│
├── story/
│   ├── StoryManager.h      # Handles story progression
│   ├── StoryManager.cpp
│   ├── Dialogue.h          # NPC dialogue system
│   ├── Dialogue.cpp
│   └── towns.json          # Town data (optional: can be .cpp)
│
└── data/
    ├── enemies.h           # Enemy definitions
    ├── items.h             # Item definitions
    ├── puzzles.h           # Puzzle definitions
    └── story_data.h        # Story beats & narrative
```

## Game Flow Overview

1. **Main Menu** → Start New Game / Continue / Exit
2. **Intro Sequence** → Warrior receives the jewel mission
3. **Town Progression** → 5 towns to traverse
4. **Gameplay Loop** per town:
   - Explore location
   - Talk to NPCs
   - Solve puzzles/crimes
   - Combat encounters
   - Find items/clues
   - Progress to next town
5. **Final Delivery** → Reach the king

## The 5 Towns Journey

1. **Thornhaven** - Starting point (tutorial-ish)
2. **Mistwood** - Forest mysteries & bandits
3. **Shadowfen** - Swamp with crime investigation
4. **Irongate** - Mountain fortress with riddles
5. **Crown's Peak** - Capital city, final challenges

## Next Steps

Let's build in this order:
1. ✅ Utils (you have this!)
2. Core classes (Player, Location, Game)
3. Basic systems (Combat, Inventory)
4. Story content
5. Puzzles & special encounters