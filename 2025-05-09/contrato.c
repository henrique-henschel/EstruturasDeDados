#include <stdio.h>
#include "contrato.h"

void imprimirContrato(Contrato c) {
	printf("\tDados do contrato\n");
	printf("\nContrato: %d", c.codigo);
	printf("\nCargo: %s", c.cargo);
	printf("\nSalario: RS %.2f", c.salario);
	printf("\nData de admissao: ");
	imprimirData(c.dataAss);
}

Contrato lerContrato() {
	Contrato c;
	printf("\nCodigo do contrato: ");
	scanf("%d", &c.codigo);
	printf("\nData de assinatura: ");
	c.dataAss = lerData();
	printf("\nCargo: ");
	fgets(c.cargo, 49, stdin);
	printf("\nSalario: RS ");
	scanf("%f", &c.salario);
	getchar();
	return c;	
}

