
std::array themes{
    "1: Dwelling",
    "2: Jungle",
    "2: Volcana",
    "3: Olmec",
    "4: Tide Pool",
    "4: Temple",
    "5: Ice Caves",
    "6: Neo Babylon",
    "7: Sunken City",
    "8: Cosmic Ocean",
    "4: City of Gold",
    "4: Duat",
    "4: Abzu",
    "6: Tiamat",
    "7: Eggplant World",
    "7: Hundun",
    "0: Base camp",
};

std::array themes_short{
    "Dwelling",
    "Jungle",
    "Volcana",
    "Olmec",
    "Tide Pool",
    "Temple",
    "Ice Caves",
    "Neo Babylon",
    "Sunken City",
    "Cosmic Ocean",
    "City of Gold",
    "Duat",
    "Abzu",
    "Tiamat",
    "Eggplant World",
    "Hundun",
    "Base camp",
};

std::array entity_flags{
    "Invisible",
    "Indestructible/special floor",
    "Solid (wall)",
    "Passes through objects",
    "Passes through everything",
    "Take no damage",
    "Throwable/Knockbackable",
    "Is platform",
    "Climbable (as rope/ladder)",
    "No gravity",
    "Interact with liquid",
    "Stunnable",
    "Collides walls",
    "Interact with semisolids?",
    "Can be stomped",
    "Power stomps",
    "Facing left",
    "Pickupable",
    "Usable item?",
    "Enable button prompt",
    "Interact with webs",
    "Can be carried through exit",
    "Shop item",
    "Shop floor (break to aggro)",
    "Passes through player",
    "Exploded",
    "Crushed",
    "Pause AI and physics",
    "Dead",
    "Character",
    "Movable",
    "Use overlay draw depth",
};

std::array more_flags{
    "Take damage on collision after throw",
    "Revived (HH)",
    "Blocks shield",
    "Passes through shield",
    "Being moved by shield",
    "Just spawned?",
    "Done spawning?",
    "Stuck in something",
    "Stuck in something, 1 frame later",
    "Pitchers mitt antigravity",
    "Swimming",
    "Hit ground",
    "Hit wall",
    "Falling",
    "Cursed effect",
    "Elixir buff",
    "Disable input",
    "Shop item held by player",
    "Falling platform something",
    "Yangs turkey",
    "Floor can be decorated",
    "Disable collision",
    "JumpWhipped to shorthop",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

std::array entity_type_properties_flags{
    "Apply solid block beautification",
    "Treat as FLOORSTYLED",
    "Unknown",
    "Unknown",
    "Squirts blood on damage",
    "Climbable (as wall)",
    "Unknown",
    "Fireproof",
    "Double fire and explosive damage",
    "Is on fire/lights on fire",
    "Poison immunity",
    "Poisons arrows when hit",
    "Curse immunity",
    "Cursed pot effect (curses you when destroyed closeby)",
    "Unknown",
    "Unknown",
    "Unknown",
    "Can be carried through layer doors",
    "Unknown",
    "Unknown",
    "Can spawn monsters on top",
    "Unknown",
    "Can be cloned",
    "Can be bubbled",
    "Can be telefragged",
    "Disable updates?",
    "Kill entity when overlay lost?",
    "",
    "",
    "",
    "",
    "",
};

std::array level_flags{
    "Upbeat dwelling intro music played",
    "Unknown",
    "Running tutorial speedrun",
    "Level has pet",
    "Level has Tun/shop?",
    "Tun killed?",
    "Ghost pot level?",
    "Dead are restless",
    "Bees/Metal clanking/Oppression",
    "Angry shopkeeper",
    "Angry Tun",
    "Angry caveman shopkeeper",
    "Angry ghist shopkeeper",
    "Angry Yang",
    "Angry Tusk",
    "Angry Waddler",
    "Shop level?",
    "Dark level (draw halo)",
    "Altar destroyed",
    "Allow pause",
    "Hide hud, transition",
    "Hide hud, camp",
    "Have clover",
    "Show forgiveness toast",
    "Unknown",
    "Daily challenge options",
    "",
    "",
    "",
    "",
    "",
    "",
};

std::array journal_flags{
    "I was a pacifist",
    "I was a vegan",
    "I was a vegetarian",
    "I was a petty criminal",
    "I was a wanted criminal",
    "I was a crime lord",
    "I was a king",
    "I was a queen",
    "I was a fool",
    "I was an eggplant",
    "I didn't care for treasure",
    "I liked pets",
    "I loved pets",
    "I took damage",
    "I survived death once",
    "I slayed Kingu",
    "I slayed Osiris",
    "I defeated Tiamat",
    "I defeated Hundun",
    "I became one with the Cosmos",
    "I eventually died",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

std::array quest_flags{
    "Reset",
    "Dark level spawned in world",
    "Vault spawned in world",
    "Next level has shopkeeper outpost (if possible)",
    "Shop spawned",
    "Shortcut used",
    "Seeded mode",
    "Daily challenge mode",
    "Caveman Shopkeeper aggroed",
    "Waddler aggroed",
    "Shop bought out",
    "Eggplant crown picked up",
    "",
    "",
    "",
    "",
    "Udjat eye spawned",
    "Black market spawned",
    "Drill spawned",
    "",
    "",
    "",
    "",
    "",
    "Moon challenge spawned",
    "Star challenge spawned",
    "Sun challenge spawned",
    "",
    "",
    "",
    "",
    "",
};

std::array presence_flags{
    "Udjat eye",
    "Black market",
    "Vlad's castle/drill",
    "",
    "",
    "",
    "",
    "",
    "Moon challenge",
    "Star challenge",
    "Sun challenge",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

std::array illumination_flags{
    "Disable light1",
    "Enable light2",
    "Enable light3",
    "Enable light4",
    "Unknown",
    "Unknown", // always on by default
    "Modulate brightness_multiplier",
    "Unknown",
};

std::array special_visibility_flags{
    "Crust embedded items shown",
    "Crust embedded items shown (level transition)",
    "",
    "",
    "",
    "",
    "",
    "",
    "Compass door markers shown",
    "Compass door markers shown (level transition)",
    "",
    "",
    "",
    "",
    "",
    "",
    "Special compass door markers shown",
    "Special compass door markers shown (level transition)",
    "",
    "",
    "",
    "",
    "",
    "",
};

std::array basecamp_dialogue_win_flags{
    "Ana Spelunky saved",
    "Margaret Tunnel saved",
    "Colin Northward saved",
    "Roffy D. Sloth saved",
    "Alto Singh saved",
    "Liz Mutton saved",
    "Nekka The Eagle saved",
    "LISE project saved",
    "Coco Von Diamonds saved",
    "Manfred Tunnel saved",
    "Little Jay saved",
    "Tina Flan saved",
    "Valerie Crump saved",
    "Au saved",
    "Demi Von Diamonds saved",
    "Pilot saved",
    "Princess Airyn saved",
    "Dirk Yamaoka saved",
    "Tiamat win",
    "Hundun win",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

std::array places_flags{
    "Dwelling",
    "Jungle",
    "Volcana",
    "Olmec's Lair",
    "Tide Pool",
    "Abzu",
    "Temple of Anubis",
    "The City of Gold",
    "Duat",
    "Ice Caves",
    "Neo Babylon",
    "Tiamat's Throne",
    "Sunken City",
    "Eggplant World",
    "Hundun's Hideaway",
    "Cosmic Ocean",
};

std::array people_flags{
    "Ana Spelunky",
    "Margaret Tunnel",
    "Colin Northward",
    "Roffy D. Sloth",
    "Alto Singh",
    "Liz Mutton",
    "Nekka the Eagle",
    "LISE Project",
    "Coco Von Diamonds",
    "Manfred Tunnel",
    "Little Jay",
    "Tina Flan",
    "Valerie Crump",
    "Au",
    "Demi Von Diamonds",
    "Pilot",
    "Princess Airyn",
    "Dirk Yamaoka",
    "Guy Spelunky",
    "Classic Guy",
    "Terra Tunnel",
    "Hired Hand",
    "Eggplant Child",
    "Shopkeeper",
    "Tun",
    "Yang",
    "Madame Tusk",
    "Tusk's Bodyguard",
    "Waddler",
    "Caveman Shopkeeper",
    "Ghist Shopkeeper",
    "Van Horsing",
    "Parsley",
    "Parsnip",
    "Parmesan",
    "Sparrow",
    "Beg",
    "Eggplant King",
};

std::array bestiary_flags{
    "Snake",
    "Spider",
    "Bat",
    "Caveman",
    "Skeleton",
    "Horned Lizard",
    "Cave Mole",
    "Quillback",
    "Mantrap",
    "Tiki man",
    "Witch Doctor",
    "Mosquito",
    "Monkey",
    "Hang Spider",
    "Giant Spider",
    "Magmar",
    "Robot",
    "Fire Bug",
    "Imp",
    "Lavamander",
    "Vampire",
    "Vlad",
    "Olmec",
    "Jiangshi",
    "Jiangshi Assassin",
    "Flying Fish",
    "Octopy",
    "Hermit Crab",
    "Pangxie",
    "Great Humphead",
    "Kingu",
    "Crocman",
    "Cobra",
    "Mummy",
    "Sorceress",
    "Cat Mummy",
    "Necromancer",
    "Anubis",
    "Ammit",
    "Apep",
    "Anubis II",
    "Osiris",
    "UFO",
    "Alien",
    "Yeti",
    "Yeti King",
    "Yeti Queen",
    "Lahamu",
    "Proto Shopkeeper",
    "Olmite",
    "Lamassu",
    "Tiamat",
    "Tadpole",
    "Frog",
    "Fire Frog",
    "Goliath Frog",
    "Grub",
    "Giant Fly",
    "Hundun",
    "Eggplant Minister",
    "Eggplup",
    "Celestial Jelly",
    "Scorpion",
    "Bee",
    "Queen Bee",
    "Scarab",
    "Golden Monkey",
    "Leprechaun",
    "Monty",
    "Percy",
    "Poochi",
    "Ghist",
    "Ghost",
    "Cave Turkey",
    "Rock Dog",
    "Axolotl",
    "Qilin",
    "Mech Rider",
};

std::array items_flags{
    "Rope Pile",
    "Bomb Bag",
    "Bomb Box",
    "Paste",
    "Spectacles",
    "Climbing Gloves",
    "Pitcher's Mitt",
    "Spring Shoes",
    "Spike Shoes",
    "Compass",
    "Alien Compass",
    "Parachute",
    "Udjat Eye",
    "Kapala",
    "Hedjet",
    "Crown",
    "Eggplant Crown",
    "The True Crown",
    "Ankh",
    "Tablet of Destiny",
    "Skeleton Key",
    "Royal Jelly",
    "Cape",
    "Vlad's Cape",
    "Jetpack",
    "Telepack",
    "Hoverpack",
    "Powerpack",
    "Webgun",
    "Shotgun",
    "Freeze Ray",
    "Clone Gun",
    "Crossbow",
    "Camera",
    "Teleporter",
    "Mattock",
    "Boomerang",
    "Machete",
    "Excalibur",
    "Broken Sword",
    "Plasma Cannon",
    "Scepter",
    "Hou Yi's Bow",
    "Arrow of Light",
    "Wooden Shield",
    "Metal Shield",
    "Idol",
    "The Tusk Idol",
    "Curse Pot",
    "Ushabti",
    "Eggplant",
    "Cooked Turkey",
    "Elixir",
    "Four-Leaf Clover",
};

std::array traps_flags{
    "Spikes",
    "Arrow Trap",
    "Totem Trap",
    "Log Trap",
    "Spear Trap",
    "Thorny Vine",
    "Bear Trap",
    "Powder Box",
    "Falling Platform",
    "Spikeball",
    "Lion Trap",
    "Giant Clam",
    "Sliding Wall",
    "Crush Trap",
    "Giant Crush Trap",
    "Boulder",
    "Spring Trap",
    "Landmine",
    "Laser Trap",
    "Spark Trap",
    "Frog Trap",
    "Sticky Trap",
    "Bone Drop",
    "Egg Sac",
};

std::array shortcut_flags{
    "None",
    "Met Terra",
    "1-4: $2,000",
    "1-4: Bomb",
    "1-4: $10,000 (Unlocked)",
    "3-1: Rope",
    "3-1: Weapon",
    "3-1: Mount (Unlocked)",
    "5-1: $50,000",
    "5-1: Hired Hand",
    "5-1: Golden Key (Unlocked)",
};

std::array button_flags{
    "Jp",
    "Wp",
    "Bm",
    "Rp",
    "Rn",
    "Dr",
};
std::array direction_flags{
    "Left",
    "Down",
    "Up",
    "Right",
};

std::array liquid_pool_names{
    "Water",
    "Coarse Water",
    "Lava",
    "Coarse Lava",
    "Stagnant Lava",
};

std::array mask_names{
    "Player",
    "Mount",
    "Monster",
    "Item",
    "Explosion",
    "Rope",
    "FX",
    "ActiveFloor",
    "Floor",
    "Decoration",
    "Background",
    "Shadow",
    "Logical",
    "Water",
    "Lava",
};

std::array char_states{
    "Flailing",
    "Standing",
    "Sitting",
    "???",
    "Hanging",
    "Ducking",
    "Climbing",
    "Pushing",
    "Jumping",
    "Falling",
    "Dropping",
    "???",
    "Attacking",
    "???",
    "???",
    "???",
    "???",
    "Throwing",
    "Stunned",
    "Entering",
    "Loading",
    "Exiting",
    "Dying",
};

std::array screen_names{
    "Logo",
    "Intro",
    "Prologue",
    "Title",
    "Menu",
    "Options",
    "Player Profile",
    "Leaderboard",
    "Seed Input",
    "Character Select",
    "Team Select",
    "Camp",
    "Level",
    "Transition",
    "Death",
    "Spaceship",
    "Win",
    "Credits",
    "Scores",
    "Constellation",
    "Recap",
    "Arena Menu",
    "Arena Stages",
    "Arena Items",
    "Arena Select",
    "Arena Intro",
    "Arena Level",
    "Arena Score",
    "Online Loading",
    "Online Lobby",
};

std::array pause_types{
    "Menu",
    "Fade",
    "Cutscene",
    "",
    "",
    "Ankh",
    "Freeze updates (game state)",           // this is not a real state.pause flag, only used by PauseAPI
    "Freeze game loop (game state + menus)", // this is not a real state.pause flag, only used by PauseAPI
    "Freeze input (for menu frame advance)", // this is not a real state.pause flag, only used by PauseAPI
    "Enforce state flags",                   // this is not a real state.pause flag, only used by PauseAPI
};

std::array pause_screens{
    "Logo",
    "Intro",
    "Prologue",
    "Title",
    "Menu",
    "Options",
    "Player Profile",
    "Leaderboard",
    "Seed Input",
    "Character Select",
    "Team Select",
    "Camp",
    "Level",
    "Transition",
    "Death",
    "Spaceship",
    "Win",
    "Credits",
    "Scores",
    "Constellation",
    "Recap",
    "Arena Menu",
    "Arena Stages",
    "Arena Items",
    "Arena Select",
    "Arena Intro",
    "Arena Level",
    "Arena Score",
    "Online Loading",
    "Online Lobby",
    "Loading, fades, etc.",
    "Exiting level",
};

std::array pause_triggers{
    "Fade start",
    "Fade end",
    "Screen loaded",
    "Exit level",
    "Trigger only once",
};

std::array levelgen_flags{
    "Should generate path",
    "Can spawn vault",
    "Can spawn shops",
    "Can have outpost?",
    "Should spawn hard floor decorations",
    "Apply ambient occlusion",
    "Should spawn behind-floor and below-floorstyled decorations",
    "Unknown",
};

std::array levelgen_flags2{
    "Spawns background decorations on ground (ceiling if false)",
    "Spawns fake ladder/chain midbg?",
    "Spawn entrance door background (Ignored in 7-1 to 7-2 transition)",
    "Procedural backlayer door midbg indicator related",
    "Spawn backlayer border/background",
    "Should spawn procedural backlayers",
    "Should spawn backlayer torches",
    "Has ghost",
};

std::array levelgen_flags3{
    "Can spawn angry NPCs",
    "Can echo",
    "Can spawn Dead are Restless",
    "Can spawn procedural skeletons",
    "Can have quests?",
    "Can spawn player coffins",
    "Unknown",
    "Unknown",
};

std::array level_chances{
    "backroom",
    "backroom interconnect",
    "backroom hidden door",
    "backroom hidden cache",
    "mount",
    "altar",
    "idol",
    "floor side spread",
    "floor bottom spread",
    "background",
    "ground background",
    "bigroom",
    "wideroom",
    "tallroom",
    "rewardroom",
};

std::array renderer_flags1{
    "Floor background shadows",
    "Emissive lighting",
    "Shockwaves, some shadows",
    "unknown",
    "unknown",
    "unknown",
    "Liquid smoothing",
    "unknown",
};

std::array player_inputs{
    "Disabled",
    "Keyboard 1",
    "Keyboard 2",
    "Keyboard 3",
    "Keyboard 4",
    "XInput 1",
    "XInput 2",
    "XInput 3",
    "XInput 4",
    "Controller 1",
    "Controller 2",
    "Controller 3",
    "Controller 4",
};

std::unordered_set<std::string> legal_options{
    "disable_ghost_timer",
    "disable_pause",
    "draw_entity_info",
    "draw_entity_tooltip",
    "draw_grid",
    "draw_hitboxes",
    "draw_hitboxes_interpolated",
    "draw_hotbar",
    "draw_hud",
    "draw_path",
    "draw_script_messages",
    "fade_script_messages",
    "fly_mode",
    "god_mode",
    "god_mode_companions",
    "hd_cursor",
    "keyboard_control",
    "lights",
    "mouse_control",
    "noclip",
    "smooth_camera",
    "pause_type",
    "pause_update_camera",
    "pause_last_instance",
    "pause_loading",
    "paused",
    "skip",
    "camera_hack",
};
