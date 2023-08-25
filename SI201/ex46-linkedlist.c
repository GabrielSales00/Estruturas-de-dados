#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura No
typedef struct No{
    int valor;
    struct No * prox;
}No;

//construtor
No * newNo(int valor){
    No * no = (No *)malloc(sizeof(No));
    no->valor=valor;
    no->prox = NULL;
    return no;
}

//Estrutura Pilha
typedef struct Pilha{
    No * topo;
}Pilha;

//Construtor
Pilha * newPilha(){
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->topo=NULL;
    return p;
}

//empilha
void push(Pilha *p,int x){
    No * no = newNo(x);//(a)
    no->prox = p->topo;//(b)
    p->topo = no;//(c)
}

//desempilha
int pop(Pilha *p){
    int valor;
    if(p->topo==NULL){
        printf("Pilha Vazia\n");
        exit(1);
    }
    valor = p->topo->valor;
    No * no = p->topo;
    p->topo = p->topo->prox;
    free(no);
    return valor;
}

int estaVazia(Pilha *p){
    return p->topo==NULL;
}

//numero de elementos na pilha
int size(Pilha *p){
    int size=0;
    No * aux = p->topo;
    while(aux!=NULL){
        aux = aux->prox;
        size++;
    }
    return size;
}

//implementacao alternativa da funcao size
int size2(Pilha *p){
    int size=0;
    for(No * aux = p->topo;aux!=NULL;aux = aux->prox){
        size++;
    }
    return size;
}

//Size recursivo
int sizeRec(No *no){
    if(no==NULL){
        return 0;
    }
    return 1+sizeRec(no->prox);
}

//chamada do size recursivo
int size3(Pilha *p){
    return sizeRec(p->topo);
}


void printPilha(Pilha *p){
    printf("(");
    No * aux = p->topo;
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux = aux->prox;
        if(aux!=NULL){
            printf("<-");
        }
    }
    
    printf(")");
    printf("[%d]\n",size(p));
}



//devolve 1 se os parenteses estao balanceados
//0 caso contrario
int balanceado(char *texto){
    int size;
    size = strlen(texto);
    Pilha * p = newPilha();
    for(int i=0;i<size;i++){
        if(texto[i]=='('){
            push(p,1);
            //printPilha(p);
        }
        if(texto[i]==')'){
            if(estaVazia(p)){
                return 0;
            }
            pop(p);
            //printPilha(p);
        }
        
    }
    return estaVazia(p);
}

void recursivePrint(Pilha* p) {
    No * aux = p->topo;
    if(aux != NULL) {
        printf("%d, ", p->valor);
        recursivePrint(p);
    }
    printf("\n");
}

int main(){
    int val = 1;
    Pilha *p = newPilha();
    while(val >= 0) {
        scanf("%d", &val);
        push(p, val);
    }
    recursivePrint(p);
}