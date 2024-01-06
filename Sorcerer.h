#ifndef SORCERER_H
#define SORCERER_H

#include "Character.h"

class Sorcerer : public Character{
public:
  Sorcerer();
  Sorcerer(string, int, int, int);

  int getMana();
  void setMana(int);

  int dealDMG(int);
  void takeDMG(int);
  void userStats();
  void save();
  void load(string);

private:
int mana;
};

#endif