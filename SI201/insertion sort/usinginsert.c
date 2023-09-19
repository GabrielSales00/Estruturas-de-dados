/*
Nome: Gabriel Sales

Este programa serve para empregar o algoritmo "Insert Sort", que funciona semelhantemente à ordenação de cartas de baralho.

*/




#include <stdio.h>
#include "insertion_sort.h"

int main () {
    int A[10];
    //Atribui aos valores de A 
    for (int i = 0; i < 10; i++ ) {
        scanf("%d", &A[i]);
    }
    //Ordena os valores de A
    insertion_sort(A);
    //Imprime os valores de A
    for (int i = 0; i < 10; i++ ) {
        printf("%d, ", A[i]);
    }
    printf("\n");
    inverse_sort(A);
    //Imprime os valores de A
    for (int i = 0; i < 10; i++ ) {
        printf("%d, ", A[i]);
    }
    printf("\n");

    return 0;
}