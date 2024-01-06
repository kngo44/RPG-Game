#ifndef GUNSLINGER_H
#define GUNSLINGER_H

#include "Character.h"

class Gunslinger : public Character{
public:
  Gunslinger();
  Gunslinger(string, int, int, int);

  int getBullets();
  void setBullets(int);

  int dealDMG(int);
  void takeDMG(int);
  void userStats();
  void save();
  void load(string);

private:
int bullets;
};

#endif