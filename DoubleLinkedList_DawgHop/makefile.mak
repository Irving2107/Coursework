# Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
# iluisorozco

A4.exe: Driver.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o Card.o DawgHop.o
	g++ Driver.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o Card.o DawgHop.o -o A4.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o

Card.o: Card.cpp
	g++ -c Card.cpp -o Card.o

DawgHop.o: DawgHop.cpp
	g++ -c DawgHop.cpp -o DawgHop.o

clean:
	rm -f *.o A4.exe

# Used during debugging to check for memory leaks, shows it on the terminal rather than a text file.
valgrind: A4.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./A4.exe