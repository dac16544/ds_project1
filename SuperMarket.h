/**
* This file provides the function prototypes
* for dispatchOrder and printLabel
*/
#ifndef _SUPERMARKET_H
#define _SUPERMARKET_H

#include "LinkedList.h"
#include "Stack.h"

/**
* function dispatchOrder
* This function will access the data part of the linked list
* for the number of orders to be dequeued and pushed onto
* the stack, it will also reset this data part to zero
* after dequeuing for that node is complete.
*/
void dispatchOrder(LinkedList &myList, string cats[]);

/*
Sample implementation to demonstrate usage */
/*
void dispatchOrder(LinkedList &myList, string cats[]){
    Stack *s = new ArrayStack();
    for(int i = 0; i < myList.size(); i++){
            string category = cats[i];
            for(int j = 0; j < myList.grabNodeByCat(category)->orderCount; j++){
                s->push(myList.getQueueByCat(category).dequeue());
            }
    }
    printLabel(*s);
}
*/

/**
* function printLabel
* This function will pop all the elements from the stack
* one-by-one and prints a label in the given format to a file.
*/
void printLabel(Stack &myStack);
#endif // _SUPERMARKET_H
