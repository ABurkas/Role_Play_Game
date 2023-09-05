#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Struct.h"

#define plecak_X 10		//stałe rozmiaru plecaka
#define plecak_Y 10

enum typ_przedmiotu
{
	pancerz,
	miecz,
	helm,
	buty,
	zbroja_na_nogach
};

void dodajPrzedmiotDoEkwipunku(przedmiot*** ekwipunek, typ_przedmiotu typ)		//reprezentacja ekwipunku
{
	przedmiot* zbroja = nullptr;		
	switch (typ)
	{
	case pancerz:
		zbroja = (przedmiot*)malloc(sizeof(przedmiot));
		zbroja -> zbroja = rand() % 10 + 1;
		zbroja -> modyfikator_ataku = rand() % 10 + 1;
		zbroja -> modyfikator_zdrowia = rand() % 10 + 1;
		zbroja -> wymagany_lvl = rand() % 10 + 1;
		zbroja -> X = 2;
		zbroja -> Y = 2;
		zbroja -> id = 1;
		printf("Wziales pancerz\n");
		break;
	case miecz:
		zbroja = (przedmiot*)malloc(sizeof(przedmiot));
		zbroja->zbroja = rand() % 10 + 1;
		zbroja->modyfikator_ataku = rand() % 10 + 1;
		zbroja->modyfikator_zdrowia = rand() % 10 + 1;
		zbroja->wymagany_lvl = rand() % 10 + 1;
		zbroja->X = 2;
		zbroja->Y = 2;
		zbroja->id = 2;
		printf("Wziales miecz\n");
		break;
	case helm:
		zbroja = (przedmiot*)malloc(sizeof(przedmiot));
		zbroja->zbroja = rand() % 10 + 1;
		zbroja->modyfikator_ataku = rand() % 10 + 1;
		zbroja->modyfikator_zdrowia = rand() % 10 + 1;
		zbroja->wymagany_lvl = rand() % 10 + 1;
		zbroja->X = 1;
		zbroja->Y = 1;
		zbroja->id = 3;
		printf("Wziales helm\n");
		break;
	case buty:
		zbroja = (przedmiot*)malloc(sizeof(przedmiot));
		zbroja->zbroja = rand() % 10 + 1;
		zbroja->modyfikator_ataku = rand() % 10 + 1;
		zbroja->modyfikator_zdrowia = rand() % 10 + 1;
		zbroja->wymagany_lvl = rand() % 10 + 1;
		zbroja->X = 2;
		zbroja->Y = 2;
		zbroja->id = 4;
		printf("Wziales buty\n");
		break;
	case zbroja_na_nogach:
		zbroja = (przedmiot*)malloc(sizeof(przedmiot));
		zbroja->zbroja = rand() % 10 + 1;
		zbroja->modyfikator_ataku = rand() % 10 + 1;
		zbroja->modyfikator_zdrowia = rand() % 10 + 1;
		zbroja->wymagany_lvl = rand() % 10 + 1;
		zbroja->X = 1;
		zbroja->Y = 1;
		zbroja->id = 5;
		printf("Wziales nagolenniki\n");
		break;
	}
	// Szukanie pustych slotów w ekwipunku
	int pustyX = -1;
	int pustyY = -1;
	for (int y = 0; y < plecak_Y; y++)
	{
		for (int x = 0; x < plecak_X; x++)
		{
			if (ekwipunek[y][x] == nullptr)
			{
				pustyX = x;
				pustyY = y;
				break;
			}
		}
		if (pustyX != -1 && pustyY != -1)
			break;
	}

	if (pustyX != -1 && pustyY != -1)	// ponowne sprawdzenie miejsca w ekwipunku
	{
		int zbrojaX = zbroja->X;
		int zbrojaY = zbroja->Y;
		for (int y = pustyY; y < pustyY + zbrojaY; y++)		
		{
			for (int x = pustyX; x < pustyX + zbrojaX; x++)
			{
				ekwipunek[x][y] = zbroja;						// umieszczenie przedmiotu w pustym sloce
				printf("Umieszczono %d w [%d,%d]\n", zbroja->id, y, x);
			}
		}
	}
	else
	{
		printf("Brak wolnego miejsca w ekwipunku!\n");
		free(zbroja);
	}
}

void ZwolnijMiejsceWEkpipunku(przedmiot*** ekwipunek)
{
	bool isFull = true;
	for (int i = 0; i < plecak_Y; i++)
	{
		for (int j = 0; j < plecak_X; j++)
		{
			if (ekwipunek[i][j] = nullptr)
			{
				isFull = false;
				break;
			}
		}
		if (!isFull)
			break;
	}
	if (isFull)				//opcjonlanie, można usunąć
	{
		printf("Ekwipunek jest pelny. Prosze usunac przedmiot, by uwolnuic miejsce.\n");
	}
}

void dealokacjaEkwipunku(przedmiot*** ekwipunek)
{
	for (int i = 0; i < plecak_Y; i++)
	{
		for (int j = 0; j < plecak_X; j++)
		{
			if (ekwipunek[i][j] != nullptr)
			{
				ekwipunek[i][j] = nullptr;
				free(ekwipunek[i][j]);
			}
		}
		ekwipunek[i] = nullptr;
		free(ekwipunek[i]);
	}
	ekwipunek = nullptr;
	free(ekwipunek);
}

void wydrukujEkwipunek(przedmiot*** ekwipunek)
{
	system("cls");

	for (int i = 0; i < plecak_Y; i++)
	{
		for (int j = 0; j < plecak_X; j++)
		{
			if (ekwipunek[i][j] != nullptr)
			{
				system("cls");
				printf("Przedmiot: %d\n", ekwipunek[i][j]->id);

			}
			else
			{
				printf("%10s", "P");
				int policzP = 0;
				policzP++;
				if (policzP >= 7)
				{
					break;
				}
			}
		}
		printf("\n");
	}
}

void usunPrzedmiotZEkwipunku(przedmiot*** ekwipunek, int IDprzedmiotu)
{
	bool znaleziono = false;

	for (int i = 0; i < plecak_Y; i++)
	{
		for (int j = 0; j < plecak_X; j++)
		{
			if (ekwipunek[i][j] != nullptr && ekwipunek[i][j]->id == IDprzedmiotu)
			{
				free(ekwipunek[i][j]);
				ekwipunek[i][j] = nullptr;
				znaleziono = true;
				break;
			}
		}
		if (znaleziono)
		break;
	}

	if (znaleziono)
		printf("Przedmiot z ID %d zostal usuniety z plecaka\n", IDprzedmiotu);
	else
		printf("Przedmiotu z ID %d nie znaleziono w plecaku\n", IDprzedmiotu);
}
// Mapa
const int Szerokosc_Mapy = 20;
const int Wysokosc_Mapy = 15;

void ustawKursor(int x, int y)
{
	COORD pozycja = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
}

void wyswietlMape(char mapa[][Szerokosc_Mapy])
{
	ustawKursor(0, 0);
	for (int i = 0; i < Wysokosc_Mapy; i++)
	{
		for (int j = 0; j < Szerokosc_Mapy; j++)
		{
			printf(" %c ", mapa[i][j]);
		}
		printf("\n");
	}
}

void wczytajMape(char mapa[][Szerokosc_Mapy])
{
	FILE* plikMapy = fopen("mapa.txt", "r");
	if (!plikMapy)
	{
		printf("Nie udalo sie odczytac pliku mapy\n");
	}

	for (int i = 0; i < Wysokosc_Mapy; i++)
	{
		for (int j = 0; j < Szerokosc_Mapy; j++)
		{
			fscanf(plikMapy, "%c ", &mapa[i][j]);
		}
	}
	fclose(plikMapy);
}

gracz Bohater;
gracz Przeciwnik;

float walka(float zdrowieP, float zdrowieG)
{
	while (zdrowieP > 0 && zdrowieG > 0)
	{
		float wartosc_atakuG = Bohater.atak * rand() % 1 + 0.5;
		zdrowieP = zdrowieP - wartosc_atakuG;
		float wartosc_atakuP = Przeciwnik.atak * rand() % 1 + 0.5;
		zdrowieG = zdrowieG - wartosc_atakuP;
	}
	if (zdrowieP <= 0)
	{
		printf("Pokonales wroga\n");
	}
	else
	{
		printf("Przegrales!\n");
	}

	return zdrowieG;
}

int main(void)
{
	char mapa[Wysokosc_Mapy][Szerokosc_Mapy];

	//Alokacja ekwipnku
	przedmiot*** ekwipunek = (przedmiot***)malloc(plecak_Y * sizeof(przedmiot**));
	for (int i = 0; i < plecak_Y; i++)
	{
		ekwipunek[i] = (przedmiot**)malloc(plecak_X * sizeof(przedmiot*));
		for (int j = 0; j < plecak_X; j++)
		{
			ekwipunek[i][j] = nullptr;
		}
 	}

	wczytajMape(mapa);
	int GraczX = 0;
	int GraczY = 0;
	mapa[GraczY][GraczX] = '@';
	char wprowadzDane;			// przechowanie wprowadzonych przez gracza znaków
	int uruchomienie = 1;	    // stan uruchomienia gry

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	while (uruchomienie)
	{
		wyswietlMape(mapa);

		wprowadzDane = _getch();

		switch (wprowadzDane)
		{
		case'w':
			if (GraczY > 0 && mapa[GraczY - 1][GraczX] != '#')
			{
				if (mapa[GraczY - 1][GraczX] == '?')
					dodajPrzedmiotDoEkwipunku(ekwipunek, pancerz);
				else if (mapa[GraczY - 1][GraczX] == '$')
				{
					int zdrowieP = 10;
					walka(zdrowieP, Bohater.zdrowie);
					printf("Pokonales wroga!\n");
					fflush(stdout);
				}
				mapa[GraczY][GraczX] = '.';
				GraczY--;
				mapa[GraczY][GraczX] = '@';
			}
			break;
		case 's':
			if (GraczY < Wysokosc_Mapy - 1 && mapa[GraczY + 1][GraczX] != '#')
			{
				if (mapa[GraczY + 1][GraczX] == '?')
					dodajPrzedmiotDoEkwipunku(ekwipunek, helm);
				else if (mapa[GraczY + 1][GraczX] == '$')
				{
					int zdrowieP = 10;
					walka(zdrowieP, Bohater.zdrowie);
					printf("Pokonales wroga!\n");
					fflush(stdout);
				}
				mapa[GraczY][GraczX] = '.';
				GraczY++;
				mapa[GraczY][GraczX] = '@';
			}
			break;
		case 'a':
			if (GraczX > 0 && mapa[GraczY][GraczX - 1] != '#')
			{
				if (mapa[GraczY][GraczX - 1] == '?')
					dodajPrzedmiotDoEkwipunku(ekwipunek, miecz);
				else if (mapa[GraczY][GraczX - 1] == '$')
				{
					int zdrowieP = 10;
					walka(zdrowieP, Bohater.zdrowie);
					printf("Pokonales wroga!\n");
					fflush(stdout);
				}
				mapa[GraczY][GraczX] = '.';
				GraczX--;
				mapa[GraczY][GraczX] = '@';
			}
			break;
		case 'd':
			if (GraczX < Szerokosc_Mapy - 1 && mapa[GraczY][GraczX + 1] != '#')
			{
				if (mapa[GraczY][GraczX + 1] == '?')
					dodajPrzedmiotDoEkwipunku(ekwipunek, buty);
				else if (mapa[GraczY][GraczX + 1] == '$')
				{
					int zdrowieP = 10;
					walka(zdrowieP, Bohater.zdrowie);
					printf("Pokonales wroga!\n");
					fflush(stdout);
				}
				mapa[GraczY][GraczX] = '.';
				GraczX++;
				mapa[GraczY][GraczX] = '@';
			}
			break;
		case 'q':
			uruchomienie = false;
			break;
		case 'i':
			wydrukujEkwipunek(ekwipunek);
			break;
		} 
	}
	printf("Hello!");
	return 0;
}