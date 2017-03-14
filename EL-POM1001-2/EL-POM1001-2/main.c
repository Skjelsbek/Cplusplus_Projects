#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"


int main() {

	char char1[] = {"10"};
	char char2[] = { "30" };
	int i = atoi(char1);
	int j = atoi(char2);
	
	printf("Tall 1 =  %d\nTall 2 = %d\nProduktet av disse er: %d", i, j, i * j);

	char str1[] = {"Går det bra ?"};
	printf("\nDagens femte utskrift %s\n", &str1[8]);
	printf(" %d", 4%5); 

	/*int iTab[] = {2, 3, 4, 5, 6};
	int *i;
	i = iTab;
	printf("*i = %d\n", *i);

	int u = *i + 2;
	printf("%d\n", u);

	printf("1<<4 = % d\n", 1<<4);
	printf("4<<1 = % d\n", 4<<1);
	printf("%d", 12|10);
	char a = getchar();
	printf("%c", a); */


	system("PAUSE");
	return 0;
}