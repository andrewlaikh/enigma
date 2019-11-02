#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include "errors.h"

using namespace std;

//forward declaration of class although could just pass in by reference if required.
class plugBoard;
class reflector;
class inputText;
class rotor;

class intermediateOutput{
public:
  vector<char> output;
  //view this function can be broken down
  void transform(const int &argNumber, const inputText &inputText, const plugBoard &plugBoard, const reflector &reflector);
  //maybe rename this to convert?
  int letterToNumber(const char input);
  char numberToLetter(const char temp, const int tempNumber);
  //probably a better idea is to pass in the data members that you need bc it makes it less expensive to copy
  int reflectorTransform(const int number, const reflector &reflector);
  int plugBoardTransform(const int tempNumber, const plugBoard &plugBoard);
};


//probably not the most elegant way to share output but it works
class plugBoard{
public:
  friend int intermediateOutput::plugBoardTransform(const int number, const plugBoard &plugBoard);
  int readFile(const string& argument);
  // check if use of static here is correct
  const static int PLUGBOARD_MAX = 26;
  // probably best to use vector but that can be declared later
  int plugBoardValues[PLUGBOARD_MAX];
  int position = 0;
};

class reflector{
public:
  friend int intermediateOutput::reflectorTransform(const int number, const reflector &reflector);
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

//still need to pass in rotor so this is a bit clunky and should definitely be reworked.
class rotor{
  friend class intermediateOutput;
  vector<int> rotorPosition;
  vector<int> notchPositions;
  int readFile(const string &argument);
};


bool valueWithinRange(const int number);

bool checkReflectorComplete(const int position);

bool checkPlugBoardEven(const int position);

bool invalidIndex(const int input);

bool checkChar(ifstream &in_stream);

void check_error(int input);
