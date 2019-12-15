#include <iostream>
#include "Book.h"
#include "Library.h"

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
	cout << "1. Wypisz ksiazki w bibliotece" << endl;
	cout << "2. Dodaj ksiazke" << endl;
	cout << "3. Usun ksiazke" << endl;
	cout << "4. Edytuj ksiazke" << endl;

	cout << "z - zapisz do pliku" << endl;
	cout << "w - wczytaj z pliku" << endl;
	cout << "r - resetuj biblioteke (kasowanie wszystkich niezapisanych danych)" << endl;
	cout << "c - cofnij do menu glownego" << endl;
	cout << "k - koniec programu" << endl;
	cout << "-----------------------------------\n" << endl;

	cout << "Co chcesz zrobic? ";
	cin >> wybor;
	cout << endl;
	return wybor;
}

bool forSure()
{
	char wybor = 'h';
	cout << "(y/n)";
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
	Library lib = Library();
	if (lib.fileValid())
	{
		lib.readFromFile();
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
						lib.showBooks();
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
					//lib.sort();
					break;
				case '4':
					system("cls");
					cout << "Edytowanie..." << endl;
					cout << "Podaj pozycje ksiazki do edycji: ";
					cin >> pos;
					lib.update(pos);
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
						lib = Library();
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
						lib = Library();
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
			break;
		default:
			break;
		}
	}
	
	lib.deletePointers();
}