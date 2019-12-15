#include "Object.h"

Object::Object()
{
	m_id = 0;
	m_title = "";
	m_genre = "";
	m_description = "";
	m_pub_date = "";
}

Object::Object(int id, string title, string genre, string description, string pub_date)
{
	m_id = id;
	m_title = title;
	m_genre = genre;
	m_description = description;
	m_pub_date = pub_date;
}
