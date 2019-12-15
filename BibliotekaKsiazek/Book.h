#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Book : public Object
{
private:
	bool m_error;
	string m_author;
public:
	Book();
	Book(int id, string title, string genre, string description, string pub_date, string author);
	Book(int id, string title, string genre, string description, string pub_date, string author, bool error);
	virtual ~Book() {};
	virtual void show();
	Book add();
	virtual void update();

	virtual int getId();
	virtual string getTitle();
	string getAuthor();
	virtual string getGenre();
	virtual string getDes();
	virtual string getPubDate();
	bool isError();
	void setError(bool is);
};

