#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

typedef struct prognoza {
	int min_temp;
	int max_temp;
	int padavine;
	int mesec;
	int dan;
}PROGNOZA;
typedef struct cvor CVOR;
typedef struct cvor* PCVOR;
struct cvor {
	PROGNOZA prognoza;
	PCVOR sledeci;
};

void prikaziNiz(int padavine[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", padavine[i]);
	}
}
void ucitaj_padavine(char* naziv_datoteke, int padavine[], int* n) {
	FILE* dat = fopen(naziv_datoteke, "r");
	if (dat == NULL) {
		printf("Greska.\n");
		return;
	}

	char s[100];
	int padavina;
	while (fgets(s, 100, dat) != NULL) {
		sscanf(s, "%d", &padavina);
		padavine[(*n)] = padavina;
		(*n)++;
	}

	fclose(dat);
}
int max_kisa(int padavine[], int n) {
	int max = 0;
	int zbir;
	for (int i = 0; i < n; i++)
	{

		zbir = 0;
		while (padavine[i] != 0) {
			zbir += padavine[i];
			i++;
		}
		if (max < zbir) {
			max = zbir;
		}
	}

	return max;
}
int susni_dani(int padavine[], int n) {
	int brojac = 0;

	for (int i = 0; i < n; i++)
	{
		if (padavine[i] == 0)
		{
			brojac++;
		}
	}


	return brojac;
}
void dodaj_temperaturu(int temperature[][24], int* n) {
	int sati = 0;


	printf("Unesite temperaturu po satima (potrebno je uneti 24 vrednosti):\n");
	while (sati < 24) {
		scanf("%d", &temperature[(*n)][sati]);
		sati++;
	}
	printf("Kraj unosa!\n");
	(*n)++;

}
int prosek_temperature(int temperature[][24], int n, int sat) {
	int zbir = 0;
	int prosek = 1;
	for (int i = 0; i < n; i++)
	{
		zbir += temperature[i][sat];
	}
	prosek = zbir / n;

	return prosek;
}
int najhladniji_sat(int temperature[][24], int n) {
	int index = INT_MIN;
	int najhladniji = INT_MAX;

	for (int j = 0; j < 24; j++)
	{
		if (najhladniji > prosek_temperature(temperature, n, j)) {
			index = j;
			najhladniji = prosek_temperature(temperature, n, j);
		}
	}

	return index;
}
void dodaj_u_listu(PROGNOZA prognoza, PCVOR* glava) {
	PCVOR novi, poslednji;
	novi = malloc(sizeof(CVOR));
	novi->prognoza = prognoza;
	novi->sledeci = NULL;
	poslednji = NULL;
	if (*glava == NULL) {
		*glava = novi;
	}
	else
	{
		poslednji = *glava;
		while (poslednji->sledeci != NULL) {
			poslednji = poslednji->sledeci;
		}
		poslednji->sledeci = novi;
	}
}
int proveri_padavine(int dan_od, int mesec_od, int dan_do, int mesec_do, PCVOR glava) {
	PCVOR tekuci = glava;
	int zbir = 0;
	while (tekuci != NULL) {
		if (tekuci->prognoza.mesec >= mesec_od && tekuci->prognoza.mesec <= mesec_do) {

			if (tekuci->prognoza.dan >= dan_od && tekuci->prognoza.dan <= dan_do) {
				zbir = tekuci->prognoza.padavine + zbir;
			}


		}
		tekuci = tekuci->sledeci;
	}

	if (zbir == 0) {
		return 0;
	}
	else
	{
		return 1;
	}

}

int main(void) {
	/*PCVOR glava = NULL;
	int temperature[24][24];
	int ntemp = 0;
	int npadavine = 0;
	int padavine[35] = { 0,0,1,0,2,5,0,4,3,1,0,2 };
	char naziv[30] = "padavine.txt";*/
	//ucitaj_padavine(naziv, padavine, &npadavine);
	//prikaziNiz(padavine, npadavine);
	//dodaj_temperaturu(temperature, &n);
	//printf("Broj susnih dana je:%d\n", susni_dani(padavine, npadavine));
	/*dodaj_temperaturu(temperature, &ntemp);
	dodaj_temperaturu(temperature, &ntemp);
	dodaj_temperaturu(temperature, &ntemp);
	printf("Najhladniji sat je :%d\n", najhladniji_sat(temperature, ntemp));*/
	//printf("Hoce li biti padavina:%d\n", );
	//printf("Najveca kolicina padavina je:%d\n", max_kisa(padavine, 12));
	/*PROGNOZA p1 = { 22,32,3,6,15 };
	PROGNOZA p2 = { 21,30,6,6,16 };
	PROGNOZA p3 = { 15,25,5,8,1 };
	PROGNOZA p4 = { 18,27,0,8,2 };
	PROGNOZA p5 = { 20,30,10,8,3 };
	PROGNOZA p6 = { 23,33,2,7,10 };
	PROGNOZA p7 = { 25,35,0,7,11 };
	PROGNOZA p8 = { 26,34,0,7,12 };

	dodaj_u_listu(p1, &glava);
	dodaj_u_listu(p2, &glava);
	dodaj_u_listu(p3, &glava);
	dodaj_u_listu(p4, &glava);
	dodaj_u_listu(p5, &glava);
	dodaj_u_listu(p6, &glava);
	dodaj_u_listu(p7, &glava);
	dodaj_u_listu(p8, &glava);


	printf("Da li ce kisa padati (11.7.- 12.7.)? %d\n", proveri_padavine(11, 7, 12, 7, glava));*/


	system("pause");
	return 0;
}