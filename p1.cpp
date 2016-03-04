#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include "Order.h"
#include "LinkedQueue.h"
#include "LinkedList.h"
#include "SuperMarket.h"
#include "algorithm"

using namespace std;

int main(const int argc, const char * argv []) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(0);
  } // if

  string filename = argv[1];

  ifstream input(filename);

  LinkedList theList;
  LinkedQueue qArrays[64];

  string catArray[100];
  string ordersArray[100];
  string dispatchArray[100];
  string dispatchNum[64];
  string dispatchCat[64];
  int flag =0;
  int i1 = 0, i2 = 0, i3 =0;
  for(string stringIn; getline(input,stringIn);) { //go thru each line


    if ((stringIn != "CATEGORIES") && (flag ==0)&&(stringIn != "ORDERS")){
      catArray[i1] = stringIn;
      i1++;
      
      //make a reference to it from the linked list
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

  
  for(int i =0;i<i1;i++){
  LinkedQueue test(catArray[i]);
  qArrays[i] = test;
  }
  int t = 0,tt=0,iii=2;
  for(int i =0;i<i3;i++){
    istringstream iss(dispatchArray[i]);
    string uinput;
    while(getline(iss, uinput, ' ')){
      if((iii%2)!=0){
      dispatchNum[t] = uinput;
      t++;
      }
      else{
	dispatchCat[tt]=uinput;
	tt++;
      }
      iii++;
    }
    //store # of orders to be dispatched on linked list
  }
  int oNum=1;
  for(int i =0;i<i2;i++){
    istringstream iss(ordersArray[i]);
    string uinput;
    int ii=0;
    string order2[4];
    while(getline(iss, uinput, ',')){
      order2[ii] = uinput;
      ii++;
    }
    order2[2].erase(remove(order2[2].begin(), order2[2].end(), ' '), order2[2].end()); 
    Order * newOrder = new Order(oNum,order2[0],order2[1],order2[2],order2[3]);
    for(int i = 0;i<i1;i++){
      if(order2[2]==qArrays[i].category){
	cout<<"inside"<<endl;
	qArrays[i].enqueue(*newOrder);
      }
    }
    oNum++;


  }

  //add all queues to linked list
  for(int i = 0; i < i1; i++) //for all categories (i1 is numCategories)
  {
  theList.append(qArrays[i].category, qArrays[i]);
  }
  //for each node with a dispatch num assign dispatch num
  int dNumsConverted[64]; //size matches dispatchNum
  stringstream converter;
  converter.clear();
  for (int k = 0; k < i3; k++) {
    converter <<dispatchNum[k];
      converter >> dNumsConverted[k];
      converter.clear();
      converter << "";
  }
  for (int k = 0; k < i3; k++) {
        theList.setOrderCount(dispatchCat[k], dNumsConverted[k]);
  }

  //for each num to dispatch in each node add the orders to stack
  dispatchOrder( theList, catArray);



  return EXIT_SUCCESS;
} // main
