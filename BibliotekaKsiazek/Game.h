#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Game : public Object
{
private:
	bool m_singleplayer;
	bool m_multiplayer;
	int m_ageLimit;
	bool m_error;
public:
	Game();
	Game(int id, string title, string genre, string description, string pub_date, int ageLimit, string single, string multi);
	Game(int id, string title, string genre, string description, string pub_date, int ageLimit, string single, string multi, bool error);
	virtual ~Game() {};
	virtual void show();
	Game add();
	virtual void update();

	virtual int getId();
	virtual string getTitle();
	virtual string getGenre();
	virtual string getDes();
	virtual string getPubDate();
	string getSingle();
	string getMulti();
	int getAgeLimit();
	bool isError();
	void setError(bool is);
};

