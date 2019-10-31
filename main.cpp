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
  plugBoard plugBoard;
  plugBoard.readFile(argv[1]);

  reflector reflector;
  reflector.readFile(argv[2]);



  return 0;
}
