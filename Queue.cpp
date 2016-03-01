#include <string>
#include "Order.h"

using namespace std;


Queue(void) = default;
	
Queue(string category);
	
	

~Queue(void){ 
	
}

virtual void enqueue(Order &) = 0;

virtual Order & dequeue(void) = 0;

virtual int queueSize(void) = 0
	
bool isEmpty() {
	return queueSize() == 0;
}

