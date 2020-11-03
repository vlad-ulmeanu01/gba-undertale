#define NARROWS 32
#define ARROW_OK 0
#define ARROW_NO 1

int yup = 155, xup = 120;
int ydn = 0, xdn = 120;
int yle = 80, xle = 200;
int yri = 80, xri = 40;

/// skin 0, cycle 1, num. cycles 2, adv_per_cycleY 3, adv_per_cycleX 4, posY 5, posX 6, end 7
int arrowTxt[NARROWS][8] = {
 { GREEN_BATTLE_UP, 0, 70, -1, 0, 155, 120, 1 },
 { GREEN_BATTLE_DOWN, 30, 70, 1, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 60, 70, 0, -1, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 90, 70, 0, 1, 80, 40, 1 },
 { GREEN_BATTLE_RIGHT, 105, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_UP, 120, 36, -2, 0, 155, 120, 1 },
 { GREEN_BATTLE_DOWN, 150, 36, 2, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 180, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 210, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_UP, 240, 36, -2, 0, 155, 120, 1 },
 { GREEN_BATTLE_DOWN, 270, 36, 2, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 300, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 330, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_UP, 360, 36, -2, 0, 155, 120, 1 },
 { GREEN_BATTLE_DOWN, 390, 36, 2, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 420, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 450, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_UP, 480, 36, -2, 0, 155, 120, 1 },
 { GREEN_BATTLE_DOWN, 510, 36, 2, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 540, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 570, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_DOWN, 600, 36, 2, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 630, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 660, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_UP, 690, 36, -2, 0, 155, 120, 1 },
 { GREEN_BATTLE_LEFT, 720, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 750, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_DOWN, 780, 36, 2, 0, 0, 120, 1 },
 { GREEN_BATTLE_LEFT, 810, 36, 0, -2, 80, 200, 1 },
 { GREEN_BATTLE_RIGHT, 840, 36, 0, 2, 80, 40, 1 },
 { GREEN_BATTLE_UP, 870, 36, -2, 0, 155, 120, 1 },
 { GREEN_BATTLE_LEFT, 910, 36, 0, -2, 80, 200, 1 }
};
