#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No * prox;
}No;

typedef struct Pilha{
    No * raiz;
}Pilha;

void push(Pilha *p, int valor){
    No * no = newNo(valor);
    no->prox = p->raiz;
    p->raiz = no;
}

int pop(Pilha *p){
    if(isEmpty(p)){
    printf("Pilha Vazia\n");
    exit(6);
    }
    No * aux = p->raiz;
    p->raiz = p->raiz->prox;
    int valor = aux->valor;
    free(aux);
    return valor;
}

