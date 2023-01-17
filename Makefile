CXX = g++
CXXFLAGS = -g -Wall -Wextra

.PHONY: all run

run: all
	./mainBook books.txt

all: mainBook

mainBook: mainBook.cpp Book.o
	$(CXX) $(CXXFLAGS) -o $@ $^
Book.o: Book.cpp  Book.h
	$(CXX) $(CXXFLAGS) -c $<
.PHONY : clean
clean:
	rm -rf *~ *.o mainBook

