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

    rotor rotorArray[2];
    check_error(rotorArray[0].readFile("rotors/I.rot"));
    check_error(rotorArray[1].readFile("rotors/II.rot"));





    //TBC: Check number of rotor values
  //   //declare an array of rotors
  //   rotor rotorArray[3];
  //   // for(int i = 0; i < 3; i++)
  //   // {
  //   //     rotorArray[i].readFile;
  //   // }
  //   check_error(rotorArray[0].readFile("rotors/shift_up.rot", intermediateOutput.rotorValues[0], intermediateOutput.rotorNotches[0]));
  // //   check_error(rotorArray[1].readFile("rotors/II.rot", intermediateOutput.rotorValues[1], intermediateOutput.rotorNotches[1]));
  // //   check_error(rotorArray[2].readFile("rotors/III.rot", intermediateOutput.rotorValues[2], intermediateOutput.rotorNotches
  // // [2]));

    //copy rotorcount to transformer

    //use the rotor array to get the final value to be accessed.

    //check file for entry
    // inputText inputText;
    // check_error(inputText.readFile("input.txt"));
    // // check_error(inputText.readFile((argc-1));
    // for (unsigned int i = 0; i < inputText.input.size(); i++)
    // {
    //   cout<< inputText.input.at(i);
    // }
    intermediateOutput intermediateOutput;
    //copy rotorarray into machine to be modified
    intermediateOutput.copy(rotorArray, 2);
    intermediateOutput.rotorPositions("rotors/I.pos"); 

    intermediateOutput.transform(argc, inputText, plugBoard, reflector);
    // for (unsigned int i = 0; i < intermediateOutput.output.size(); i++)
    // {
    //   cout<< intermediateOutput.output.at(i);
    // }

    //output files. So, HOW do you output as a class?
    // outputText outputText;
    // check_error(outputText.outputFile("output.txt", intermediateOutput.input()));
    // check_error(inputText.outputFile((argc));
  return 0;
}
