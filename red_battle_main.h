#define MAX_Y 160
#define MAX_X 240

void red_battle_main ( ) {

  int py = MAX_Y / 2, px = MAX_X / 2, cpy = py, cpx = px;

  drawModel ( py, px, 5, 5, player, 31, 0, 0 );

  while( 1 ) { /// while there are no collisions
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

    _sleep ( 12 );
  }
}
