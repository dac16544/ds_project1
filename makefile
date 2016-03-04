CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: p1

p1: p1.o Order.o ArrayQueue.o ArrayStack.o SuperMarket.o		
	$(CC) $(LFLAGS) -o p1 p1.o Order.o ArrayQueue.o ArrayStack.o SuperMarket.o	

ArrayStack.o: ArrayStack.cpp	
	$(CC) $(CFLAGS)	ArrayStack.cpp
	
Order.o: Order.cpp	
	$(CC) $(CFLAGS)	Order.cpp	
	
ArrayQueue.o: ArrayQueue.cpp	
	$(CC) $(CFLAGS)	ArrayQueue.cpp	
	
SuperMarket.o: SuperMarket.cpp	
	$(CC) $(CFLAGS)	SuperMarket.cpp					

p1.o: p1.cpp	
	$(CC) $(CFLAGS)	p1.cpp

clean:
	rm -rf p1
	rm -rf shippingLabels.txt
	rm -rf *.o	
  	
run:
	./p1 test.txt
  
