#include"Global.h"
#include"Music.h"

void Play_SoundEffect()
{
    Mix_PlayChannel(-1,sound_effect,0) ;
}
void Play_Music()
{
    Mix_PlayMusic(music,-1) ;
}
