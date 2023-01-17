/*
Book.cpp
Author: M00734132
Created: 30/03/2021
Updated: 16/04/2021
*/

#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include<list>
#include <fstream>
#include <sstream>
#include<iterator>



 Book :: Book(){
	 this->next = nullptr;
 }


 Book :: Book(std::string title,std::string author, std::string isbn, std::string qty){
	this->title = title;
	this->author = author;
	this->isbn = isbn;
	this->qty = qty;
	this->next = nullptr;
 }

  std::string Book :: get_title(){
    return this->title;
  }

  std::string Book :: get_author(){
    return this->author;
  }

  std::string Book :: get_isbn(){
    return this->isbn;
  }

  std::string Book :: get_qty(){
    return this->qty;
  }

   Book* Book :: get_next(){
     return this->next;
   }

  void Book :: set_title(std::string title){
      this->title = title;
  }

  void Book :: set_author(std::string author){
      this->author = author;
  }

    void Book :: set_isbn(std::string isbn){
      this->isbn = isbn;
  }

    void Book :: set_qty(std::string qty){
      this->qty = qty;
  }

  void Book :: set_next(Book * next){
    this->next = next;
  }

Hash_Table :: Hash_Table(){
}

//Hash table constructor
Hash_Table :: Hash_Table(unsigned int size) {
    unsigned int i;
    if (!size)
        throw "author must be over 0";
    this->size = size;
    this->internal_array = new Book*[size];
    for (i = 0; i < size; i++)
        this->internal_array[i] = nullptr;
}

//Hash table destructor
Hash_Table :: ~Hash_Table(){
  this->delete_table();

}

//Hash function returns hash code
unsigned long int Hash_Table::hash_Func(std::string str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    for (auto x: str)
    {
        c = x;
        hash = ((hash << 5) + hash) + c;
        /* hash * 33 + c */
    }
    return (hash % this->size);
}

// insert the book into the hash table
bool Hash_Table::addBook(std::string title, std::string author, std::string isbn, std::string qty) {
    Book *curr;
    unsigned long int idx;

        Book *n = new Book(title, author, isbn, qty);
        idx = this->hash_Func(title);
        curr = this->internal_array[idx];

        if (curr == nullptr) {
            this->internal_array[idx] = n;
            return true;
        }

        while (true)
        {
            if (title == curr->get_title())
            {
                // author found in the chain (so modify)
                curr->set_author(author);
                curr->set_isbn(isbn);
                curr->set_qty(qty);
                return true;
            }

            if (curr->get_next() && curr->get_next()->get_next())
            {
                curr = curr->get_next();
                continue;
            }else{
                break;
            }
        }
        curr->set_next(n);
        return true;
}

// search the book from the hash table
bool Hash_Table :: searchBook(std::string title){
    unsigned long int idx;
    std::string str;
    Book *curr;

        idx = this->hash_Func(title);
        curr = this->internal_array[idx];

            while (curr)
            {
                if (title == curr->get_title())
                {
                  // author found in the chain (retrieve book details)
                  curr->get_author();
                  curr->get_isbn();
                  curr->get_qty();
                    str = "\nAuthor : " + curr->get_author() + "\nISBN : " + curr->get_isbn() + "\nQuantity : " + curr->get_qty();
                    std::cout << str;
                    return true;
                }
                 curr = curr->get_next();
            }
            std::cout << "The title: " << title << " is not present in hash table. Please enter a valid title\n" << std::endl;
            return false;
  }

// remove the book from the hash table
bool Hash_Table :: removeBook(std::string title){
unsigned long int idx;
    std::string str;
    Book *curr;
    Book *prev;

    idx = this->hash_Func(title);

	for (curr = this->internal_array[idx]; curr != nullptr; prev = curr, curr = curr->get_next())
        {
            if (title == curr->get_title())
            {
                // we found the title in our chain
                break; // break out so we can delete this later on
            }
        }

	// if curr == nullptr we have gone through the entire chain
	// and found nothing (or the initial hash gave us nothing).
    if(!curr)
        {
            str = "The title '" + title + "' was not found in the hash table. Enter valid title\n";
            std::cout << str;
            return false;
        }

	// if the node to be deleted has a next
	if (curr->get_next() != nullptr)
        {
            prev->set_next(curr->get_next());
        }

	delete curr;

    str = "The title: '" + title + "' has been removed from the hash table Successfully\n";
    std::cout << str;

    return true;


}

//Put the string into a vector
std::vector<std::string> Hash_Table:: StringToVector(std::string title, char separator){


    std::vector<std::string> vecsWords;
    std::stringstream ss (title);
    std::string sIndivStr;

    while(getline(ss, sIndivStr, separator)){

        vecsWords.push_back(sIndivStr);
    }

    return vecsWords;
    }

//Delete Hash table destructor
bool Hash_Table::delete_table()
{
    std::string str = " ";
    Book *tmp;
    Book *curr;
    unsigned long int i;

    for (i = 0; i < this->size; i++)
    {
        if ((curr = this->internal_array[i]))
        {
            while (curr)
            {
                tmp = curr;
                curr = curr->get_next();
                delete tmp;
            }
         }
     }
     delete[] this->internal_array;
     str = "\nThe Hash Table has been deleted Successfully";
     std::cout << str << std::endl;
     return true;
}

// Read provided file
std::string Hash_Table::ReadFile(std::string file_name){
std::string str = " ";
std::ifstream f;
std::string lineFromFile = " ";
f.open(file_name, std::ios_base::in);

if(f.is_open())
{
  while(f.good())
  {
    getline(f, lineFromFile);
    std::vector<std::string> vect = StringToVector(lineFromFile, '\t');
      if(f.good())
      {
        this->addBook(vect[0], vect[1], vect[2], (vect[3]));
      }
  }
  f.close();
  str = "\nEntered File : " + file_name + " Read Successfully!";
  return str;
}else
    {
          str = "\nEntered File : " + file_name + " Not read, Enter with proper file name/format";
          return str;
    }
}

// Insert book into provided file
std::string Hash_Table::insertContentToFile(std::string title,std::string author, std::string isbn, std::string qty, std::string file_name) {
std::string str = "";
std::fstream f;
f.open(file_name,std::ios_base::out|std::ios::app);
f << title << '\t' << author << '\t' << isbn << '\t' << qty << '\n';
f.close();

str = "\nEntered data : Title- '" + title + "' Author- '" + author + "' ISBN- '" + isbn + "' Quantity- '" + qty +  "' added to '" + file_name + "' Successfully!\n" ;
return str;
}

// Delete book from provided file
std::string Hash_Table::deleteFileContent (std::string title, std::string file_name){
std::string str = " ";
std::string lineFromFile = " ";
std::ifstream f;
f.open(file_name);
std::ofstream temp;
temp.open("temp.txt");
while (getline(f, lineFromFile))
{
  if (lineFromFile.substr(0, title.size()) != title)
    {
      temp << lineFromFile << std::endl;
    }
}

str = "\nEntered data : Title- '" + title + "' deleted from '" + file_name + "' Successfully!";
std::cout << str << std::endl;;
f.close();
temp.close();
std::remove(file_name.c_str());
rename("temp.txt", file_name.c_str());

return str;
}
