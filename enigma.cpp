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

// int outputText::outputFile(const string &argument, const vector<char> input)
// {
//   ofstream of_stream;
//   of_stream.open(argument);
//   if(of_stream.fail())
//   {
//     return 11;
//   }
//   for (unsigned int i = 0; i < input.size())
//   char entry;
//   char entry;
//   return 0;
// }

void intermediateOutput::transform(const int &argNumber, const inputText &inputText, const plugBoard &plugBoard, const reflector &reflector)
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
      cout << "Initial Number: " << tempNumber << endl;
      tempNumber = plugBoardTransform(tempNumber, plugBoard);
      cout << "Rotor transform number: " << tempNumber << endl;
      tempNumber = rotorForwardTransform(tempNumber);
      cout << "plugBoard Number: " << tempNumber << endl;
      tempNumber = reflectorTransform(tempNumber, reflector);
      cout << "reflectorTransform Number: " << tempNumber << endl;
      tempNumber = rotorReverseTransform(tempNumber);
      //CHECK but it should be the case tht value goes through the plugboard again.
      tempNumber = plugBoardTransform(tempNumber, plugBoard);

      //insert function to convert back from number to upper/lower
      temp = numberToLetter(temp, tempNumber);
    }
    output.push_back(temp);
  }
}

int intermediateOutput::plugBoardTransform(const int tempNumber, const plugBoard &plugBoard)
{
  //conducting a simple iterative search through the board
  for (int i = 0; i < plugBoard.position; i++)
  {
    if(tempNumber == plugBoard.plugBoardValues[i])
    {
      //convert output in accordance with requirements for plugboard
      if (i%2 == 0)
      {
        //if character is the first char in array pair, then return the next value in the pair
        return (plugBoard.plugBoardValues[(i+1)]);
      }
      if (i%2==1)
      {
        //if character is the second char in array pair
        return(plugBoard.plugBoardValues[(i-1)]);
      }
    }
  }
  return tempNumber;
}

int intermediateOutput::reflectorTransform(const int tempNumber, const reflector &reflector)
{
  //conducting a simple iterative search through the board
  for (int i = 0; i < reflector.position; i++)
  {
    if(tempNumber == reflector.reflectorValues[i])
    {
      //convert output in accordance with requirements for plugboard
      if (i%2 == 0)
      {
        //if character is the first char in array pair
        return (reflector.reflectorValues[i+1]);
      }
      if (i%2==1)
      {
        //if character is the second char in array pair
        return(reflector.reflectorValues[i-1]);
      }
    }
  }
}


void intermediateOutput::transformNoPBRF(const int &argNumber, const inputText &inputText)
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
      cout << "Initial Number: " << tempNumber << endl;
      tempNumber = rotorForwardTransform(tempNumber);
      tempNumber = rotorReverseTransform(tempNumber);
      cout << "Rotor OUTPUT: " << tempNumber << endl;
      temp = numberToLetter(temp, tempNumber);
    }
    output.push_back(temp);
  }
}

int intermediateOutput::rotorReverseTransform(int tempNumber)
{
  int max_rotor_number = rotorPositions.size();
  int count (0);
  for (int rotorNumber=max_rotor_number; rotorNumber > 0 ; rotorNumber--)
  {
    cout <<"COUNT: " << rotorNumber << endl;
    rotorReverseWiringConvert(tempNumber, (rotorNumber-1));
  }
  return tempNumber;
}


int intermediateOutput::letterToNumber(const char input)
{
  if(isupper(input))
  {
    return (static_cast<int>(input) - 65);
  }
  else
  {
    return (static_cast<int>(input) -97);
  }
}

char intermediateOutput::numberToLetter(const char temp, const int tempNumber)
{
  if(isupper(temp))
  {
    return (static_cast<char>(tempNumber + 65));
  }
  else
  {
    return (static_cast<char>(tempNumber + 97));
  }
}

int rotor::readFile(const string &argument)
{
  ifstream in_stream;
  in_stream.open(argument);

  //need to pass file as a function to be read. NOt elegant way, is there a better way?
  if(in_stream.fail())
  {
    return 11;
  }

  int numberEntry;

  //read in entries for the initial mapping
  while(!in_stream.eof() && rotorValues.size() < 26)
  {
    in_stream >> ws;
    in_stream >> numberEntry;
    if (invalidIndex(numberEntry)==true)
    {
      return 3;
    }
    rotorValues.push_back(numberEntry);
    //check for end of stream
    if (checkChar(in_stream)==false)
    {
      return 4;
    }
  }

  //read in entries for the initial entries
  while(!in_stream.eof())
  {
    in_stream >> ws;
    in_stream >> numberEntry;
    if (invalidIndex(numberEntry)==true)
    {
      return 3;
    }
    rotorNotches.push_back(numberEntry);
    if (checkChar(in_stream)==false)
    {
      return 4;
    }
  }

  int count = 0;
  cout << "Rotorpositions: " << endl;
  for (int i = 0;i < rotorValues.size(); i++)
  {
    cout << rotorValues.at(i) << endl;
    (count = count + 1);
  }

  cout << "COUNT: "<< count << endl;

  cout << "Notchpositions: " << endl;
  for (int i = 0;i < rotorNotches.size(); i++)
  {
    cout << rotorNotches.at(i) << endl;
  }

  in_stream.close();
  return 0;
}

void intermediateOutput::copy(rotor rotorArray[], int rotorNumber)
{
  //resize so that rotorvalues can be input into rotor array 2d vector
  rotorValues.resize(rotorNumber);
  //resize so that rotorvalues can be input into rotor notches 2d vector
  rotorNotches.resize(rotorNumber);

  //copy values into 2-d vector
  for(int i = 0; i < rotorNumber;i++)
  {
    for(int j=0; j<rotorArray[i].rotorValues.size(); j++)
    {
      int temp = rotorArray[i].rotorValues.at(j);
      rotorValues[i].push_back(temp);
    }

    for(int j=0; j<rotorArray[i].rotorNotches.size(); j++)
    {
      rotorNotches[i].push_back(rotorArray[i].rotorNotches.at(j));
    }
  }

  int count(0);
  for(int i = 0; i < rotorNumber;i++)
  {
    cout << "Rotor Number: " << (i+1) << endl;
    for(int j=0; j<rotorArray[i].rotorValues.size(); j++)
    {
      cout << rotorValues[i][j] << endl;
    }
  }
  cout << "Rotor Number: " << count << endl;

  count=0;
  for(int i = 0; i < rotorNumber;i++)
  {
    for(int j=0; j<rotorArray[i].rotorNotches.size(); j++)
    {
      count++;
    }
  }
  cout << "Rotor Notches: " << count << endl;

}


int intermediateOutput::rotorForwardTransform(int tempNumber)
{
  int max_rotor_number = rotorPositions.size();
  cout << "max rotor number: " << max_rotor_number << endl;
  for (int rotorNumber = 0; rotorNumber < max_rotor_number; rotorNumber++)
  {
    //check if previous entry is notch. Excpet for first rotor where it's always rotated back one
    if(previous_notch(rotorNumber)==true)
    {
      cout << "Notch " << rotorNumber -1 << " turned" << endl;
      rotateBackOne(rotorNumber);
    }
    //run number through wirint in absolute position
    rotorWiringConvert(tempNumber, rotorNumber);
  }
  return tempNumber;
}

void intermediateOutput::rotateBackOne(const int rotorNumber)
{
  //rotor position is INFORMED with notch movement
  rotorPositions[rotorNumber] = ((rotorPositions.at(rotorNumber) + 1)%26);
  cout << "rotatebackone number: " << rotorPositions[rotorNumber] << endl;
}

void intermediateOutput::rotorWiringConvert(int &tempNumber, const int rotorNumber)
{
  cout << "tempNumber: " <<tempNumber << " rotorPositions[rotorNumber]: " << rotorPositions[rotorNumber] << endl;
  int absoluteEntryPosition = (tempNumber + rotorPositions[rotorNumber]) % 26;
  cout << "abs entry: " << absoluteEntryPosition << endl;
  tempNumber = rotorValues[rotorNumber][absoluteEntryPosition] - rotorPositions[rotorNumber];
  //hard code to prevent negative numberEntry
  if (tempNumber < 0)
  {
    tempNumber = tempNumber + 26;
  }
}

void intermediateOutput::rotorReverseWiringConvert(int &tempNumber, const int rotorNumber)
{
  cout << "tempNumber: " <<tempNumber << " rotorPositions[rotorNumber]: " << rotorPositions[rotorNumber] << endl;
  int absoluteEntryPosition = ((tempNumber + rotorPositions[rotorNumber])%26);
  cout << "abs entry: " << absoluteEntryPosition << endl;
  if (rotorNumber ==0)
  {
    cout << "rotor values: " << endl;
  }
  for(unsigned int i = 0; i < rotorValues[rotorNumber].size(); i++)
  {
    if (rotorNumber == 0)
    {
      cout << rotorValues[rotorNumber][i] << endl;
    }
    if(absoluteEntryPosition == rotorValues[rotorNumber][i])
    {
      tempNumber = (i - rotorPositions[rotorNumber]);
    }
  }
  //hard code to prevent negative numberEntry
  if (tempNumber < 0)
  {
    tempNumber = tempNumber + 26;
  }
  cout << "REVERSE TRANSFORM TEMPNUMBER: " << tempNumber << endl;
}



//previous notch should be ok.
bool intermediateOutput::previous_notch(const int rotorNumber)
{
  if (rotorNumber > 0 )
  {
    for (int i = 0; i < rotorNotches[rotorNumber-1].size(); i++)
    {
      if(rotorNotches[(rotorNumber-1)][i] == rotorPositions[rotorNumber-1])
      {
        cout << "NOTCH HIT!" << endl;
        return true;
      }
    }
    return false;
  }
  else
  //bc first notch always turns
    return true;
}



int intermediateOutput::rotorPositionInput(const string &argument)
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
    rotorPositions.push_back(numberEntry);
    if (checkChar(in_stream)==false)
    {
      return 4;
    }
  }

  cout << "ROTOR POSITIONING: " << endl;
  //need to validate with the number of rotors in the program
  for (int i = 0;i < rotorPositions.size(); i++)
  {
    cout << rotorPositions.at(i) << endl;
  }
  in_stream.close();
  return 0;
}
