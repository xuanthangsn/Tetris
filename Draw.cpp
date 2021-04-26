
#include"Draw.h"
#include"Global.h"
#include"Text.h"


void Draw_Tile(int posX, int posY, int color)
{
    current_color = &Color[color] ;
    SDL_Rect temp = {posX*UNIT,posY*UNIT,UNIT,UNIT} ;
    SDL_RenderCopy(renderer,tile_texture,current_color,&temp) ;
}
void Draw_Map_Tile()
{
    for(int r = 0 ;r < ROW ;r++)
    for(int c = 0 ;c < COLUMN ;c++){
        Draw_Tile(c,r,Board[r][c]) ;
    }
    SDL_RenderPresent(renderer) ;
}
void Draw_Highlight(int posX, int posY)
{
    SDL_Rect temp = {posX*UNIT,posY*UNIT,UNIT,UNIT} ;
    SDL_RenderCopy(renderer,high_light,NULL,&temp) ;

}
void Draw_Shadow(int posX, int posY)
{
    SDL_Rect temp = {posX*UNIT,posY*UNIT,UNIT,UNIT} ;
    SDL_RenderCopy(renderer,shadow,NULL,&temp) ;
}
void Draw_Menu_Background()
{
    SDL_RenderCopy(renderer,menu_background,NULL,NULL) ;
    SDL_RenderPresent(renderer) ;
}
void Draw_Layout()
{
    SDL_Rect temp1 = {0,20*UNIT,18*UNIT,3*UNIT} ;
    SDL_Rect temp2 = {10*UNIT,0,8*UNIT,20*UNIT} ;
    SDL_RenderCopy(renderer,layout_1,NULL,&temp1) ;
    SDL_RenderCopy(renderer,layout_2,NULL,&temp2) ;

    SDL_RenderPresent(renderer) ;
}
 void Draw_Score(int posX, int posY, int _score)
{
    score_board = {posX,posY,SCORE_BOARD_WIDTH,SCORE_BOARD_HEIGHT} ;
    SDL_RenderCopy(renderer,tile_texture,&Color[WHITE],&score_board) ;
    SDL_RenderPresent(renderer) ;
    TTF_Font* font = TTF_OpenFont("arial.ttf",25) ;
    SDL_Color color = {0,0,0} ;
    std :: stringstream ss ;
    ss << _score ;
    surface = TTF_RenderText_Solid(font, ss.str().c_str(),color) ;
    score_texture = SDL_CreateTextureFromSurface(renderer,surface) ;
    SDL_RenderCopy(renderer,score_texture,NULL,&score_board) ;
    SDL_RenderPresent(renderer) ;
    TTF_CloseFont(font) ; font = NULL ;
}
void Draw_High_Score(int posX, int posY)
{
    std :: fstream file ;
    file.open("high_score.txt",std :: ios :: in) ;
    int _score ;
    file >> _score ;
    file.close() ;
    Draw_Score(posX,posY,_score) ;
}
void Update_High_Score()
{
    std :: fstream file ;
    file.open("high_score.txt",std :: ios :: in) ;
    int n ;
    file >> n ;
    file.close() ;
    if(score > n){
        file.open("high_score.txt",std :: ios :: out | std :: ios :: trunc) ;
        file << score ;
        file.close() ;
    }
}
void Draw_Text_Bar()
{
    Text text_bar  ;
    text_bar.RenderText(TEXT_BAR_POSX,TEXT_BAR_POSY-35,"ENTER YOUR NAME!",30) ;
    SDL_Rect temp = {TEXT_BAR_POSX,TEXT_BAR_POSY,TEXT_BAR_WIDTH,TEXT_BAR_HEIGHT} ;
    SDL_RenderCopy(renderer,text_bar_texture,NULL,&temp) ;
    SDL_RenderPresent(renderer) ;
}
