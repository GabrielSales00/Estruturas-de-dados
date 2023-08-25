#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int *v;
    int max,top;
}Pilha;

Pilha *newPilha(int max){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->v = (int *)malloc(sizeof(int)*max);
    p->max = 0;
    p->top = max - 1;
    return p;
}

//empilha
void push(Pilha *p,int x){
    //verifica se a pilha esta cheia
    if(p->top == p->max){
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    p->v[p->top]=x;
    p->top--;
}

//desempilha
int pop(Pilha *p){
    //verifica se a pilha esta vazia
    if(p->top == p->max){
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    p->top++;
    return p->v[p->top];
}

int estaVazia(Pilha *p){
    return p->top==0;
}

//numero de elementos na pilha
int size(Pilha *p){
    return p->top;
}

void printPilha(Pilha *p){
    printf("(");
    for(int i = p->top-1; i>=0;i--){
        printf("%d",p->v[i]);
        if(i>0){
            printf("<-");
        }
    }
    printf(")");
    printf("\n");
}

/**
 Refaça a tarefa anterior usando a estrutura Pilha.
 */

int main(){
    int val = 0, maxVal = 10;
    Pilha *p = newPilha(maxVal);
    printf("Insira alguma sequência, separada por enter: \n");
    while (val >= 0) {
        scanf("%d", &val);
        push(p, val);
    }
    printf("Os valores, em ordem inversa: ");
    while (p->max > 0) {
        printf("%d, ", pop(p));
    }
    printf("\n");
    return 0;
}