#include<bits/stdc++.h>
#define fst first
#define snd second
using namespace std;


 bool vis[17][19];

void setvalids(){

 int i,j;

 for(i=0,j=0;j<19;j++)vis[i][j]=true;
 for(i=0,j=0;i<17;i++)vis[i][j]=true;

 for(i=16,j=0;j<19;j++)vis[i][j]=true;
 for(i=0,j=18;i<17;i++)vis[i][j]=true;

 return;
}


bool validornot(int Cord,int siz){

 /*
 Verifies whether or not the position of the snake's body is valid
 Returns true if it's valid
 Returns false otherwise
 */

 int i,j;

 for(i=0;i<siz;i++){
   if(vis[coor[i].fst][coor[i].snd]==false)vis[coor[i].fst][coor[i].snd]=true;
   else{
     return false;
   }
 }

 for(i=1;i<16;i++){
   for(j=1;j<18;j++)vis[i][j]=false;
 }

 return true;
}
