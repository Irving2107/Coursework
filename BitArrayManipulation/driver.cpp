// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "bitarray.h"
#include "set.h"
#include "dictionary.h"
int main()
{
  int bits = 32;
  char wordA[] = "test";
  Dictionary dict;
  dict.initialize(wordA, bits);

  std::cout << "Dictionary: " << std::endl;
  dict.getData().print();

  std::cout << "Rank: "
            << dict.rank(32)
            << std::endl;

  std::cout << "Rank Range (15-31): "
            << dict.rank_range(15, 31)
            << std::endl;

  std::cout << "Select(5,1): "
            << dict.select(5, 1)
            << std::endl;

  std::cout << "Select Range(0,15,2,1): "
            << dict.select_range(0, 15, 2, 1)
            << std::endl;

  std::cout << "Printing lookup table..." << std::endl;
  dict.printLookupTable(std::cout);

  // ryan was used to better test if my program was working correctly
  // char wordB[] = "ryan";

  // Set A(bits);
  // Set B(bits);

  // A.initialize(wordA, bits);
  // B.initialize(wordB, bits);

  // A.getData().print();
  // B.getData().print();

  // std::cout << "Cardinality of A: " << A.getCardinality() << std::endl;

  // Union of A and B
  // Set unionSet = A;
  // unionSet.setUnion(B);
  // std::cout << "Union of A and B: " << std::endl;
  // unionSet.getData().print();

  // Intersection of A and B
  // Set intersectionSet = A;
  // intersectionSet.setIntersection(B);
  // std::cout << "Intersection of A and B: " << std::endl;
  // intersectionSet.getData().print();

  // bool success = false;
  // std::cout << "Number of bits: " << bits << std::endl;
  // BitArray ba(bits);
  // ba.initialize(wordA, bits);
  // ba.print();

  // std::cout << "0th bit set: " << (ba.get(0) ? "True" : "False") << std::endl;
  // std::cout << "10th bit set: " << (ba.get(10) ? "True" : "False") << std::endl;

  // std::cout << "Setting 0th bit to 1..." << std::endl;
  // ba.set(0, 1);
  // std::cout << "0th bit set: " << (ba.get(0) ? "True" : "False") << std::endl;
  // ba.print();

  // std::cout << "Setting 10th bit to 0..." << std::endl;
  // ba.set(10, 0);
  // std::cout << "10th bit set: " << (ba.get(10) ? "True" : "False") << std::endl;
  // ba.print();

  // std::cout << "Complementing..." << std::endl;
  // ba.complement();
  // ba.print();

  // std::cout << "Clearing..." << std::endl;
  // ba.clear();
  // ba.print();

  return 0;
}