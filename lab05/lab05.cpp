//Felicity Ng
//Lab05
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// class StudentRecord;
// class TimeSlot;

class Section{
  public:
    Section(const string& labName, const string& dayOfWeek, const int& timeOfDay)
    : name(labName), timeOfLab(dayOfWeek, timeOfDay){    }

    void addStudent(const string& newStudent){
      StudentRecord* newS(new StudentRecord(newStudent));
      studentGrades.push_back(newS);
    }
    void addGrade(const string& studentName, const int& grade, const int& week){
      for(size_t i = 0; i < studentGrades.size(); i++){
        if(studentGrades[i]->getName()==studentName){
          studentGrades[i]->changeGrade(week,grade);
        }
      }
    }
    void display() const{
      cout << "Section: " << name << ", ";
      cout <<  "Time slot: ";
      timeOfLab.display();
      cout << ", Students: ";
      if(studentGrades.size()<1){
        cout << "None\n";
      }else{
        cout << "\n";
        for(size_t i = 0; i < studentGrades.size(); i++){
          studentGrades[i]->display();
          cout << "\n";
        }
      }
    }
    ~Section(){
      cout << name << " is being deleted\n";
      for(size_t i = 0; i < studentGrades.size() ; i++){
        cout << studentGrades[i]->getName() << " is being deleted\n";
        delete studentGrades[i];
      }
      cout << "\n";
    }

    Section(const Section& other) {
      name = string(other.name);
      timeOfLab = TimeSlot(other.timeOfLab);
      for(size_t i = 0; i < other.studentGrades.size(); i++){
        StudentRecord* addressForAdding = new StudentRecord(*other.studentGrades[i]);
        studentGrades.push_back(addressForAdding);
      }
    }

  private:
    string name;
    class StudentRecord{
      public:
        StudentRecord(const string& newName) : name(newName){
          for(int i = 0; i < 14; i++){
            grades.push_back(-1);
          }
        }

        StudentRecord(const StudentRecord& original){
          name = string(original.name);
          for(int i = 0; i < 14; i++){
            int value = original.grades[i];
            grades.push_back(int(value));
          }
        }

        string getName(){
          return name;
        }
        void changeGrade(const int& week, const int& grade){
          grades[week-1]=grade;
        }
        void display() const{
          cout << "Name: " << name << ", ";
          cout << "Grades:";
          for(size_t i = 0; i < grades.size(); i++){
            cout << " " << grades[i];
          }
        }
      private:
        string name;
        vector<int> grades;
    };
    class TimeSlot{
      public:
        TimeSlot() : dayOfWeek("Sunday"), timeOfDay(0){}
        TimeSlot(const string& whatDay, const int& oClock) : dayOfWeek(whatDay), timeOfDay(oClock){
        }
        TimeSlot(const TimeSlot& other){
          dayOfWeek = other.dayOfWeek;
          timeOfDay = other.timeOfDay;
        }
        string getDayOfWeek(){
          return dayOfWeek;
        }
        int getTimeOfDay(){
          return timeOfDay;
        }
        void display() const{
          cout << "[Day: " << dayOfWeek << ", Start time: ";
          if(timeOfDay>=12){
            if(timeOfDay==12){
              cout << timeOfDay;
            }else{
              cout << timeOfDay-12;
            }
            cout << "pm]";
          }else{
            if(timeOfDay==0){
              cout << 12;
            }else{
              cout << timeOfDay;
            }
            cout << "am]";
          }
        }
      private:
        string dayOfWeek;
        int timeOfDay;
    };
    TimeSlot timeOfLab;
    vector<StudentRecord*> studentGrades;

};

class LabWorker{
  public:
    // LabWorker() : name("Felicity"){
    // }
    LabWorker(const string& newName) : name(newName), labSection(NULL){
    }
    void display() const{
      if(labSection==NULL){
      cout << name;
      cout << " does not have a section\n";
      }else{
        cout << "Jane has ";
        labSection->display();
      }
    }
    void addSection(Section& newSection){
      labSection = &newSection;
    }
    void addGrade(const string& studentName, const int& grade, const int& week){
      labSection->addGrade(studentName,grade,week);
    }

    private:
      string name;
      Section* labSection;
};

void doNothing(Section sec){
  sec.display();
}

int main(){
  cout << "Test 1: Defining a section\n";
  Section secA2("A2", "Tuesday", 16);
  secA2.display();

  cout << "\nTest 2: Adding students to a section\n";
  secA2.addStudent("John");
  secA2.addStudent("George");
  secA2.addStudent("Paul");
  secA2.addStudent("Ringo");
  secA2.display();

  cout << "\nTest 3: Defining a lab worker.\n";
  LabWorker moe("Moe");
  moe.display();

  cout << "\nTest 4: Adding a section to a lab worker.\n";
  moe.addSection( secA2 );
  moe.display();

  cout << "\nTest 5: Adding a second section and lab worker.\n";
  LabWorker jane( "Jane" );
  Section secB3( "B3", "Thursday", 11 );
  secB3.addStudent("Thorin");
  secB3.addStudent("Dwalin");
  secB3.addStudent("Balin");
  secB3.addStudent("Kili");
  secB3.addStudent("Fili");
  secB3.addStudent("Dori");
  secB3.addStudent("Nori");
  secB3.addStudent("Ori");
  secB3.addStudent("Oin");
  secB3.addStudent("Gloin");
  secB3.addStudent("Bifur");
  secB3.addStudent("Bofur");
  secB3.addStudent("Bombur");
  jane.addSection( secB3 );
  jane.display();

  cout << "\nTest 6: Adding some grades for week one\n";
  moe.addGrade("John", 17, 1);
  moe.addGrade("Paul", 19, 1);
  moe.addGrade("George", 16, 1);
  moe.addGrade("Ringo", 7, 1);
  moe.display();

  cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
  moe.addGrade("John", 15, 3);
  moe.addGrade("Paul", 20, 3);
  moe.addGrade("Ringo", 0, 3);
  moe.addGrade("George", 16, 3);
  moe.display();

  cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";

  cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
  doNothing(secA2);
  cout << "Back from doNothing\n\n";
}
