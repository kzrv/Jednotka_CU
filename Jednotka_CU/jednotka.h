#pragma once

typedef struct jednotka {
	char typ[20];
	int cena;
	struct jednotka* dalsi;
}tJednotka;

typedef struct vykonTyp {
	float vykon;
	int pocet;
	struct vykonTyp* dalsi;
	tJednotka* prvni;
}tVykonTyp;

tVykonTyp* nactijednotky(char* jmSoub);
void vypisJednotky(tVykonTyp* jednotky);