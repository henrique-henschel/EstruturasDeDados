#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

/* Cada no armazena o caractere, a frequencia e os
   ponteiros para os proximos nos
*/
typedef struct no
{
	unsigned char caractere;
	int frequencia;
	struct no *esq, *dir, *proximo;
} No;

// Lista armazena o endereco do primeiro no e seu tamanho
typedef struct
{
	No *inicio;
	int tam;
} Lista;

// Preencher a tabela de frequencia com zeros
void inicializa_tabela(unsigned int tab[])
{
	int i;
	
	for (i = 0; i < TAM; i++) {
		tab[i] = 0;
	}
}

/* Iterar sobre o texto incrementando o valor
   no indice igual ao valor ASC II de cada ca-
   ractere na tabela em um a cada vez que en-
   contra-lo. Caractere nao presente no texto
   continua com o valor zero no seu respectivo
   indice
*/
preencher_tab_freq(unsigned char texto[], unsigned int tab[])
{
	int i = 0;
	
	while (texto[i] != '\0') {
		tab[texto[i]]++;
		i++;
	}
}

/* Iterar sobre a tabela imprimindo o valor em
   todos os indices equivalentes ao ASC II dos
   caracteres existentes
*/
void imprime_tab_freq(unsigned int tab[])
{
	int i;
	
	printf("\tTabela de Frequência\n");
	for (i = 0; i < TAM; i++) {
		if (tab[i] > 0) {
			printf("\t%d = %u = %c\n", i, tab[i], i);
		}
	}
}

void criar_lista(Lista *lista)
{
	lista->inicio = NULL;
	lista->tam = 0;
}

void inserir_ordenado(Lista *lista, No *no)
{
	No *aux;
	
	if (lista->inicio == NULL) {
		lista->inicio = no;
	} else if (no->frequencia < lista->inicio->frequencia) {
		no->proximo = lista->inicio;
		lista->inicio = no;
	} else {
		aux = lista->inicio;
		while (aux->proximo && aux->proximo->frequencia <= no->frequencia) {
			aux = aux->proximo;
		}
		no->proximo = aux->proximo;
		aux->proximo = no;
	}
	lista->tam++;
}

void preencher_lista(unsigned int tab[], Lista *lista)
{
	int i;
	No *novo;
	for (i = 0; i < TAM; i++) {
		if (tab[i] > 0) {
			novo = (No*)malloc(sizeof(No));
			if (novo) {
				novo->caractere = (char)i;
				novo->frequencia = tab[i];
				novo->dir = NULL;
				novo->esq = NULL;
				novo->proximo = NULL;
				
				inserir_ordenado(lista, novo);
			} else {
				printf("\nErro ao alocar memória.\n");
				break;
			}
		}
	}
}

void imprimir_lista(Lista *lista)
{
	No *aux = lista->inicio;
	
	printf("\nLista ordanada: Tamanho: %d\n", lista->tam);
	while (aux) {
		printf("\nCaractere: %c Frequência: %d\n", aux->caractere, aux->frequencia);
		aux = aux->proximo;
	}
}

int main(void)
{
	unsigned char texto[] = "Vamos aprender a programar";
	unsigned int tab_freq[TAM];
	Lista lista;
	No *arvore;
	int colunas;
	char **dicionario;
	char *codificado, *decodificado;
	
	setlocale(LC_ALL, "Portuguese");
	
	inicializa_tabela(tab_freq);
	preencher_tab_freq(texto, tab_freq);
	imprime_tab_freq(tab_freq);
	
	criar_lista(&lista);
	preencher_lista(tab_freq, &lista);
	imprimir_lista(&lista);
	
	return 0;
}

