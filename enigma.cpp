#include "enigma.h"

using namespace std;

int plugBoard::readFile(const string& argument)
{
    ifstream in_stream;
    in_stream.open(argument);

    //need to pass file as a function to be read
    if(in_stream.fail())
    {
      //make sure you understand what cerr is showing
      cerr << "ERROR_OPENING_CONFIGURATION_FILE" << endl;
      return 11;
    }
    //Fidelis: Basic guide to operator overloading to read in the files
    int num;
    int position = 0;
    //peek value to check if stream is correct
    if ()
    //http://www.cplusplus.com/reference/istream/istream/peek/ use peek functionality to check if it has exceeded or not.

    char c= in_stream.peek();

    in_stream >> num;

    while(!in_stream.eof())
    {
      //INSERT values into arrays
      plugBoardValues[position] = num;
      position= position + 1;
      in_stream >> num;
    }

    for (int i = 0;i < position; i++)
    {
      cout << plugBoardValues[i] << endl;
    }

    in_stream.close();
    return 0;
}


int reflector::readFile(const string& argument)
{
    ifstream in_stream;
    in_stream.open(argument);
    if(in_stream.fail())
    {
      cerr << "ERROR_OPENING_CONFIGURATION_FILE" << endl;
      return 11;
    }
    //Fidelis: Basic guide to operator overloading to read in the files
    int num;
    int position = 0;
    in_stream >> num;
    while(!in_stream.eof())
    {
      if(valueWithinRange(num) == false)
        return 3;
      //INSERT values into arrays
      reflectorValues[position] = num;
      position= position + 1;
      in_stream >> num;
    }
    cout << "the position is: " << position << endl;
    if (checkReflectorComplete(position) == false)
    {
      cerr << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS" << endl;
      return 6;
    }
    for (int i = 0; i < position; i++)
    {
      cout << reflectorValues[i] << endl;
    }

    in_stream.close();
    return 0;
}


bool valueWithinRange(int number)
{
  if (number < 0 || number > 25)
  {
    return false;
  }
  return true;
}


bool checkReflectorComplete(int position)
{
  if (position!= 26)
    return false;
  else
    return true;
}
