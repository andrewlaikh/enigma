#include "enigma.h"

using namespace std;

int plugBoard::readFile(const string& argument)
{
  ifstream in_stream;
  in_stream.open(argument);

  //need to pass file as a function to be read. NOt elegant way, is there a better way?
  if(in_stream.fail())
  {
    return 11;
  }

  int numberEntry;

  //not will's recommended solution but it works.
  while(!in_stream.eof())
  {
    in_stream >> ws;
    in_stream >> numberEntry;
    if (invalidIndex(numberEntry)==true)
    {
      return 3;
    }
    plugBoardValues[position] = numberEntry;
    //check for end of stream
    if (checkChar(in_stream)==false)
    {
      return 4;
    }
    //note that position goes over by 1.
    position++;

  }
  if (checkPlugBoardEven(position)==false)
  {
    return 6;
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
    return 11;
  }

  int numberEntry;

  //not will's recommended solution but it works.
  while(!in_stream.eof())
  {
    in_stream >> ws;
    in_stream >> numberEntry;
    if (invalidIndex(numberEntry)==true)
    {
      return 3;
    }
    // if(invalidReflectorMapping(numberEntry, reflectorValues[], position)==true)
    // {
    //   return 9;
    // }
    //INSERT values into arrays
    reflectorValues[position] = numberEntry;
    if (checkChar(in_stream)==false)
    {
      return 4;
    }
    position++;
  }

  if (checkReflectorComplete(position) == false)
  {
    return 6;
  }

  for (int i = 0; i < position; i++)
  {
    cout << reflectorValues[i] << endl;
  }
  in_stream.close();
  return 0;
}


bool valueWithinRange(const int number)
{
  if (number < 0 || number > 25)
  {
    return false;
  }
  return true;
}

bool checkPlugBoardEven(const int position)
{
  //this is confusing, rewrite to make it clearer instead of position%2! = 1 is true
  if (position%2==0)
  {
    return true;
  }
  else
  return false;
}

bool checkReflectorComplete(const int position)
{
  if (position!= 26)
  return false;
  else
  return true;
}

bool checkChar(ifstream &in_stream)
{
  in_stream >> ws;
  int peekValue = (int)in_stream.peek();
  if((peekValue < 48 || peekValue > 57) && peekValue!= -1)
  {
    return false;
  }
  else
  return true;
}

bool invalidIndex(const int input)
{
  if (input > 25 || input < 0)
  {
    return true;
  }
  else
  return false;
}

//
// //to be completed
// bool invalidReflectorMapping(const int input, const int position, const int& reflectorValues[])
// {
//   for (int i = 0; i < position; i++)
//   {
//     if(reflectorValues[i]==input)
//     return true;
//   }
//   else
//     return false;
// }

// bool invalidReflectorMapping(const int input, const int position, const int& reflectorValues[])


void check_error(int input)
{
  switch(input)
  {
    case 0:
    break;
    case 1:
    cerr << "INSUFFICIENT_NUMBER_OF_PARAMETERS"<< endl;
    exit(1);
    case 2:
    cerr << "INVALID_INPUT_CHARACTER "<< endl;
    exit(1);
    case 3:
    cerr << "INVALID_INDEX"<< endl;
    exit(1);
    case 4:
    cerr << "NON_NUMERIC_CHARACTER"<< endl;
    exit(1);
    case 5:
    cerr << "IMPOSSIBLE_PLUGBOARD_CONFIGURATION"<< endl;
    exit(1);
    case 6:
    cerr << "INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS"<< endl;
    exit(1);
    case 7:
    cerr << "INVALID_ROTOR_MAPPING"<< endl;
    exit(1);
    case 8:
    cerr << "NO_ROTOR_STARTING_POSITION"<< endl;
    exit(1);
    case 9:
    cerr << "INVALID_REFLECTOR_MAPPING"<< endl;
    exit(1);
    case 10:
    cerr << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS"<< endl;
    exit(1);
    case 11:
    cerr << "ERROR_OPENING_CONFIGURATION_FILE"<< endl;
    exit(1);
  }
  exit;
}


int inputText::readFile(const string& argument)
{
  ifstream in_stream;
  in_stream.open(argument);
  if(in_stream.fail())
  {
    return 11;
  }

  char entry;
  //first line here trying to get first entry; WON'T enter if it fails.
  in_stream >> noskipws >> entry;
  while(!in_stream.eof())
  {
    input.push_back(entry);
    in_stream >> noskipws >> entry;
  }
  in_stream.close();
  return 0;
}

int outputText::outputFile(const string &argument, const vector<char> input)
{
  ofstream of_stream;
  of_stream.open(argument);
  if(of_stream.fail())
  {
    return 11;
  }
  for (unsigned int i = 0; i < input.size())
  char entry;
  char entry;
  return 0;
}

void intermediateOutput::transform(const int argNumber)
{
  //iterate through every character and apply transformation
  for (unsigned int i = 0; i < inputText.input.size(); i++)
  {
    //now need to define a bunch of anciiliary functions to get desired output
    char temp = inputText.input.at(i);

    //SKIP if letter is false.
    if (isalpha(temp))
    {
      //insert function to check if upper or lower
      int tempNumber = letterToNumber(temp);
      tempNumber = plugBoardTransform(tempNumber);
      //disable rotor xform first
      // tempNumber = rotorTransform(tempNumber, argNumber);
      tempNumber = reflectorTransform(tempNumber);
      //disable rotor xform first
      // tempNumber = rotorBackwardsTransform(tempNumber, argNumber);

      //insert function to convert back from number to upper/lower
      temp = numberToLetters(temp, tempNumber);
    }
    output.at(i) = temp;
  }
}

int intermediateOutput::plugBoardTransform(const char input)
{
  //convert input to number
  int number = letterToNumber(input);
  //conducting a simple iterative search through the board
  for (int i = 0; i < plugBoard.position; i++)
  {
    int swapChar;
    if(number == plugBoard.position[i])
    {
      //convert output in accordance with requirements for plugboard
      if (i%2 == 0)
      {
        //if character is the first char in array pair
        return (swapChar=plugBoard.position[i+1]);
      }
      if (i%2==1)
      {
        //if character is the second char in array pair
        return(swapChar=plugBoard.position[i-1]);
      }
    }
  }


int intermediateOutput::letterToNumber(const char input)
{
  if(isupper(char))
  {
    return (static_cast<int>input - 65);
  }
  else
  {
    return (static_cast<int>input -97);
  }
}

char intermediateOutput::numberToLetter(const char temp, const int tempNumber)
{

}

  //
  // bool intermediateOutput::checkLetter(const char &input)
  // {
  //   int inputASCII=static_cast<int> (input);
  //   if ((inputASCII>=64 && inputASCII <=91) || (inputASCII <=96 && inputASCII >=123))
  //   {
  //     return true;
  //   }
  //   else
  //   return false;
  // }
