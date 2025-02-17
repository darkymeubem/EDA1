#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia
    if ((f->u + 1) % f->N == f->p) {
        // Redimensiona o vetor dados para o dobro do tamanho
        int novoTamanho = 2 * f->N;
        int *novoDados = malloc(novoTamanho * sizeof(int));
        if (novoDados == NULL) return 0; // Falha na alocação de memória

        // Copia os elementos da fila antiga para a nova
        int i = 0;
        int j = f->p;
        while (j != f->u) {
            novoDados[i++] = f->dados[j];
            j = (j + 1) % f->N;
        }

        // Atualiza os ponteiros e o tamanho da fila
        free(f->dados);
        f->dados = novoDados;
        f->N = novoTamanho;
        f->p = 0;
        f->u = i;
    }

    // Insere o novo elemento na fila
    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}

int main() {
    // Criação de uma fila com capacidade inicial de 5
    fila *f = malloc(sizeof(fila));
    if (f == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }
    f->N = 5;
    f->dados = malloc(f->N * sizeof(int));
    f->p = 0;
    f->u = 0;

    if (f->dados == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        free(f);
        return 1;
    }

    // Teste de enfileiramento
    for (int i = 1; i <= 10; i++) {
        if (enfileira(f, i)) {
            printf("Enfileirado: %d\n", i);
        } else {
            printf("Fila cheia ao tentar enfileirar: %d\n", i);
        }
    }

    // Libera a memória alocada
    free(f->dados);
    free(f);
    return 0;
}