#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//typedef enum { false, true }boolean;
int tab[20], n;
void citire(void);
void afisare(void);
void deplasare(int, int);
void heapsort(void);
int main()
{
	//clrscr();
	citire();
	afisare();
	heapsort();
	afisare();
	return 0;
}
void citire(void)
{
	int i;
		printf("\nIntroduceti numarul de elemente ale tabloului: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf("%d", &tab[i]);
	}
	puts("");
}
void afisare(void)
{
	int i;
	puts("\n");
	for (i = 0; i < n; i++)
		printf("%d ", tab[i]);
	getch();
	puts("\n");
}
void deplasare(int s, int d)
{
	int i, j, x;
	bool bul;
	i = s; j = 2 * i; x = tab[i]; bul = false;
	while (j <= d && bul == false) {
		if (j < d) {
			if (tab[j + 1] > tab[j]) j = j + 1;
		}
		if (x < tab[j]) {
			tab[i] = tab[j]; i = j; j = 2 * i;
		}
		else {
			bul = true;
		}
	}
	tab[i] = x;
}
void heapsort(void)
{
	int s, d, aux;
	s = n / 2 + 1; d = n - 1;
	while (s > 0) {
		s--;
		deplasare(s, n - 1);
	}
	while (d > 0) {
		aux = tab[0]; tab[0] = tab[d]; tab[d] = aux;
		d--;
		deplasare(0, d);
	}
}