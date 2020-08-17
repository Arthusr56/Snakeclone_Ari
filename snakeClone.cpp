#include <bits/stdc++.h>
#include <windows.h>
#include "snakeGameplay.h"
using namespace std;

 bool validAnswer = false;
 int velocityMovement;

enum possibleInput{
    easy = 0,
    normal = 1,
    hard = 2,
    htp = 3,
    unvalid = 4
};

void introduction(){

  cout<<"Welcome! \n";
  Sleep(1500);
  cout<<"This game is a clone of the classic game \"Snake\". \n";
  Sleep(2500);
  cout<<"Your snake will start at the middle of the plain, an unit of food \n";
  cout<<"will spawn in a random spot of the plain, if you reach the food, \n";
  cout<<"you'll gain a point. \n";
  Sleep(9000);
  cout<<"Be careful though, each time you reach the food, you're snake will \n";
  cout<<"grow one unit of length, occupying more space the larger it gets. \n";
  Sleep(7000);
  cout<<"You'll lose if your snake hits the edge of the plain or hits its body. \n \n";

  cout<<"Press any key to continue . . .";
  cin.get();
  system("cls");

}

void showcaseControls(){

 system("cls");
         cout<<"How to play: \n";
         cout<<"Use W to go up \n";
         cout<<"Use S to go down \n";
         cout<<"Use A to go left \n";
         cout<<"Use D to go right \n\n";

         cout<<"Press any key to return . . . \n";
         cin.get();

 system("cls");
}

void optionDisplay(){

   cout<<"\tType \"easy\" for easy mode \n";
   cout<<"\tType \"normal\" for normal mode \n";
   cout<<"\tType \"hard\" for hard mode \n";
   cout<<"\tType \"htp\" for controls \n";
   cout<<"\n";

}

void unvalidInput(){

       system("cls");
       cout<<"You entered an unvalid input.\n";
       Sleep(1500);
       cout<<"Make sure that you're typing correctly \n";
       cout<<"the difficulty without captions. \n";
       Sleep(3000);
       cout<<"Remember: \n";
       Sleep(800);

}

possibleInput playerInput(string diff){

  if(diff == "easy")
    return possibleInput::easy;
  if(diff == "normal")
    return possibleInput::normal;
  if(diff == "hard")
    return possibleInput::hard;
  if(diff == "htp")
    return possibleInput::htp;

  return possibleInput::unvalid;
}

void Menu(){

 string difficultyLevel;
 int levelChosen;
 introduction();

  cout<<"Now, select what difficulty you want to play, the harder the difficulty \n";
  cout<<"the faster your snake will be. \n";
  Sleep(6000);
  optionDisplay();
   cin>>difficultyLevel;

   while(validAnswer == false){
     validAnswer = true;
      levelChosen = playerInput(difficultyLevel);

      switch(levelChosen){

         case 0:
           velocityMovement = 800;
         case 1:
           velocityMovement = 400;
         case 2:
           velocityMovement = 200;
         case 3:
           validAnswer = false;
           showcaseControls();
           optionDisplay();
           cin>>difficultyLevel;
         case 4:
           unvalidInput();
           optionDisplay();
           cin>>difficultyLevel;

      }

   }

   system("cls");
   cout<<"Obtain as many points as you can! \n\n";
   Sleep(3000);

   play(velocityMovement);
}


int main(){

 Menu();
}
