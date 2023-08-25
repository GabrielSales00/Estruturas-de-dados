#include <stdio.h>
#define MAX 100

//pilha implementada com vetor (sequencial)
int top=0;
int v[MAX];

void push(int x){
    v[top++]=x;
}

int pop(){
    return v[--top];
}

/**
 Uma utilidade da pilha é inverter uma determinada
 sequência. Para tanto, basta inserir os elementos
 na pilha e depois removê-los. Faça uma função main
 que faz a leitura de uma sequência de inteiros até
 que seja digitado um número menor que 0. Após
 digitar um número menor que zero, deve-se imprimir
 a sequência na ordem contrária a ordem que foi digitada.

 */

int main(){
    int val = 0;
    printf("Insira alguma sequência, separada por enter: \n");
    while (val >= 0) {
        scanf("%d", &val);
        push(val);
    }
    printf("Os valores, em ordem inversa: ");
    while (top > 0) {
        printf("%d, ", pop());
    }
    printf("\n");
    return 0;
}
