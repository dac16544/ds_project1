#ifndef _ARRAY_H
#define _ARRAY_H
#include <string>
#include "Order.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

class ArrayStack : public Stack {
public:
  Order stackList[64];
  int size;
  Order toPop;

   ArrayStack();
   // ~ArrayStack();
    void push(Order & order);

    /**
    * Pop the top order from the stack
    * to be processed by the printLabel function
    */
    Order & pop(void);

};

#endif
