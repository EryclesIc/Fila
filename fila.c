#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "no.h"

int tamanho(fila *fila) {
	return fila->tamanho;
}
int vazia(fila* fila) {
	return tamanho(fila) == 0;
}
fila* criaFila() {
	fila *novaFila = (fila*)malloc(sizeof(fila));
	novaFila->cabeca = NULL;
	novaFila->cauda = NULL;
	novaFila->tamanho = 0;
	return novaFila;
}
void enfileira(int item, fila *fila) {
	no *novoNo = criaNo(item);
	if(vazia(fila)) {
		fila->cauda = novoNo;
		fila->cabeca = fila->cauda;
	} else {
		fila->cauda->proximo = novoNo;
		fila->cauda = novoNo;
	}
	fila->tamanho++;
}
int desenfileira(fila *fila) {
	if(vazia(fila)) {
		return -1;
	} else {
		int item = fila->cabeca->item;
		no *no = fila->cabeca;
		fila->cabeca = fila->cabeca->proximo;
		free(no);
		fila->tamanho--;
		return item;
	}
}
int proximo(fila *fila) {
	if(vazia(fila)) {
		return -1;
	} else {
		return fila->cabeca->item;
	}
}
