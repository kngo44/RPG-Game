#include "Character.h"

Character::Character(){
  name = "Noob";
  health = 500;
  level = 1;
}

Character::Character(string _name, int _health, int _level){
  name = _name;
  health = _health;
  level = _level;
}

string Character::getName(){
  return name;
}
int Character::getHealth(){
  return health;
}
int Character::getLevel(){
  return level;
}

void Character::setName(string _name){
   name = _name;
}
void Character::setHealth(int _health){
  health = _health;
}
void Character::setLevel(int _level){
  level = _level;
}