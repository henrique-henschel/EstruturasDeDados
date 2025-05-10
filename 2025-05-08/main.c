#include <stdio.h>
#include <stdlib.h>

#define TAM 15

typedef struct no {
	int chave;
	struct no *proximo;
} No;

typedef struct {
	No *inicio;
	int tam;
} Lista;

void inicializarLista(Lista *l) {
	l->inicio = NULL;
	l->tam = 0;
}

void inserirLista(Lista *l, int valor) {
	No *novo = (No*) malloc(sizeof(No));
	
	if (novo) {
		novo->chave = valor;
		novo->proximo = l->inicio;
		l->inicio = novo;
		l->tam++;
	} else
		printf("\nErro ao alocar memoria.\n");
}

int buscarLista(Lista *l, int valor) {
	No *aux = l->inicio;
	
	while (aux && aux->chave != valor)
		aux = aux->proximo;
	if (aux)
		return aux->chave;
	return 0;
}

void imprimirLista(Lista *l) {
	No *aux = l->inicio;
	
	printf("Tam: %d | ", l->tam);
	while (aux) {
		printf("%d ", aux->chave);
		aux = aux->proximo;
	}
}

void inicializarTabela(Lista t[]) {
	int i;
	for (i = 0; i < TAM; i++)
		inicializarLista(&t[i]);
}

int funcaoHash(int chave) {
	return chave % TAM;
}

void inserir(Lista t[], int valor) {
	int id = funcaoHash(valor);
	inserirLista(&t[id], valor);
}

int busca(Lista t[], int chave) {
	int id = funcaoHash(chave);
	return buscarLista(&t[id], chave);
}

void imprimir(Lista t[]) {
	int i;
	for (i = 0; i < TAM; i++) {
		printf("%2d = ", i);
		imprimirLista(&t[i]);
		printf("\n");
	}
}

int main(void) {
	int opcao, valor, retorno;
	Lista tabela[TAM];
	
	inicializarTabela(tabela);
	
	do {
		printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("\n--> Digite o valor: ");
				scanf("%d", &valor);
				inserir(tabela, valor);
				break;
			
			case 2:
				printf("\n--> Digite o valor: ");
				scanf("%d", &valor);
				retorno = busca(tabela, valor);
				if (retorno != 0)
					printf("\nValor encontrado: %d\n", retorno);
				else
					printf("\nValor nao encontrado.\n");
				break;
				
			case 3:
				imprimir(tabela);
				break;
				
			default:
				if (opcao != 0)
					printf("\nOpcao invalida.\n");
		}
	} while (opcao != 0);
	
	return 0;
}

