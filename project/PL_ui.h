#ifndef _PL_UI_H_
#define _PL_UI_H_

extern void welcome_screen();
extern void show_menu();
extern void clearscr(void);
extern int readchar(void);

player_t G_players[2];
game_t G_current_game;
current_move_t cmp;
position_t pos;
#endif
