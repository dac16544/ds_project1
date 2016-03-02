#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#inlcude "Order.h"

using namespace std;

int main(const int argc, const char * argv []) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(0);
  } // if

  string filename = argv[1];

  ifstream input(filename);

  string catArray[100];
  string ordersArray[100];
  string dispatchArray[100];
  int flag =0;
  int i = 0, i2 = 0, i3 =0;
  for(string stringIn; getline(input,stringIn);) { //go thru each line


    if ((stringIn != "CATEGORIES") && (flag ==0)&&(stringIn != "ORDERS")){
      catArray[i] = stringIn;
      i++;
    }
    if(stringIn == "ORDERS"){
      flag++;
    }
    if ((stringIn != "ORDERS") && (flag ==1)&&(stringIn != "CATEGORIES")&&(stringIn != "DISPATCH")){
      ordersArray[i2] = stringIn;
      i2++;
    }
    if(stringIn == "DISPATCH"){
      flag++;
    }
    if ((stringIn != "DISPATCH") && (flag ==2)){
      dispatchArray[i3] = stringIn;
      i3++;
    }




  } // for
  int oNum=1;
  for(int i =0;i<i2;i++){
    istringstream iss(ordersArray[i]);
    string uinput;
    int ii=0;
    string order2[5];
    while(getline(iss, uinput, ',')){
      order2[ii] = uinput;
    }
    /*
    Order newOrder(oNum,order2[0],order2[1],order2[2],order2[3],order2[4]);
    put order in que
    then delete it
    oNum++;

    */
  }

  return EXIT_SUCCESS;
} // main
