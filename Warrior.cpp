#include "Warrior.h"

Warrior::Warrior() : Character()
{
  stamina = 200;
}
Warrior::Warrior(string _name, int _health, int _level, int _stamina) : Character(_name, _health, _level)
{
  stamina = _stamina;
}

int Warrior::getStamina(){
  return stamina;
}
void Warrior::setStamina(int _stamina){
  stamina = _stamina;
}

int Warrior::dealDMG(int attack){
  int dealt = 0;
  int HP;
  int AP;
  
  srand((unsigned) time(NULL));
  if(attack == 1){
    dealt = 20 + (rand() % 16);
    return dealt;
  }else if(attack == 2){
    HP = 120 + (rand() % 61);
    AP = 50 + (rand() % 100);
    setHealth(getHealth()+HP);
    setStamina(getStamina()+AP);
    return dealt;
  }else if(attack == 3){
    if(getStamina() < 20){
      return dealt;
    }else{
    dealt = 40 + (rand() % 11);
    setStamina(getStamina()-20);
    return dealt;
      }
  }else if(attack == 4){
    if(getStamina() < 50){
      return dealt;
    }else{
    dealt = 65 + (rand() % 26);
    setStamina(getStamina()-50);
    return dealt;
      }
  }else if(attack == 5){
    if(getStamina() < 100){
      return dealt;
    }else{
    dealt = 150 + (rand() % 51);
    setStamina(getStamina()-100);
    return dealt;
      }
  }

  return dealt;
}
void Warrior::takeDMG(int defend){
  int taken;
  taken = getHealth() - defend;
  setHealth(taken);
}
void Warrior::userStats(){
  cout << "Name: " << getName() << endl;
  cout << "Health: " << getHealth() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Stamina: " << getStamina() << endl;
}
void Warrior::save(){
  ofstream outFile(getName());
  outFile << getName() << endl;
  outFile << getHealth() << endl;
  outFile << getLevel() << endl;
  outFile << getStamina() << endl;
  outFile.close();
  cout << "Character saved." << endl;
  userStats();
}
void Warrior::load(string username){
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
  setStamina(stoi(array[3]));
  inFile.close();
  cout << "Character loaded." << endl;
  userStats();
}

