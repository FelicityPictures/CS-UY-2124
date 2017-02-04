//Felicity Ng
//hw02 warriors battle to the death

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior{
  string name;
  int strength;
};

//returns place in vector where warrior with that name is located
size_t findWarriorInVector(const vector<Warrior>& vect, const string& name){
  for(size_t i = 0; i < vect.size(); i++){
    if(vect[i].name == name){
      return i;
    }
  }
  return vect.size();
}

void battle(vector<Warrior>& vect, const string& nameOfChallenger,
	    const string& nameOfChallenged){
  cout << nameOfChallenger << " battles " << nameOfChallenged << "\n";
  Warrior& challenger = vect[findWarriorInVector(vect,nameOfChallenger)];
  Warrior& challenged = vect[findWarriorInVector(vect,nameOfChallenged)];
  if(challenger.strength == challenged.strength){
    if (challenger.strength > 0){ //alive but equal in strength
      challenger.strength = 0;
      challenged.strength = 0;
      cout << "Mutual Annihalation: " << nameOfChallenger << " and ";
      cout << nameOfChallenged << " die at each other's hands\n";
    }else{ //both dead
      cout << "Oh, NO! They're both dead! Yuck!\n";
    }
  }else{
    //both alive but unequal in strength
    if(challenger.strength > 0 && challenged.strength > 0){
      int challengersStrengthBeforeDeduction = challenger.strength;
      challenger.strength = challenger.strength-challenged.strength;
      challenged.strength = challenged.strength-challenger.strength;
      if(challenger.strength > challenged.strength){
	challenged.strength = 0;
	cout << nameOfChallenger << " defeats " << nameOfChallenged << "\n";
      }else{
	challenger.strength = 0;
	cout << nameOfChallenged << " defeats " << nameOfChallenger << "\n";
      }
    }else{ //one of them is dead
      if(challenger.strength == 0){
	cout << "You're dead, " << nameOfChallenger << "\n";
      }else{
	cout << "He's dead, " << nameOfChallenger << "\n";
      }
    }
  }
}

void printStatusOfWarriors(const vector<Warrior>& vect){
  cout << "There are: " << vect.size() << " warriors\n";
  for(size_t i = 0; i < vect.size(); i++){
    cout << "Warrior: " << vect[i].name << "; ";
    cout << " Strength: " << vect[i].strength << "\n";
  }
}

int main(){
  ifstream file("warriors.txt");
  vector<Warrior> warriors;
  string action, mainName, opponent;
  int strength;
  Warrior aNew;
  while(file >> action){
    if(action == "Warrior"){
      file >> mainName;
      file >> strength;
      aNew.name = mainName;
      aNew.strength = strength;
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
