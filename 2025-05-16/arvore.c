#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

NoArvore* inserir_v1(NoArvore *raiz, int num)
{
	if (raiz == NULL) {
		NoArvore *aux = (NoArvore*) malloc(sizeof(NoArvore));
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		return aux;
	} else {
		if (num < raiz->valor)
			raiz->esquerda = inserir_v1(raiz->esquerda, num);
		else
			raiz->direita = inserir_v1(raiz->direita, num);
		return raiz;
	}
}

void inserir_v2(NoArvore **raiz, int num)
{
	if (*raiz == NULL) {
		*raiz = (NoArvore*) malloc(sizeof(NoArvore));
		(*raiz)->valor = num;
		(*raiz)->esquerda = NULL;
		(*raiz)->direita = NULL;
	} else {
		if (num < (*raiz)->valor)
			inserir_v2(&((*raiz)->esquerda), num);
		else
			inserir_v2(&((*raiz)->direita), num);
	}
}

void inserir_v3(NoArvore **raiz, int num)
{
	NoArvore *aux = *raiz;
	
	while (aux) {
		if (num < aux->valor)
			raiz = &aux->esquerda;
		else
			raiz = &aux->direita;
		aux = *raiz;
	}
	
	aux = (NoArvore*) malloc(sizeof(NoArvore));
	aux->valor = num;
	aux->esquerda = NULL;
	*raiz = aux;
}

void imprimir_pre_ordem(NoArvore *raiz)
{
	if (raiz) {
		printf("%d ", raiz->valor);
		imprimir_pre_ordem(raiz->esquerda);
		imprimir_pre_ordem(raiz->direita);
	}
}

void imprimir_in_ordem(NoArvore *raiz)
{
	if (raiz) {
		imprimir_in_ordem(raiz->esquerda);
		printf("%d ", raiz->valor);
		imprimir_in_ordem(raiz->direita);
	}
}

void imprimir_pos_ordem(NoArvore *raiz)
{
	if (raiz) {
		imprimir_pos_ordem(raiz->esquerda);
		imprimir_pos_ordem(raiz->direita);
		printf("%d ", raiz->valor);
	}
}

NoArvore* buscar_v1(NoArvore *raiz, int num)
{
	if (raiz) {
		if (num == raiz->valor)
			return raiz;
		else if (num < raiz->valor)
			return buscar_v1(raiz->esquerda, num);
		else
			return buscar_v1(raiz->direita, num);
	}
	
	return NULL;
}

NoArvore* buscar_v2(NoArvore *raiz, int num)
{
	while (raiz) {
		if (num < raiz->valor)
			raiz = raiz->esquerda;
		else if (num > raiz->valor)
			raiz = raiz->direita;
		else
			return raiz;
	}
	
	return NULL;
}
