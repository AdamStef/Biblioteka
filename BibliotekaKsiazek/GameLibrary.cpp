#include "GameLibrary.h"

GameLibrary::GameLibrary() : Library()
{
	games = new Game[50];
}

void GameLibrary::show()
{
	for (int i = 0; i < size; i++)
	{
		games[i].show();
	}
}

void GameLibrary::add(Game game, int pos)
{
	if (pos == -1)
		pos = size;

	games[pos] = game;
	size++;
}

void GameLibrary::update(int pos)
{
	games[pos - 1].update();
}

void GameLibrary::deleteB(int pos)
{
	pos--;
	for (int i = pos; i < size - 1; i++) {
		games[i] = games[i + 1];
	}
	size--;
}

int GameLibrary::getSize()
{
	return size;
}

void GameLibrary::decreaseSize()
{
	size--;
}

void GameLibrary::saveToFile()
{
	fstream file;
	file.open("GameLibrary.txt", std::ios::out);
	if (file.good())
	{
		file << size << endl;
		for (int i = 0; i < size; i++)
		{
			file << games[i].getId() << endl;
			file << games[i].getTitle() << endl;
			file << games[i].getGenre() << endl;
			file << games[i].getDes() << endl;
			file << games[i].getPubDate() << endl;
			file << games[i].getAgeLimit() << endl;
			file << games[i].getSingle() << endl;
			file << games[i].getMulti() << endl;
		}

		file.close();
	}
}

void GameLibrary::readFromFile()
{
	string sizeS;
	int id;
	string idS;
	string title;
	string genre;
	string description;
	string pub_date;
	int ageLimit;
	string ageLimitS;
	string single;
	string multi;


	fstream file;

	file.open("GameLibrary.txt", std::ios::in);
	if (file.good())
	{
		getline(file, sizeS);
		size = std::stoi(sizeS);

		for (int i = 0; i < size; i++)
		{
			getline(file, idS);
			getline(file, title);
			getline(file, genre);
			getline(file, description);
			getline(file, pub_date);
			getline(file, ageLimitS);
			getline(file, single);
			getline(file, multi);

			id = std::stoi(idS);
			ageLimit = std::stoi(ageLimitS);

			this->add(Game(id, title, genre, description, pub_date, ageLimit, single, multi), i);
			size--;
		}

		file.close();
	}
}

bool GameLibrary::fileValid()
{
	fstream file;
	file.open("GameLibrary.txt", std::ios::in);
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

void GameLibrary::deletePointers()
{
	delete[] games;
}