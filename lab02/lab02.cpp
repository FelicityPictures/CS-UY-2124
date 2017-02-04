//Felicity Ng
//Lab02
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Molecule{
  vector<string> name;
  int carbons;
  int hydrogens;
};

size_t findSameFormula(const vector<Molecule>& vect, int carbon, int hydrogen){
  for(size_t i = 0; i < vect.size(); i++){
    if(vect[i].carbons == carbon && vect[i].hydrogens == hydrogen){
      return i;
    }
  }
  return vect.size();
}

void printVectorinOrder(const vector<Molecule>& vect,int maxC){
  for(int c = 0; c <= maxC; c++){
    for(size_t i = 0; i < vect.size(); i++){
      if(vect[i].carbons == c){
        cout << "C";
        cout << vect[i].carbons;
        cout << "H";
        cout << vect[i].hydrogens;
        cout << " ";
        for(int n = 0; n < vect[i].name.size(); n++){
          cout << vect[i].name[n] << " ";
        }
        cout << "\n";
      }
    }
  }
}

int main(){
  vector<Molecule>molecule;

  ifstream file("hydrocarbs.txt");
  string name;
  char carbon,hydrogen;
  int C,H;
  size_t whereInVector;
  int biggestCarbonInFormula=0;
  while(file >> name >> carbon >> C >> hydrogen >> H){
    whereInVector = findSameFormula(molecule,C,H);
    if(whereInVector == molecule.size()){
      Molecule newMolecule;
      newMolecule.carbons = C;
      newMolecule.hydrogens = H;
      newMolecule.name.push_back(name);
      molecule.push_back(newMolecule);
    }else{
      molecule[whereInVector].name.push_back(name);
    }
    if(C > biggestCarbonInFormula){
      biggestCarbonInFormula=C;
    }
  }
  printVectorinOrder(molecule,biggestCarbonInFormula);
}
