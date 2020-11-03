#define NSPIDERS 6

int mauve_ln[3] = { 35, 80, 125 };

/// 0 sens, 1 ciclu start, 2 linie, 3 viteza ( unitati / ciclu ), 4 valabil, 5 y curr, 6 x curr
int spiderTxt[NSPIDERS][7] = {
  { 0,  40, 0,   5, 0, 0, 0 },
  { 1, 110, 2, -10, 0, 0, 0 },
  { 1, 180, 1, -15, 0, 0, 0 },
  { 0, 250, 2,   5, 0, 0, 0 },
  { 1, 320, 0, -10, 0, 0, 0 },
  { 0, 390, 1,  15, 0, 0, 0 }
};
