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
	//Book add(Book book);
	virtual void update();
	//void deleteB(Book book);
	//void lend(Book book);
	//void returnB(Book book);

	virtual int getId();
	virtual string getTitle();
	string getAuthor();
	virtual string getGenre();
	virtual string getDes();
	virtual string getPubDate();
	bool isError();
	void setError(bool is);

	virtual string setTitle(string s);
	string setAuthor(string s);
	virtual string setDes(string s);
	virtual string setPubDate(string s);
};

