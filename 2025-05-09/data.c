#include <stdio.h>
#include "data.h"

void imprimirData(Data d) {
	printf("%02d/%02d/%4d", d.dia, d.mes, d.ano);
}

Data lerData() {
	Data d;
	printf("\nDigite a data (dd mm aaaa): ");
	scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
	getchar();
	return d;
}

