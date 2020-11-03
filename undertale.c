/* undertale.c - Gameboy Advance - Vlad */
#include <stdio.h>
#include <math.h>
#include "fonts.h"
#include "keypad.h"
#include "flowey.h"
#include "models.h"
#include "red_battle_main.h"
#include "green_battle.script.h"
#include "green_battle_main.h"
#include "blue_battle.script.h"
#include "blue_battle_main.h"
#include "mauve_battle.script.h"
#include "mauve_battle_main.h"
#include "picpalette.h"

#define RGB16(r,g,b)  ((r)+((g)<<5)+((b)<<10))
#define MAX_Y 160 /// linia
#define MAX_X 240 /// coloana
#define OPS 125000

//#define REG_DISPCNT    *(u32*)0x4000000
//#define MODE_4 0x4
//#define BG2_ENABLE 0x400

u16* paletteMem = (u16*)0x5000000;	/// Pal is 256 16 bit BGR
u16* videoBuffer = (u16*)0x6000000; /// video memory

int ys, xs;

char isKeyPressed ( short val ) {
  return ( !( (*KEYS) & val ) );
  /// va returna 1 daca cheia respectiva a fost apasata, sau 0 daca nu
}

void _sleep ( int s ) { /// programul "doarme" pentru s milisecunde
  /// procesorul are 16.7 MHz <=> face cam 125 000 de op/s
  int i, n = s * OPS;

  for ( i = 0; i < n; i += 1000 );
}

void drawPixel ( unsigned char i, unsigned char j, char _r, char _g, char _b ) {
  u16* Screen = (u16*)0x6000000;
	*(u32*)0x4000000 = 0x403; /// mode 3, bg2 on

  Screen[j+i*240] = RGB16( _r, _g, _b );
}

void clearScreen ( char _r, char _g, char _b, int y, int x, int l, int c ) {
  int i, j;

  for ( i = y; i < y + l; i++ )
    for ( j = x; j < x + c; j++ )
      drawPixel ( i, j, _r, _g, _b );
}

void drawModel ( int y, int x, int l, int c, char name[l][c], char _r, char _g, char _b ) {
  int i, j;

  for ( i = y; i < y + l; i++ )
    for ( j = x; j < x + c; j++ )
      if ( name[i-y][j-x] == '#' )
        drawPixel ( i, j, _r, _g, _b );
      else
        drawPixel ( i, j, 0, 0, 0 );
}

void decodeChar ( char ch, int y, int x, int l, int c ) {

  if ( ch >= 'a' && ch <= 'z' )
      drawModel ( y, x, l, c, fontTerminal[ch-'a'], 31, 31, 31 );
  else {
    switch ( ch ) {
      case ' ' :
        drawModel ( y, x, l, c, fontAdditional[DEF_SPC], 31, 31, 31 );
        break;

      case ',' :
        drawModel ( y, x, l, c, fontAdditional[DEF_VIR], 31, 31, 31 );
        break;

      case '.' :
        drawModel ( y, x, l, c, fontAdditional[DEF_PCT], 31, 31, 31 );
        break;

      case '?' :
        drawModel ( y, x, l, c, fontAdditional[DEF_INT], 31, 31, 31 );
        break;

      case '!' :
        drawModel ( y, x, l, c, fontAdditional[DEF_EXL], 31, 31, 31 );
        break;
    }
  }
}

void drawText ( int y, int x, int l, int c, int len, char string[len], int stime ) {
  int k;

  for ( k = 0; k < len; k++, x += c, _sleep ( stime ) )
    decodeChar ( string[k], y, x, l, c );
}

void drawTextInBox ( int len, char string[len], int stime, int l, int c, int y, int x ) {
  int nlot = len / ( c / 10 ); /// cate loturi de c / 10 am de afisat
  int i, j, k, n = 0, cy = y, cx = x;
  char bpres = 0; /// daca a fost apasat KEY_B, atunci nu mai dorm pentru randul respectiv

  k = 0;
  while ( k <= nlot && n <= len ) {
    i = 0;
    while ( i < l / 10 && n <= len ) { /// cate linii am de afisat
      j = 0;
      while ( j < c / 10 && n <= len ) { /// cate coloane am de afisat
        decodeChar ( string[n], y, x, 10, 10 ); /// afisez pe coloana

        j++; /// cresc contorul pentru coloana
        n++; /// cresc contorul pentru caractere
        x += 10; /// cresc coloana de unde va incepe afisarea urmatorului model

        if ( isKeyPressed ( KEY_B ) == 1 )
          bpres = 1;

        if ( bpres == 0 )
          _sleep ( stime );
      }
      i++; /// cresc contorul pentru linie
      y += 10; /// cresc linia de unde va incepe afisarea urmatorului model
      x = cx; /// resetez coloana de unde va incepe afisarea urmatorului model
    }

    while ( isKeyPressed ( KEY_A ) == 0 )
      ;

    clearScreen ( 0, 0, 0, cy, cx, l, c );

    k++; /// cresc numarul de loturi afisate
    y = cy; x = cx; /// resetez linia si coloana
    bpres = 0; /// resetez apasarea cheii KEY_B
  }
}

double dist ( double i1, double j1, double i2, double j2 ) { ///:(
  return sqrt ( ( i2 - i1 ) * ( i2 - i1 ) + ( j2 - j1 ) * ( j2 - j1 ) );
}

/// de unde pana unde in np pasi
int goRoad ( int k, int ns, int ye, int xe, int py, int px, int np, int stime ) {
  int addY = ye - ys, addX = xe - xs, e = k + ns; /// diferenta dintre end si start
  int rY = addY / np, rX = addX / np;

  for ( ;k < np && k < e && dist ( ys, xs, py, px ) > 5; k++ ) {
    clearScreen ( 0, 0, 0, ys, xs, 5, 5 );
    ys += rY;
    xs += rX;
    drawModel ( ys, xs, 5, 5, bullet, 31, 31, 31 );
    _sleep ( stime );
  }

  if ( k < np && k < e )
    return -1;
  else
    return e;
}

int main() {
 	char x, y;

	/// clear screen, and draw a black background
	clearScreen ( 0, 0, 0, 0, 0, MAX_Y, MAX_X );

  drawModel ( 25, 65, 88, 85, floweyHappy, 31, 31, 31 );
  drawTextInBox ( 265, "howdy ! i am flowey the flower ! you are new here, arentcha ? well, someone has to teach you how things work around here ! golly, i guess little old me ought to do ! in this world, we share love through little white .friendliness pellets. i.ll share sone with you !" , 110, 20, 220, 130, 10 );

  while ( isKeyPressed ( KEY_A ) == 0 );

  clearScreen ( 0, 0, 0, 0, 0, MAX_Y, MAX_X );

  int py = 80, px = 120, cpy = py, cpx = px;
  int g1 = 0, k = 0;

  drawModel ( py, px, 5, 5, player, 31, 0, 0 );

	while( k != -1 && k < 40 ) { /// while there are no collisions
    if ( isKeyPressed( KEY_UP ) == 1 && py > 0 )
      py--;
    if ( isKeyPressed( KEY_DOWN ) == 1 && py + 5 < MAX_Y - 1 )
      py++;
    if ( isKeyPressed( KEY_LEFT ) == 1 && px > 0 )
      px--;
    if ( isKeyPressed( KEY_RIGHT ) == 1 && px + 5 < MAX_X - 1 )
      px++;

    if ( cpy != py || cpx != px ) {
      clearScreen ( 0, 0, 0, cpy, cpx, 5, 5 );
      cpy = py;
      cpx = px;
      drawModel ( py, px, 5, 5, player, 31, 0, 0 );
    }

    if ( g1 == 0 )
      k = goRoad ( k, 2, 160, 240, py, px, 40, 20 );
    if ( k == 40 || k == -1 )
      g1 = 1;

    _sleep ( 12 );
	}

  if ( k == -1 ) {
    clearScreen ( 31, 0, 0, 0, 0, MAX_Y, MAX_X );
    drawText ( 50, 0, 10, 10, 18, "kill or be killed!", 25 );
  }
  else {
    clearScreen ( 0, 0, 0, 0, 0, MAX_Y, MAX_X );

    drawTextInBox ( 85, "click .up. to get red, .down. to get blue, right to get green or left to get mauve !", 90, 20, 220, 50, 10 );

    int cu = 0, cd = 0, cr = 0, cl = 0;

    while ( cu == 0 && cd == 0 && cr == 0 && cl == 0 ) {
      if ( isKeyPressed ( KEY_UP ) == 1 )
        cu = 1;
      else if ( isKeyPressed ( KEY_DOWN ) == 1 )
        cd = 1;
      else if ( isKeyPressed ( KEY_RIGHT ) == 1 )
        cr = 1;
      else if ( isKeyPressed ( KEY_LEFT ) == 1 )
        cl = 1;
    }

    clearScreen ( 0, 0, 0, 50, 10, 70, 230 );

    if ( cu == 1 ) { /// rosu
      red_battle_main ();
    }
    else if ( cd == 1 ) { /// albastru
      blue_battle_main ( 0, 250 );
      while ( 1 ) {}
    }
    else if ( cr == 1 ) { /// verde
      green_battle_main ( 0, 950 );
      while ( 1 ) {}
    }
    else { /// mov -- purple
      mauve_battle_main ( 0, 1000 );
      while ( 1 ) {}
    }

  }

  while ( 1 ) {}
}
