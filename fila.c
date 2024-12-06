#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar uma fila vazia

Fila *fila_cria() {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  if (f == NULL) {
    printf("Erro ao alocar memória para a fila");
    exit(1);
  }
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

// Função para inserir um elemento no final da fila

void fila_insere(Fila *f, int info) {
  No *novo = malloc(sizeof(No));

  if (novo == NULL) {
    printf("Erro ao alocar memória para o nó");
    exit(1);
  }
  novo->info = info;
  novo->prox = NULL;
  novo->ant = f->fim;
  if (f->fim != NULL) {
    f->fim->prox = novo;
  } else {
    f->inicio = novo;
  }
  f->fim = novo;
}

// Função para remover o elemento do início da fila

void fila_remove(Fila *f) {
  if (f->inicio == NULL) {
    printf("Fila vazia\n");
  }
  int info = f->inicio->info;
  No *temp = f->inicio;
  f->inicio = f->inicio->prox;
  if (f->inicio == NULL) {
    f->fim = NULL;
  }
  free(temp);
}

// Função para imprimir os elementos da fila

void fila_imprime(Fila *f) {
  No *atual = f->inicio;
  if(atual == NULL) {
    printf("Lista vazia\n");
  }
  while (atual != NULL) {
    printf("%d ", atual->info);
    atual = atual->prox;
  }
}

// Função para liberar a memória alocada pela fila

void fila_libera(Fila *f) {
  No *atual = f->inicio;
  while (atual != NULL) {
    No *temp = atual;
    atual = atual->prox;
    free(temp);
  }
  free(f);
}
