# Library-Search-System

### Table of Contents
1. [Introduction](#introduction)
2. [Application Demonstration](#application-demonstration)
3. [Data Structure Selection and Analysis](#data-structure-selection-and-analysis)
4. [Testing Approach](#testing-approach)
5. [Conclusions](#conclusions)
6. [Limitations and Critical Reflection](#limitations-and-critical-reflection)



#### Introduction
This repository contains the design and implementation of a C++ based library search system that allows users to search, add and remove books efficiently using appropriate data structures and algorithms. It is suitable for use in libraries with a large collection of books, and useful for anyone looking to implement a library search system or improve their understanding of data structures and algorithms.

#### Application Demonstration


| ![](https://github.com/Deadrep/Library-Search-System/blob/main/SC_1.png) | *Screenshot 1: Search functionality demonstration* |
| --- | ----------- |

| ![](https://github.com/Deadrep/Library-Search-System/blob/main/SC_2.png) | *Screenshot 2: Add functionality demonstration* |
| --- | ----------- |

| ![](https://github.com/Deadrep/Library-Search-System/blob/main/SC_3.png) | *Screenshot 3: Remove functionality demonstration* |
| --- | ----------- |

#### Data Structure Selection and Analysis

### Hash Tables

The library system implemented in this project contains a large number of books, which are arranged based on title, author, ISBN, and quantity. To improve the efficiency of the system, the data structure chosen was Hash Tables (using Separate chaining). This data structure assigns a unique key to each book in the library system, allowing for quick retrieval of the book's location.

### Separate Chaining (Open Hashing)

The Hash Table is implemented using the Separate Chaining method, where entries in the table are linked lists. If two elements have the same hash output or code, they are entered into the same linked list. This method is effective in looking up a particular key in a uniformly distributed table, and is efficient in deletion. However, if all keys have the same hash code, the cost of lookup is proportional to the number of keys in the table.

### Comparison with Binary Search Tree (BST)

In comparison to a BST implementation, the code is simpler and search times are optimal (constant). The use of an efficient hash function can also satisfy the uniform hashing assumption. Hashing can be faster than a Red-Black BST, depending on the type of key. For typical key types, hashing will be significantly faster because it uses only a constant number of operations.

#### Testing Approach
#### Conclusions
#### Limitations and Critical Reflection
