# Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
# iluisorozco

RBT.exe: Driver.o
	g++ Driver.o -o RBT.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o

# Node.o: Node.cpp
# 	g++ -c Node.cpp -o Node.o

# LinkedNode.o: LinkedNode.cpp
# 	g++ -c LinkedNode.cpp -o LinkedNode.o

# TreeNode.o: TreeNode.cpp
# 	g++ -c TreeNode.cpp -o TreeNode.o

# BinarySearchTree.o: BinaryTreeSearch.cpp
# 	g++ -c BinaryTreeSearch.cpp -o BinarySearchTree.o

clean:
	rm -f *.o RBT.exe

# Used during debugging to check for memory leaks, shows it on the terminal rather than a text file.
valgrind: RBT.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./RBT.exe