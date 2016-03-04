#include <string>
#include <cstdlib>
#include <iostream>
#include "Order.h"
#include "LinkedList.h"
#include "Queue.h"
#include "LinkedQueue.h"



using namespace std;


Queue::Queue(string category){
	this->category = category;
}

Queue::~Queue(void){
//	cout << "Deleted Order" << endl;
}

LinkedQueue::LinkedQueue(string category){
	this->category = category;
}
LinkedQueue::LinkedQueue(){

}

void LinkedQueue::enqueue(Order & o){ //enqueue into ARRAY
	
	//1 Make new node in enq end of queueList
	//2 put order in node 
	
	if (deqEnd == (enqEnd+1)%(maxsize)) {
		cout << "queue full" << endl;
	}
	
	queueList[enqEnd] = o;
	enqEnd = (enqEnd+1)%(maxsize); 

}


Order & LinkedQueue::dequeue(void){
	int deqSpot = deqEnd;
	deqEnd = (deqEnd+1)%(maxsize);
	return queueList[deqSpot];
}


int LinkedQueue::queueSize(void){
	if (deqEnd < enqEnd) // tail right of head
	{
		return enqEnd - deqEnd;
	}
	else if (deqEnd > enqEnd) //tail left of head, in circular
	{
		int i;
		for (i = deqEnd; i < maxsize; i++) {
		}
		int j;
		for (j = 0; j < enqEnd; j++)
		{
		}
		int size = i + j;
		return size;
	}
	else
		return maxsize; //is full
	
}
	
