#include <conio.h>
#include <stdio.h>

typedef struct {
	char titlu[30], n_a[30], p_a[30];
	int an;
}carte;

carte tab[15];
int n=0;

void citire()
{
	FILE *f;
	
	f = fopen("Carti.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", tab[n].titlu);
		fscanf(f, "%s", tab[n].p_a);
		fscanf(f, "%s", tab[n].n_a);
		fscanf(f, "%d", &tab[n].an);
		n++;
	}
	n--;
}

void afisare()
{
	int j;
	for (j = 0; j <= n; j++)
	{
		printf("%s %s %s %d\n", tab[j].titlu,tab[j].p_a,tab[j].n_a,tab[j].an);
	}
	

}

void shell()
{
	int gap,i;
	carte aux;
	for (gap = n / 2; gap > 0; gap--)
	{
		for (i = 0; i < n-1; i = i + gap)
		{
			if (tab[i].an > tab[i + gap].an)
			{
				aux = tab[i];
				tab[i] = tab[i + gap];
				tab[i + gap] = aux;
			}
		}
	}
}
int partition(int low, int high)
{
	int pivot = tab[high].an;
	carte aux;
	int i = low - 1;
	int j;
	for (j = low; j < high; j++)
	{
		if (tab[j].an <= pivot)
		{
			i++;
			aux = tab[j];
			tab[j] = tab[i];
			tab[i] = aux;

		}
	}
	aux = tab[i + 1];
	tab[i + 1] = tab[high];
	tab[high] = aux;
	return i + 1;
}
void quick(int low,int high)
{
	if (low < high)
	{
		int pi = partition(low, high);
		quick(low, pi - 1);
		quick(pi + 1, high);
	}
}
int main()
{
	citire();
	afisare();
	//shell();
	quick(0, n);
	afisare();
	_getch();
	return 0;
}