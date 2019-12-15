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
public:
	Game();
	Game(int id, string title, string genre, string description, string pub_date, string single, string multi);
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

	virtual string setTitle(string s);
	virtual string setDes(string s);
	virtual string setPubDate(string s);
};

