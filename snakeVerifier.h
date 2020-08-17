#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

 bool visitedCells[17][19];

void setValids(){

 int i ,j;

 for(i = 0 , j = 0 ; j < 19 ; j++ )visitedCells[i][j] = true;
 for(i = 0 , j = 0 ; i < 17 ; i++ )visitedCells[i][j] = true;

 for(i = 16 , j = 0 ; j < 19 ; j++ )visitedCells[i][j] = true;
 for(i = 0 , j = 18 ; i < 17 ; i++ )visitedCells[i][j] = true;

 return;
}


bool isItValid(vector < pair < int , int > > snakeBody(), int currentLength){

 /**
  *   Verifies whether or not the position of the snake's body is valid

  *   @param snakeBody(), coordinates occupied by the snake's body
  *   @param currentLength, the current size of the snake
  *   @return true if it's valid, false otherwise
  */

 int i, j;
 int actualRow, actualColumn;

 /*
 for(i = 0 ; i < currentLength ; i++){

    actualRow = snakeBody[i].fst;
    actualColumn = snakeBody[i].snd;

    if(visitedCells[actualRow][actualColumn] == true)
        return false;
    visitedCells[actualRow][actualColumn] = true;
 }
 */

 for(i = 1 ; i < 16 ; i++){
    for(j = 1 ; j < 18 ; j++)
       visitedCells[i][j]=false;
 }
 return true;
}
