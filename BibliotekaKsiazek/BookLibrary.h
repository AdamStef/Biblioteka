#pragma once
#include "Library.h"

class BookLibrary : public Library
{
private:
	Book* books;
public:
	BookLibrary();
	virtual ~BookLibrary() {};
	virtual void show();
	void add(Book book, int pos = -1);
	virtual void update(int pos);
	virtual void deleteB(int pos);
	virtual int getSize();
	virtual void decreaseSize();
	virtual void saveToFile();
	virtual void readFromFile();
	virtual bool fileValid();
	virtual void deletePointers();
};

