#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <iostream>

int main() {

	// Variabler
	float belop = 0;
	float rente = 0;
	int ar = 0;
	float belopEtter;

	// Henter bel�p, rente og �r fra bruker	
	std::cout << "snickers";
	printf("Skriv inn belop:\n");
	scanf("%f", &belop);
	printf("Skriv inn rente:\n");
	scanf("%f", &rente);
	printf("Skriv inn antall ar:\n");
	scanf("%d", &ar);
	printf("\n");

	// Matte
	rente = (100 + rente) / 100;	// Gj�r om renta fra prosent til vekstfaktor
	belopEtter = belop * pow(rente, (double)ar);	// Gj�r utregningen for opptjent bel�p

	// Clear screen
	system("cls");

	// Skriver ut bel�p etter x �r med 2 desimaler
	printf("Etter %d ar vil du ha %.2fkr\n", ar, belopEtter);

	system("PAUSE");
	return 0;
}