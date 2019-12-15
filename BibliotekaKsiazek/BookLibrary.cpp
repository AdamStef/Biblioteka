#include "BookLibrary.h"


BookLibrary::BookLibrary() : Library()
{
	books = new Book[50];
}

void BookLibrary::show()
{
	for (int i = 0; i < size; i++)
	{
		books[i].show();
	}
}

void BookLibrary::add(Book book, int pos)
{
	if (pos == -1)
		pos = size;

	books[pos] = book;
	size++;
}

void BookLibrary::update(int pos)
{
	books[pos - 1].update();
}

void BookLibrary::deleteB(int pos)
{
	pos--;
	for (int i = pos; i < size - 1; i++) {
		books[i] = books[i + 1];
	}
	size--;
}

int BookLibrary::getSize()
{
	return size;
}

void BookLibrary::decreaseSize()
{
	size--;
}

void BookLibrary::saveToFile()
{
	fstream file;
	file.open("BookLibrary.txt", std::ios::out);
	if (file.good())
	{
		file << size << endl;
		for (int i = 0; i < size; i++)
		{
			file << books[i].getId() << endl;
			file << books[i].getTitle() << endl;
			file << books[i].getGenre() << endl;
			file << books[i].getAuthor() << endl;
			file << books[i].getDes() << endl;
			file << books[i].getPubDate() << endl;
		}

		file.close();
	}
}

void BookLibrary::readFromFile()
{
	string sizeS;
	int id;
	string idS;
	string title;
	string genre;
	string author;
	string description;
	string pub_date;
	fstream file;

	file.open("BookLibrary.txt", std::ios::in);
	if (file.good())
	{
		getline(file, sizeS);
		size = std::stoi(sizeS);

		for (int i = 0; i < size; i++)
		{
			getline(file, idS);
			getline(file, title);
			getline(file, genre);
			getline(file, author);
			getline(file, description);
			getline(file, pub_date);

			id = std::stoi(idS);

			this->add(Book(id, title, genre, description, pub_date, author), i);
			size--;
		}

		file.close();
	}
}

bool BookLibrary::fileValid()
{
	fstream file;
	file.open("BookLibrary.txt", std::ios::in);
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

void BookLibrary::deletePointers()
{
	delete[] books;
}