//Felicity Ng
//hw03
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Warrior{
  public:

    Warrior(const string& name, const string& weaponName, int weaponStrength)
    : name(name), weapon(weaponName,weaponStrength){
    }
    int getStrength() const{
      return weapon.getStrength();
    }
    void setStrength(int newStrength){
      weapon.setStrength(newStrength);
    }
    string getName() const{
      return name;
    }
    string getWeaponName() const{
      return weapon.getName();
    }

  private:

    class Weapon{
      public:
        Weapon(const string& weapName, int weapStrength) : name(weapName), strength(weapStrength){
        }
        int getStrength() const{
          return strength;
        }
        void setStrength(int newStrength){
          strength = newStrength;
        }
        string getName() const{
          return name;
        }
      private:
        string name;
        int strength;
    };

    string name;
    Weapon weapon;
};

//returns place in vector where warrior with that name is located
size_t findWarriorInVector(const vector<Warrior>& vect, const string& name){
  for(size_t i = 0; i < vect.size(); i++){
    if(vect[i].getName() == name){
      return i;
    }
  }
  return vect.size();
}
/*==================================*/
void battle(vector<Warrior>& vect, const string& nameOfChallenger,
	    const string& nameOfChallenged){
  cout << nameOfChallenger << " battles " << nameOfChallenged << "\n";
  Warrior& challenger = vect[findWarriorInVector(vect,nameOfChallenger)];
  Warrior& challenged = vect[findWarriorInVector(vect,nameOfChallenged)];
  if(challenger.getStrength() == challenged.getStrength()){
    if (challenger.getStrength() > 0){ //alive but equal in strength
      challenger.setStrength(0);
      challenged.setStrength(0);
      cout << "Mutual Annihalation: " << nameOfChallenger << " and ";
      cout << nameOfChallenged << " die at each other's hands\n";
    }else{ //both dead
      cout << "Oh, NO! They're both dead! Yuck!\n";
    }
  }else{
    //both alive but unequal in strength
    if(challenger.getStrength() > 0 && challenged.getStrength() > 0){
      int challengersStrengthBeforeDeduction = challenger.getStrength();
      challenger.setStrength(challenger.getStrength() - challenged.getStrength());
      challenged.setStrength(challenged.getStrength() - challenger.getStrength());
      if(challenger.getStrength() > challenged.getStrength()){
      	challenged.setStrength(0);
      	cout << nameOfChallenger << " defeats " << nameOfChallenged << "\n";
      }else{
      	challenger.setStrength(0);
      	cout << nameOfChallenged << " defeats " << nameOfChallenger << "\n";
      }
    }else{ //one of them is dead
      if(challenger.getStrength() == 0){
	cout << "You're dead, " << nameOfChallenger << "\n";
      }else{
	cout << "He's dead, " << nameOfChallenger << "\n";
      }
    }
  }
}
/*=======================================================*/
void printStatusOfWarriors(const vector<Warrior>& vect){
  cout << "There are: " << vect.size() << " warriors\n";
  for(size_t i = 0; i < vect.size(); i++){
    cout << "Warrior: " << vect[i].getName() << "; ";
    cout << " Weapon: " << vect[i].getWeaponName() << ", " << vect[i].getStrength() << "\n";
  }
}

int main(){
  ifstream file("warriors.txt");
  vector<Warrior> warriors;
  string action, mainName, weaponName, opponent;
  int strength;
  while(file >> action){
    if(action == "Warrior"){
      file >> mainName;
      file >> weaponName;
      file >> strength;
      Warrior aNew(mainName, weaponName, strength);
      warriors.push_back(aNew);
    }else if(action == "Status"){
      printStatusOfWarriors(warriors);
    }else if(action == "Battle"){
      file >> mainName;
      file >> opponent;
      battle(warriors, mainName, opponent);
    }
  }
}
