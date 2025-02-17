#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *esq; // Ponteiro para o nó à esquerda
    struct Node *dir; // Ponteiro para o nó à direita
    int valor;        // Valor armazenado no nó
} Node;

typedef struct Pilha {
    Node **item;
    int topo;
    int maxN;
} Pilha;

Pilha *criarPilha(int maxN) {
    Pilha *p = malloc(sizeof(Pilha));
    p->item = malloc(maxN * sizeof(Node *));
    p->topo = -1;
    p->maxN = maxN;
    return p;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, Node *n) {
    p->item[++p->topo] = n;
}

Node *desempilhar(Pilha *p) {
    return p->item[p->topo--];
}

void dfsIterativa(Node *raiz) {
    if (raiz == NULL) return;

    Pilha *pilha = criarPilha(100);
    empilhar(pilha, raiz);

    while (!pilhaVazia(pilha)) {
        Node *atual = desempilhar(pilha);
        printf("%d ", atual->valor);

        // Empilha primeiro o nó direito para que o nó esquerdo seja processado primeiro
        if (atual->dir != NULL) {
            empilhar(pilha, atual->dir);
        }
        if (atual->esq != NULL) {
            empilhar(pilha, atual->esq);
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
    // Criação de uma árvore binária para teste
    Node* raiz = novoNo(8);
    raiz->esq = novoNo(3);
    raiz->dir = novoNo(10);
    raiz->esq->esq = novoNo(1);
    raiz->esq->dir = novoNo(6);
    raiz->esq->dir->esq = novoNo(4);
    raiz->esq->dir->dir = novoNo(7);
    raiz->dir->dir = novoNo(14);
    raiz->dir->dir->esq = novoNo(13);

    // Executa a DFS iterativa e imprime os valores dos nós
    printf("DFS iterativa da árvore binária: ");
    dfsIterativa(raiz);
    printf("\n");

    return 0;
}