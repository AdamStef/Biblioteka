#include "Book.h"

Book::Book() : Object()
{
	m_author = "";
	m_is_lent = false;
}

Book::Book(int id, string title, string genre, string description, string pub_date, string author) : Object(id, title, genre, description, pub_date)
{
	m_author = author;
	m_is_lent = false;
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

	id = stoi(idS);

	return Book(id, title, genre, description, pub_date, author);
}
//
//Book Book::add(Book book)
//{
//	cout << "Podaj ID: ";
//	cin >> book.m_id;
//	cout << "Podaj tytul: ";
//	cin >> book.m_title;
//	cout << "Podaj autora: ";
//	cin >> book.m_author;
//	cout << "Podaj opis: ";
//	cin >> book.m_description;
//	cout << "Podaj date publikacji: ";
//	cin >> book.m_pub_date;
//	//string name = to_string(id);
//	//Book name = Book(id, title, author, description, pub_date);
//	return Book(book.m_id, book.m_title, book.m_author, book.m_description, book.m_pub_date);
//}

void Book::update()
{
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

	if (id == 0)
		id = m_id;
	if (title == "")
		title = m_genre;
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
//
//void Book::deleteB(Book book)
//{
//	book.~Book();
//}

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

string Book::setTitle(string s)
{
	return m_title = s;
}

string Book::setAuthor(string s)
{
	return m_author = s;
}

string Book::setDes(string s)
{
	return m_description = s;
}

string Book::setPubDate(string s)
{
	return m_pub_date = s;
}
