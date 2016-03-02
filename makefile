CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: p1

p1: p1.o Order.o LinkedQueue.o LinkedStack.o SuperMarket.o		
	$(CC) $(LFLAGS) -o p1 p1.o Order.o LinkedQueue.o LinkedStack.o SuperMarket.o	

LinkedStack.o: LinkedStack.cpp	
	$(CC) $(CFLAGS)	LinkedStack.cpp
	
Order.o: Order.cpp	
	$(CC) $(CFLAGS)	Order.cpp	
	
LinkedQueue.o: LinkedQueue.cpp	
	$(CC) $(CFLAGS)	LinkedQueue.cpp	
	
SuperMarket.o: SuperMarket.cpp	
	$(CC) $(CFLAGS)	SuperMarket.cpp					

p1.o: p1.cpp	
	$(CC) $(CFLAGS)	p1.cpp

clean:
	rm -rf p1
	rm -rf *.o	
  	
run:
	./p1 input.txt
  
