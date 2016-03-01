/**
 * Queue class
 */

#ifndef _QUEUE_H
#define _QUEUE_H

/**
* The queue will store orders until the order dispatcher
* dequeues the order and pushes it onto a stack.
* Each category of product will have different order queues.
*/
#include <string>
#include "Order.h"
using namespace std;

class Queue {
public:
	int head = 0;
	int tail = -1;
	string category = ""; // the product category whose orders are stored in this queue.

	/**
    * Default constructor
    */
    Queue(void) = default;
	
	/**
    * Constructor
    */
    Queue(string category);
	
	/**
	* Destructor
	*/
	~Queue(void) { }

    /**
	* Insert a member into the queue
	* at the end
	*/
    virtual void enqueue(Order &) = 0;

	/**
	* Remove a queue member from the
	* front of the queue
	*/
	virtual Order & dequeue(void) = 0;

	/**
	* Returns the current size of the queue
	*/
	virtual int queueSize(void) = 0;

	/**
	* Returns true if the queue is empty
	*/
	bool isEmpty() {
        return queueSize() == 0;
    }
};

#endif //_QUEUE_H
