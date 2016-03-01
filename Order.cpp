#include <string>
#include "Order.h"

using namespace std;

int Order::orderNumber = -1;
string Order::name = "";
string Order::item = "";
string Order::category = "";
string Order::shipArea = "";

/**
 * Default Constructor
 */
Order::Order() = default;


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
Order Order:: & operator = (const Order & m){
  this->orderNumber = m.orderNumber;
  this->name = m.name;
  this->item = m.item;
  this->category = m.category;
  this->shipArea = m.shipArea;
}

/**
 * Destructor
 */
Order::~Order(void){

}

