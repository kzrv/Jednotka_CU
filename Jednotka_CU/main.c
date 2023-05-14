#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "jednotka.h"

int main(void) {

	tVykonTyp *v =  nactijednotky("produkty.csv");
	vypisJednotky(v);
	return 0;
}