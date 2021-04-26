#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>
extern const int ROW ;
extern const int COLUMN ;
extern const int WINDOW_WIDTH ;
extern const int WINDOW_HEIGHT ;

extern const int START_BUTTON_WIDTH ;
extern const int START_BUTTON_HEIGHT ;
extern const int QUIT_BUTTON_WIDTH ;
extern const int QUIT_BUTTON_HEIGHT ;
extern const int REPLAY_BUTTON_WIDTH ;
extern const int REPLAY_BUTTON_HEIGHT ;
extern const int QUITGAME_BUTTON_WIDTH ;
extern const int QUITGAME_BUTTON_HEIGHT ;
extern const int SCORE_BOARD_WIDTH ;
extern const int SCORE_BOARD_HEIGHT;
extern const int YOURSCORE_BUTTON_WIDTH ;
extern const int YOURSCORE_BUTTON_HEIGHT ;
extern const int HIGHSCORE_BUTTON_WIDTH ;
extern const int HIGHSCORE_BUTTON_HEIGHT ;
extern const int TEXT_BAR_WIDTH ;
extern const int TEXT_BAR_HEIGHT ;


extern const int START_BUTTON_POSX ;
extern const int START_BUTTON_POSY ;
extern const int QUIT_BUTTON_POSX ;
extern const int QUIT_BUTTON_POSY ;
extern const int REPLAY_BUTTON_POSX ;
extern const int REPLAY_BUTTON_POSY ;
extern const int QUITGAME_BUTTON_POSX ;
extern const int QUITGAME_BUTTON_POSY ;
extern const int NEXTSHAPE_POSX ;
extern const int NEXTSHAPE_POSY ;
extern const int SCORE_BOARD_POSX ;
extern const int SCORE_BOARD_POSY ;
extern const int YOURSCORE_BUTTON_POSX ;
extern const int YOURSCORE_BUTTON_POSY  ;
extern const int HIGHSCORE_BUTTON_POSX ;
extern const int HIGHSCORE_BUTTON_POSY ;
extern const int YOURSCORE_BOARD_POSX ;
extern const int YOURSCORE_BOARD_POSY ;
extern const int TEXT_BAR_POSX ;
extern const int TEXT_BAR_POSY ;
extern const int UNIT ;
extern const char* TITLE ;
extern int Board[20][10] ;

extern SDL_Window* window ;
extern SDL_Renderer* renderer ;

extern SDL_Texture* menu_background ;
extern SDL_Texture* layout_1 ;
extern SDL_Texture* layout_2 ;
extern SDL_Texture* tile_texture ;
extern SDL_Texture* high_light ;
extern SDL_Texture* shadow ;
extern SDL_Texture* start_button_texture_1 ;
extern SDL_Texture* start_button_texture_2 ;
extern SDL_Texture* quit_button_texture_1 ;
extern SDL_Texture* quit_button_texture_2 ;
extern SDL_Texture* replay_button_texture_1 ;
extern SDL_Texture* replay_button_texture_2 ;
extern SDL_Surface* surface ;
extern SDL_Texture* score_texture ;
extern SDL_Texture* yourscore_texture ;
extern SDL_Texture* highscore_texture ;
extern SDL_Texture* text_bar_texture ;
//extern TTF_Font* font ;
//extern SDL_Color   color ;

extern  int score ;

extern SDL_Rect score_board ;
extern SDL_Rect* current_color ;
extern SDL_Rect  Color[8] ;

//define color //
extern const int PINK ;
extern const int BLUE ;
extern const int GREEN1 ;
extern const int GREEN2 ;
extern const int RED ;
extern const int VIOLET ;
extern const int WHITE ;
extern const int YELLOW ;

extern const int z ;
extern const int s ;
extern const int j ;
extern const int t ;
extern const int l ;
extern const int i ;
extern const int o ;

extern const int Form_Shape[6][4][4][4] ;
extern const int O[4][4] ;

extern Uint32 start ;
extern Uint32 now ;
extern Uint32 delta ;

extern bool die ;

extern Mix_Music* music ;
extern Mix_Chunk* sound_effect ;

#endif // GLOBAL_H_INCLUDED

