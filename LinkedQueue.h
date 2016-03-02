#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H


#include <string>
#include "Order.h"
#include "LinkedList.h"
#include "Queue.h"

#define MAX_SIZE 64

using namespace std;

class LinkedQueue : public Queue {
	
 

public:

int enqEnd = 0; //tail end
int deqEnd = 0; //head end
Order queueList[MAX_SIZE];
bool isFull;
int maxsize = MAX_SIZE;

	
    void enqueue(Order &);

	/**
	* Remove a queue member from the
	* front of the queue
	*/
	Order & dequeue(void);

	/**
	* Returns the current size of the queue
	*/
	int queueSize(void);

};

#endif //_LINKEDQUEUE_H
