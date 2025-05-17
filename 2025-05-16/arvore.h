#ifndef ARVORE_H
#define ARVORE_H

typedef struct no
{
	int valor;
	struct no *direita, *esquerda;
} NoArvore;

NoArvore* inserir_v1(NoArvore *raiz, int num);

void inserir_v2(NoArvore **raiz, int num);

void inserir_v3(NoArvore **raiz, int num);

void imprimir_pre_ordem(NoArvore *raiz);

void imprimir_in_ordem(NoArvore *raiz);

void imprimir_pos_ordem(NoArvore *raiz);

NoArvore* buscar_v1(NoArvore *raiz, int num);

NoArvore* buscar_v2(NoArvore *raiz, int num);

#endif
