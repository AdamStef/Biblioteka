#pragma once
#include <algorithm>
#include <fstream>
#include "Book.h"
#include "Game.h"

class Library
{
private:
	int size;
	Book* books;
	Game* games;
public:
	Library();
	void showBooks();
	void showGames();
	void add(Book book, int pos = -1);
	void add(Game game, int pos = -1);
	void update(int pos);
	void deleteB(int pos);
	int getSize();
	void saveToFile();
	void readFromFile();
	bool fileValid();
	void deletePointers();
	//void sort();
	//bool compare(Book& a, Book& b);
};

