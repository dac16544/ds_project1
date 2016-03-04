#include <string>
#include "Order.h"
#include "ArrayStack.h"
#include "Stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Stack::~Stack(void){
}

ArrayStack::ArrayStack(){
}

void ArrayStack::push(Order & order){
  for(int i =0; i<size;i++){
    stackList[i+1] = stackList[i];
  }
  stackList[0] = order;
  size++;


}


Order & ArrayStack::pop(void){
  toPop = stackList[0];
  for(int i = 1; i<size;i++){
    stackList[i-1] = stackList[i];
  }
  return toPop;
}


