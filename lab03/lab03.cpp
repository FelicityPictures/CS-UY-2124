//Felicity Ng
//Sandwich company simulator
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//task one: basic sandwich class
class BasicSandwich{
public:
  //task four: initialize mayo to be 0.1
  BasicSandwich() : breadSlices(2), tomatoSlices(2), cheese(1),
  mustard(0.05), mayo(1.0){

  }
  //task five: sandwich with changes
  BasicSandwich(int tomato, int cheese, double mustard=0.05, double mayo=1.0)
  : breadSlices(2), tomatoSlices(tomato), cheese(cheese), mustard(mustard), mayo(mayo){

  }
  //task six: accessor methods
  int getBread() const{
    return breadSlices;
  }
  int getTomatoSlices() const{
    return tomatoSlices;
  }
  int getCheese() const{
    return cheese;
  }
  double getMustard() const{
    return mustard;
  }
  double getMayo() const{
    return mayo;
  }
  //task seven: mutator methods

  /* bread should be a set value
  int setBread(const int& newValue){
    breadSlices = newValue;
    return breadSlices;
  }
  */

  int setTomatoSlices(const int& newValue){
    tomatoSlices = newValue;
    return tomatoSlices;
  }
  int setCheese(const int& newValue){
    cheese = newValue;
    return cheese;
  }
  double setMustard(const int& newValue){
    mustard = newValue;
    return mustard;
  }
  double setMayo(const int& newValue){
    mayo = newValue;
    return mayo;
  }
  //task two: display method
  void print() const{
    cout << "Bread slices: " << getBread() << "\n";
    cout << "Cheese: " << getCheese() << "\n";
    cout << "Mayo: " << getMayo() << "\n";
    cout << "Tomato Slices: " << getTomatoSlices() << "\n";
    cout << "Mustard: " << getMustard() << "\n";
  }

private:
  //task eight: compiler warning when setting to a default value
  //int breadSlices = 2;
  //int tomatoSlices, cheese;
  int breadSlices, tomatoSlices, cheese;
  //task three: default initialization
  double mustard, mayo;
};

//task ten: Truck class
class SandwichTruck{
  public:

    //SandwichTruck(){}

    void insertSandwich(const BasicSandwich& sandwich){
      sandwiches.push_back(sandwich);
    }

    int getTotalBread() const{
      int total = 0;
      for(size_t i = 0; i < sandwiches.size(); i++){
        total += sandwiches[i].getBread();
      }
      return total;
    }

    int getTotalTomatoes() const{
      int total = 0;
      for(size_t i = 0; i < sandwiches.size(); i++){
        total += sandwiches[i].getTomatoSlices();
      }
      return total;
    }

    int getTotalCheese() const{
      int total = 0;
      for(size_t i = 0; i < sandwiches.size(); i++){
        total += sandwiches[i].getCheese();
      }
      return total;
    }

    double getTotalMustard() const{
      double total = 0;
      for(size_t i = 0; i < sandwiches.size(); i++){
        total += sandwiches[i].getMustard();
      }
      return total;
    }

    double getTotalMayo() const{
      double total = 0;
      for(size_t i = 0; i < sandwiches.size(); i++){
        total += sandwiches[i].getMayo();
      }
      return total;
    }

    BasicSandwich getSandwichByCustomerNumber(int n){
      return sandwiches[n];
    }

    void checkOutAllIngredients() const{
      cout << "Total Bread: " << getTotalBread() << "\n";
      cout << "Total Tomatoes: " << getTotalTomatoes() << "\n";
      cout << "Total Cheese: " << getTotalCheese() << "\n";
      cout << "Total Mayo: " << getTotalMayo() << "\n";
      cout << "Total Mustard: " << getTotalMustard() << "\n";
    }

  private:
    vector<BasicSandwich> sandwiches;
};

int main(){
  SandwichTruck truck = SandwichTruck();
//Task eleven: Simulate
  BasicSandwich customer1 = BasicSandwich();
  BasicSandwich customer2 = BasicSandwich();
  customer2.setMustard(0);
  BasicSandwich customer3 = BasicSandwich(2, 2);
  BasicSandwich customer4 = BasicSandwich();
  truck.insertSandwich(customer1);
  truck.insertSandwich(customer2);
  truck.insertSandwich(customer3);
  truck.insertSandwich(customer4);
  truck.checkOutAllIngredients();
  cout << "Customer 2's mustard: " << truck.getSandwichByCustomerNumber(1).getMustard() << "\n";

}
