# Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
# iluisorozco

RBT.exe: Driver.o Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o
	g++ Driver.o Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o -o RBT.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

clean:
	rm -f *.o RBT.exe

# Used during debugging to check for memory leaks, shows it on the terminal rather than a text file.
valgrind: RBT.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./RBT.exe