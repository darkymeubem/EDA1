#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int valor;
    struct Node *esq, *dir;
} Node;



typedef struct {
    Node **item;
    int primeiro, ultimo, maxN;
} Fila;

Fila *criar(int maxN) {
    Fila *p = malloc(sizeof(Fila));
    p->item = malloc(maxN * sizeof(Node *));
    p->primeiro = p->ultimo = 0;
    p->maxN = maxN;
    return p;
}

int vazia(Fila *f) {
    return f->primeiro == f->ultimo;
}

Node *desenfileira(Fila *f) {
    return f->item[f->primeiro++];
}

void enfileira(Fila *f, Node *n) {
    f->item[f->ultimo++] = n;
}

int main() {
    Fila *fila = criar(100);

    Node *raiz = malloc(sizeof(Node));
    raiz->valor = 8;
    raiz->esq = malloc(sizeof(Node));
    raiz->esq->valor = 6;
    raiz->esq->esq = malloc(sizeof(Node));
    raiz->esq->esq->valor = 1;
    raiz->esq->esq->esq = NULL;
    raiz->esq->esq->dir = NULL;
    raiz->esq->dir = malloc(sizeof(Node));
    raiz->esq->dir->valor = 7;
    raiz->esq->dir->esq = NULL;
    raiz->esq->dir->dir = NULL;
    raiz->dir = malloc(sizeof(Node));
    raiz->dir->valor = 12;
    raiz->dir->esq = malloc(sizeof(Node));
    raiz->dir->esq->valor = 9;
    raiz->dir->esq->esq = NULL;
    raiz->dir->esq->dir = NULL;
    raiz->dir->dir = malloc(sizeof(Node));
    raiz->dir->dir->valor = 13;
    raiz->dir->dir->esq = NULL;
    raiz->dir->dir->dir = NULL;

    enfileira(fila, raiz);

    while (!vazia(fila)) {
        Node *atual = desenfileira(fila);
        printf("%d ", atual->valor);
        if (atual->esq != NULL) {
            enfileira(fila, atual->esq);
        }
        if (atual->dir != NULL) {
            enfileira(fila, atual->dir);
        }
    }

    free(raiz->esq->esq);
    free(raiz->esq->dir);
    free(raiz->esq);
    free(raiz->dir->esq);
    free(raiz->dir->dir);
    free(raiz->dir);
    free(raiz);
    free(fila->item);
    free(fila);

    printf("\n");
    
    return 0;
}