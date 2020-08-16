#include<bits/stdc++.h>
#include<windows.h>
#include "sngameplay.h"
using namespace std;

 string Dif;
 bool Val=false;
 int vel;

 /*
 Altura : 15
 Longitud : 17
 */

void Menu(){

  cout<<"Welcome! \n";
  Sleep(2000);
  cout<<"This game is a clone of the famous game \"Snake\". \n";
  Sleep(3000);
  cout<<"Your snake will start at the middle of the plain, an unit of food \n";
  cout<<"will spawn in a random spot of the plain, if you reach the food, \n";
  cout<<"you'll gain a point. \n";
  Sleep(10000);
  cout<<"Be careful though, each time you reach the food, you're snake will \n";
  cout<<"grow one unit of length, occupying more space the larger it gets. \n";
  Sleep(8000);

  cout<<"You'll lose if your snake hits the edge of the plain or hits its body. \n \n";

  cout<<"Press any key to continue . . .";
  cin.get();
  system("cls");

  cout<<"Now, select what difficulty you want to play, the harder the difficulty \n";
  cout<<"the faster your snake will be. \n";
  Sleep(6000);
  cout<<"\tType \"easy\" for easy mode \n";
  cout<<"\tType \"normal\" for normal mode \n";
  cout<<"\tType \"hard\" for hard mode \n";
  cout<<"\tType \"htp\" for controls \n";
  cout<<"\n";

   cin>>Dif;
   while(Val==false){
     if(Dif=="easy"){
      vel=800;
      Val=true;
     }
     else if(Dif=="normal"){
      vel=400;
      Val=true;
     }
     else if(Dif=="hard"){
      vel=200;
      Val=true;
     }
     else if(Dif=="htp"){
       system("cls");
         cout<<"Controls: \n";
         cout<<"W is to go up \n";
         cout<<"S is to go down \n";
         cout<<"A is to go left \n";
         cout<<"D is to go right \n\n";

         cout<<"Press any key to return . . . \n";
         cin.get();

        cout<<"\tType \"easy\" for easy mode \n";
        cout<<"\tType \"normal\" for normal mode \n";
        cout<<"\tType \"hard\" for hard mode \n";
        cout<<"\tType \"htp\" to read the controls \n";
        cout<<"\n";

        cin>>Dif;
     }
     else{
       system("cls");
       cout<<"You entered an unvalid input.\n";
       Sleep(1500);
       cout<<"Make sure that you're typing correctly \n";
       cout<<"the difficulty without captions. \n";
       Sleep(3000);
       cout<<"Remember: \n";
       Sleep(800);
        cout<<"\tType \"easy\" for easy mode \n";
        cout<<"\tType \"normal\" for normal mode \n";
        cout<<"\tType \"hard\" for hard mode \n";
        cout<<"\tType \"htp\" for controls \n";
        cout<<"\n";

        cin>>Dif;
     }
   }

   system("cls");
   cout<<"Obtain as many point as you can! \n\n";
   Sleep(3000);

   play(vel);
}


int main(){

 Menu();
}
