#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include "errors.h"

using namespace std;

//probably not the most elegant way to share output but it works
class plugBoard{
public:
  friend class intermediateOutput;
  int readFile(const string& argument);
  // check if use of static here is correct
  const static int PLUGBOARD_MAX = 26;
  // probably best to use vector but that can be declared later
  int plugBoardValues[PLUGBOARD_MAX];
  int position = 0;
};

class reflector{
public:
  friend class intermediateOutput;
  int readFile(const string& argument);
  const static int REFLECTOR_MAX = 26;
  int reflectorValues[REFLECTOR_MAX];
  int position = 0;
};

class inputText{
public:
  friend class intermediateOutput;
  vector<char> input;
  int readFile(const string& argument);
};

class rotor{
  friend class intermediateOutput;
  vector<int> rotorValues;
};

class intermediateOutput{
public:
  vector<char> output;
  void transform(const int &argNumber, const vector<char> input);
  //maybe rename this to convert?
  int letterToNumber(const char input);
  char numberToLetter(const char temp, const int tempNumber);
  int plugBoardTransform(const int number);
  int reflectorTransform(const int number);

};


bool valueWithinRange(const int number);

bool checkReflectorComplete(const int position);

bool checkPlugBoardEven(const int position);

bool invalidIndex(const int input);

bool checkChar(ifstream &in_stream);

void check_error(int input);
