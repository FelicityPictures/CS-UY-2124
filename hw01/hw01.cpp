//By Felicity Ng
//hw01: Caesar Cypher

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printVectorBackwards(vector<string>vector){
  for(int i = vector.size()-1;i>=0;i--){
    cout << vector[i] << "\n";
  }
  cout << "\n";
}

char decryptCharacter(char c,int step){
  //checks if it's a lowercase letter
  if(c>=97 && c<=122){
    //checks if it will wrap around
    if(c<'a'+step){
      return c-step+26;
    }else{
      return c-step;
    }
  }
  return c;
}

void decryptStringsInVector(vector<string>& vect,int step){
  for(int line=0;line<vect.size();line++){
    for(int character = 0;character<vect[line].length();character++){
      vect[line][character]=decryptCharacter(vect[line][character],step);
    }
  }
}


int main(){
  ifstream file("encrypted.txt");
  
  int step;
  file >> step;

  vector <string> message;
  string putIntoVector;

  getline(file,putIntoVector); //gets rid of first blank line

  while(getline(file,putIntoVector)){ //fills vector
    message.push_back(putIntoVector);
  }

  printVectorBackwards(message);
  decryptStringsInVector(message,step);
  printVectorBackwards(message);
}
