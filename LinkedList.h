/**
* LinkedList class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ArrayQueue.h"
#include <string>

using namespace std;
// forward declaration of LinkedList

class LinkedList;
class ArrayQueue;

/**
* Represents a node in a doubly-linked list.
* A node represent a category of product in the store.
* Each node stores information about the number of orders
* in that category that needs to be dispatched.
*/

class Node {
	friend class LinkedList;
private:
    string category = "";   // The category of products in this node.
	ArrayQueue &orderQueue; // The order queue for this category.
	Node * prev = nullptr;
	Node * next = nullptr;
public:
	int orderCount; // The number of orders in this node/category of product to dispatch.
	
	/**
	* Parameterized Constructor
	*/
	Node(Node * prev, Node * next, string category, ArrayQueue &orderQueue) : orderQueue(orderQueue) {
		this->prev = prev;
		this->next = next;
		this->category = category;
		
	}	
	
}; // Node

/**
* A doubly-linked list data structure.
*/

class LinkedList {
private:
	Node * headptr = nullptr;
    Node * tailptr = nullptr;
public:
	int length = 0;
	
	
	
	/**
	* Adds an item to the end of this list.
	*
	* @param category The category of the queue, the node having this queue is being appended
	* @param orderQueue The queue this node will have
	*/
	void append(string category, ArrayQueue &orderQueue){
			
		//make node with queue and cat

				
		//if no head or tail, assign node to head
		if(headptr == nullptr && tailptr == nullptr){	
			headptr = new Node(nullptr,nullptr,category,orderQueue);
			length++;
		}
		//if no tail but a head, assign node to tail
		else if(headptr != nullptr && tailptr == nullptr){	
			tailptr = new Node(headptr,nullptr,category,orderQueue);
			headptr->next = tailptr;
			length++;
		}
		//else make node new tail
		else {
			Node * oldTail = tailptr;
			tailptr = new Node(oldTail,nullptr,category,orderQueue);
			oldTail->next = tailptr;
			length++;
		}
		
		
    }

	/**
	* Returns the queue for a given category.
	* Use this to quickly get the required queues
	* for enqueue and dequque operations.
	* @param cat the category for the required queue. 
	*/
	ArrayQueue & getQueueByCat(string cat) {
		Node * here = headptr;
		while (here != nullptr)
		{
		if (here->category == cat)
			{
				return here->orderQueue;
			}
		here = here->next;
		}
		return here->next->orderQueue;
	}
	
	Node * grabNodeByCat (string cat) {
		Node * here = headptr;
		while (here != nullptr)
		{
		if (here->category == cat)
			{
                return here;
			}
        here = here->next;
		}
        return here->next;
	}
	
		
	/**
	* Sets the value of orderCount for the given category.
	*
	* @param cat the category name
	* @param count the numbe of orders to dispatch
	*/
	void setOrderCount(string cat, int count){
		Node * here = headptr;
		while (here != nullptr)
		{
		if (here->category == cat)
			{
				here->orderCount = count;
			}
		here = here->next;
		}
		
	}
	

	/**
	* Returns the number of elements in this list.
	*/
	const int size() const{
		return length;
	}

	/**
	* Returns whether or not this linked list is empty. 
	*/
	const bool empty() const {
		return size() == 0;
	} // empty
	
}; // LinkedList
#endif /** LINKED_LIST_H */
