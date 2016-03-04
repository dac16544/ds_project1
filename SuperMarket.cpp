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
	 //Pop order off
  /*
  ofstream myfile;
  myfile.open("output.txt");
  for(int i=0;i<numbertodispatch;i++{
  myfile <<"------------------------------ \n";
  myfile <<"Order Number: " <<uniqueordernumber<<"\n";
  myfile <<"Name: "<<ordernanme<<"\n";
  myfile <<"Item: "<<itemname<<"\n";
  myfile <<"Ship To: "<<location<<"\n";
}
  myfile <<"------------------------------ \n";

  myfile.close();
  */
  const char * filename = "shippingLabels.txt";
  int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT); //create labels or truncate over existing ones
  int nfd = dup2(fd, STDOUT_FILENO);  // redirect standard out
  
  myStack.pop();
  
}
