#include <iostream>
#include <fstream>
#include "errors.h"

using namespace std;

class plugBoard{
public:
  int readFile(const string& argument);
  // check if use of static here is correct
  const static int PLUGBOARD_MAX = 26;
  // probably best to use vector but that can be declared later
  int plugBoardValues[PLUGBOARD_MAX];
  int position = 0;
};


class reflector{
public:
  int readFile(const string& argument);
  const static int REFLECTOR_MAX = 26;
  int reflectorValues[REFLECTOR_MAX];
  int position = 0;
};

bool valueWithinRange(const int number);

bool checkReflectorComplete(const int position);

bool checkPlugBoardEven(const int position);

bool invalidIndex(const int input);

bool checkChar(ifstream &in_stream);

void check_error(int input);
