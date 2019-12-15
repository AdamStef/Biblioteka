#pragma once
#include "Library.h"

class GameLibrary : public Library
{
private:
	Game* games;
public:
	GameLibrary();
	virtual ~GameLibrary() {};
	virtual void show();
	void add(Game games, int pos = -1);
	virtual void update(int pos);
	virtual void deleteB(int pos);
	virtual int getSize();
	virtual void decreaseSize();
	virtual void saveToFile();
	virtual void readFromFile();
	virtual bool fileValid();
	virtual void deletePointers();
};

