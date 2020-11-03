#define MAX_Y 160
#define MAX_X 240
                      /// start cycle, how many cycles
void green_battle_main ( int s_cyc, int e_cyc ) {
  int py, px;

  py = MAX_Y / 2;
  px = MAX_X / 2;

  drawModel ( py - 13, px - 13, 31, 31, _case, 31, 31, 31 );
  drawModel ( py, px, 5, 5, player, 0, 31, 0 );

  int pos = 0, cyc = s_cyc, i, end = 0;

  while ( cyc < s_cyc + e_cyc && end < 3 ) {

    drawModel ( 0, 110, 10, 10, fontNumbers[3-end], 31, 31, 31 );
    drawModel ( 0, 120, 10, 10, fontAdditional[DEF_PCT], 31, 31, 31 );
    drawModel ( 0, 130, 10, 10, fontNumbers[3], 31, 31, 31 );

    if ( isKeyPressed( KEY_UP ) == 1 ) {
      clearScreen( 0, 0, 0, wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1] );
      pos = GREEN_BATTLE_UP;
      drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsUD[pos], 0, 0, 31 );
    }
    if ( isKeyPressed( KEY_DOWN ) == 1 ) {
      clearScreen( 0, 0, 0, wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1] );
      pos = GREEN_BATTLE_DOWN;
      drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsUD[pos], 0, 0, 31 );
    }
    if ( isKeyPressed( KEY_LEFT ) == 1 ) {
      clearScreen( 0, 0, 0, wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1] );
      pos = GREEN_BATTLE_LEFT;
      drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsLR[pos-2], 0, 0, 31 );
    }
    if ( isKeyPressed( KEY_RIGHT ) == 1 ) {
      clearScreen( 0, 0, 0, wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1] );
      pos = GREEN_BATTLE_RIGHT;
      drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsLR[pos-2], 0, 0, 31 );
    }

    for ( i = 0; i < NARROWS; i++ ) {
      if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_DOWN &&
            pos != GREEN_BATTLE_UP && arrowTxt[i][5] > 68 ) {
        //drawModel ( 150, 230, 10, 10, fontTerminal[0], 31, 31, 31 );
        end++;
        arrowTxt[i][7] = ARROW_NO;
      }
      else if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_DOWN &&
            pos == GREEN_BATTLE_UP && arrowTxt[i][5] > 68  ) {

        arrowTxt[i][7] = ARROW_NO;

        drawModel ( py - 13, px - 13, 31, 31, _case, 31, 31, 31 );
        drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsUD[pos], 0, 0, 31 );
        drawModel ( py, px, 5, 5, player, 0, 31, 0 );
      }
      ///----------------
      if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_UP &&
            pos != GREEN_BATTLE_DOWN && arrowTxt[i][5] < 92 ) {
        //drawModel ( 150, 230, 10, 10, fontTerminal[1], 31, 31, 31 );
        end++;
        arrowTxt[i][7] = ARROW_NO;
      }
      else if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_UP &&
            pos == GREEN_BATTLE_DOWN && arrowTxt[i][5] < 92 ) {
        arrowTxt[i][7] = ARROW_NO;

        drawModel ( py - 13, px - 13, 31, 31, _case, 31, 31, 31 );
        drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsUD[pos], 0, 0, 31 );
        drawModel ( py, px, 5, 5, player, 0, 31, 0 );
      }
      ///----------------
      if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_LEFT &&
            pos != GREEN_BATTLE_RIGHT && arrowTxt[i][6] < 132 ) {
        //drawModel ( 150, 230, 10, 10, fontTerminal[2], 31, 31, 31 );
        end++;
        arrowTxt[i][7] = ARROW_NO;
      }
      else if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_LEFT &&
            pos != GREEN_BATTLE_RIGHT && arrowTxt[i][6] < 132 ) {
        arrowTxt[i][7] = ARROW_NO;

        drawModel ( py - 13, px - 13, 31, 31, _case, 31, 31, 31 );
        drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsLR[pos-2], 0, 0, 31 );
        drawModel ( py, px, 5, 5, player, 0, 31, 0 );
      }
      ///----------------
      if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_RIGHT &&
            pos != GREEN_BATTLE_LEFT && arrowTxt[i][6] > 108 ) {
        //drawModel ( 150, 230, 10, 10, fontTerminal[3], 31, 31, 31 );
        end++;
        arrowTxt[i][7] = ARROW_NO;
      }
      else if ( arrowTxt[i][7] == ARROW_OK && arrowTxt[i][0] == GREEN_BATTLE_RIGHT &&
            pos != GREEN_BATTLE_LEFT && arrowTxt[i][6] > 108 ) {
        arrowTxt[i][7] = ARROW_NO;

        drawModel ( py - 13, px - 13, 31, 31, _case, 31, 31, 31 );
        drawModel( wallsPos[pos][0], wallsPos[pos][1], wallsSize[pos][0], wallsSize[pos][1], wallsLR[pos-2], 0, 0, 31 );
        drawModel ( py, px, 5, 5, player, 0, 31, 0 );
      }
    }


    for ( i = 0; i < NARROWS; i++ ) {
      if ( arrowTxt[i][1] == cyc ) { /// trebuie sa afisez
        drawModel ( arrowSpawn[arrowTxt[i][0]][0], arrowSpawn[arrowTxt[i][0]][1],
                    5, 5, arrows[arrowTxt[i][0]], 31, 31, 31
                  );
        arrowTxt[i][7] = ARROW_OK;
      }
      else if ( arrowTxt[i][1] < cyc && cyc < arrowTxt[i][1] + arrowTxt[i][2] && arrowTxt[i][7] == ARROW_OK ) {
        /// trebuie sa mut tinta
        //drawModel( 0, 0, 10, 10, fontTerminal[i], 31, 31, 31 );
        clearScreen( 0, 0, 0, arrowTxt[i][5], arrowTxt[i][6], 5, 5 );
        arrowTxt[i][5] += arrowTxt[i][3]; /// adun pe Y
        arrowTxt[i][6] += arrowTxt[i][4]; /// adun pe X
        drawModel ( arrowTxt[i][5], arrowTxt[i][6], 5, 5, arrows[arrowTxt[i][0]], 31, 31, 31 );
      }
      else if ( cyc == arrowTxt[i][1] + arrowTxt[i][2] ) { /// trebuie sa sterg tinta
        clearScreen( 0, 0, 0, arrowTxt[i][5], arrowTxt[i][6], 5, 5 );
        arrowTxt[i][7] = ARROW_NO;
      }
    }

    cyc += ( end < 3 ); /// cresc numarul de cicluri
  }

  if ( end == 3 ) {
    drawModel ( 0, 110, 10, 10, fontNumbers[0], 31, 31, 31 );
    drawModel ( 0, 120, 10, 10, fontAdditional[DEF_PCT], 31, 31, 31 );
    drawModel ( 0, 130, 10, 10, fontNumbers[3], 31, 31, 31 );
  }
  else {
    clearScreen ( 31, 0, 31, 0, 0, MAX_Y, MAX_X );
    drawText ( 80, 0, 10, 10, 9, "you won !", 20 );
    drawModel ( 0, 110, 10, 10, fontNumbers[3-end], 31, 31, 31 );
    drawModel ( 0, 120, 10, 10, fontAdditional[DEF_PCT], 31, 31, 31 );
    drawModel ( 0, 130, 10, 10, fontNumbers[3], 31, 31, 31 );
  }

}

