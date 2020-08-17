#include<bits/stdc++.h>
#include "snverifier.h"
#define fst first
#define snd second
using namespace std;

 /*
 Altura: 15
 Longitud : 17
 (0,y) invalid
 (x,0) invalid
 (16,y) invalid
 (x,17) invalid

 char number 79 : head of the snake
 char number 64 : snake's body
 char number 35 : field's edge
 char number 43 : food
 */


 char Mat[17][19]; ///playing field
 /// first : line  second : column
 vector<pair<int,int> >Cord(300); /// coordinates of each space the snake occupies

void setup(){

 int i,j;

 for(i=0,j=0;j<19;j++)Mat[i][j]='#';
 for(i=0,j=0;i<17;i++)Mat[i][j]='#';

 for(i=16,j=0;j<19;j++)Mat[i][j]='#';
 for(i=0,j=18;i<17;i++)Mat[i][j]='#';

 Mat[1][1]='@';
 Mat[1][2]='@';
 Mat[1][3]='@';
 Mat[1][4]='O';

 Cord[0].fst=1,Cord[0].snd=1;
 Cord[1].fst=1,Cord[1].snd=2;
 Cord[2].fst=1,Cord[2].snd=3;
 Cord[3].fst=1,Cord[3].snd=4;
 setvalids();
}

void play(int vel){

 setup();
 int Lin,Col;
 int i,j;
 int Score=0;

 Lin=rand()%17;
 Col=rand()%19;

 while(Lin<=0||16<=Lin)Lin=rand();
 while(Col<=0||18<=Col)Col=rand();

 for(i=0;i<17;i++){
   for(j=0;j<19;j++){
     if(i==Lin&&j==Col)cout<<'+';
     else cout<<Mat[i][j];
   }
   cout<<"\n";
 }
}
