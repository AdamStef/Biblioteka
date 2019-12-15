#pragma once
#include <iostream>
#include <string>

using namespace std;

class Object
{
protected:
	int m_id;
	string m_title;
	string m_genre;
	string m_description;
	string m_pub_date;
public:
	Object();
	Object(int id, string title, string genre, string description, string pub_date);
	virtual ~Object(){}
	virtual void show() = 0;
	virtual void update() = 0;
	virtual int getId() = 0;
	virtual string getTitle() = 0;
	virtual string getGenre() = 0;
	virtual string getDes() = 0;
	virtual string getPubDate() = 0;
};

