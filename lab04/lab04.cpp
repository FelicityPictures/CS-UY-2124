//Felicity Ng
//Lab 04: Pointer basics

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        roomie = &newRoomate;        // now I have a new roomie
        newRoomate.roomie = this;    // and now they do too
    }
    string getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    string getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie;
    string name;
};

struct Complex {
 double real;
 double img;
};

class SpeakerSystem {
   public:
   void vibrateSpeakerCones( unsigned signal ) const {

      cout << "Playing: " << signal << "Hz sound..." << endl;
      cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};

class Amplifier {
public:
  //remove const SpeakerSystem if you want to modify speakers
   void attachSpeakers( const SpeakerSystem& spkrs )
   {
      if( attachedSpeakers )
         cout << "already have speakers attached!\n";
      else
         attachedSpeakers = &spkrs;
   }
   void detachSpeakers()
   { attachedSpeakers = NULL; }
     // should there be an "error" message if not attached?
   void playMusic( ) const {
      if( attachedSpeakers )
         attachedSpeakers -> vibrateSpeakerCones( 440 );
      else
         cout << "No speakers attached\n";
   }
private:
   const SpeakerSystem* attachedSpeakers = NULL;
};

class Colour {
public:
    Colour( const string& name, unsigned r, unsigned g, unsigned b )
        : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;    // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};

int main(){
  // int x;
  // x = 10;
  // cout << "x = " << x << "\n";
  // cout << &x;
  // int* p;
  // p = &x;
  //p = 0x28ff18;
  // cout << "p: " << p << "\n";
  // cout << "p points to where " << *p << " is stored\n";
  // cout << "*p contains " << *p << endl;
  // *p = -2763;
  // cout << "p points to where " << *p << " is stored\n";
  // cout << "*p now contains " << *p << endl;
  // cout << "x now contains " << x << endl;
//task 12
//   int y(13);
//   cout << "y contains " << y << endl;
//   p = &y;
//   cout << "p now points to where " << *p << " is stored\n";
//   cout << "*p now contains " << *p << endl;
//   *p = 980;
//   cout << "p points to where " << *p << " is stored\n";
//   cout << "*p now contains " << *p << endl;
//   cout << "y now contains " << y << endl;
// //task 13
//   int* q;
//   q = p;
//   cout << "q points to where " << *q << " is stored\n";
//   cout << "*q contains " << *q << endl;
// //task 14
//   double d(33.44);
//   double* pD(&d);
//   // cout << *pD << endl;
//   *pD = *p;
//   // cout << *pD << endl;
//   *pD = 73.2343;
//   *p  = *pD;
//   *q  = *p;
  //pD  = p;
  //p   = pD;

//task 15
  // int joe( 24 );
  // const int sal( 19 );
  // int*  pI;
  // pI = &joe;
  // cout << pI << endl;
  // *pI = 234;
  // cout << pI << endl;
  // cout << &joe << endl;
  // // pI = &sal;//error because sal is a const int*
  // *pI = 7623;
  // cout << pI << endl;
  // cout << &joe << endl;

  // const int* pcI;
  // cout << pcI << endl;
  // pcI = &joe; //allowed
  // cout << pcI << endl;
  // //*pcI = 234;
  // //error in assigning to a straight int
  // pcI = &sal;
  // cout << pcI << endl;
  // //*pcI = 7623;

  //cpI is const so you can't change it at all
  //int* const cpI;
  //int* const cpI(&joe);
  //int* const cpI(&sal);
  //cpI = &joe;
  //*cpI = 234;
  //cpI = &sal;
  //*cpI = 7623;

  //no reassignments because cpcI is const
  //can't change address b/x address is const as well
  // const int* const cpcI; //uninitialized error
  // const int* const cpcI(&joe);
  // const int* const cpcI(&sal);
  // cpcI = &joe;
  // *cpcI = 234;
  // cpcI = &sal;
  // *cpcI = 7623;

// //task 16

//   Complex c = {11.23,45.67};
//   Complex* pC(&c);
//   cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
//   cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;

// //task 17
//   class PlainOldClass {
//     public:
//      PlainOldClass() : x(-72) {}
//      int getX() const { return x; }
//      void setX( int val )  { x = val; }
//     private:
//      int x;
//   };
//
//   PlainOldClass poc;
//   PlainOldClass* ppoc( &poc );
//   cout << ppoc->getX() << endl;
//   ppoc->setX( 2837 );
//   cout << ppoc->getX() << endl;

// //task 18
//   class PlainOldClass {
//   public:
//      PlainOldClass() : x(-72) {}
//      int getX() const { return x; }
//      void setX( int x )  { this->x = x; } // HMMMM???
//   private:
//      int x;
//   };

// //task 19
  int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
//   // cout << &pDyn << endl;
  *pDyn = 17;
//   cout << "The " << *pDyn
//      << " is stored at address " << pDyn
//      << " which is in the heap\n";
//
// // task 20
//   cout << pDyn << endl;
//   delete pDyn;
//   cout << pDyn << endl;
//   cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
//   cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
//
// // task 21
//   pDyn = NULL;
//   double* pDouble( NULL );
//
// // task 22
//   cout << "Can we dereference NULL?  " << *pDyn << endl;
//   cout << "Can we dereference NULL?  " << *pDouble << endl;

// // task 24
//   double* pTest = new double(12);
//   delete pTest;
//   pTest = NULL;
//   delete pTest; // safe

// // task 25 //but it worked with double delete
//   short* pShrt = new short( 5 );
//   delete pShrt;
//   delete pShrt;

// // task 26
//   long jumper( 12238743 );
//   delete jumper;
//   long* ptrTolong( &jumper );
//   delete ptrTolong;
//   Complex cmplx;
//   delete cmplx;

// //task 27
//   vector<Complex*> complV; // can hold pointers to Complex objects
//   Complex* tmpPCmplx;      // space for a Complex pointer
//   for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
//    tmpPCmplx = new Complex; // create a new Complex object on the heap
//    tmpPCmplx->real = ndx;   // set real and img to be the
//    tmpPCmplx->img  = ndx;   // value of the current ndx
//    complV.push_back( tmpPCmplx ); // store the ADDRESS of the object in a vector or pointer to Complex
//   }
//   // display the objects using the pointers stored in the vector
//   for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
//     cout << complV[ ndx ]->real << endl;
//     cout << complV[ ndx ]->img  << endl;
//   }
//   // release the heap space pointed at by the pointers in the vector
//   for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
//     delete complV[ ndx ];
//   }
//   // clear the vector
//   complV.clear();
//   // for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
//   //   cout << complV[ ndx ]->real << endl;
//   //   cout << complV[ ndx ]->img  << endl;
//   // }

// //task 28
//   vector< Colour* > colours;
//   string inputName;
//   unsigned inputR, inputG, inputB;
//
//   // fill vector with Colours from the file
//   // this could be from an actual file but here we are using the keyboard instead of a file
//   //(so we don't have to create an actual file)
//   // do you remember the keystroke combination to indicate "end of file" at the keyboard?
//   // somehow the while's test has to fail - from keyboard input
//   while ( cin >> inputName >> inputR >> inputG >> inputB ) {
//     colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
//   }
//
//   // display all the Colours in the vector:
//   for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
//     colours[ndx]->display();
//     cout << endl;
//   }

// // task 29
//   SpeakerSystem ss;
//   Amplifier a;
//   a.detachSpeakers();
//   a.playMusic();
//   a.attachSpeakers(ss);
//   a.playMusic();
//   a.detachSpeakers();
//   a.playMusic();

//task 30
// write code to model two people in this world
Person joeBob("Joe Bob"), billyJane("Billy Jane");
// now model these two becoming roommates
joeBob.movesInWith( billyJane );
// did this work out?
cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;

}
