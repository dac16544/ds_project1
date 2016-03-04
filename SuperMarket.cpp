#include "LinkedStack.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std; 

void printLabel(Stack &myStack);

void dispatchOrder(LinkedList &myList, string cats[]){
	
    Stack *s = new LinkedStack();
    for(int i = 0; i < myList.size(); i++){
            string category = cats[i];
            for(int j = 0; j < myList.grabNodeByCat(category)->orderCount; j++){
                s->push(myList.getQueueByCat(category).dequeue());
            }
    }
    printLabel(*s);

}

void printLabel(Stack &myStack){
    /*
    ofstream myfile;
    myfile.open("output.txt);
    myfile.close();
    */

  const char * filename = "shippingLabels.txt";
  int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT); //create labels or truncate over existing ones
  dup2(fd, STDOUT_FILENO);  // redirect standard out
  
  Order toWrite;
  for(int i=0; i < myStack.size; i++){
  toWrite = myStack.pop();
  cout <<"------------------------------ \n";
  cout <<"Order Number: " << toWrite.orderNumber<<"\n";
  cout <<"Name: "<<toWrite.name <<"\n";
  cout <<"Item: "<< toWrite.item <<"\n";
  cout <<"Ship To: " << toWrite.shipArea << "\n";
}
  cout <<"------------------------------ \n";
  
}
