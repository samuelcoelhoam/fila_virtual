// Importação das bibliotecas que serão utilizadas no programa.

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Declaração das funções que serão utilizadas no programa.

void carregar_fila(Fila *f, char *nome_arquivo);

void atende_clientes(Fila *f);

void bubble_sort(Fila *f);

int main(void) {

  // Cria a fila
  Fila *fila = fila_cria();

  // Nome do arquivo com os números
  char *nome_arquivo = "clientes.txt";

  // Carrega os números do arquivo para a fila
  carregar_fila(fila, nome_arquivo);

  // Ordena a fila do cliente mais velho para o mais novo
  bubble_sort(fila);

  // Atende os clientes da fila
  atende_clientes(fila);

  // Libera a memória alocada pela fila
  fila_libera(fila);

  return 0;
}

void carregar_fila(Fila *f, char *nome_arquivo) {
  FILE *arquivo = fopen(nome_arquivo, "r");

  // Verifica se houve algum erro ao abrir o arquivo
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  int numero;

  // Lê os números do arquivo e insere na fila
  while (fscanf(arquivo, "%d", &numero) != EOF) {
    fila_insere(f, numero);
  }

  fclose(arquivo);
}

void atende_clientes(Fila *f) {
  // Enquanto a fila não estiver vazia, remove o cliente mais velho e o atende
  while (f->inicio != NULL) {
    printf("Cliente atendido! Idade: %d\n", f->inicio->info);
    fila_remove(f);
  }
  printf("\n");
  printf("Todos os clientes já foram atendidos!\n");
}

void bubble_sort(Fila *f) {

  // Verifica se a fila está vazia
  if (f->inicio == NULL)
    return;

  // Variável para indicar se houve troca na última iteração ocorrida
  int trocado;
  No *atual;
  No *fim = NULL;

  // Repete o processo até que nenhuma troca seja feita
  do {
    trocado = 0;
    atual = f->inicio;

    while (atual->prox != fim) {
      if (atual->info < atual->prox->info) {
        // Troca os valores caso estejam fora de ordem (ordem decrescente)
        int temp = atual->info;
        atual->info = atual->prox->info;
        atual->prox->info = temp;

        // Marca que uma troca foi feita
        trocado = 1;
      }
      atual = atual->prox;
    }
    fim = atual;
  } while (trocado); // Enquanto houver troca, continua o processo
}