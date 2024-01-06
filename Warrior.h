#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character{
public:
  Warrior();
  Warrior(string, int, int, int);

  int getStamina();
  void setStamina(int);

  int dealDMG(int);
  void takeDMG(int);
  void userStats();
  void save();
  void load(string);

private:
int stamina;
};

#endif