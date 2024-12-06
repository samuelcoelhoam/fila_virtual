// fila.h

#include <stdio.h>
#include <stdlib.h>

// Structs para criação das filas

typedef struct fila Fila;
typedef struct no No;

struct no {
  int info;
  No *prox;
  No *ant;
};

struct fila {
  No *inicio;
  No *fim;
};

// Funções do TAD Fila

/*
Função que cria e inicializa uma nova fila.
- Parâmetros:
  - Nenhum.
- Retorno:
  - Um ponteiro para uma estrutura `Fila` inicializada com os ponteiros `inicio` e `fim` configurados como `NULL`.
- Como usar:
  Chame esta função para alocar memória e criar uma fila antes de utilizá-la.
*/

Fila *fila_cria(void);

/*
Função que insere um elemento na fila.
- Parâmetros:
  - `f`: Ponteiro para a estrutura `Fila` onde o elemento será inserido.
  - `info`: Valor inteiro a ser armazenado no novo nó da fila.
- Retorno:
  - Nenhum.
- Como usar:
  Utilize esta função para adicionar elementos ao final da fila. Certifique-se de que a fila foi criada previamente com `fila_cria`.
*/

void fila_insere(Fila *f, int info);

/*
Função que remove o primeiro elemento da fila.
- Parâmetros:
  - `f`: Ponteiro para a estrutura `Fila` de onde o elemento será removido.
- Retorno:
  - Nenhum.
- Como usar:
  Chame esta função para remover o nó que está no início da fila. Se a fila estiver vazia, uma mensagem será exibida.
*/

void fila_remove(Fila *f);

/*
Função que imprime os elementos da fila.
- Parâmetros:
  - `f`: Ponteiro para a estrutura `Fila` cujos elementos serão impressos.
- Retorno:
  - Nenhum.
- Como usar:
  Utilize esta função para visualizar os valores armazenados na fila em ordem sequencial, do início ao fim.
*/

void fila_imprime(Fila *f);

/*
Função que libera a memória ocupada pela fila.
- Parâmetros:
  - `f`: Ponteiro para a estrutura `Fila` que será liberada.
- Retorno:
  - Nenhum.
- Como usar:
  Chame esta função ao final do uso da fila para liberar todos os nós alocados e a estrutura `Fila`. Após esta operação, o ponteiro para a fila não será mais válido.
*/

void fila_libera(Fila *f);