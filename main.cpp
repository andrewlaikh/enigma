#include <iostream>
#include <fstream>
#include "engima.h"

using namespace std;

int main(int argc, char** argv)
{
  // check if there are more than 3 different arguments
  // if (argc < 4)
  // {
  //     cout << "You need to have more than 3 different arguments" << endl;
  // }
  plugBoard plugBoard;
  plugBoard.readFile(argv[1]);



  return 0;
}
