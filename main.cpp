#include <iostream>
#include <fstream>
#include <vector>
#include "enigma.h"
#include "errors.h"

using namespace std;

//thought process here is that the steer is towards using friend functions.

int main(int argc, char** argv)
{
  // check if there are more than 3 different arguments
  // if (argc < 4)
  // {
  //     cout << "You need to have more than 3 different arguments" << endl;
  // }
  // REVIEW THROWING AND CATCHING IN MAIN

    plugBoard plugBoard;
    cout << "PB VALUES: "<< endl;
    check_error(plugBoard.readFile("plugboards/I.pb"));
    //need to create a function here for plugboard to reflect values


    // plugBoard.readFile(argv[1]);
    reflector reflector;
    cout << "RF VALUES: "<< endl;
    check_error(reflector.readFile("reflectors/I.rf"));
    //need to create a function here for plugboard to reflect values
    // reflector.readFile(argv[2]);

    //check number of rotor values
    // int rotorNumber = (argc - 6);
    // for(int i = 0; i < rotorNumber; i++)
    // {
    //   //you can create a new array of objects that could work quite well as well.
    //   //read in rotor values for any number of rotors from left to right
    //   check_error(rotor.rotorValues)
    // }

    //check file for entry
    inputText inputText;
    check_error(inputText.readFile("input.txt"));
    // check_error(inputText.readFile((argc-1));
    for (unsigned int i = 0; i < inputText.input.size(); i++)
    {
      cout<< inputText.input.at(i);
    }

    //transform function using the intermediate ouput option. Shouldn't return any errors in the process.
    intermediateOutput intermediateOutput;
    intermediateOutput.transform(argc, inputText.input);

    //output files. So, HOW do you output as a class?
    // outputText outputText;
    // check_error(outputText.outputFile("output.txt", intermediateOutput.input()));
    // check_error(inputText.outputFile((argc));
  return 0;
}
