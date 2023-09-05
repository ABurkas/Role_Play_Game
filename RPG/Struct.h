struct gracz
{
	int zdrowie;
	int lvl;
	int atak;
};

struct przedmiot
{
	int X;
	int Y;
	int id;
	int zbroja;
	int modyfikator_ataku;
	int modyfikator_zdrowia;
	int wymagany_lvl;
	int miejsce[100];
};

struct statystyki
{
	int licznik_zabojstw;
	int licznik_smierci;
};