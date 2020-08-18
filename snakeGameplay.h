#include <bits/stdc++.h>
#include "snakeVerifier.h"
#include <windows.h>
#include <time.h>
#define fst first
#define snd second
using namespace std;

 const int maxRow = 17;
 const int maxColumn = 19;
 const float frame_length = 1;

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
 /// last saved position belongs to the snake's head
 int snakesLength = 4;
 Pixel fruit;
 int Score = 0;

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

 if(fruit.row == 0 || fruit.row == 16)return false;
 if(fruit.column == 0 || fruit.column == 18)return false;

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

 system("cls");
 int i, j;

 for(i = 0 ; i < 17 ; i++){
   for(j = 0 ; j < 19 ; j++){
         if(i == fruit.row && j == fruit.column)cout<<'+';
         else cout<<playField[i][j];
   }
   cout<<"\n";
 }
}

char determineNewDirection(char currentDirection, char actionInputed){

 switch(actionInputed){
  case 'W':
      if(currentDirection == 'S') return currentDirection;
      else return actionInputed;
  case 'A':
      if(currentDirection == 'D') return currentDirection;
      else return actionInputed;
  case 'S':
      if(currentDirection == 'W') return currentDirection;
      else return actionInputed;
  case 'D':
      if(currentDirection == 'A') return currentDirection;
      else return actionInputed;
  default:
      return currentDirection;
 }

}

void updateAndAdd(pair < int , int > newSpot){

 Score++;

 Coordinates[snakesLength] = newSpot;
 playField[Coordinates[snakesLength-1].fst][Coordinates[snakesLength-1].snd] = '@';
 playField[Coordinates[snakesLength].fst][Coordinates[snakesLength].snd] = 'O';
 snakesLength++;

 fruit = asignRandomCell();
  while(validFruit(fruit) == false)fruit = asignRandomCell();
}

void updateOnly(pair < int , int > newSpot){

 playField[Coordinates[0].fst][Coordinates[0].snd] = ' ';
 playField[Coordinates[snakesLength-1].fst][Coordinates[snakesLength-1].snd] = '@';

  for(int i = 0 ; i < snakesLength ; i++)
    Coordinates[i] = Coordinates[i+1];

 Coordinates[snakesLength-1] = newSpot;
 playField[Coordinates[snakesLength-1].fst][Coordinates[snakesLength-1].snd] = 'O';
}

void moveOneCell(char currentDirection , pair< int , int > headPosition){

 pair< int , int > newSpot;

 switch(currentDirection){
   case 'W':
      newSpot.fst = headPosition.fst - 1;
      newSpot.snd = headPosition.snd;
      break;
   case 'A':
      newSpot.fst = headPosition.fst;
      newSpot.snd = headPosition.snd - 1;
      break;
   case 'S':
      newSpot.fst = headPosition.fst + 1;
      newSpot.snd = headPosition.snd;
      break;
   case 'D':
      newSpot.fst = headPosition.fst;
      newSpot.snd = headPosition.snd + 1;
      break;
 }

 if(fruit.row == newSpot.fst && fruit.column == newSpot.snd)
    updateAndAdd(newSpot);
 else
    updateOnly(newSpot);
}

void play(int msPerMove){

 commenceSetup();
 int i, j;

 fruit = asignRandomCell();
  while(validFruit(fruit) == false)fruit = asignRandomCell();

 outputField(fruit);

 /// Start playing
 clock_t chronoMeter;
 bool notCrashed = true;
 int keyPress;
 char nextAction, currentDirection = 'D';

 while(notCrashed == true){

  chronoMeter = clock();

   while(clock() - chronoMeter < (msPerMove * frame_length)){

     //Sleep(200);

     for(keyPress = 0x41 ; keyPress < 0x5a ; keyPress++){
         if(GetAsyncKeyState(keyPress)){
            nextAction = char(keyPress);
            break;
         }
     }
   }

  currentDirection = determineNewDirection(currentDirection, nextAction);

  moveOneCell(currentDirection , Coordinates[snakesLength-1]);
   if(!isItValid(Coordinates, snakesLength))return;
  outputField(fruit);
 }
}
