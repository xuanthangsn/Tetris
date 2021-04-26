#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include"Global.h"
class Text{
private :
    TTF_Font* font ;
    SDL_Texture* text_texture ;
    int width ;
    int height ;

public :
    Text() ;
    void LoadFromRenderedText(std :: string s,int _font) ;
    void LoadFromRenderedNumber(int number,int _font) ;
    void Render(int posX, int posY) ;
    void RenderText(int posX, int posY, std :: string s, int _font) ;
    void RenderNumber(int posX, int posY,int number, int _font) ;
    void Free() ;
};


#endif // TEXT_H_INCLUDED
