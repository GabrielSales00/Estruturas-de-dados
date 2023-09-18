#include <stdio.h>
#include <stdlib.h>


//Define o tipo pilha
typedef struct Pilha {
    int *v;
    int max, top;
} Pilha;

//Inicializa uma nova pilha
Pilha *newPilha (int max) {
    Pilha *p = (Pilha *) malloc (sizeof(Pilha));
    p->v = (int *) malloc(sizeof(int) * max);
    p->max = max;
    p->top = 0;
    return p;
}

//empilha, basicamente insere um valor no vetor da pilha e move o índice para a direita 
void push (Pilha *p, int x) {
    //verifica se a fila está vazia 
    if(p -> top == 0) {
        printf("Erro! Pilha vazia!\n");
        exit(1);
    }
    p->v[p->top++] = x;
}


//O valor continua lá, mas ele será reinicializado, observe que 
//só retira o último valor da pilha
int pop (Pilha *p) {
    //verifica se a pilha está vazia 
    if (p->top == 0) {
        printf("Erro! Pilha vazia!\n");
        exit(1);
    }
    p->v[p->top--];
    return p->v[p->top];
}

int estaVazia (Pilha *p) {
    return p->top == 0;
}

//numero de elementos na pilha
int size (Pilha *p) {
    return p->top;
}
void printPiulha(Pilha *p) {
    printf("(");
    for (int i = p->top - 1; i >= 0; i--) {
        printf("%d", p->v[i]);
        if (i > 0) {
            printf("<-");
        }
    }
    printf(")");
    printf("\n");
}

int main() {
    Pilha *p;
    p = newPilha(3);
    for ( int i = 0; i < 10; i++ ){
        push(p, i);
    }
    pop (p);
}