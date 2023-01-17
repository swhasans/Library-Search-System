#ifndef _BOOK_H_
#define _BOOK_H_

/*
Book.h
Author: M00734132
Created: 30/03/2021
Updated: 16/04/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<iterator>

class Book{

    private:
        std::string title;
        std::string author;
        std::string isbn;
        std::string qty;


    public:
        Book();
        Book(std::string title, std::string author, std::string isbn, std::string qty);
        Book* next;

        std::string get_title();
        std::string get_author();
        std::string get_isbn();
        std::string get_qty();
        Book* get_next();

        void set_title(std::string title);
        void set_author(std::string author);
        void set_isbn(std::string isbn);
        void set_qty(std::string qty);
        void set_next(Book *next);
};

class Hash_Table {
    private:
        unsigned int size;
        Book** internal_array;

    public:
        Hash_Table();
        Hash_Table(unsigned int size);
        ~Hash_Table();

        unsigned int get_size();
        unsigned long int hash_Func(std::string str);
        bool addBook(std::string title, std::string author, std::string isbn, std::string qty);
        std::vector<std::string> StringToVector(std::string title, char separator);
        bool removeBook(std::string title);
        bool searchBook(std::string title);

        void printHash();
        bool delete_table();
        std::string ReadFile(std::string file_name);
        std::string insertContentToFile(std::string title, std::string author, std::string isbn, std::string qty, std::string file_name);
        std::string deleteFileContent(std::string title, std::string file_name);
};

#endif
