#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H


#include <string>
#include "Order.h"
#include "Queue.h"

using namespace std;

class LinkedQueue : public Queue {
public:
	
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
