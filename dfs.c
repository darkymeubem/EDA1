#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *esq; // Ponteiro para o nó à esquerda
    struct Node *dir; // Ponteiro para o nó à direita
    int valor;        // Valor armazenado no nó
} Node;

void dfs(Node *atual) {
    if (atual == NULL) {
        return; // Caso base: se o nó atual for NULL, termina a recursão.
    }

    

    if (atual->esq != NULL) {
        dfs(atual->esq); // Chama recursivamente a DFS no nó à esquerda
    }
    
    

    if (atual->dir != NULL) {
        dfs(atual->dir); // Chama recursivamente a DFS no nó à direita
    }

    printf("%d ", atual->valor); // Processa (imprime) o valor do nó atual
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

    // Executa a DFS e imprime os valores dos nós
    printf("DFS da árvore binária: ");
    dfs(raiz);
    printf("\n");

    return 0;
}