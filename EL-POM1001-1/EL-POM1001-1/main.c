#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

float Gjennomsnitt(float tall[], int antall) {
	float sum = 0;
	for (int i = 0; i < antall; i++) {
		sum += tall[i];
	}
	return sum / antall;
}

int main() {
	int antall;
	float tall[100];
	char kjørIgjen;

	printf("Dette er et program som regner ut gjennomsnitt!");
	
	do {				
		printf("\nSkriv inn onsket antall tall:");
		scanf(" %d", &antall);

		for (int i = 0; i < antall; i++) {
			printf("\nSkriv inn tall på plass %d: ", i + 1);
			scanf(" %f", &tall[i]);
		}

		printf("\nGjennomsnittet er: %.2f", Gjennomsnitt(tall, antall));
		printf("\n\nØnsker du å kjøre programmet på nytt? ('j' for ja og 'n' for nei)");		
		scanf(" %c", &kjørIgjen);

	} while (kjørIgjen == 'j');

	system("PAUSE");
	return 0;
}