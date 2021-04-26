#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
void Draw_Tile(int posX, int posY, int color) ;

void Draw_Map_Tile() ;

void Draw_Highlight(int posX, int posY) ;

void Draw_Shadow(int posX, int posY) ;

void Draw_Menu_Background() ;

 void Draw_Layout() ;

void Draw_Score(int posX, int posY, int _score) ;

 void Draw_High_Score(int posX, int posY) ;

 void Update_High_Score() ;

 void Draw_Text_Bar() ;

#endif // DRAW_H_INCLUDED
