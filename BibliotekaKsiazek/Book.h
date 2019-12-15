#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Book : public Object
{
private:
	int m_id;
	bool m_is_lent;
	string m_title;
	string m_author;
	string m_description;
	string m_pub_date;
public:
	Book();
	Book(int id, string title, string author, string description, string pub_date);
	void show();
	Book add();
	Book add(Book book);
	void update();
	//void deleteB(Book book);
	void lend(Book book);
	void returnB(Book book);
	int getId();
	string getTitle();
	string getAuthor();
	string getDes();
	string getPubDate();
	string setTitle(string s);
	string setAuthor(string s);
	string setDes(string s);
	string setPubDate(string s);
};

