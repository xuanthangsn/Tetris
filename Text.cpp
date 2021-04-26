#include"Text.h"
#include"Global.h"
Text :: Text()
{
    font = NULL ;
    text_texture = NULL ;
    width =  0 ;
    height = 0 ;
}
void Text :: Free()
{
    if(font != NULL){
        TTF_CloseFont(font) ; font = NULL ;
    }
    if(text_texture != NULL){
        SDL_DestroyTexture(text_texture) ; text_texture = NULL ;
    }
}
void Text :: LoadFromRenderedText(std :: string s, int _font)
{
    SDL_Color color = {0,0,0} ;
    font = TTF_OpenFont("arial.ttf",_font) ;
    SDL_Surface* surface = TTF_RenderText_Solid(font,s.c_str(),color) ;
    width = surface -> w ;
    height = surface -> h ;
    text_texture = SDL_CreateTextureFromSurface(renderer,surface) ;
    SDL_FreeSurface(surface) ; surface = NULL ;
}
void Text :: LoadFromRenderedNumber(int number,int _font)
{
    SDL_Color color = {0,0,0} ;
    font = TTF_OpenFont("arial.ttf",_font) ;
    std :: stringstream ss ;
    ss << number ;
    SDL_Surface* surface = TTF_RenderText_Solid(font,ss.str().c_str(),color) ;
    width = surface -> w ;
    height = surface -> h ;
    text_texture = SDL_CreateTextureFromSurface(renderer,surface) ;
    SDL_FreeSurface(surface) ; surface = NULL ;
}
void Text :: Render(int posX, int posY)
{
    SDL_Rect temp = {posX ,posY,width,height} ;
    SDL_RenderCopy(renderer,text_texture,NULL,&temp) ;
    SDL_RenderPresent(renderer) ;
}
void Text ::RenderText(int posX, int posY, std :: string s, int _font)
{
    LoadFromRenderedText(s,_font) ;
    Render(posX,posY) ;
}
void Text :: RenderNumber(int posX, int posY,int number, int _font)
{
    LoadFromRenderedNumber(number,_font) ;
    Render(posX,posY) ;
}
