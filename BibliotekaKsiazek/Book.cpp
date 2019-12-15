#include "Book.h"

Book::Book() : Object()
{
	m_author = "";
}

Book::Book(int id, string title, string genre, string description, string pub_date, string author) : Object(id, title, genre, description, pub_date)
{
	m_author = author;
}

Book::Book(int id, string title, string genre, string description, string pub_date, string author, bool error) : Object(id, title, genre, description, pub_date)
{
	m_author = author;
	m_error = error;
}

void Book::show()
{
	cout << endl;
	cout << this->m_id << ". " << this->m_title << endl;
	cout << "Autor: " << this->m_author << endl;
	cout << "Gatunek: " << this->m_genre << endl;
	cout << "Opis: " << this->m_description << endl;
	cout << "Rok wydania: " << this->m_pub_date << endl;
	cout << endl;
}


Book Book::add()
{
	bool isDigit = false;
	int id = 0;
	string idS;
	string title;
	string author;
	string genre;
	string description;
	string pub_date;
	cout << "Podaj ID: ";
	getline(cin.ignore(), idS);
	cout << "Podaj tytul: ";
	getline(cin, title);
	cout << "Podaj autora: ";
	getline(cin, author);
	cout << "Podaj gatunek: ";
	getline(cin, genre);
	cout << "Podaj opis: ";
	getline(cin, description);
	cout << "Podaj date publikacji: ";
	getline(cin, pub_date);

	for (auto i : idS)
	{
		if (isdigit(i))
			isDigit = true;
		else
		{
			isDigit = false;
			break;
		}
	}
	if (isDigit)
		id = stoi(idS);
	else
	{
		return Book(0, "", "", "", "", "", true);
	}

	return Book(id, title, genre, description, pub_date, author, false);
}

void Book::update()
{
	bool isDigit = false;
	int id = 0;
	string idS = "";
	string title = "";
	string author = "";
	string genre = "";
	string description = "";
	string pub_date = "";
	cout << "Podaj ID: ";
	getline(cin.ignore(), idS);
	cout << "Podaj tytul: ";
	getline(cin, title);
	cout << "Podaj autora: ";
	getline(cin, author);
	cout << "Podaj gatunek: ";
	getline(cin, genre);
	cout << "Podaj opis: ";
	getline(cin, description);
	cout << "Podaj date publikacji: ";
	getline(cin, pub_date);

	if (idS == "")
		id = m_id;
	else
	{
		for (auto i : idS)
		{
			if (isdigit(i))
				isDigit = true;
			else
			{
				isDigit = false;
				break;
			}
		}
		if (isDigit)
			id = stoi(idS);
		else
		{
			cout << "\nZle ID" << endl;
			return;
		}
	}

	if (id == 0)
		id = m_id;
	if (genre == "")
		genre = m_genre;
	if (title == "")
		title = m_title;
	if (author == "")
		author = m_author;
	if (description == "")
		description = m_description;
	if (pub_date == "")
		pub_date = m_pub_date;

	m_id = id;
	m_title = title;
	m_genre = genre;
	m_author = author;
	m_description = description;
	m_pub_date = pub_date;
}

int Book::getId()
{
	return m_id;
}

string Book::getTitle()
{
	return m_title;
}

string Book::getAuthor()
{
	return m_author;
}

string Book::getGenre()
{
	return m_genre;
}

string Book::getDes()
{
	return m_description;
}

string Book::getPubDate()
{
	return m_pub_date;
}

bool Book::isError()
{
	return m_error;
}

void Book::setError(bool is)
{
	m_error = is;
}