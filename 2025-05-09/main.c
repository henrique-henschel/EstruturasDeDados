#include <stdio.h>
#include "hash.h"

#define TAM 15

int main(void) {
	int opcao, valor, retorno;
	Pessoa *buscar, tabela[TAM];
	
	inicializarTabela(tabela, TAM);
	
	do {
		printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n");
		printf("\n--> Digite a opcao desejada: ");
		scanf("%d", &opcao);
		getchar();
		
		switch (opcao) {
			case 1:
				inserir(tabela, TAM);
				break;
			
			case 2:
				printf("\n--> Digite o CPF:");
				scanf("%d", &valor);
				buscar = busca(tabela, valor, TAM);
				if (buscar) {
					printf("\nCPF encontrado\n");
					imprimirPessoa(*buscar);
				} else
					printf("\nCPF nao encontrado\n");
				break;
				
			case 3:
				imprimir(tabela, TAM);
				break;
				
			default:
				if (opcao != 0)
					printf("\nERRO! Opcao INVALIDA. Tente outra opcao.\n");
		}
	} while (opcao != 0);
	
	return 0;
}

