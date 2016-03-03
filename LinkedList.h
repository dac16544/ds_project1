/**
* LinkedList class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedQueue.h"
#include <string>

using namespace std;
// forward declaration of LinkedList

class LinkedList;
class LinkedQueue;

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
	LinkedQueue &orderQueue; // The order queue for this category.
	Node * prev = nullptr;
	Node * next = nullptr;
public:
	int orderCount; // The number of orders in this node/category of product to dispatch.
	
	/**
	* Parameterized Constructor
	*/
	Node(Node * prev, Node * next, string category, LinkedQueue &orderQueue) : orderQueue(orderQueue) {
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
	void append(string category, LinkedQueue &orderQueue){
			
		//make node with queue and cat
		if(headptr == tailptr == nullptr){	
			headptr = tailptr =  new Node(prev,next,category,orderQueue);
		}
				
		//if no head or tail, assign node to head
		
		//if no tail but a head, assing node to tail
		
		//else make node new tail
		
		//length++
		
    }

	/**
	* Returns the queue for a given category.
	* Use this to quickly get the required queues
	* for enqueue and dequque operations.
	* @param cat the category for the required queue. 
	*/
//	LinkedQueue & getQueueByCat(string cat) {
//
//	}

	/**
	* Sets the value of orderCount for the given category.
	*
	* @param cat the category name
	* @param count the numbe of orders to dispatch
	*/
	void setOrderCount(string cat, int count);

	/**
	* Returns the number of elements in this list.
	*/
	const int size() const{
		/*
		int size = 0;
		if (headptr != nullptr){
			Node * currentNode = headptr;
			while(currentNode->next != nullptr){
				currentNode = currentNode->next;	
				size++;
			}	 
		}
		return size; */
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
