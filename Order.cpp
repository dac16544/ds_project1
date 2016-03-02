#include <string>
#include "Order.h"

using namespace std;



/**
 * Constructor
 */
Order::Order(const int orderNumber, const string &name, const string &item,const string &category, const string &shipArea){
  this->orderNumber = orderNumber;
  this->name = name;
  this->item = item;
  this->category = category;
  this->shipArea = shipArea;

}

/**
 * copy constructor
 */
Order::Order(const Order & m){
  this->orderNumber = m.orderNumber;
  this->name = m.name;
  this->item = m.item;
  this->category = m.category;
  this->shipArea = m.shipArea;


}

/**
 * copy operator
 */
 /*
  Order & operator = Order::(const Order & m){
  this->orderNumber = m.orderNumber;
  this->name = m.name;
  this->item = m.item;
  this->category = m.category;
  this->shipArea = m.shipArea;
} */

/**
 * Destructor
 */
Order::~Order(void){

}

