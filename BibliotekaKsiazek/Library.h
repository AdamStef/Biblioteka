#pragma once
#include <fstream>
#include "Book.h"
#include "Game.h"

class Library
{
public:
	int size;
	Library();
	//Library(char c);
	virtual ~Library() {};
	virtual void show() = 0;
	virtual void update(int pos) = 0;
	virtual void deleteB(int pos) = 0;
	virtual int getSize() = 0;
	virtual void decreaseSize() = 0;
	virtual void saveToFile() = 0;
	virtual void readFromFile() = 0;
	virtual bool fileValid() = 0;
	virtual void deletePointers() = 0;
	//void sort();
	//bool compare(Book& a, Book& b);
};

