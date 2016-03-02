#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>

#include "Order.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

void nope_out(const string & name) {
  perror(name.c_str());
  exit(EXIT_FAILURE);
} // nope_out


int main(const int argc, const char * argv []) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(0);
  } // if


/* OLD p0 CODE

  const char * filename = argv[1];
  int fd = open(filename, O_RDONLY);

  if (fd != -1) {
  } else {
    nope_out("open");
  } // if

  int n;           // number of bytes read
  char buffer[4]; // buffer
  int inputNums[MAX_IN]; //can't actually have a variable array so have a set array and keep track of it's actual size seperatly
  for(int i = 0; i < MAX_IN; i++){
      inputNums[i] = ~0; //initialize to a number we won't actually have in a input file
      }
  int k = 0; //counter
  int j = 0; //spot we actually assign at
  stringstream stream;
  int integerIn;
  bool alreadyExists = false;

  while ((n = read(fd, buffer, 2)) > 0) { //go thru each line
    if (n != -1) {
        buffer[n] = '\0';
       // cout << buffer;
        stream << buffer;
        stream >> integerIn;
        alreadyExists = false;
        for(int i = 0; i < k; i++){
            if(integerIn == inputNums[i]){
                alreadyExists = true;
                break;
            }
        }
        if (!alreadyExists) {
            inputNums[j] = integerIn;
            j++;
        }
        k++;
    } // if
  } // while

  //close input file
  int cr = close(fd);

  if (cr != -1) {

  } else {
    nope_out("close");
  } // if

//test reading in
//  for(int i = 0; i < j; i++){
 // cout << inputNums[i] << endl;
//  }


  cout << "Array size is " << j << endl;

  //create output txt file
  int outFD = open("output.txt", O_WRONLY | O_CREAT | O_EXCL);
  if(outFD == -1) { //may error due to already existing
      outFD = open("output.txt", O_WRONLY); //open already existing file
      if(outFD == -1) {
          nope_out("open");
      }
  }

  string toWrite;
  for (int i = j-1; i > -1; i--) {
  stream.clear();
  stream << inputNums[i];
  stream >> toWrite;

  if(write(outFD, toWrite.c_str(), toWrite.size()) == -1) {
      perror(argv[0]);
      exit(0);
  }
  if(write(outFD, "\n", 1) == -1) { //newline
      perror(argv[0]);
      exit(0);
  }
}
  if (close(outFD) == -1) {
      nope_out("close");
  }
 END OLD
*/
  return EXIT_SUCCESS;
} // main

