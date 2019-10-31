#include <iostream>
#include <fstream>
#include "enigma.h"
#include "errors.h"

using namespace std;

//note the thing about returning erorr codes using the return statement

int main(int argc, char** argv)
{
  // check if there are more than 3 different arguments
  // if (argc < 4)
  // {
  //     cout << "You need to have more than 3 different arguments" << endl;
  // }
  //REVIEW THROWING AND CATCHING IN MAIN
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


    //check file for entry
    //get input char by char and output
    //complete the leftover

  return 0;
}
