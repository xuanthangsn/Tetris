#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
class Piece{
private:
    int shape[4][4] ;
    int newtypeShape ;
    int rotateN ;
    int shadowN ;
    int typeShape ;
    int posX ;
    int posY ;
public :
    void newNextShape() ;
    void drawNextShape() ;
    void newPiece();
    void Draw() ;
    void unDraw() ;
    bool Collision(int x,int y,int _rotateN) ;
    void moveLeft() ;
    void moveRight() ;
    void moveDown() ;
    void lockPiece() ;
    void Rotate() ;
    void Drop() ;
    void HighLight(int r) ;
    void removeRow() ;
    int getPieceButton() ;

    void updateShadowN() ;
    void drawShadow() ;
    void undrawShadow() ;
    void fastDown() ;
};

#endif // PIECE_H_INCLUDED
