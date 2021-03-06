#include "ArrayStack.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

void printLabel(ArrayStack &myStack);

void dispatchOrder(LinkedList &myList, string cats[]){

    ArrayStack *s = new ArrayStack();
    for(int i = 0; i < myList.size(); i++){
            string category = cats[i];
     for(int j = 0; j < myList.grabNodeByCat(category)->orderCount; j++){
            s->push(myList.getQueueByCat(category).dequeue());
            }
    }

    printLabel(*s);

}

void printLabel(ArrayStack &myStack){

  ofstream myfile;
  myfile.open("shippingLabels.txt");

  for(int i=0; i < myStack.size; i++){
  Order toWrite(myStack.pop());
  myfile <<"------------------------------ \n";
  myfile <<"Order Number: " << toWrite.orderNumber<<"\n";
  myfile <<"Name: "<<toWrite.name <<"\n";
  myfile <<"Item: "<< toWrite.item <<"\n";
  myfile <<"Ship To: " << toWrite.shipArea << "\n";
}
  myfile <<"------------------------------ \n";
myfile.close();
}
