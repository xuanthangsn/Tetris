
#include"Piece.h"
#include"Global.h"
#include"Draw.h"


void Piece:: newNextShape()
{
    newtypeShape = rand()% 7 ;

}
void Piece:: drawNextShape()
{
    if(newtypeShape == o){
        for(int r = 0 ; r< 4;r++)
        for(int c = 0 ;c < 4;c++){
            Draw_Tile(NEXTSHAPE_POSX+c,NEXTSHAPE_POSY+r,O[r][c]) ;
        }
    }
    else{
        for(int r = 0 ; r< 4;r++)
        for(int c = 0 ;c < 4;c++){
            Draw_Tile(NEXTSHAPE_POSX+c,NEXTSHAPE_POSY+r,Form_Shape[newtypeShape][0][r][c]) ;
        }
    }
    SDL_RenderPresent(renderer) ;
}
void Piece ::newPiece()
{
    posX = 4 ;
    posY = -4 ;
    rotateN = 0 ;
    typeShape = newtypeShape ;
    if(typeShape == o){
        for(int r = 0 ;r < 4 ;r++)
        for(int c = 0 ;c<4;c++){
            shape[r][c] = O[r][c] ;
        }
    }
    else{
        for(int r = 0 ;r < 4;r++)
        for(int c = 0 ;c < 4;c++){
            shape[r][c] = Form_Shape[typeShape][rotateN][r][c] ;
        }
    }
    newNextShape() ;
    updateShadowN() ;
    drawNextShape() ;
    Draw() ;
    drawShadow() ;
}
void Piece ::Draw()
{
    for(int r = 0 ; r < 4 ;r++)
    for(int c = 0 ; c < 4 ;c++){
        if(shape[r][c] != WHITE)
        Draw_Tile(posX + c, posY + r ,shape[r][c]) ;
    }
    SDL_RenderPresent(renderer) ;
}
void Piece ::unDraw()
{
    for(int r = 0 ; r< 4;r++)
    for(int c = 0 ; c< 4;c++){
        if(shape[r][c]!= WHITE)
        Draw_Tile(posX + c, posY + r, WHITE) ;
    }
    SDL_RenderPresent(renderer) ;
}
bool Piece::Collision(int x, int y, int _rotateN)
{
    //int newrotateN = rotateN + _rotateN ;
    int newPosX = posX + x ;
    int newPosY = posY + y ;
    if(typeShape == o){
        for(int r = 0 ;r<4;r++)
        for(int c = 0 ;c<4;c++){
            if(O[r][c]!= WHITE){
                if(newPosY+ r < 0){
                    if(newPosX+c < 0 || newPosX +c > COLUMN -1 )
                        return true ;
                }
                else{
                    if(newPosX + c < 0 || newPosX +c > COLUMN -1 || Board[newPosY+r][newPosX+c]!= WHITE)
                        return true ;
                }
            }
        }
        return false ;
    }
    else{
        int newrotateN = (rotateN + _rotateN) % 4 ;
        for(int r = 0 ;r < 4 ;r++)
        for(int c = 0 ;c < 4 ;c++){
            if(Form_Shape[typeShape][newrotateN][r][c]!= WHITE){
                if(newPosY + r <0){
                    if(newPosX+c<0 || newPosX + c > COLUMN -1)
                        return true ;
                }
                else{
                    if(newPosX +c < 0 || newPosX + c > COLUMN-1 || Board[newPosY+r][newPosX+c]!= WHITE)
                        return true ;
                }
            }
        }
        return false ;
    }
}
void Piece::lockPiece()
{
    for(int r = 0 ; r < 4 ;r++)
    for(int c = 0 ; c < 4 ;c++){
        if(shape[r][c] != WHITE){
            Board[posY + r][posX + c] = shape[r][c] ;
        }
    }
}
void Piece:: moveLeft()
{
    if(!Collision(-1,0,0)){
        unDraw() ;
        undrawShadow() ;
        posX -= 1 ;
        updateShadowN() ;
        Draw() ;
        drawShadow() ;

    }
}
void Piece::moveRight()
{
    if(!Collision(1,0,0)){
        unDraw() ;
        undrawShadow() ;
        posX+= 1 ;
        updateShadowN() ;
        Draw() ;
        drawShadow() ;
    }
}
void Piece::moveDown()
{
    if(!Collision(0,1,0)){
        unDraw() ;
        posY+= 1 ;
        shadowN -= 1 ;
        Draw() ;
    }
    else{
        if(posY < 0 ) die = true ;
    else{
        lockPiece() ;
      //  Draw_Map_Tile() ;
        removeRow() ;
        Draw_Map_Tile() ;
        newPiece() ;
    }

    }
}
void Piece:: Rotate()
{
    if(typeShape != o){
        if(Collision(-1,0,1) == false && Collision(1,0,1)== false && Collision(0,1,1) == false){
            unDraw() ;
            undrawShadow() ;
            rotateN  = (rotateN +1)%4;
            for(int r = 0 ;r< 4;r++)
            for(int c = 0 ;c< 4;c++){
                shape[r][c] = Form_Shape[typeShape][rotateN][r][c] ;
            }
            updateShadowN() ;
            Draw() ;
            drawShadow() ;
        }
    }
}
void Piece::Drop()
{
    now = SDL_GetTicks() ;
    delta = now - start ;
    if(delta > 500){
        start = now ;
        moveDown() ;
    }
}
void Piece :: HighLight(int r)
{
 for(int c = 0 ; c< COLUMN ;c++){
    Draw_Highlight(c,r);
 }
 SDL_RenderPresent(renderer) ;
}
int Piece :: getPieceButton()
{
    for(int r = 3 ;r >= 0 ;r --)
    for(int c = 0 ;c< 4 ;c++){
        if(shape[r][c] != WHITE)
            return r ;
    }
}


void Piece::removeRow()
{
    int scoreN = 0 ;
    int k = getPieceButton()+posY ;
    for(int r = k ; r >= 0 ;r--){
        int n = 0 ;
        for(int c = 0 ;c < COLUMN ;c ++){
            Board[k][c] = Board[r][c] ;
            if(Board[r][c]!= WHITE) n ++ ;
        }
        if(n < COLUMN) k-- ;
        else{
            HighLight(r) ;
            scoreN++ ;
        }
    }
    if(k > -1){
        SDL_Delay(200) ;
        for(int r = k-1;r >= 0 ;r--)
        for(int c = 0 ; c < COLUMN ;c ++){
                Board[r][c] = WHITE ;
        }
       // Draw_Map_Tile() ;

    }
    if(scoreN != 0)
    {
        if(scoreN == 1) score += 1 ;
        if(scoreN == 2) score += 3 ;
        if(scoreN == 3) score += 5 ;
        if(scoreN == 4) score += 10 ;
       Draw_Score(SCORE_BOARD_POSX,SCORE_BOARD_POSY,score) ;
    }

}
void Piece:: updateShadowN()
{
    int i = 1 ;
    while(!Collision(0,i,0))
        i++ ;
    shadowN = i-1 ;
}
void Piece:: drawShadow()
{
    for(int r = 0 ;r < 4;r++)
    for(int c = 0 ;c < 4 ;c++){
        if(Form_Shape[typeShape][rotateN][r][c]!= WHITE){
            Draw_Shadow(posX+c,posY+shadowN+r) ;
        }
    }
    SDL_RenderPresent(renderer) ;
}
void Piece:: undrawShadow()
{
    for(int r = 0 ;r < 4 ;r++)
    for(int c = 0 ;c < 4 ;c++){
        if(Form_Shape[typeShape][rotateN][r][c]!= WHITE){
            Draw_Tile(posX+c,posY+shadowN+r,WHITE) ;
        }
    }
    SDL_RenderPresent(renderer) ;
}
void Piece :: fastDown()
{
    unDraw() ;
    posY+= shadowN ;
    Draw() ;
}
