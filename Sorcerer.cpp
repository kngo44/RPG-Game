#include "Sorcerer.h"

Sorcerer::Sorcerer() : Character()
{
  mana = 500;
}
Sorcerer::Sorcerer(string _name, int _health, int _level, int _mana) : Character(_name, _health, _level)
{
  mana = _mana;
}

int Sorcerer::getMana(){
  return mana;
}
void Sorcerer::setMana(int _mana){
  mana = _mana;
}

int Sorcerer::dealDMG(int attack){
  int dealt = 0;
  int HP;
  int AP;
  
  srand((unsigned) time(NULL));
  if(attack == 1){
    dealt = 30 + (rand() % 16);
    return dealt;
  }else if(attack == 2){
    HP = 115 + (rand() % 51);
    AP = 150 + (rand() % 100);
    setHealth(getHealth()+HP);
    setMana(getMana()+AP);
    return dealt;
  }else if(attack == 3){
    if(getMana() < 50){
      return dealt;
    }else{
    dealt = 60 + (rand() % 21);
    setMana(getMana()-50);
    return dealt;
      }
  }else if(attack == 4){
    if(getMana() < 100){
      return dealt;
    }else{
    dealt = 70 + (rand() % 41);
    setMana(getMana()-100);
    return dealt;
      }
  }else if(attack == 5){
    if(getMana() < 200){
      return dealt;
    }else{
    dealt = 175 + (rand() % 56);
    setMana(getMana()-200);
    return dealt;
      }
  }

  return dealt;
}
void Sorcerer::takeDMG(int defend){
  int taken;
  taken = getHealth() - defend;
  setHealth(taken);
}
void Sorcerer::userStats(){
  cout << "Name: " << getName() << endl;
  cout << "Health: " << getHealth() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Mana: " << getMana() << endl;
}
void Sorcerer::save(){
  ofstream outFile(getName());
  outFile << getName() << endl;
  outFile << getHealth() << endl;
  outFile << getLevel() << endl;
  outFile << getMana() << endl;
  outFile.close();
  cout << "Character saved." << endl;
  userStats();
}
void Sorcerer::load(string username){
  ifstream inFile(username);

  if(!inFile.is_open()){
    cout << "Invalid username." << endl;
    exit(1);
  }
  
  string array[5];
  int i = 0;
  while(getline(inFile, array[i])){
    i++;
  }
  setName(array[0]);
  setHealth(stoi(array[1]));
  setLevel(stoi(array[2]));
  setMana(stoi(array[3]));
  inFile.close();
  cout << "Character loaded." << endl;
  userStats();
}
