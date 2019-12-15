#include <iostream>
#include "Book.h"
#include "Game.h"
#include "BookLibrary.h"
#include "GameLibrary.h"

using namespace std;

char mainMenu()
{
	char wybor = 'h';
	cout << "\n-----------------------------------" << endl;
	cout << "1. Biblioteka ksiazek" << endl;
	cout << "2. Biblioteka gier" << endl;

	cout << "k - koniec programu" << endl;
	cout << "-----------------------------------\n" << endl;

	cout << "Co chcesz zrobic? ";
	cin >> wybor;
	cout << endl;
	return wybor;
}

char bookMenu()
{
	char wybor = 'h';
	cout << "\n-----------------------------------" << endl;
	cout << "1. Wypisz ksiazki w bibliotece" << endl;
	cout << "2. Dodaj ksiazke" << endl;
	cout << "3. Usun ksiazke" << endl;
	cout << "4. Edytuj ksiazke" << endl;

	cout << "z - zapisz do pliku" << endl;
	cout << "w - wczytaj z pliku" << endl;
	cout << "r - resetuj biblioteke (kasowanie wszystkich niezapisanych danych)" << endl;
	cout << "c - cofnij do menu glownego" << endl;
	//cout << "k - koniec programu" << endl;
	cout << "-----------------------------------\n" << endl;

	cout << "Co chcesz zrobic? ";
	cin >> wybor;
	cout << endl;
	return wybor;
}

char gameMenu()
{
	char wybor = 'h';
	cout << "\n-----------------------------------" << endl;
	cout << "1. Wypisz gry w bibliotece" << endl;
	cout << "2. Dodaj gre" << endl;
	cout << "3. Usun gre" << endl;
	cout << "4. Edytuj gre" << endl;

	cout << "z - zapisz do pliku" << endl;
	cout << "w - wczytaj z pliku" << endl;
	cout << "r - resetuj biblioteke (kasowanie wszystkich niezapisanych danych)" << endl;
	cout << "c - cofnij do menu glownego" << endl;
	cout << "-----------------------------------\n" << endl;

	cout << "Co chcesz zrobic? ";
	cin >> wybor;
	cout << endl;
	return wybor;
}

bool forSure()
{
	char wybor = 'h';
	cout << " (y/n) ";
	cin >> wybor;
	cout << endl;
	while (true)
	{
		if (wybor == 'y' || wybor == 'Y')
			return true;
		else if (wybor == 'n' || wybor == 'N')
			return false;
		else
			cout << "Zla opcja" << endl;
	}
}

int main()
{
	char biblioteka = 'h';
	char wybor = 'h';
	int pos;
	Book book;
	Game game;
	BookLibrary lib = BookLibrary();
	GameLibrary gLib = GameLibrary();
	if (lib.fileValid())
	{
		lib.readFromFile();
	}
	if (gLib.fileValid())
	{
		gLib.readFromFile();
	}
	while (biblioteka != 'k')
	{
		wybor = 'h';
		cout << "Witaj w bibliotece!" << endl;
		biblioteka = mainMenu();
		switch (biblioteka)
		{
		case '1':
			
			system("cls");
			cout << "Witaj w bibliotece ksiazek!" << endl;
			while (wybor != 'c')
			{
				wybor = bookMenu();
				switch (wybor)
				{
				case '1':
					system("cls");
					cout << "Wyswietlanie..." << endl;
					if (lib.getSize() == 0)
						cout << "Brak ksiazek w bibliotece." << endl;
					else
						lib.show();
					break;
				case '2':
					cout << "Dodawanie..." << endl;
					book = book.add();
					if (!book.isError())
					{
						lib.add(book);
						system("cls");
						book.show();
					}
					else
					{
						system("cls");
						cout << "\nNie dodano ksiazki\n" << endl;
					}
					break;
				case '3':
					system("cls");
					cout << "Usuwanie..." << endl;
					cout << "Podaj pozycje ksiazki do usuniecia: ";
					cin >> pos;
					lib.deleteB(pos);
					break;
				case '4':
					cout << "Edytowanie..." << endl;
					cout << "Podaj pozycje ksiazki do edycji: ";
					cin >> pos;
					lib.update(pos);
					system("cls");
					break;
				case 'Z':
				case 'z':
					cout << "Czy chcesz zapisac dane?";
					if (forSure())
					{
						lib.saveToFile();
						system("cls");
						cout << "Zapisano do pliku." << endl;
					}
					else
						cout << "Nie zapisano danych." << endl;
					break;
				case 'W':
				case 'w':
					cout << "Czy chcesz wczytac dane?";
					if (lib.fileValid() && forSure())
					{
						lib = BookLibrary();
						lib.readFromFile();
						system("cls");
						cout << "Wczytano dane z pliku." << endl;
					}
					else if (!lib.fileValid())
						cout << "Brak danych do wczytania." << endl;
					else
						cout << "Nie wczytano danych." << endl;
					break;
				case 'R':
				case 'r':
					cout << "Czy chcesz zresetowac dane?";
					if (forSure())
					{
						lib = BookLibrary();
						system("cls");
					}
					else
						cout << "Nie skasowano danych." << endl;
					break;
				case 'C':
				case 'c':
					break;
				default:
					cout << "Podano zla opcje!" << endl;
					break;
				}
			}
			system("cls");
			break;
		case '2':
			system("cls");
			cout << "Witaj w bibliotece gier!" << endl;
			while (wybor != 'c')
			{
				wybor = gameMenu();
				switch (wybor)
				{
				case '1':
					system("cls");
					cout << "Wyswietlanie..." << endl;
					if (gLib.getSize() == 0)
						cout << "Brak gier w bibliotece." << endl;
					else
						gLib.show();
					break;
				case '2':
					cout << "Dodawanie..." << endl;
					game = game.add();
					if (!game.isError())
					{
						gLib.add(game);
						system("cls");
						game.show();
					}
					else
					{
						system("cls");
						cout << "\nNie dodano gry\n" << endl;
					}
					break;
				case '3':
					cout << "Usuwanie..." << endl;
					cout << "Podaj pozycje gry do usuniecia: ";
					cin >> pos;
					gLib.deleteB(pos);
					break;
				case '4':
					cout << "Edytowanie..." << endl;
					cout << "Podaj pozycje gry do edycji: ";
					cin >> pos;
					gLib.update(pos);
					system("cls");
					cout << "Zmieniono gre" << endl;
					break;
				case 'Z':
				case 'z':
					cout << "Czy chcesz zapisac dane?";
					if (forSure())
					{
						gLib.saveToFile();
						system("cls");
						cout << "Zapisano do pliku." << endl;
					}
					else
						cout << "Nie zapisano danych." << endl;
					break;
				case 'W':
				case 'w':
					cout << "Czy chcesz wczytac dane?";
					if (lib.fileValid() && forSure())
					{
						gLib = GameLibrary();
						gLib.readFromFile();
						system("cls");
						cout << "Wczytano dane z pliku." << endl;
					}
					else if (!gLib.fileValid())
						cout << "Brak danych do wczytania." << endl;
					else
						cout << "Nie wczytano danych." << endl;
					break;
				case 'R':
				case 'r':
					cout << "Czy chcesz zresetowac dane?";
					if (forSure())
					{
						gLib = GameLibrary();
						system("cls");
						cout << "Zresetowano biblioteke." << endl;
					}
					else
						cout << "Nie skasowano danych." << endl;
					break;
				case 'C':
				case 'c':
					break;
				default:
					cout << "Podano zla opcje!" << endl;
					break;
				}
			}
			system("cls");
			break;
		default:
			break;
		}
	}

	lib.deletePointers();
	gLib.deletePointers();
}