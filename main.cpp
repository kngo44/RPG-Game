#include "Warrior.h"
#include "Sorcerer.h"
#include "Gunslinger.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
  cout << "Welcome to my RPG Game!" << endl; //Beginning of game
  string user;
  cout << "Are you new to this game? (Please type \"Yes\" or \"No\")" << endl; //If the user is new to the game, ask them to enter their name and choose a class, otherwise load an old character.
  cin >> user;
  while(user!="Yes" && user!="No"){
    cout << "Please type \"Yes\" or \"No\"" << endl;
    cin >> user;
  }

  //Creation or loading of the first player's character.
  string username;
  int choice;
  string load;
  if(user == "Yes"){
    cout << endl;
    cout << "Rules of the Game:" << endl;
    cout << "Your main objective is to defeat the other player. Once you beat him/her, you win." << endl;
    cout << "Each player will take turns attacking until one player's health reaches zero."<< endl;
    cout << "Different classes have different skill sets. Choose whichever suits you best." << endl;
    cout << endl;
    cout << "Please enter the name of the first player:" << endl;
    cin >> username;
    cout << "Please choose a class:" << endl;
    cout << "Type 1 to choose: Warrior" << endl;
    cout << "Type 2 to choose: Sorcerer" << endl;
    cout << "Type 3 to choose: Gunslinger" << endl;
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3){
      cout << "Please enter a valid option:" << endl;
      cout << "Type 1 to choose: Warrior" << endl;
      cout << "Type 2 to choose: Sorcerer" << endl;
      cout << "Type 3 to choose: Gunslinger" << endl;
      cin >> choice;
    }
    load = "New";
  }else if(user == "No"){
    cout << endl;
    cout << "Would you like to load a previous game or start a new game?" << endl;
    cout << "Type \"New\" or \"Load\"" << endl;
    cin >> load;
    while(load!="New" && load!="Load"){
      cout << "Please type \"New\" or \"Load\"" << endl;
      cin >> load;
    }
    if(load == "New"){
      cout << endl;
      cout << "Please enter a name for your character:" << endl;
      cin >> username;
      cout << "Please choose a class:" << endl;
      cout << "Type 1 to choose: Warrior" << endl;
      cout << "Type 2 to choose: Sorcerer" << endl;
      cout << "Type 3 to choose: Gunslinger" << endl;
      cin >> choice;
      while(choice != 1 && choice != 2 && choice != 3){
        cout << "Please enter a valid option:" << endl;
        cout << "Type 1 to choose: Warrior(Normal Mode)" << endl;
        cout << "Type 2 to choose: Sorcerer(Hard Mode)" << endl;
        cout << "Type 3 to choose: Gunslinger" << endl;
        cin >> choice;
      }
    }else if(load == "Load"){
      cout << "Please enter the previous name for the first player." << endl;
      cin >> username;
      cout << "Please enter the class for your previous Character:" << endl;
      cout << "Type 1 to choose: Warrior" << endl;
      cout << "Type 2 to choose: Sorcerer" << endl;
      cout << "Type 3 to choose: Gunslinger" << endl;
      cin >> choice;
    }
  }

  //Player 1 is either created or loaded. This portion of the code sets all variables of the character. The character's stats are now accessible.
  Character* player;
  if(load == "New"){
    if(choice == 1){
      cout << endl;
      cout << "Congratulations! You have chosen the Warrior class." << endl;
      cout << "Warriors have the highest health but deal the least damage compared to other classes." << endl;
      cout << endl;
      cout << "Your abilities are:" << endl;
      cout << "1. Basic Attack (Deals 20-35 dmg, Costs 0 stamina)" << endl;
      cout << "2. Meditation (Replenishes 120-180 health and 10-50 stamina)" << endl;
      cout << "3. Shield Bash (Deals 40-50 dmg, Costs 20 stamina)" << endl;
      cout << "4. Heavy Strike  (Deals 65-90 dmg, Costs 50 stamina)" << endl;
      cout << "5. Decimate (Deals 150-200 dmg, Costs 100 stamina)" << endl;
      cout << endl;
      player = new Warrior;
      player->setHealth(1200);
      player->setName(username);
      player->setLevel(1);
      //player->setStamina(200);
      cout << "Character created and ";
      player->save();
    }else if(choice == 2){
      cout << endl;
      cout << "Congratulations! You have chosen the Sorcerer class." << endl;
      cout << "Sorcerers have average health and average damage compared to other classes." << endl;
      cout << endl;
      cout << "Your abilities are:" << endl;
      cout << "1. Basic Spell (Deals 30-45 dmg, Costs 0 mana)" << endl;
      cout << "2. Heal Aura (Replenishes 115-165 health and 50-100 mana)" << endl;
      cout << "3. Aqua Prison (Deals 60-80 dmg, Costs 50 mana)" << endl;
      cout << "4. Lightning Strike  (Deals 70-110 dmg, Costs 100 mana)" << endl;
      cout << "5. Meteor Shower (Deals 175-230 dmg, Costs 200 mana)" << endl;
      cout << endl;
      player = new Sorcerer;
      player->setHealth(1000);
      player->setName(username);
      player->setLevel(1);
      //player->setMana(500);
      cout << "Character created and ";
      player->save();
    }else if(choice == 3){
      cout << endl;
      cout << "Congratulations! You have chosen the Gunslinger class." << endl;
      cout << "Gunslingers have the least health but deal the most damage compared to other classes." << endl;
      cout << endl;
      cout << "Your abilities are:" << endl;
      cout << "1. Knife (Deals 40-55 dmg, Costs 0 bullets)" << endl;
      cout << "2. Recover (Replenishes 100-130 health and 1-7 bullets)" << endl;
      cout << "3. Headshot (Deals 70-140 dmg, Costs 2 bullets)" << endl;
      cout << "4. Quick Shot (Shoot between 1-7 bullets, Deals 30 dmg per shot)" << endl;
      cout << "5. Full Arsenal (Deals 200-500 dmg, Costs 8 bullets)" << endl;
      cout << endl;
      player = new Gunslinger;
      player->setHealth(800);
      player->setName(username);
      player->setLevel(1);
      //player->setBullets(8);
      cout << "Character created and ";
      player->save();
    }
  }else if(load == "Load"){
    if(choice == 1){
      player = new Warrior;
      cout << endl;
      player->load(username);
    }else if(choice == 2){
      player = new Sorcerer;
      cout << endl;
      player->load(username);
      }else if(choice == 3){
      player = new Gunslinger;
      cout << endl;
      player->load(username);
      }
  }


  //Creation or loading of the second player's character.
  string username2;
  int choice2;
  if(user == "Yes"){
    cout << endl;
    cout << "Please enter the name of the second player:" << endl;
    cin >> username2;
    cout << "Please choose a class:" << endl;
    cout << "Type 1 to choose: Warrior" << endl;
    cout << "Type 2 to choose: Sorcerer" << endl;
    cout << "Type 3 to choose: Gunslinger" << endl;
    cin >> choice2;
    while(choice2 != 1 && choice2 != 2 && choice2 != 3){
      cout << "Please enter a valid option:" << endl;
      cout << "Type 1 to choose: Warrior" << endl;
      cout << "Type 2 to choose: Sorcerer" << endl;
      cout << "Type 3 to choose: Gunslinger" << endl;
      cin >> choice2;
    }
    load = "New";
  }else if(user == "No"){
    if(load == "New"){
      cout << endl;
      cout << "Please enter the name of the second player:" << endl;
      cin >> username2;
      cout << "Please choose a class:" << endl;
      cout << "Type 1 to choose: Warrior" << endl;
      cout << "Type 2 to choose: Sorcerer" << endl;
      cout << "Type 3 to choose: Gunslinger" << endl;
      cin >> choice2;
      while(choice2 != 1 && choice2 != 2 && choice2 != 3){
        cout << "Please enter a valid option:" << endl;
        cout << "Type 1 to choose: Warrior" << endl;
        cout << "Type 2 to choose: Sorcerer" << endl;
        cout << "Type 3 to choose: Gunslinger" << endl;
        cin >> choice2;
      }
    }else if(load == "Load"){
      cout << endl;
      cout << "Please enter the previous name for the second player." << endl;
      cin >> username2;
      cout << "Please enter the class for your previous Character:" << endl;
      cout << "Type 1 to choose: Warrior" << endl;
      cout << "Type 2 to choose: Sorcerer" << endl;
      cout << "Type 3 to choose: Gunslinger" << endl;
      cin >> choice2;
    }
  }

  //Player 2 is either created or loaded. This portion of the code sets all variables of the character. The character's stats are now accessible.
  Character* player2;
  if(load == "New"){
    if(choice2 == 1){
      cout << endl;
      cout << "Congratulations! You have chosen the Warrior class." << endl;
      cout << "Warriors have the highest health but deal the least damage compared to other classes." << endl;
      cout << endl;
      cout << "Your abilities are:" << endl;
      cout << "1. Basic Attack (Deals 20-35 dmg, Costs 0 stamina)" << endl;
      cout << "2. Meditation (Replenishes 120-180 health and 10-50 stamina)" << endl;
      cout << "3. Shield Bash (Deals 40-50 dmg, Costs 20 stamina)" << endl;
      cout << "4. Heavy Strike  (Deals 65-90 dmg, Costs 50 stamina)" << endl;
      cout << "5. Decimate (Deals 150-200 dmg, Costs 100 stamina)" << endl;
      cout << endl;
      player2 = new Warrior;
      player2->setHealth(1200);
      player2->setName(username2);
      player2->setLevel(1);
      //player->setStamina(200);
      cout << "Character created and ";
      player2->save();
    }else if(choice2 == 2){
      cout << endl;
      cout << "Congratulations! You have chosen the Sorcerer class." << endl;
      cout << "Sorcerers have average health and average damage compared to other classes." << endl;
      cout << endl;
      cout << "Your abilities are:" << endl;
      cout << "1. Basic Spell (Deals 30-45 dmg, Costs 0 mana)" << endl;
      cout << "2. Heal Aura (Replenishes 115-165 health and 50-100 mana)" << endl;
      cout << "3. Aqua Prison (Deals 60-80 dmg, Costs 50 mana)" << endl;
      cout << "4. Lightning Strike  (Deals 70-110 dmg, Costs 100 mana)" << endl;
      cout << "5. Meteor Shower (Deals 175-230 dmg, Costs 200 mana)" << endl;
      cout << endl;
      player2 = new Sorcerer;
      player2->setHealth(1000);
      player2->setName(username2);
      player2->setLevel(1);
      //player->setMana(500);
      cout << "Character created and ";
      player2->save();
    }else if(choice2 == 3){
      cout << endl;
      cout << "Congratulations! You have chosen the Gunslinger class." << endl;
      cout << "Gunslingers have the least health but deal the most damage compared to other classes." << endl;
      cout << endl;
      cout << "Your abilities are:" << endl;
      cout << "1. Knife (Deals 40-55 dmg, Costs 0 bullets)" << endl;
      cout << "2. Recover (Replenishes 100-130 health and 1-7 bullets)" << endl;
      cout << "3. Headshot (Deals 70-140 dmg, Costs 2 bullets)" << endl;
      cout << "4. Quick Shot (Shoot between 1-7 bullets, Deals 30 dmg per shot)" << endl;
      cout << "5. Full Arsenal (Deals 200-500 dmg, Costs 8 bullets)" << endl;
      cout << endl;
      player2 = new Gunslinger;
      player2->setHealth(800);
      player2->setName(username2);
      player2->setLevel(1);
      //player->setBullets(8);
      cout << "Character created and ";
      player2->save();
    }
  }else if(load == "Load"){
    if(choice == 1){
      player2 = new Warrior;
      cout << endl;
      player2->load(username2);
    }else if(choice == 2){
      player2 = new Sorcerer;
      cout << endl;
      player2->load(username2);
      }else if(choice == 3){
      player2 = new Gunslinger;
      cout << endl;
      player2->load(username2);
      }
  }

  cout << endl;
  cout << endl;
  cout << endl;

  //Game Loop. Players choose to fight or quit game.
  cout << "Time to Battle!" << endl;
  cout << endl;
  int attack, attack2;
  int dmg, dmg2;
  string cont;
  while(player->getHealth() > 0 && player2->getHealth() > 0){
    cout << username << "'s turn. Choose an ability to attack!" << endl;
    cin >> attack;
    while(attack != 1 && attack != 2 && attack != 3 && attack != 4 && attack != 5){
      cout << "Please enter a valid ability. Type 1, 2, 3, 4, or 5." << endl;
      cin >> attack;
    }
    dmg = player->dealDMG(attack);
    cout << username << " dealt " << dmg << " damage!" << endl;
    player2->takeDMG(dmg);
    cout << endl;
    cout << username2 << "'s turn. Choose an ability to attack!" << endl;
    cin >> attack2;
    while(attack2 != 1 && attack2 != 2 && attack2 != 3 && attack2 != 4 && attack2 != 5){
      cout << "Please enter a valid ability. Type 1, 2, 3, 4, or 5." << endl;
      cin >> attack2;
    }
    dmg2 = player2->dealDMG(attack2);
    cout << username2 << " dealt " << dmg2 << " damage!" << endl;
    player->takeDMG(dmg2);
    cout << endl;
    player->userStats();
    cout << endl;
    player2->userStats();
    cout << endl;
    cout << "Continue to fight or end game?" << endl;
    cout << "Type Continue or Quit." << endl;
    cin >> cont;
    cout << endl;
    if(cont == "Quit"){
      player->save();
      cout << endl;
      player2->save();
      cout << "Game exited." << endl;
      exit(1);
    }
  }

  //Result of game.
  if(player->getHealth() <= 0){
    cout << username2 << " won! Good Game!" << endl;
  }else{
    cout << username << " won! Good Game!" << endl;
  }
  return 0;
}