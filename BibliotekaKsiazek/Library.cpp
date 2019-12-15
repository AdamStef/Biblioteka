#include "Library.h"

Library::Library()
{
	size = 0;
	books = new Book[50];
}

Library::~Library()
{
	delete[] books;
}

void Library::show()
{
	for (int i = 0; i < size; i++)
	{
		books[i].show();
	}
}

void Library::add(Book book, int pos)
{
	if (pos == -1)
		pos = size;

	books[pos] = book;
	size++;
}

void Library::update(int pos)
{
	books[pos - 1].update();
}

void Library::deleteB(int pos)
{
	pos--;
	for (int i = pos; i < size - 1; i++) {
		books[i] = books[i + 1];
	}
	size--;
}

int Library::getSize()
{
	return size;
}

void Library::saveToFile()
{
	fstream file;
	file.open("library.txt", std::ios::out);
	if (file.good())
	{
		file << size << endl;
		for (int i = 0; i < size; i++)
		{
			file << books[i].getId() << endl;
			file << books[i].getTitle() << endl;
			file << books[i].getAuthor() << endl;
			file << books[i].getDes() << endl;
			file << books[i].getPubDate() << endl;
		}

		file.close();
	}
}

void Library::readFromFile()
{
	string sizeS;
	int id;
	string idS;
	string title;
	string author;
	string description;
	string pub_date;
	fstream file;

	file.open("library.txt", std::ios::in);
	if (file.good())
	{
		getline(file, sizeS);
		size = std::stoi(sizeS);

		for (int i = 0; i < size; i++)
		{
			getline(file, idS);
			getline(file, title);
			getline(file, author);
			getline(file, description);
			getline(file, pub_date);

			id = std::stoi(idS);

			this->add(Book(id, title, author, description, pub_date), i);
			size--;
		}

		file.close();
	}
}

bool Library::fileValid()
{
	fstream file;
	file.open("library.txt", std::ios::in);
	if (file.good())
	{
		string s;
		getline(file, s);
		if (s != "")
		{
			file.close();
			return true;
		}
		else
		{
			file.close();
			return false;
		}
	}
	else
	{
		file.close();
		return false;
	}

}



//
//void Library::sort()
//{
//	//std::sort(books, books + 50, compare);
//	std::sort(books, books + 50,
//		[](Book const& a, Book const& b) -> bool
//	{ return a.m_id < b.m_id; });
//}
//
//bool Library::compare(Book& a, Book& b)
//{
//	return a.m_id < b.m_id;
//}