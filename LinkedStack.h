#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H


#include <string>
#include "Order.h"
#include "Stack.h"
using namespace std;

class LinkedStack : public Stack {
public:
	
    void push(Order & order);

    /**
    * Pop the top order from the stack
    * to be processed by the printLabel function
    */
    Order & pop(void);

};



#endif
