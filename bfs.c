#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *esq, *dir;
} Node;

typedef struct Fila {
    Node **item;
    int primeiro, ultimo, maxN;
} Fila;

Fila *criarFila(int maxN) {
    Fila *f = malloc(sizeof(Fila));
    f->item = malloc(maxN * sizeof(Node *));
    f->primeiro = f->ultimo = 0;
    f->maxN = maxN;
    return f;
}

int filaVazia(Fila *f) {
    return f->primeiro == f->ultimo;
}

void enfileira(Fila *f, Node *n) {
    f->item[f->ultimo++] = n;
}

Node *desenfileira(Fila *f) {
    return f->item[f->primeiro++];
}

void bfs(Node *raiz) {
    if (raiz == NULL) return;

    Fila *fila = criarFila(100);
    enfileira(fila, raiz);

    while (!filaVazia(fila)) {
        Node *atual = desenfileira(fila);
        printf("%d ", atual->valor);

        if (atual->esq != NULL) {
            enfileira(fila, atual->esq);
        }
        if (atual->dir != NULL) {
            enfileira(fila, atual->dir);
        }
    }
}

Node* novoNo(int valor) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->valor = valor;
    node->esq = NULL;
    node->dir = NULL;
    return node;
}

int main() {
    Node* raiz = novoNo(8);
    raiz->esq = novoNo(3);
    raiz->dir = novoNo(10);
    raiz->esq->esq = novoNo(1);
    raiz->esq->dir = novoNo(6);
    raiz->esq->dir->esq = novoNo(4);
    raiz->esq->dir->dir = novoNo(7);
    raiz->dir->dir = novoNo(14);
    raiz->dir->dir->esq = novoNo(13);

    printf("BFS da árvore binária: ");
    bfs(raiz);
    printf("\n");

    return 0;
}