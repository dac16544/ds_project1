#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H
#include <string>
#include "Order.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

class LinkedStack : public Stack {
public:
  Order stackList[64];
  int size;
  Order toPop;

   LinkedStack();
   // ~LinkedStack();
    void push(Order & order);

    /**
    * Pop the top order from the stack
    * to be processed by the printLabel function
    */
    Order & pop(void);

};

#endif
