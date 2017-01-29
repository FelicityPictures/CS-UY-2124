//By: Ng, Felicity
//Game Of Life
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void printBooleanVector(vector<bool> vector,int wide){
  for(int i = 0; i<vector.size();i++){
    if(i%wide==0){
      cout << "\n";
    }
    if(vector[i]){
      cout<< "*";
    }else{
      cout << " ";
    }
  }
  cout << "\n\n\n================\n";
}

void live(vector<bool>& mainG,int width){
  vector<bool> secondaryGrid=mainG;
  for(int i = 0; i<mainG.size();i++){
/*---CHECKS----------------------*/
    
    // cout << i << " ";

    int numbOfNeighbors=0;
    //check north

    int north = i-width;
    if(north<0){
      ;
    }else{
      if(mainG[north]){
	//	cout << "n ";
        numbOfNeighbors++;
      }
    }
    //check south
    int south = i+width;
    if(south>=mainG.size()){
      ;
    }else{
      if(mainG[south]){
	//	cout << "s ";
	numbOfNeighbors++;
      }
    }
    //check west
    int west = i-1;
    if(west<0 || west%width==width-1){
      ;
    }else{
      if(mainG[west]){
	//	cout << "w ";
	numbOfNeighbors++;
      }
    }
    //check east
    int east = i+1;
    if(east>mainG.size() || east%width==0){
      ;
    }else{
      if(mainG[east]){
	//	cout << "e ";
        numbOfNeighbors++;
      }
    }
    //check northeast
    int ne = i-width+1;
    if(ne<1 || ne%width==0){
      ;
    }else{
      if(mainG[ne]){
	//	cout << "ne ";
        numbOfNeighbors++;
      }
    }
    //check northwest
    int nw = i-width-1;
    if(nw<0 || nw%width==width-1){
      ;
    }else{
      if(mainG[nw]){
	//	cout << "nw ";
        numbOfNeighbors++;
      }
    }
    //check southeast
    int se = i+width+1;
    //cout << se%width << "\n";
    if(se>mainG.size() || se%width==0){
      ;
    }else{
      if(mainG[se]){
	//	cout << "se ";
        numbOfNeighbors++;
      }
    }
    //check southwest
    int sw = i+width-1;
    if(sw>mainG.size() || sw%width==width-1){
      // cout<< sw%width;
      //cout << " " << width-1;
    }else{
      if(mainG[sw]){
	//	cout << "sw ";
        numbOfNeighbors++;
      }
    }

    // cout << " " << numbOfNeighbors << "\n";

    if(mainG[i]){
      if(numbOfNeighbors < 2){
          secondaryGrid[i] = false;
      }else if(numbOfNeighbors > 3){
          secondaryGrid[i] = false;
      }else if(numbOfNeighbors==3 || numbOfNeighbors==2){
        secondaryGrid[i] = true;
      }
    }else{
      if(numbOfNeighbors==3){
        secondaryGrid[i]=true;
      }
    }
  }
/*-----END CHECKS ------ */
  mainG=secondaryGrid;
}

int main(){
    ifstream file("life.txt");
    vector<bool>mainGrid;
    int width;
    string forWidth;
    getline(file,forWidth);
    width = forWidth.length();
    // cout << forWidth << "\n";
    // cout << width << "\n";
    for(int i = 0; i<forWidth.size();i++){
      if(forWidth[i] == '*'){
	mainGrid.push_back(true);
      }else{
	mainGrid.push_back(false);
      }
    }
    while(file >> forWidth){
      for(int i = 0; i<forWidth.size();i++){
	if(forWidth[i] == '*'){
	  mainGrid.push_back(true);
	}else{
	  mainGrid.push_back(false);
	}
      }
    }
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
    live(mainGrid,width);
    printBooleanVector(mainGrid,width);
}
