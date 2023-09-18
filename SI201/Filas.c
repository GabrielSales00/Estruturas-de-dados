#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORIDADES 100

typedef struct {
    int *elements;
    int length;
    int capacidade;
} Fila;

typedef struct {
    Fila filas[MAX_PRIORIDADES + 1];
    int max_prioridade;
} FilaPrioridade;

void inicializarFila(Fila *fila, int capacidade) {
    fila->itens = (int *)malloc(sizeof(int) * capacidade);
    fila->tamanho = 0;
    fila->capacidade = capacidade;
}

void destruirFila(Fila *fila) {
    free(fila->itens);
}

void enfileirar(Fila *fila, int elemento) {
    if (fila->tamanho < fila->capacidade) {
        fila->itens[fila->tamanho++] = elemento;
    }
}

int desenfileirar(Fila *fila) {
    if (fila->tamanho > 0) {
        int elemento = fila->itens[0];
        for (int i = 0; i < fila->tamanho - 1; i++) {
            fila->itens[i] = fila->itens[i + 1];
        }
        fila->tamanho--;
        return elemento;
    }
    return -1; // Fila vazia
}

void inicializarFilaPrioridade(FilaPrioridade *filaPrioridade, int max_prioridade) {
    for (int i = 0; i <= max_prioridade; i++) {
        inicializarFila(&filaPrioridade->filas[i], 100); // Capacidade padrão de 100 elementos por fila
    }
    filaPrioridade->max_prioridade = max_prioridade;
}

void destruirFilaPrioridade(FilaPrioridade *filaPrioridade) {
    for (int i = 0; i <= filaPrioridade->max_prioridade; i++) {
        destruirFila(&filaPrioridade->filas[i]);
    }
}

void inserirElemento(FilaPrioridade *filaPrioridade, int elemento, int prioridade) {
    if (prioridade >= 0 && prioridade <= filaPrioridade->max_prioridade) {
        enfileirar(&filaPrioridade->filas[prioridade], elemento);
        printf("Elemento %d inserido na fila com prioridade %d.\n", elemento, prioridade);
    } else {
        printf("Prioridade inválida.\n");
    }
}

void removerElemento(FilaPrioridade *filaPrioridade) {
    for (int i = 0; i <= filaPrioridade->max_prioridade; i++) {
        if (filaPrioridade->filas[i].tamanho > 0) {
            int elemento = desenfileirar(&filaPrioridade->filas[i]);
            printf("Elemento removido: %d (prioridade %d)\n", elemento, i);
            return;
        }
    }
    printf("A fila de prioridade está vazia.\n");
}

void imprimirFilaPrioridade(FilaPrioridade *filaPrioridade) {
    for (int i = 0; i <= filaPrioridade->max_prioridade; i++) {
        printf("Fila de prioridade %d: [", i);
        for (int j = 0; j < filaPrioridade->filas[i].tamanho; j++) {
            printf("%d", filaPrioridade->filas[i].itens[j]);
            if (j < filaPrioridade->filas[i].tamanho - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main() {
    int max_prioridade;
    printf("Digite o valor máximo de prioridade: ");
    scanf("%d", &max_prioridade);

    FilaPrioridade filaPrioridade;
    inicializarFilaPrioridade(&filaPrioridade, max_prioridade);

    int opcao;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir fila de prioridades\n");
        printf("4. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                int elemento, prioridade;
                printf("Digite o elemento: ");
                scanf("%d", &elemento);
                printf("Digite a prioridade: ");
                scanf("%d", &prioridade);
                inserirElemento(&filaPrioridade, elemento, prioridade);
                break;
            case 2:
                removerElemento(&filaPrioridade);
                break;
            case 3:
                imprimirFilaPrioridade(&filaPrioridade);
                break;
            case 4:
                destruirFilaPrioridade(&filaPrioridade);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}
