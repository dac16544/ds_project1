#include "LinkedStack.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

void printLabel(LinkedStack &myStack);

void dispatchOrder(LinkedList &myList, string cats[]){

    LinkedStack *s = new LinkedStack();
    for(int i = 0; i < myList.size(); i++){
            string category = cats[i];
     for(int j = 0; j < myList.grabNodeByCat(category)->orderCount; j++){
            s->push(myList.getQueueByCat(category).dequeue());
            }
    }

    printLabel(*s);

}

void printLabel(LinkedStack &myStack){

  ofstream myfile;
  myfile.open("shippingLabels.txt");

  Order toWrite;
  for(int i=0; i < myStack.size; i++){
  toWrite = myStack.pop();
  myfile <<"------------------------------ \n";
  myfile <<"Order Number: " << toWrite.orderNumber<<"\n";
  myfile <<"Name: "<<toWrite.name <<"\n";
  myfile <<"Item: "<< toWrite.item <<"\n";
  myfile <<"Ship To: " << toWrite.shipArea << "\n";
}
  myfile <<"------------------------------ \n";
myfile.close();
}
