
#include<SDL.h>
#include<SDL_image.h>
#include"Global.h"
#include"Piece.h"
#include"Draw.h"
#include"Button.h"
#include"Text.h"
#include"Music.h"
#include<sstream>
#include<iostream>
 const int ROW = 20 ;
 const int COLUMN = 10 ;
 const int WINDOW_WIDTH = 18*25 ;
 const int WINDOW_HEIGHT  = 23*25;

 const int START_BUTTON_WIDTH = 6*25 ;
 const int START_BUTTON_HEIGHT = 4*25 ;

 const int QUIT_BUTTON_WIDTH = 6*25 ;
 const int QUIT_BUTTON_HEIGHT = 4*25 ;

 const int REPLAY_BUTTON_WIDTH = 6*25 ;
 const int REPLAY_BUTTON_HEIGHT = 4*25 ;

 const int QUITGAME_BUTTON_WIDTH = 6*25 ;
 const int QUITGAME_BUTTON_HEIGHT = 4*25 ;

 const int SCORE_BOARD_WIDTH = 60;
 const int SCORE_BOARD_HEIGHT = 40 ;

 const int YOURSCORE_BUTTON_WIDTH = 6*25 ;
 const int YOURSCORE_BUTTON_HEIGHT = 4*25 ;

 const int HIGHSCORE_BUTTON_WIDTH = 6*25 ;
 const int HIGHSCORE_BUTTON_HEIGHT = 4*25 ;

 const int TEXT_BAR_WIDTH = 500 ;
 const int TEXT_BAR_HEIGHT = 32 ;

 const int SCORE_BOARD_POSX = 13*25-10 ;
 const int SCORE_BOARD_POSY = 3*25 ;

 const int START_BUTTON_POSX = 6*25 ;
 const int START_BUTTON_POSY = 7*25 ;

 const int QUIT_BUTTON_POSX = 6*25 ;
 const int QUIT_BUTTON_POSY = 16*25 ;

 const int REPLAY_BUTTON_POSX = 2*25 ;
 const int REPLAY_BUTTON_POSY = 2*25 ;

 const int QUITGAME_BUTTON_POSX = 10*25 ;
 const int QUITGAME_BUTTON_POSY = 2*25 ;

 const int YOURSCORE_BUTTON_POSX = 6*25 ;
 const int YOURSCORE_BUTTON_POSY = 9*25 ;

 const int HIGHSCORE_BUTTON_POSX = 6*25 ;
 const int HIGHSCORE_BUTTON_POSY = 16*25 ;

 const int YOURSCORE_BOARD_POSX = 8*25 -5 ;
 const int YOURSCORE_BOARD_POSY = 9*25+60 ;

 const int NEXTSHAPE_POSX = 12 ;
 const int NEXTSHAPE_POSY = 12 ;

 const int TEXT_BAR_POSX = 2*25 ;
 const int TEXT_BAR_POSY = 9*25 ;

 const int UNIT = 25 ;
 const char* TITLE = "Tetris" ;
 int Board[20][10]  ;

 SDL_Window* window =  NULL ;
 SDL_Renderer* renderer= NULL;

 SDL_Texture* menu_background = NULL ;
 SDL_Texture* layout_1 = NULL ;
 SDL_Texture* layout_2 = NULL ;
 SDL_Texture* tile_texture = NULL;
 SDL_Texture* high_light = NULL ;
 SDL_Texture* shadow = NULL ;
 SDL_Texture* start_button_texture_1 = NULL ;
 SDL_Texture* start_button_texture_2 = NULL ;
 SDL_Texture* quit_button_texture_1  = NULL ;
 SDL_Texture* quit_button_texture_2 = NULL ;
 SDL_Texture* replay_button_texture_1 = NULL ;
 SDL_Texture* replay_button_texture_2 = NULL ;
 SDL_Surface* surface = NULL ;
 SDL_Texture* score_texture = NULL ;
 SDL_Texture* yourscore_texture = NULL ;
 SDL_Texture* highscore_texture = NULL ;
 SDL_Texture* text_bar_texture = NULL ;
 SDL_Rect* current_color = NULL;
 SDL_Rect score_board ;

 //TTF_Font* font  = NULL ;
 //SDL_Color color = {255,255,255} ;
 SDL_Rect  Color[8]  ;
 int score ;
 //std :: stringstream ss ;
//define color //
 const int PINK  = 0;
 const int BLUE = 1;
 const int GREEN1 = 2  ;
 const int GREEN2  = 3;
 const int RED  = 4;
 const int VIOLET  = 5;
 const int WHITE = 6;
 const int YELLOW = 7;

 const int z = 0 ;
 const int s = 1;
 const int j = 2;
 const int t = 3;
 const int l = 4;
 const int i = 5;
 const int o = 6;

 bool die = false ;
 const int Form_Shape[6][4][4][4] =
 {
	{
	{
		0,0,6,6,
		6,0,0,6,
		6,6,6,6,
		6,6,6,6
	},
	{
		6,6,0,6,
		6,0,0,6,
		6,0,6,6,
		6,6,6,6
	},
	{
		6,6,6,6,
		0,0,6,6,
		6,0,0,6,
		6,6,6,6
	},
	{
		6,0,6,6,
		0,0,6,6,
		0,6,6,6,
		6,6,6,6
	}
},
  {
	{6,1,1,6,
	 1,1,6,6,
	 6,6,6,6,
	 6,6,6,6
	},
	{6,1,6,6,
	 6,1,1,6,
	 6,6,1,6,
	 6,6,6,6
	},
	{6,6,6,6,
	 6,1,1,6,
	 1,1,6,6,
	 6,6,6,6
	},
	{1,6,6,6,
	 1,1,6,6,
	 6,1,6,6,
	 6,6,6,6
	}
},
{
	{6,2,6,6,
	 6,2,6,6,
	 2,2,6,6,
	 6,6,6,6
	},
	{2,6,6,6,
	 2,2,2,6,
	 6,6,6,6,
	 6,6,6,6
	},
	{6,2,2,6,
	 6,2,6,6,
	 6,2,6,6,
	 6,6,6,6
	},
	{6,6,6,6,
	 2,2,2,6,
	 6,6,2,6,
	 6,6,6,6
	}
},
 {
	{6,6,6,6,
	 3,3,3,6,
	 6,3,6,6,
	 6,6,6,6
	},
	{6,3,6,6,
	 3,3,6,6,
	 6,3,6,6,
	 6,6,6,6
	},
	{6,3,6,6,
	 3,3,3,6,
	 6,6,6,6,
	 6,6,6,6
	},
	{6,3,6,6,
	 6,3,3,6,
	 6,3,6,6,
	 6,6,6,6
	}
},
  {
	{6,4,6,6,
	 6,4,6,6,
	 6,4,4,6,
	 6,6,6,6
	},
	{6,6,6,6,
	 4,4,4,6,
	 4,6,6,6,
	 6,6,6,6
	},
	{4,4,6,6,
	 6,4,6,6,
	 6,4,6,6,
	 6,6,6,6
	},
	{6,6,4,6,
	 4,4,4,6,
	 6,6,6,6,
	 6,6,6,6
	}
},
 {
	{6,5,6,6,
	 6,5,6,6,
	 6,5,6,6,
	 6,5,6,6
	},
	{6,6,6,6,
	 5,5,5,5,
	 6,6,6,6,
	 6,6,6,6
	},
	{6,6,5,6,
	 6,6,5,6,
	 6,6,5,6,
	 6,6,5,6
	},
	{6,6,6,6,
	 6,6,6,6,
	 5,5,5,5,
	 6,6,6,6
	}
}
} ;
 const int O[4][4] =
 {
     6,6,6,6,
     6,7,7,6,
     6,7,7,6,
     6,6,6,6
 } ;
 Uint32 start ;
 Uint32 now ;
 Uint32 delta ;
 Text yourscore_text ;
 Text highscore_text ;
 Text input_text ;
 Text name ;


 Mix_Music* music  = NULL;
 Mix_Chunk* sound_effect  = NULL;
 void Draw_Name()
 {
     std :: fstream winner ;
     winner.open("high_score.txt",std :: ios :: in) ;
     int a ; std :: string x ;
     winner >> a ;
     getline(winner,x) ;
     winner.close() ;
     name.RenderText(6*25,20*25,"by "+x,25) ;
 }
 void init()
 {
     SDL_Init(SDL_INIT_EVERYTHING) ;
     IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG) ;
     TTF_Init() ;
     Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) ;
     window = SDL_CreateWindow(TITLE,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN) ;
     renderer = SDL_CreateRenderer(window,-1,0) ;


 }
 void Prepare_Graphic()
 {
     // load texture for file to tile_texture //
     start_button_texture_1 = IMG_LoadTexture(renderer,"start_button_1.png") ;

     start_button_texture_2 = IMG_LoadTexture(renderer,"start_button_2.png") ;

     quit_button_texture_1 = IMG_LoadTexture(renderer,"quit_button_1.png") ;

     quit_button_texture_2 = IMG_LoadTexture(renderer,"quit_button_2.png") ;

     replay_button_texture_1 = IMG_LoadTexture(renderer,"replay_button_1.png") ;

     replay_button_texture_2 = IMG_LoadTexture(renderer,"replay_button_2.png") ;

     high_light = IMG_LoadTexture(renderer,"highlight.png") ;

     tile_texture = IMG_LoadTexture(renderer,"newTiles.png") ;

     menu_background = IMG_LoadTexture(renderer,"menu_background.jpg") ;

     layout_1 = IMG_LoadTexture(renderer,"layout_1.png") ;

     layout_2 = IMG_LoadTexture(renderer,"layout_2.png") ;
      yourscore_texture = IMG_LoadTexture(renderer,"yourscore_button.png") ;
      highscore_texture = IMG_LoadTexture(renderer,"highscore_button.png") ;
      text_bar_texture = IMG_LoadTexture(renderer,"text_bar.png") ;


     shadow = IMG_LoadTexture(renderer,"shadow.png") ;

    // font  = TTF_OpenFont("arial.ttf",25) ;
     // prepare the color //
     for(int i = 0 ;i < 8 ;i++){
        Color[i] = {i*UNIT,0,UNIT,UNIT} ;
     }
     // prepare the game board to be white //
     for(int r = 0 ;r < ROW ;r++)
     for(int c = 0 ;c < COLUMN ;c ++){
        Board[r][c] = WHITE ;
     }
     // prepare sound effect and music //
     music = Mix_LoadMUS("Tetris.mp3") ;
     sound_effect = Mix_LoadWAV("button.wav") ;

 }


 void close()
 {
     name.Free() ;
     input_text.Free() ;
     yourscore_text.Free() ; highscore_text.Free() ;
     SDL_DestroyTexture(tile_texture) ; tile_texture = NULL ;
     SDL_DestroyTexture(menu_background) ; menu_background = NULL ;
     SDL_DestroyTexture(high_light) ; high_light = NULL ;
     SDL_DestroyTexture(shadow) ; shadow = NULL ;
     SDL_DestroyTexture(layout_1) ; layout_1 = NULL ;
     SDL_DestroyTexture(layout_2) ; layout_2 = NULL ;
     SDL_DestroyTexture(start_button_texture_1) ; start_button_texture_1 = NULL ;
     SDL_DestroyTexture(start_button_texture_2) ; start_button_texture_2 = NULL ;
     SDL_DestroyTexture(quit_button_texture_1) ; quit_button_texture_1 = NULL ;
     SDL_DestroyTexture(quit_button_texture_2) ; quit_button_texture_2 = NULL ;
     SDL_DestroyTexture(replay_button_texture_1) ; replay_button_texture_1 = NULL ;
     SDL_DestroyTexture(replay_button_texture_2) ; replay_button_texture_2 = NULL ;
     SDL_DestroyTexture(score_texture) ; score_texture = NULL ;
     SDL_DestroyTexture(yourscore_texture) ; yourscore_texture = NULL ;
     SDL_DestroyTexture(highscore_texture) ; highscore_texture = NULL ;
     SDL_DestroyTexture(text_bar_texture) ; text_bar_texture = NULL ;
   //  TTF_CloseFont(font) ; font = NULL ;
     Mix_FreeChunk(sound_effect) ; sound_effect = NULL ;
     Mix_FreeMusic(music) ; music = NULL ;
     SDL_FreeSurface(surface) ; surface = NULL ;
     SDL_DestroyRenderer(renderer) ; renderer = NULL ;
     SDL_DestroyWindow(window) ; window = NULL ;
     Mix_Quit() ;
     TTF_Quit() ;
     IMG_Quit() ;
     SDL_Quit() ;
 }
 int main(int argc, char* argv[])
 {
     init() ;
     Prepare_Graphic() ;
  //   bool quit_text = false ;
     bool quit_menu = false ;
    // std :: string text = ;
     SDL_Event e ;
     Button start_button(START_BUTTON_POSX,START_BUTTON_POSY,START_BUTTON_WIDTH,START_BUTTON_HEIGHT,start_button_texture_1,start_button_texture_2) ;
     Button quit_button(QUIT_BUTTON_POSX,QUIT_BUTTON_POSY,QUIT_BUTTON_WIDTH,QUIT_BUTTON_HEIGHT,quit_button_texture_1,quit_button_texture_2) ;
     Draw_Menu_Background() ;
     start_button.Draw() ;
     quit_button.Draw() ;
     int x ; int y ;
     while(!quit_menu)
     {
         while(SDL_PollEvent(&e))
         {
             if(e.type == SDL_QUIT){
                close() ;
                return 0 ;
             }
             else{
                if(e.type == SDL_MOUSEMOTION){
                    SDL_GetMouseState(&x,&y) ;
                    start_button.HandleEvent(x,y) ;
                    quit_button.HandleEvent(x,y) ;
                }
                if(e.type == SDL_MOUSEBUTTONDOWN){
                    SDL_GetMouseState(&x,&y) ;
                    if(quit_button.ontheButton(x,y))
                    {
                        Play_SoundEffect() ;
                        close() ;
                        return 0 ;
                    }
                    if(start_button.ontheButton(x,y))
                    {
                        Play_SoundEffect() ;
                        quit_menu = true ;
                    }

                }
             }
         }
     }

     std :: fstream file ;
     Piece piece ;
     Button replay_button(REPLAY_BUTTON_POSX,REPLAY_BUTTON_POSY,REPLAY_BUTTON_WIDTH,REPLAY_BUTTON_HEIGHT,replay_button_texture_1,replay_button_texture_2) ;
     Button quitgame_button(QUITGAME_BUTTON_POSX,QUITGAME_BUTTON_POSY,QUITGAME_BUTTON_WIDTH,QUITGAME_BUTTON_HEIGHT,quit_button_texture_1,quit_button_texture_2);
   //  Button yourscore_button(YOURSCORE_BUTTON_POSX,YOURSCORE_BUTTON_POSY,YOURSCORE_BUTTON_WIDTH,YOURSCORE_BUTTON_HEIGHT,yourscore_texture,NULL) ;
    // Button highscore_button(HIGHSCORE_BUTTON_POSX,HIGHSCORE_BUTTON_POSY,HIGHSCORE_BUTTON_WIDTH,HIGHSCORE_BUTTON_HEIGHT,highscore_texture,NULL) ;
     while(true)
     {
         for(int r = 0 ;r < ROW ;r++)
         for(int c = 0 ;c < COLUMN ;c++){
            Board[r][c] = WHITE ;
         }
         Draw_Layout() ;
         Draw_Map_Tile() ;
         score  = 0 ;
         Draw_Score(SCORE_BOARD_POSX,SCORE_BOARD_POSY,score) ;
         piece.newNextShape() ;
         piece.newPiece() ;
         start = SDL_GetTicks() ;
         Play_Music() ;

     while(!die)
     {
         while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                close() ;
                return 0 ;
            }
            else{
                if(e.type == SDL_KEYDOWN)
                    switch(e.key.keysym.sym)
                {
                case SDLK_LEFT:
                    piece.moveLeft() ;
                    break ;
                case SDLK_RIGHT:
                    piece.moveRight() ;
                    break ;
                case SDLK_DOWN :
                    piece.moveDown() ;
                  //  Draw_Score() ;
                    break ;
                case SDLK_UP :
                    piece.Rotate() ;
                    break ;
                case SDLK_SPACE :
                    piece.fastDown() ;
                    break ;
                }
            }
         }
         piece.Drop() ;
        // Draw_Score() ;
     }
  //   Update_High_Score() ;
     //fstream file  ;
     Mix_HaltMusic() ;
     file.open("high_score.txt",std :: ios :: in ) ;
     int high_score ;
     file >> high_score ;
     file.close() ;
     if(score > high_score)
     {
         Draw_Text_Bar() ;

         std :: string text = "" ;
         bool quit_text = false ;
         SDL_StartTextInput() ;
         while(!quit_text)
         {
             while(SDL_PollEvent(&e)){
                if(e.type == SDL_QUIT){
                    SDL_StopTextInput() ;
                    close() ;
                    return 0 ;
                }
                else{
                     if(e.type == SDL_TEXTINPUT){
                    text += e.text.text ;
                    input_text.RenderText(TEXT_BAR_POSX,TEXT_BAR_POSY,text,25) ;
                    }
                    if(e.type == SDL_KEYDOWN){
                    if(e.key.keysym.sym == SDLK_BACKSPACE && text.length()>0){
                        text.pop_back() ;
                        SDL_Rect temp = {TEXT_BAR_POSX,TEXT_BAR_POSY,TEXT_BAR_WIDTH,TEXT_BAR_HEIGHT} ;
                        SDL_RenderCopy(renderer,text_bar_texture,NULL,&temp) ;
                        SDL_RenderPresent(renderer) ;
                        if(text != "") input_text.RenderText(TEXT_BAR_POSX,TEXT_BAR_POSY,text,25) ;
                        else input_text.RenderText(TEXT_BAR_POSX,TEXT_BAR_POSY," ",25) ;
                    }
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        file.open("high_score.txt",std :: ios :: out | std :: ios :: trunc) ;
                        file << score << text ;
                        file.close() ;
                        quit_text = true ;
                    }
                }
                }

             }
         }
         SDL_StopTextInput() ;
     }
     else {

     Draw_Score(YOURSCORE_BOARD_POSX,YOURSCORE_BOARD_POSY,score) ;
     Draw_High_Score(HIGHSCORE_BUTTON_POSX+25,HIGHSCORE_BUTTON_POSY+50) ;
    // highscore_button.Draw() ;
     yourscore_text.RenderText(YOURSCORE_BUTTON_POSX,YOURSCORE_BUTTON_POSY,"YOUR SCORE :",40) ;
     highscore_text.RenderText(HIGHSCORE_BUTTON_POSX,HIGHSCORE_BUTTON_POSY,"HIGH SCORE :",40) ;
     Draw_Name() ;

     }

     replay_button.Draw() ;
     quitgame_button.Draw() ;
     while(die)
     {
         while(SDL_PollEvent(&e))
         {
             if(e.type== SDL_MOUSEMOTION){
                SDL_GetMouseState(&x,&y) ;
                replay_button.HandleEvent(x,y) ;
                quitgame_button.HandleEvent(x,y) ;
             }
             if(e.type == SDL_MOUSEBUTTONDOWN){
                SDL_GetMouseState(&x,&y);
                if(quitgame_button.ontheButton(x,y))
                {
                    Play_SoundEffect() ;
                    SDL_Delay(100);
                    close() ;
                    return 0 ;
                }
                if(replay_button.ontheButton(x,y))
                {
                    Play_SoundEffect() ;
                     die = false ;
                }


             }
         }
     }
     }



     close() ;
     return 0 ;
 }
