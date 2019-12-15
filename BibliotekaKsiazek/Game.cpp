#include "Game.h"

Game::Game() : Object()
{
	m_singleplayer = false;
	m_multiplayer = false;
	m_ageLimit = 0;
	m_error = false;
}

Game::Game(int id, string title, string genre, string description, string pub_date, int ageLimit, string single, string multi) : Object(id, title, genre, description, pub_date)
{
	m_error = false;
	m_ageLimit = ageLimit;
	if (single == "y")
		m_singleplayer = true;
	else
		m_singleplayer = false;
	if (multi == "y")
		m_multiplayer = true;
	else
		m_multiplayer = false;
}

Game::Game(int id, string title, string genre, string description, string pub_date, int ageLimit, string single, string multi, bool error) : Object(id, title, genre, description, pub_date)
{
	m_error = error;
	m_ageLimit = ageLimit;
	if (single == "y")
		m_singleplayer = true;
	else
		m_singleplayer = false;
	if (multi == "y")
		m_multiplayer = true;
	else
		m_multiplayer = false;
}

void Game::show()
{
	cout << endl;
	cout << this->m_id << ". " << this->m_title << endl;
	cout << "Gatunek: " << this->m_genre << endl;
	cout << "Opis: " << this->m_description << endl;
	cout << "Rok wydania: " << this->m_pub_date << endl;
	cout << "Limit wiekowy: " << this->m_ageLimit << endl;
	cout << "Singleplayer?: ";
	if (m_singleplayer)
		cout << "y" << endl;
	else
		cout << "n" << endl;
	cout << "Multiplayer?: ";
		if (m_multiplayer)
			cout << "y" << endl;
		else
			cout << "n" << endl;
	cout << endl;
}

Game Game::add()
{
	bool idIsDigit = false;
	bool ageIsDigit = false;
	int id = 0;
	string idS;
	string title;
	string genre;
	string description;
	string pub_date;
	int ageLimit = 0;
	string ageLimitS;
	string single;
	string multi;

	cout << "Podaj ID: ";
	getline(cin.ignore(), idS);
	cout << "Podaj tytul: ";
	getline(cin, title);
	cout << "Podaj gatunek: ";
	getline(cin, genre);
	cout << "Podaj opis: ";
	getline(cin, description);
	cout << "Podaj date publikacji: ";
	getline(cin, pub_date);
	cout << "Podaj limit wiekowy: ";
	getline(cin, ageLimitS);
	cout << "Czy ta gra jest singleplayer(y/n): ";
	getline(cin, single);
	cout << "Czy ta gra jest multiplayer(y/n): ";
	getline(cin, multi);

	for (auto i : idS)
	{
		if (isdigit(i))
			idIsDigit = true;
		else
		{
			idIsDigit = false;
			break;
		}
	}
	if (idIsDigit)
		id = stoi(idS);
	else
	{
		return Game(0, "", "", "", "", 0, "", "", true);
	}

	for (auto i : ageLimitS)
	{
		if (isdigit(i))
			ageIsDigit = true;
		else
		{
			ageIsDigit = false;
			break;
		}
	}
	if (ageIsDigit)
		ageLimit = stoi(ageLimitS);
	else
	{
		return Game(0, "", "", "", "", 0, "", "", true);
	}

	return Game(id, title, genre, description, pub_date, ageLimit, single, multi, false);
}

void Game::update()
{
	bool isDigit = false;
	bool ageIsDigit = false;
	int id = 0;
	string idS = "";
	string title = "";
	string genre = "";
	int ageLimit = 0;
	string ageLimitS = "";
	string description = "";
	string pub_date = "";
	string single = "";
	string multi = "";

	cout << "Podaj ID: ";
	getline(cin.ignore(), idS);
	cout << "Podaj tytul: ";
	getline(cin, title);
	cout << "Podaj gatunek: ";
	getline(cin, genre);
	cout << "Podaj opis: ";
	getline(cin, description);
	cout << "Podaj date publikacji: ";
	getline(cin, pub_date);
	cout << "Podaj limit wiekowy: ";
	getline(cin, ageLimitS);
	cout << "Czy ta gra jest singleplayer(y/n): ";
	getline(cin, single);
	cout << "Czy ta gra jest multiplayer(y/n): ";
	getline(cin, multi);

	if (idS == "")
		id = m_id;
	else
	{
		for (auto id : idS)
		{
			if (isdigit(id))
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

	if (ageLimitS == "")
		ageLimit = m_ageLimit;
	else
	{
		for (auto age : ageLimitS)
		{
			if (isdigit(age))
				ageIsDigit = true;
			else
			{
				ageIsDigit = false;
				break;
			}
		}
		if (ageIsDigit)
			ageLimit = stoi(ageLimitS);
		else
		{
			cout << "\nZly wiek" << endl;
			return;
		}
	}
	

	if (id == 0)
		id = m_id;
	if (genre == "")
		genre = m_genre;
	if (title == "")
		title = m_title;
	if (description == "")
		description = m_description;
	if (pub_date == "")
		pub_date = m_pub_date;
	if (ageLimit == 0)
		ageLimit = m_ageLimit;
	if (single == "")
		if (m_singleplayer)
			single = "y";
		else
			single = "n";
	if (multi == "")
		if (m_multiplayer)
			multi = "y";
		else
			multi = "n";

	m_id = id;
	m_title = title;
	m_genre = genre;
	m_description = description;
	m_pub_date = pub_date;
	m_ageLimit = ageLimit;

	if (single == "y")
		m_singleplayer = true;
	else
		m_singleplayer = false;
	if (multi == "n")
		m_multiplayer = true;
	else
		m_multiplayer = false;
}

int Game::getId()
{
	return m_id;
}

string Game::getTitle()
{
	return m_title;
}

string Game::getGenre()
{
	return m_genre;
}

string Game::getDes()
{
	return m_description;
}

string Game::getPubDate()
{
	return m_pub_date;
}

string Game::getSingle()
{
	if (m_singleplayer)
		return "y";
	else
		return "n";
}

string Game::getMulti()
{
	if (m_multiplayer)
		return "y";
	else
		return "n";
}

int Game::getAgeLimit()
{
	return m_ageLimit;
}

bool Game::isError()
{
	return m_error;
}

void Game::setError(bool is)
{
	m_error = is;
}
