/*
mainBook.cpp
Author: M00734132
Created: 26/03/2021
Updated: 16/04/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<iterator>
#include "Book.h"

//It determines if the string entered by the user is a number or not while entering the ISBN and quantity.
bool check_if_number(std::string str){
  for(unsigned int i =0; i < str.length(); i++){
    if(isdigit(str[i]) == false){
        return false;
    }
  }
      return true;
}

//This function comprises of the menu interface
//It calls the search, add & remove functions mentioned earlier
void mainMenu(std::string file_name){
  unsigned int s = 1024;
  Hash_Table *ht = new Hash_Table(s);
  std::cout << ht->ReadFile(file_name);

  char option;
  std::string title;
  std::string author;
  std::string isbn;
  std::string qty;

  do {
    std::cout << "\n****************************************";
    std::cout << "\n******** Book Management System ********";
    std::cout << "\n****************************************\n";
    std::cout << "\n******** Menu **********************\n";
    std::cout << "S : Search For Books (By Title) \n";
    std::cout << "A : Add Books \n";
    std::cout << "R : Remove Books \n";
    std::cout << "Q : Quit!\n";
    std::cout << "**************************************\n";
    std::cout << "\n\n Select an option from above: ";
    std::cin >> option;

    if (option == 'S' || option == 's') {
       std::cout << " \n************************************\n You chose S : Search For Books (By Title)\n************************************\n";
        std::cout<<"\nEnter the book's title:\n-----------------\n\n";
        std::cin.ignore();
        getline(std::cin, title);

        // user input validation
        if(title != " " && !title.empty() ){
          ht->searchBook(title);
        }else{
          std::cout << "Title space left blank. Please enter valid title" << std::endl;
        }

    } else if (option == 'A' || option == 'a') {
       std::cout << " \n************************************\n You chose A : Add Books \n************************************\n";
        std::cout<<"\nEnter the book's title:\n-----------------\n\n";
        std::cin.ignore();
        getline(std::cin, title);

        std::cout<<"\nEnter the author of the book:\n-----------------\n\n";
        getline(std::cin, author);

        std::cout<<"\nEnter the ISBN of the book:\n-----------------\n\n";
        getline(std::cin, isbn);

        // user input validation
        while(check_if_number(isbn) == false){
           std::cout << "Please enter valid ISBN number: " << std::endl;
           getline(std::cin, isbn);
        }

        std::cout<<"\nEnter the quantity of the book:\n-----------------\n\n";
        getline(std::cin,qty);

        // user input validation
        while(check_if_number(qty) == false){
           std::cout << "Please enter valid quantity: " << std::endl;
           getline(std::cin, qty);
        }

        // user input validation if the user enters empty string
        if(title != " " && !title.empty() && author != " " && !author.empty() && isbn != " " && !isbn.empty() && qty != " " && !qty.empty()){
          ht->addBook(title,author,isbn,qty);
          ht->insertContentToFile(title,author ,isbn ,qty ,file_name);
        }else{
          std::cout << "Either Title, Author, ISBN & Qty space is left blank. Please enter valid input" << std::endl;
        }

    } else if (option == 'R' || option == 'r') {
       std::cout << " \n************************************\n You chose R : Remove Books  \n************************************\n";
        std::cout<<"\nEnter the book's title:\n-----------------\n\n";
        std::cin.ignore();
        getline(std::cin, title);

        // user input validation
        if(title != " " && !title.empty())
        {
            if(ht->removeBook(title) == true)
            {
            ht->deleteFileContent(title, file_name);
            }
        }else{
          std::cout << "Title space left blank. Please enter valid title" << std::endl;
        }

    } else if (option != 'Q' && option != 'q') {
      std::cout << "Invalid option. Please enter S,R,A,V or Q \n " << std::endl;
    }

  } while (option != 'Q' && option != 'q');

  std::cout << "\n\t\tThank You!\n";
  std::cout << "\n\t\tTerminating.... ";

   delete ht;

}


int main(int argc, char *argv[]) {
  if(argc < 2){
    std::cout << "Enter Filename alongside " << argv[0] << " <filename>\n";
    exit(1);
  }

  std::string file_name;
  file_name = argv[1];
  mainMenu(file_name);

}
