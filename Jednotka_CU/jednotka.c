#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "jednotka.h"
#define N 100

tVykonTyp* nactijednotky(char* jmSoub) {
	FILE* f = fopen(jmSoub, "r");
	if (f == NULL) {
		printf("CHYBA NACTENI");
		return NULL;
	}
	char buf[N];
	fgets(buf, N, f);
	tVykonTyp* v = NULL;
	int i = 0;
	while (fgets(buf, N, f)) {
		tJednotka* jed = malloc(sizeof(tJednotka));
		jed->dalsi = NULL;
		float vyk ;
		sscanf(buf, "%[^;];%f;%d", jed->typ, &vyk, &jed->cena);
		if (v == NULL) {
			v = malloc(sizeof(tVykonTyp));;
			v->pocet=1;
			v->dalsi = NULL;
			v->prvni = jed;
			v->vykon = vyk;
		}
		else {
			tVykonTyp* pos = v;
			int find = 0;
			while (pos != NULL) {
				if (pos->vykon == vyk) {
					tJednotka* prv = pos->prvni;
					if (prv != NULL) {
						while (prv->dalsi != NULL) {
							prv=prv->dalsi;
						}
						prv->dalsi = jed;
					}
					else prv = jed;
					find = 1;
					pos->pocet++;
					break;
				}
				if(pos->dalsi==NULL)break;
				pos=pos->dalsi;
			}
			if (find == 0) {
				pos->dalsi = malloc(sizeof(tVykonTyp));
				pos = pos->dalsi;
				pos->pocet=1;
				pos->dalsi = NULL;
				pos->prvni = jed;
				pos->vykon = vyk;
			}
		}

	}
	return v;

}
void vypisJednotky(tVykonTyp* jednotky) {
	tVykonTyp* j = jednotky;
	while (j != NULL) {
		printf("Vykon: %4.1f Pocet: %d\n-----------------\n", j->vykon, j->pocet);
		tJednotka* n = j->prvni;
		while (n != NULL) {
			printf("Typ: %s Cena: %d \n", n->typ, n->cena);
			n = n->dalsi;
		}
		printf("-----------------\n");
		j = j->dalsi;
	}
}