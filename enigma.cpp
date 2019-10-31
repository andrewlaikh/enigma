#include <iostream>
#include "engima.h"

using namespace std;

class plugBoard{
public:
  void readFile(const string& argument)
  {
    ifstream in_stream;
    in_stream.open(argv[1]);
    if(in_stream.fail())
    {
      cout << "Sorry, file could not be opened." << endl;
      exit(1);
    }
    //Fidelis: Basic guide to operator overloading to read in the files
    int num;
    in_stream >> num;
    while(!in_stream.eof())
    {
      //INSERT file into pairings and make sure it works. 
      cout << num << endl;
      in_stream >> num;
    }
    in_stream.close();
    //create output file to ensure documentation is complete.
  }
private:
  int Pairings[52];


}
