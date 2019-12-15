#pragma once
#include <iostream>
#include <string>

using namespace std;

class Object
{
private:
	int m_id;
	string m_title;
	string m_genre;
	string m_description;
	string m_pub_date;
public:
	Object();
	Object(int id, string title, string description, string pub_date);
	virtual ~Object(){}
	virtual void show();
	virtual void update();
	virtual string getTitle();
	virtual string getDes();
	virtual string getPubDate();
	virtual string setTitle(string s);
	virtual string setDes(string s);
	virtual string setPubDate(string s);
};

