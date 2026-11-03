# Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
# iluisorozco

First.exe: Driver.o BitArray.o Set.o Dictionary.o
	g++ Driver.o BitArray.o Set.o Dictionary.o -o First.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o

BitArray.o: bitarray.cpp
	g++ -c bitarray.cpp -o BitArray.o

Set.o: set.cpp
	g++ -c set.cpp -o Set.o

Dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o Dictionary.o

clean:
	rm -f *.o First.exe

run: First.exe
	./First.exe

# Used during debugging to check for memory leaks, shows it on the terminal rather than a text file.
valgrind: First.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./First.exe