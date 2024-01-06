#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

class Character{
public:
  Character();
  Character(string, int, int);

  string getName();
  int getHealth();
  int getLevel();
  void setName(string);
  void setHealth(int);
  void setLevel(int);

  virtual int dealDMG(int)=0;
  virtual void takeDMG(int)=0;
  virtual void userStats()=0;
  virtual void save()=0;
  virtual void load(string)=0;

private:
  string name;
  int health;
  int level;
};

#endif