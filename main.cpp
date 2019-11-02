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
    //declare an array of rotors
    // Rotor rotorArray[3];
    // for(int i = 0; i < 3; i++)
    // {
    //     rotorArray[i].readFile;
    // }

    //check file for entry
    inputText inputText;
    check_error(inputText.readFile("input.txt"));
    // check_error(inputText.readFile((argc-1));
    for (unsigned int i = 0; i < inputText.input.size(); i++)
    {
      cout<< inputText.input.at(i);
    }

    intermediateOutput intermediateOutput;
    intermediateOutput.transform(argc, inputText, plugBoard, reflector);
    for (unsigned int i = 0; i < intermediateOutput.output.size(); i++)
    {
      cout<< intermediateOutput.output.at(i);
    }

    //output files. So, HOW do you output as a class?
    // outputText outputText;
    // check_error(outputText.outputFile("output.txt", intermediateOutput.input()));
    // check_error(inputText.outputFile((argc));
  return 0;
}
