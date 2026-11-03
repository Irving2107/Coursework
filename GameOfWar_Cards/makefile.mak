# Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
# iluisorozco

First.exe: Driver.o Card.o StandardDeck.o NonStandardDeck.o
	g++ Driver.o Card.o StandardDeck.o NonStandardDeck.o -o First.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o

Card.o: card.cpp
	g++ -c card.cpp -o Card.o

StandardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o StandardDeck.o

NonStandardDeck.o: nonStandardDeck.cpp
	g++ -c nonStandardDeck.cpp -o NonStandardDeck.o

clean:
	rm -f *.o First.exe

run: First.exe
	./First.exe

# Used during debugging to check for memory leaks, shows it on the terminal rather than a text file.
valgrind: First.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./First.exe