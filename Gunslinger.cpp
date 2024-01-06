 #include "Gunslinger.h"

Gunslinger::Gunslinger() : Character()
{
  bullets = 8;
}
Gunslinger::Gunslinger(string _name, int _health, int _level, int _bullets) : Character(_name, _health, _level)
{
  bullets = _bullets;
  if(bullets >= 8){
    bullets = 8;
  }
}

int Gunslinger::getBullets(){
  return bullets;
}
void Gunslinger::setBullets(int _bullets){
  bullets = _bullets;
  if(bullets >= 8){
    bullets = 8;
  }
}

int Gunslinger::dealDMG(int attack){
  int dealt = 0;
  int HP;
  int AP;
  
  srand((unsigned) time(NULL));
  if(attack == 1){
    dealt = 40 + (rand() % 16);
    return dealt;
  }else if(attack == 2){
    HP = 100 + (rand() % 31);
    AP = 1 + (rand() % 7);
    setHealth(getHealth()+HP);
    setBullets(getBullets()+AP);
    return dealt;
  }else if(attack == 3){
    if(getBullets() < 2){
      return dealt;
    }else{
    dealt = 70 + (rand() % 71);
    setBullets(getBullets()-2);
    return dealt;
      }
  }else if(attack == 4){
    if(getBullets() < 1){
      return dealt;
    }else{
    AP = 1 + (rand() % getBullets());
    setBullets(getBullets()-AP);
      dealt = 30*AP;
    return dealt;
      }
  }else if(attack == 5){
    if(getBullets() <= 7){
      return dealt;
    }else{
    dealt = 200 + (rand() % 300);
    setBullets(getBullets()-8);
    return dealt;
      }
  }

  return dealt;
}
void Gunslinger::takeDMG(int defend){
  int taken;
  taken = getHealth() - defend;
  setHealth(taken);
}
void Gunslinger::userStats(){
  cout << "Name: " << getName() << endl;
  cout << "Health: " << getHealth() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Bullets: " << getBullets() << endl;
}
void Gunslinger::save(){
  ofstream outFile(getName());
  outFile << getName() << endl;
  outFile << getHealth() << endl;
  outFile << getLevel() << endl;
  outFile << getBullets() << endl;
  outFile.close();
  cout << "Character saved." << endl;
  userStats();
}
void Gunslinger::load(string username){
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
  setBullets(stoi(array[3]));
  inFile.close();
  cout << "Character loaded." << endl;
  userStats();
}
