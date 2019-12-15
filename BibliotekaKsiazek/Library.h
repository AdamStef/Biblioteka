#pragma once
#include <algorithm>
#include <fstream>
#include "Book.h"

class Library
{
private:
	int size;
	Book* books;
public:
	Library();
	~Library();
	void show();
	void add(Book book, int pos = -1);
	void update(int pos);
	void deleteB(int pos);
	int getSize();
	void saveToFile();
	void readFromFile();
	bool fileValid();
	//void sort();
	//bool compare(Book& a, Book& b);
};

