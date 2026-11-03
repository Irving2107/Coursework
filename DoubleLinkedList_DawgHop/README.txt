# DawgHop Card Sorting Program

## Overview

This project implements a card-based double linked list and uses an insertion sort algorithm to sort the cards by their face values in ascending order.

The program reads card information from a text file, inserts the cards into a double linked list, sorts the list using insertion sort, and displays the sorted cards along with the number of Dawg Hops performed.

## Features

- Represents playing cards using suit and face values.
- Implements a singly linked list and a double linked list.
- Reads card information from an input text file.
- Inserts cards into a double linked list.
- Sorts cards in ascending order by face value using insertion sort.
- Counts the number of Dawg Hops performed during sorting.
- Displays the list before and after sorting.

## Input File Format

The program reads card information from a text file named deck.txt.

The first line contains the total number of cards. Each subsequent line contains two integers:

1. Suit value
2. Face value

Example deck.txt:

text:
4
1 12
1 8
3 7
1 3

The first line indicates that the file contains four cards. The remaining lines represent each card's suit and face values.

## Compilation

Compile the program using a C++ compiler such as g++.

Example:

```bash
g++ -std=c++11 *.cpp -o DawgHop
```

## Running the Program

Run the compiled executable:

```bash
./DawgHop
```

Make sure deck.txt is located in the program's working directory.

## Sorting Algorithm

The program uses insertion sort to arrange the cards in ascending order according to their face values.

The algorithm traverses the double linked list and moves cards into their correct positions by updating the nodes' next and previous pointers.

The program also tracks the number of Dawg Hops performed during sorting.

## Example Output

text:
Cards from file:
Queen of Clubs <--> Eight of Spades <--> Seven of Hearts <--> Three of Clubs

Insertion Sort...

Three of Clubs <--> Seven of Hearts <--> Eight of Spades <--> Queen of Clubs

Dawg Hops: 6


*Note: The exact card names and formatting depend on the card-printing implementation.*

## Memory Management

The double linked list is dynamically allocated using new and deallocated using delete.

The linked-list destructor is responsible for deleting the nodes in the list to prevent memory leaks.

## Project Files

- Card.h / Card.cpp – Defines the Card class and its functionality.
- LinkedNode.h / LinkedNode.cpp – Defines the linked-list node.
- LinkedList.h / LinkedList.cpp – Implements the singly linked list.
- DoubleLinkedList.h / DoubleLinkedList.cpp – Implements the double linked list.
- DawgHop.h / DawgHop.cpp – Implements the insertion sort algorithm.
- main.cpp – Reads the input file, creates the list, and runs the sorting algorithm.
- deck.txt – Contains the input card data.

Author: Irving Luis-Orozco
Made as part of a course assignment