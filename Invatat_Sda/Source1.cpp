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
	
	printf("================\n\n");
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
int fanion(int an)//cautam dupa an
{
	int i;
	n++;//marim tablou sa punem elementul cautat pe ultima pozitie
	tab[n].an = an; //punem la final anul chiar daca restul informatiilor sunt goale, cautam dupa an=>nu avem nevoie de restul inf
	for (i = 0; i <= n; i++)
	{
		if (tab[i].an == an)
		{
			printf("element gasit pozitia: %d\n", i+1); //adunam 1 sa afiseze frumos pozitia(am inceput de la 0)
			n--;//scadem dimensiunea tabloului pentru ca am adaugat elementul la final si afiseaza un simplu an copiat
			return i;//am gasit pozitia elementului in tablou unde anul coincide=> returnam pozitia gasita oprim functia
		} 
	}
	return n; //daca nu gaseste returneaza ultima pozitie.... Oricum nu ajunge aici 
}
int interpolare(int an)
{
	//informatiile sunt deja sortate
	int m,low = 0, high = n; //capetele vectorului
	if (an >= tab[low].an&& an <= tab[high].an) //verificam anul cautat sa fie in interval
	{
		do {
			m = low + (an - tab[low].an) / (tab[high].an - tab[low].an)*(high - low);//formula am demonstrat-o la lab, ceva cu ecuatia pantei si un punct de pe dreapta, am uitat -__- =>toceala express
		//gasim un punct cat mai aproape de cel cautat
			if (an > tab[m].an)
				low = m + 1;//daca ce cautam este mai sus decat unde suntem acum modifica limita de jos a intervalului de cautare
			else
				high = m - 1; //daca e mai jos
		} while (tab[m].an!=an); //repetam pana gasim ce cautam
		//am iesit yeee am gasit
		printf("Poz el: %d\n", m);
		 //returnam pozitia, daca o vrem in main
	}
	return m;
}
int main()
{
	int poz;
	citire();
	afisare();
	//poz = fanion(564); //cautam anul 564 din fisierul Carti.txt 
	//shell();
	quick(0, n);
	afisare();// afisam sortat 
	poz = interpolare(564); //executam dupa o sortare
	afisare();
	_getch();
	return 0;
}