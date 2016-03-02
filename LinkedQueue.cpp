#include <string>
#include "Order.h"
//#include "LinkedList.h"
#include "Queue.h"
#include "LinkedQueue.h"

using namespace std;


Queue::Queue(string category){
	this->category = category;
}

void enqueue(Order & o){
	
}

Order & dequeue(void){
	Order o = new Order();
	return o; 	
}

int queueSize(void){
	return 0;
}
	

