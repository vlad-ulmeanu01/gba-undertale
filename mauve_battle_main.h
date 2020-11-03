#define MAX_Y 160 /// oY
#define MAX_X 240 /// oX

///                     start cycle, how many cycles
void mauve_battle_main ( int s_cyc, int e_cyc ) {

  int cyc = s_cyc, end = 0; /// end -> nr. de vieti irosite
  int i, j;

  drawModel ( 0, 0, 10, 10, fontNumbers[3], 31, 31, 31 );
  drawText( 0, 15, 10, 10, 5, "lives", 0 );

  /// draw 3 web lines
  for ( i = 0; i < 3; i++ )
    for ( j = 0; j < MAX_X; j++ )
      drawPixel( mauve_ln[i], j, 31, 0, 31 );

  int py = MAX_Y / 2 - 2, px = MAX_X / 2 - 2, line = 1;
  int spc = 0; /// spider count

  drawModel( py, px, 5, 5, player, 31, 0, 31 );

  while ( cyc < s_cyc + e_cyc && end < 3 ) {

    if ( isKeyPressed ( KEY_LEFT ) == 1 && px > 0 ) {
      drawModel( py, px, 5, 5, emptyln, 31, 0, 31 );
      px--;
      drawModel( py, px, 5, 5, player, 31, 0, 31 );
      _sleep ( 15 );
    }
    if ( isKeyPressed ( KEY_RIGHT ) == 1 && px < MAX_X - 5 ) {
      drawModel( py, px, 5, 5, emptyln, 31, 0, 31 );
      px++;
      drawModel( py, px, 5, 5, player, 31, 0, 31 );
      _sleep ( 15 );
    }
    if ( isKeyPressed( KEY_UP ) == 1 && line > 0 ) {
      drawModel( py, px, 5, 5, emptyln, 31, 0, 31 );
      line--;
      py = mauve_ln[line] - 2;
      drawModel( py, px, 5, 5, player, 31, 0, 31 );
      _sleep ( 170 );
    }
    if ( isKeyPressed( KEY_DOWN ) == 1 && line < 2 ) {
      drawModel( py, px, 5, 5, emptyln, 31, 0, 31 );
      line++;
      py = mauve_ln[line] - 2;
      drawModel( py, px, 5, 5, player, 31, 0, 31 );
      _sleep ( 170 );
    }

    /// pun paianjenii
    while ( spc < NSPIDERS && spiderTxt[spc][1] + s_cyc == cyc ) {
      if ( spiderTxt[spc][0] == 0 ) {
        spiderTxt[spc][5] = mauve_ln[ spiderTxt[spc][2] ] - 2;
        spiderTxt[spc][6] = 0;
        drawModel ( spiderTxt[spc][5], spiderTxt[spc][6], 5, 5, spider, 31, 31, 31 );
      }
      else {
        spiderTxt[spc][5] = mauve_ln[ spiderTxt[spc][2] ] - 2;
        spiderTxt[spc][6] = MAX_X - 5;
        drawModel ( spiderTxt[spc][5], spiderTxt[spc][6], 5, 5, spider, 31, 31, 31 );
      }
      spc++;
    }

    /// ii misc

    if ( ( cyc - s_cyc ) % 10 == 0 ) {
      for ( i = 0; i < spc; i++ ) {
        if ( spiderTxt[i][4] == 0 && abs ( spiderTxt[i][5] - py ) <= 5 && abs ( spiderTxt[i][6] - px ) <= 5 ) {
          spiderTxt[i][4] = 2;
          end++;
          drawModel ( 0, 0, 10, 10, fontNumbers[3-end], 31, 31, 31 );
        }

        if ( spiderTxt[i][4] == 0 || spiderTxt[i][4] == 2 ) { /// e ok
          drawModel ( spiderTxt[i][5], spiderTxt[i][6], 5, 5, emptyln, 31, 0, 31 );
          spiderTxt[i][6] += spiderTxt[i][3];
          if ( spiderTxt[i][6] < MAX_X - 5 && spiderTxt[i][6] >= 0 )
            drawModel ( spiderTxt[i][5], spiderTxt[i][6], 5, 5, spider, 31, 31, 31 );
          else
            spiderTxt[i][4] = 1;
        }
      }
      _sleep ( 50 );
    }

    cyc++;
  }
}
