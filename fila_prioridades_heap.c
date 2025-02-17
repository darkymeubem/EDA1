#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t = A; A = B; B = t; }

// static: acessível somente no arquivo
static Item *pq;
static int N;

void PQinit(int maxN) {
    pq = malloc(sizeof(Item) * (maxN + 1));
    N = 0;
}

void fixUp(int k){
    while (k > 1 && less(pq[k/2], pq[k])) {
        exch(pq[k/2], pq[k]);
        k = k/2;
    }
}

void fixDown(int k, int N){
    int j;
    while(2*k <= N){
        j = 2*k; //filho da esquerda
        if(j < N && less(pq[j], pq[j+1])) j++; // se tiver filho da direita e for maior
        if(!less(pq[k], pq[j])) break; // pq[k] maior que o maior filho 
        exch(pq[k], pq[j]);
        k = j;
    }
}

int PQempty() {
    return N == 0;
}

void PQinsert(Item v) {
    pq[++N] = v;    // inserir na última posição
    fixUp(N);       // consertar a heap
}

Item PQdelmax() {
    exch(pq[1], pq[N]);    // trocar primeiro com último
    fixDown(1, N-1);       // consertar heap
    return pq[N--];        // devolver o máximo
}

// Ideia de utilização da fila de prioridades
void PQsort(Item *v, int l, int r) {
    PQinit(r - l + 1); // Inicializa a fila de prioridades com capacidade suficiente
    for (int k = l; k <= r; k++) {
        PQinsert(v[k]); // Insere todos os elementos no heap
    }
    for (int k = r; k >= l; k--) {
        v[k] = PQdelmax(); // Remove os elementos em ordem decrescente
    }
}

int main() {
    Item v[] = {5, 2, 8, 1, 9};
    int n = sizeof(v) / sizeof(v[0]); //calcula quantos blocos de memoria existe, ou seja, seu tamanho

    PQsort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}