#include <stdio.h>
#include <conio.h>


typedef struct {
	char titlu_carte[30],prenume_autor[30],nume_a[30];
	int an;
}carte;
int citire(carte *tab)
{
	int i = 0;
	FILE *f;
	f = fopen("Carti.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", (tab + i)->titlu_carte);
		fscanf(f, "%s", (tab + i)->prenume_autor);
		fscanf(f, "%s", (tab + i)->nume_a);
		fscanf(f, "%d", &(tab + i)->an);
			i++;
	}
	return i;
}

void afisare(carte *tab, int j)
{
	int i = 0;
	for (i = 0; i < j; i++)
	{
		printf("%s %s %s %d\n", (tab + i)->titlu_carte, (tab + i)->prenume_autor, (tab + i)->nume_a, (tab + i)->an);
	}
}
int main()
{
	carte tab[15];
	int n;
	n=citire(tab);
	afisare(tab,n);
	_getch();
	return 0;
}