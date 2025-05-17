#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(int argc, char *argv[])
{
	NoArvore *raiz = NULL;
	NoArvore *busca = NULL;
	int opcao, valor;
	
	// Versao estatica (valores fixos):
	/*
	raiz = inserir_v1(raiz, 24);
	raiz = inserir_v1(raiz, 32);
	raiz = inserir_v1(raiz, 10);
	raiz = inserir_v1(raiz, 5);
	raiz = inserir_v1(raiz, 29);
	raiz = inserir_v1(raiz, 12);
	raiz = inserir_v1(raiz, 35);
	raiz = inserir_v1(raiz, 39);
	
	imprimir_pre_ordem(raiz);
	printf("\n-------------------------\n");
	imprimir_in_ordem(raiz);
	printf("\n-------------------------\n");
	imprimir_pos_ordem(raiz);
	printf("\n-------------------------\n");
	printf("\nFIM :D\n");
	*/
	
	// Versao dinamica (o usuario pode digitar valores):
	do {
		printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("\n--> Digite o valor: ");
				scanf("%d", &valor);
				inserir_v3(&raiz, valor);
				break;
			case 2:
				printf("\n===  PRE-ORDEM  ===\n");
				imprimir_pre_ordem(raiz);
				printf("\n===  ORDEM  ===\n");
				imprimir_in_ordem(raiz);
				printf("\n===  POS-ORDEM  ===\n");
				imprimir_pos_ordem(raiz);
				break;
			case 3:
				printf("\n--> Digite o valor: ");
				scanf("%d", &valor);
				busca = buscar_v2(raiz, valor);
				if (busca)
					printf("\n>>> Valor encontrado: %d\n", busca->valor);
				else
					printf("\n>>> Valor NAO encontrado.\n");
			default:
				if (opcao != 0)
					printf("\n>>> ERRO! Opcao INVALIDA. Tente outra opcao.\n");
		}
	} while (opcao != 0);
	
	return 0;
}
