#include <bits/stdc++.h>
#include "snakeVerifier.h"
#define fst first
#define snd second
using namespace std;

 const int maxRow = 17;
 const int maxColumn = 19;

 /*
 Height : 15
 Length : 17

 Field boundaries:
 (0,y)
 (x,0)
 (16,y)
 (x,17)

 char number 79 - O : head of the snake
 char number 64 - @ : snake's body
 char number 35 - # : field's edge
 char number 43 - + : food
 */

struct Pixel{
 int row;
 int column;
 Pixel(int _row, int _column) :
 row(_row) , column(_column) {}
 Pixel() : row(0) , column(0) {}
};

 char playField[maxRow][maxColumn]; ///playing field
 /// first : row  second : column
 vector< pair < int , int > > Coordinates(300); /// coordinates of each space the snake occupies
 int snakesLength = 4;

int randInterval(int a, int b){
   return rand()%(b-a)+a;
}

Pixel asignRandomCell(){

 return Pixel(randInterval(1 , maxRow), randInterval(1, maxColumn));
}

bool validFruit(Pixel fruit){

 for(int i = 0 ; i < snakesLength ; i++){
    if(Coordinates[i].fst == fruit.row && Coordinates[i].snd == fruit.column)
        return false;

 }

 return true;
}

void setBoundaries(){

 int i, j;

 for(i = 0 , j = 0 ; j < 19 ; j++)playField[i][j] = '#';
 for(i = 0 , j = 0 ; i < 17 ; i++)playField[i][j] = '#';

 for(i = 16 , j = 0 ; j < 19 ; j++)playField[i][j] = '#';
 for(i = 0 , j = 18 ; i < 17 ; i++)playField[i][j] = '#';

}

void commenceSetup(){

 int i, j;

 setBoundaries();

 playField[1][1] = '@';
 playField[1][2] = '@';
 playField[1][3] = '@';
 playField[1][4] = 'O';

 Coordinates[0] = {1 , 1};
 Coordinates[1] = {1 , 2};
 Coordinates[2] = {1 , 3};
 Coordinates[3] = {1 , 4};

 setValids();
}

void outputField(Pixel fruit){

 int i, j;

 for(i = 0 ; i < 17 ; i++){
   for(j = 0 ; j < 19 ; j++){
         if(i == fruit.row && j == fruit.column)cout<<'+';
         else cout<<playField[i][j];
   }
   cout<<"\n";
 }
}

void play(int msPermove){

 commenceSetup();
 Pixel fruit;
 int i, j;
 int Score = 0;

 fruit = asignRandomCell();
  while(validFruit(fruit) == false)fruit = asignRandomCell();

 outputField(fruit);

 /// Start playing
 bool notCrashed = true;

 while(notCrashed == true){



 }


}
