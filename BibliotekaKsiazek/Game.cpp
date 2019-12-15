#include "Game.h"

Game::Game() : Object()
{
	m_singleplayer = false;
	m_multiplayer = false;
	m_ageLimit = 0;
}

Game::Game(int id, string title, string genre, string description, string pub_date, string single, string multi) : Object(id, title, genre, description, pub_date)
{
}

void Game::show()
{
}

Game Game::add()
{
	return Game();
}

void Game::update()
{
}

int Game::getId()
{
	return m_id;
}

string Game::getTitle()
{
	return string();
}

string Game::getGenre()
{
	return string();
}

string Game::getDes()
{
	return string();
}

string Game::getPubDate()
{
	return string();
}

string Game::setTitle(string s)
{
	return string();
}

string Game::setDes(string s)
{
	return string();
}

string Game::setPubDate(string s)
{
	return string();
}
