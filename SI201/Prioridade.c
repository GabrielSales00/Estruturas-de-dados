#include <stdio.h>
#include <stdlib.h>

//Criando o tipo Nó
typedef struct No {
    int v[max];
    int prioridade;
    struct No *prox;
} no;

//Construtor!
No *newNo (int valor, int prioridade) {
    No *n = (No *) malloc(sizeof(No));
    n->valor = 
}