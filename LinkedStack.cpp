#include <string>
#include "Order.h"
#include "LinkedStack.h"
#include "Stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Stack::~Stack(void){
}

LinkedStack::LinkedStack(){
}

void LinkedStack::push(Order & order){
  for(int i =0; i<size;i++){
    stackList[i+1] = stackList[i];
  }
  stackList[0] = order;
  size++;


}


Order & LinkedStack::pop(void){
  toPop = stackList[0];
  for(int i = 1; i<size;i++){
    stackList[i-1] = stackList[i];
  }
  return toPop;
}


