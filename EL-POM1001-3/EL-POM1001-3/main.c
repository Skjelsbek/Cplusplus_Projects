#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "math.h"


int main() {

	// Variabler
	float belop = 0;
	float rente = 0;
	float ar = 0;
	float belopEtter;

	// Henter beløp, rente og år fra bruker
	printf("Skriv inn belop:\n");
	scanf("%f", &belop);
	printf("Skriv inn rente:\n");
	scanf("%f", &rente);
	printf("Skriv inn antall ar:\n");
	scanf("%f", &ar);
	printf("\n");

	// Matte
	rente = (100 + rente) / 100;				// Gjør om renta fra prosent til vekstfaktor
	belopEtter = belop * pow(rente, ar);		// Gjør utregningen for opptjent beløp

												// Clear screen
	system("cls");

	// Skriver ut beløp etter x år med 2 desimaler
	printf("Etter %.2f ar vil du ha %.2fkr\n", ar, belopEtter);

	system("PAUSE");
	return 0;
}