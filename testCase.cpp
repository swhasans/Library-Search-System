/*
testCase.cpp
Author: M00734132
Created: 08/03/2021
Updated: 16/04/2021
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Book.cpp"
#include <iostream>


//Testing the main functionalities (Add, Remove & Search)
TEST_CASE("Test_coreFunctions", "[TestCoreFunctionality]")
{
std::string file_name = "books.txt";
unsigned int s = 1024;
Hash_Table *ht = new Hash_Table(s);
ht->ReadFile(file_name);

  REQUIRE(ht->searchBook("Graph Database Fundamentals") == true);
  REQUIRE(ht->addBook("Data Structures & Algorithms", "Robert De Niro", "43735746734", "1") == true);
  std::cout << std::endl;
  REQUIRE(ht->removeBook("Data Structures & Algorithms") == true);
  std::cout << std::endl;

  REQUIRE(ht->searchBook(" ") == false);
  std::cout << std::endl;
  REQUIRE(ht->addBook(" ", " ", " ", " ") == true);
  std::cout << std::endl;
  REQUIRE(ht->removeBook(" ") == true);
  std::cout << std::endl;
}


//Checking the file functionalities (File read, Insert content to file & Delete content from file)
TEST_CASE("Test_fileActions", "[TestFileFunctionality]")
{
std::string file_name = "books.txt";
std::string title = "Head First To Java";
std::string author = "Anthony Maquire";
std::string isbn = "7805938769571";
std::string qty = "2";

unsigned int s = 1024;
Hash_Table *ht = new Hash_Table(s);

    REQUIRE(ht->ReadFile(file_name) == "\nEntered File : " + file_name + " Read Successfully!");
    REQUIRE(ht->insertContentToFile(title, author, isbn, qty, file_name) ==
    "\nEntered data : Title- '" + title + "' Author- '" + author + "' ISBN- '" + isbn + "' Quantity- '" + qty +  "' added to '" + file_name + "' Successfully!\n" );
    REQUIRE(ht->deleteFileContent(title, file_name) == "\nEntered data : Title- '" + title + "' deleted from '" + file_name + "' Successfully!" );
    std::cout << std::endl;
}


//Checking if the hash table contents and itself is erased after the program is terminated (Delete Table)
 TEST_CASE("Test_hashtableDeleted", "[TestDeleteTable]")
{
    std::string file_name = "books.txt";
    unsigned int s = 1024;
    Hash_Table *ht = new Hash_Table(s);
    ht->ReadFile(file_name);

  REQUIRE(ht->delete_table() == true);

}


