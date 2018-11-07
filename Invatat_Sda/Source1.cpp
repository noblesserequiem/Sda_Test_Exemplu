#include <conio.h>
#include <stdio.h>

typedef struct {
	char titlu[30], n_a[30], p_a[30];
	int an;
}carte;

carte tab[15];
int i=0;

void citire()
{
	FILE *f;
	
	f = fopen("Carti.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", tab[i].titlu);
		fscanf(f, "%s", tab[i].p_a);
		fscanf(f, "%s", tab[i].n_a);
		fscanf(f, "%d", &tab[i].an);
		i++;
	}

}

void afisare()
{
	int j;
	for (j = 0; j < i; j++)
	{
		printf("%s %s %s %d\n", tab[j].titlu,tab[j].p_a,tab[j].n_a,tab[j].an);
	}

}
int main()
{
	citire();
	afisare();
	_getch();
	return 0;
}