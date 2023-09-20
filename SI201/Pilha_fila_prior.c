/*Universidade Estadual de Campinas (UNICAMP)

Disciplina: SI201 - Estrutura de Dados I.

Nomes: Gabriel Sales da Silva Matos de Araujo, Lorena Eduarda Santos, Leonardo Issao Sato.

Questão 57 da Apostila de Estrutura de Dados.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

//construtor de nó

No *newNo (int valor) {
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

//Fila
typedef struct Fila {
    No *inicial;
    No *final;
} Fila;

typedef struct FilaPrioridade {
    Fila *prioritario;
    Fila *normal;
} FilaPrioridade;


//Estrutura do exercício 57
typedef struct FilaPriMult {
    Fila **prioridade;
} FilaPriMult;
//Construtor para Fila

Fila *newFila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila -> inicial = NULL;
    fila -> final = NULL;
    return fila;
}

FilaPrioridade *newFilaPrioridade() {
    FilaPrioridade *fila = (FilaPrioridade *) malloc(sizeof(FilaPrioridade *));
    fila ->prioritario = newFila();
    fila->normal = newFila();
    return fila;
}

//construtor fila de múltiplas prioridades
FilaPriMult *newFilaPriMult(int maxprior) {
    FilaPriMult *fila = (FilaPriMult *) malloc(sizeof(FilaPriMult));
    fila -> prioridade = malloc(sizeof(Fila)*maxprior);
    for (int i = 0; i < maxprior; i++) {
        fila->prioridade[i] = newFila();
    }
    return fila;
}

int estaVazia (Fila *f) {
    return f->inicial == NULL;
}

void add(Fila *f, int valor) {
    No *no = newNo(valor);
    //checa se está vazia
    if(estaVazia(f)) {
        f->inicial = no;
        f->final = no;
    }
    else {
        f -> final -> prox = no; //esse duplo acesso significa acessar o atributo prox do no apontado por final.
        f->final = no;
    }
}

int remover(Fila *f) {
    int valor;
    if (estaVazia(f)) {
        printf("Fila Vazia\n");
        exit(1);
    }
    valor = f -> inicial -> valor;
    No *no = f->inicial;
    if (f->inicial == f -> final ) {
        f -> inicial = NULL;
        f -> final = NULL;
    }
    else {
        f->inicial = f ->  inicial -> prox;
    }
    free (no);
    return valor;
}

int size (Fila *f) {
    int size = 0;
    No *aux = f ->inicial;
    while(aux!=NULL) {
        aux = aux->prox;
        size++;
    }
    return size;
}

void printFila(Fila *f) {
    printf("[");
    No *aux = f->inicial;
    while(aux!= NULL) {
        printf("%d", aux->valor);
        aux = aux->prox;
        if(aux!=NULL) {
            printf(" ,");
        }
    }
}

void produtor(Fila *f) {
    int tarefa = rand()%100;
    add(f, tarefa);
    printf("Add tarefa %d\n", tarefa);
}

void consumidor(Fila *f) {
    if(!estaVazia(f)) {
        int tarefa = remover(f);
        printf("Processando tarefa %d\n", tarefa);
    }
}

void executa() {
    Fila *filaTarefas = newFila();
    for (int i = 0; i < 1000; i++) {
        int r = rand()%100;
        if (r < 40) {
            produtor(filaTarefas);
        }
        else {
            consumidor(filaTarefas);
        }
        printFila(filaTarefas);
        sleep(1);
    }
}

void addPri(FilaPrioridade *f, int x, int prioritario) {
    if(prioritario) {
        add(f->prioritario,x);
    }
    else {
        add(f->normal, x);
    }
}

int removerPri(FilaPrioridade *f) {
    if(!estaVazia(f->prioritario)) {
        return remover (f->prioritario);
    }
    else {
        return remover(f->normal);
    }
} 

void printFilaPri(FilaPrioridade *fila) {
    printf("Prioritários\n");
    printFila(fila->prioritario);
    printf("Normal\n");
    printFila(fila->normal);
}

int estaVaziaPri(FilaPrioridade *fila) {
    return estaVazia(fila->prioritario) && 
    estaVazia(fila->normal);
}

//Exercício 57
void printFilaPriMult(FilaPriMult *fila, int maxprior) {
    printf("Fila de prioridades %d\n", maxprior);
    
    for (int i = 0; i < maxprior; i++) {
        printf("Prioridade %d: ", i);
        printFila(fila->prioridade[i]);
        printf("]");
        printf("\n");
    }
}


int estaVaziaPriMult(FilaPriMult *f, int prior) {
    return estaVazia(f->prioridade[prior]);
}


void addPriMult(FilaPriMult *fila, int x, int prior) {
    add(fila->prioridade[prior], x);
}

int removerPriMult(FilaPriMult *f, int maxprior) {
    int prior = 0;
    while(estaVaziaPriMult(f, prior) && prior < maxprior) {
        prior++;
    }
    return remover(f->prioridade[prior]);
}


int main() {
    int maxprior, op, prior, value;
    printf("Por favor, insira o número de prioridades abaixo e pressione a tecla Enter. \n");
    scanf("%d", &maxprior);

    FilaPriMult * f = newFilaPriMult(maxprior); //adicionamos mais um para não termos overflow

    printf("\nPrioridade máxima: %d\n", maxprior - 1);

    while(1) {
        printf("\nPressione 1 para inserir um elemento, 2 para remover um elemento, 3 para imprimir e 4 para sair\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nInsira o valor do elemento e sua prioridade, separados por um espaço:\n");
            scanf("%d %d", &value, &prior);
            addPriMult(f, value, prior);
            break;
        case 2:
            printf("\nRemovendo... \n");
            removerPriMult(f, maxprior);
            break;
        case 3:
            printFilaPriMult(f, maxprior);
            break;
        case 4:
            printf("\nSaindo...\n");
            exit(0);


        default:
            printf("\nValor inválido!\n");
            break;
        }
    }

}
