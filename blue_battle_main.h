#define MAX_Y 160
#define MAX_X 240

void blue_battle_main ( int s_cyc, int e_cyc ) {

  int down = 0;
  int py = MAX_Y / 2, px = MAX_X / 2, cpy = py, cpx = px;
  int cap_y = 40, cyc = s_cyc, cap_lim = 0;
  int smax = 15; /// sleep-ul maxim cu care urca player-ul ( atins numai la cap_y )
  int smax_dwn = 7; /// sleep-ul maxim cu care coboara player-ul ( atins numai la cap_y )
  int i;

  drawModel ( py, px, 5, 5, player, 0, 0, 31 );

  while( cyc < e_cyc ) { /// forever

    if ( isKeyPressed( KEY_UP ) == 1 && down == 0 && cap_lim < 20 ) {
      py -= 2;
      if ( py <= cap_y ) {
        py = cap_y;
        cap_lim++;
      }

      _sleep ( smax * ( MAX_Y - py ) / ( MAX_Y - cap_y ) );
      drawModel( 150, 230, 10, 10, fontTerminal[smax * ( MAX_Y - py ) / ( MAX_Y - cap_y )], 31, 31, 31 );
      /// inca apasa in sus
    }
    else
      down = 1; /// incep coborarea

    if ( isKeyPressed( KEY_DOWN ) == 1 && py + 5 < MAX_Y - 1 )
      py++;

    if ( isKeyPressed( KEY_LEFT ) == 1 && px > 0 ) {
      px--;
      px -= ( px > 0 && down == 1 );
      _sleep ( 5 );
    }

    if ( isKeyPressed( KEY_RIGHT ) == 1 && px + 5 < MAX_X - 1 ) {
      px++;
      px += ( px < MAX_X - 1 && down == 1 );
      _sleep ( 5 );
    }

    if ( cpy != py || cpx != px ) {
      _sleep ( 9 );
      clearScreen ( 0, 0, 0, cpy, cpx, 5, 5 );
      cpy = py;
      cpx = px;
      drawModel ( py, px, 5, 5, player, 0, 0, 31 );
    }

    _sleep ( 12 );

    if ( down == 1 ) { /// daca nu mai apasa incep cobor
      if ( py >= MAX_Y - 5 ) {
        down = 0;
        cap_lim = 0;
      }
      else {
        py++;
        _sleep ( smax_dwn * ( MAX_Y - py ) / ( MAX_Y - cap_y ) );
        drawModel( 150, 230, 10, 10, fontTerminal[smax_dwn * ( MAX_Y - py ) / ( MAX_Y - cap_y )], 0, 31, 31 );
      }
    }

    /// misc obstacolele
    for ( i = 0; i < NBONES; i++ )
      if ( cyc == boneTxt[i][6] )
        clearScreen ( 31, 31 ,31, boneTxt[i][1], boneTxt[i][2], boneTxt[i][3], boneTxt[i][4] );
      else if ( cyc > boneTxt[i][6] && cyc < boneTxt[i][6] + boneTxt[i][7] ) {
        clearScreen ( 0, 0, 0, boneTxt[i][1], boneTxt[i][2], boneTxt[i][3], boneTxt[i][4] );
        boneTxt[i][2] += boneTxt[i][5];
        clearScreen ( 31, 31, 31, boneTxt[i][1], boneTxt[i][2], boneTxt[i][3], boneTxt[i][4] );
      }
      else if ( cyc == boneTxt[i][6] + boneTxt[i][7] )
        clearScreen ( 0, 0, 0, boneTxt[i][1], boneTxt[i][2], boneTxt[i][3], boneTxt[i][4] );

    cyc++;
  }

}
