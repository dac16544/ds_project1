#include <string>
#include <cstdlib>
#include <iostream>
#include "Order.h"
#include "LinkedList.h"
#include "Queue.h"
#include "ArrayQueue.h"



using namespace std;


Queue::Queue(string category){
	this->category = category;
}

Queue::~Queue(void){

}

ArrayQueue::ArrayQueue(string category){
	this->category = category;
}
ArrayQueue::ArrayQueue(){

}

void ArrayQueue::enqueue(Order & o){ //enqueue into ARRAY
	
	//1 Make new node in enq end of queueList
	//2 put order in node 
	
	if (deqEnd == (enqEnd+1)%(maxsize)) {
		cout << "queue full" << endl;
	}
	
	queueList[enqEnd] = o;
	enqEnd = (enqEnd+1)%(maxsize); 

}


Order & ArrayQueue::dequeue(void){
	int deqSpot = deqEnd;
	deqEnd = (deqEnd+1)%(maxsize);
	return queueList[deqSpot];
}


int ArrayQueue::queueSize(void){
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
	
