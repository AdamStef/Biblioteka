#include "Object.h"

Object::Object()
{
	m_id = 0;
	m_title = "";
	m_description = "";
	m_pub_date = "";
}

Object::Object(int id, string title, string description, string pub_date)
{
	m_id = id;
	m_title = title;
	m_description = description;
	m_pub_date = pub_date;
}
