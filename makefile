CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: p1

p1: p1.o LinkedList.o Order.o Queue.o Stack.o SuperMarket.o	
	$(CC) $(LFLAGS) -o p1 p1.o LinkedList.o Order.o Queue.o Stack.o SuperMarket.o	

LinkedList.o: LinkedList.cpp	
	$(CC) $(CFLAGS)	LinkedList.cpp
	
p1.o: p1.cpp	
	$(CC) $(CFLAGS)	p1.cpp	
	
Order.o: Order.cpp	
	$(CC) $(CFLAGS)	Order.cpp	
	
Queue.o: Queue.cpp	
	$(CC) $(CFLAGS)	Queue.cpp	
	
Stack.o: Stack.cpp	
	$(CC) $(CFLAGS)	Stack.cpp	
	
SuperMarket.o: SuperMarket.cpp	
	$(CC) $(CFLAGS)	SuperMarket.cpp					

p1.o: p1.cpp	
	$(CC) $(CFLAGS)	p1.cpp

clean:
	rm -rf p1
	rm -rf *.o	
  	
run:
	./p1 input.txt
  
