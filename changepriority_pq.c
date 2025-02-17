#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap_utils.c"

typedef struct {
    char nome[20];
    int chave;
} Item;

void PQinit(int maxN);
void PQinsert(int k);
void PQchange(int k);
int PQdelmax();


void PQinit(int maxN) {
    pq = malloc(sizeof(int) * (maxN + 1));
    qp = malloc(sizeof(int) * (maxN + 1));
    N = 0;
}


void PQchange(int k) {
    fixUp(qp[k]);     // Try moving up
    fixDown(qp[k], N); // Try moving down if needed
}

int PQdelmax() {
    int max = pq[1];           // Store max element
    exch(pq[1], pq[N]);       // Exchange with last element
    qp[pq[N]] = 1;            // Update position
    qp[pq[1]] = N;            // Update position
    N--;                       // Decrease size
    fixDown(1, N);            // Fix heap property
    return max;
}

// data[k]: insere elemento k na fila de prioridade
void PQinsert(int k) {
    pq[++N] = k;    // inserir na última posição
    qp[k] = N;      // lista de índices
    fixUp(N);
    
}




int main() {
    Item data[6] = {
        {"José", 10},
        {"Maria", 9},
        {"Júlio", 4},
        {"Paulo", 23},
        {"Ana", 30},
        {"Carla", 17}
    };

    PQinit(6);
    for(int i = 0; i < 6; i++) 
        PQinsert(i);

    data[1].chave = 50;
    PQchange(1);

    int k = PQdelmax();
    printf("%d %s\n", data[k].chave, data[k].nome);

    return 0;
}