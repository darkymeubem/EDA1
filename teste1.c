#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define exch(A, B) { Item t = A; A = B; B = t; }
#define less(A, B) ((A) < (B))
#define compexch(A, B) if(less(B, A)) exch(A, B)

typedef int Item;

// Funções de ordenação
void heap_sort(Item *v, int l, int r);
void merge_sort(Item *v, int l, int r);
void quick_sort(Item *v, int l, int r);
void bubble_sort(Item *arr, int n);
void insertion_sort(Item *arr, int n);

// Funções auxiliares
void merge(int *v, int l, int m, int r);
void fixDown(int k, int N);
int partition(int *v, int l, int r);

// Funções de leitura, impressão e verificação
void readInput(Item **v, int *n, const char *filename);
void printArray(Item *v, int n);
int isSorted(Item *v, int n);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <algorithm> <input_file>\n", argv[0]);
        return 1;
    }

    Item *v;
    int n;
    readInput(&v, &n, argv[2]);

    if (strcmp(argv[1], "heapsort") == 0) {
        heap_sort(v, 0, n - 1);
    } else if (strcmp(argv[1], "mergesort") == 0) {
        merge_sort(v, 0, n - 1);
    } else if (strcmp(argv[1], "quicksort") == 0) {
        quick_sort(v, 0, n - 1);
    } else if (strcmp(argv[1], "bubblesort") == 0) {
        bubble_sort(v, n);
    } else if (strcmp(argv[1], "insertionsort") == 0) {
        insertion_sort(v, n);
    } else {
        fprintf(stderr, "Unknown algorithm: %s\n", argv[1]);
        free(v);
        return 1;
    }

    isSorted(v, n) ? printf("Ordenado\n") : printf("Desordenado\n");

    free(v);
    return 0;
}

// Função de leitura de entrada
void readInput(Item **v, int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    fscanf(file, "%d", n);
    *v = malloc(*n * sizeof(Item));
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &(*v)[i]);
    }

    fclose(file);
}

// Função de impressão do array
void printArray(Item *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função para verificar se o array está ordenado
int isSorted(Item *v, int n) {
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            return 0; // Não está ordenado
        }
    }
    return 1; // Está ordenado
}

// Função de ordenação por heap sort
static Item *pq;
static int N;

void heap_sort(Item *v, int l, int r) {
    pq = v + l - 1; // fila de prioridades construída em v
    N = r - l + 1;

    for (int k = N / 2; k >= 1; k--) {
        fixDown(k, N);
    }

    while (N > 1) {
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}

void fixDown(int k, int N) {
    int j;
    while (2 * k <= N) {
        j = 2 * k;
        if (j < N && less(pq[j], pq[j + 1])) j++;
        if (!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }
}

// Função de ordenação por merge sort
void merge_sort(Item *v, int l, int r) {
    if (l >= r) return;
    int m = (r + l) / 2;
    merge_sort(v, l, m); //metade da esquerda
    merge_sort(v, m + 1, r); //metade da direita
    merge(v, l, m, r);
}

void merge(int *v, int l, int m, int r) {
    int tam = r + 1 - l;
    int *aux = malloc(tam * sizeof(int));

    int i = l;
    int j = m + 1;
    int k = 0;

    while (k < tam) {
        if (i > m)
            aux[k++] = v[j++]; //i é o left, j é o elemento da segunda divisão
        else if (j > r) // segunda parte da direita
            aux[k++] = v[i++];
        else if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    for (k = 0, i = l; i <= r; i++)
        v[i] = aux[k++];

    free(aux);
}

// Função de ordenação por quick sort
void quick_sort(Item *v, int l, int r) {
    if (r <= l) return;
    int p = partition(v, l, r);
    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}

int partition(int *v, int l, int r) {
    int pivot = v[r];  // Pivô é o elemento mais à direita
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (v[j] <= pivot) {
            i++;
            exch(v[i], v[j]);
        }
    }
    exch(v[i + 1], v[r]);
    return i + 1;
}

// Função de ordenação por bubble sort
void bubble_sort(int *arr, int n) {
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = 1;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (flag == 0) // array is sorted
            return;
    }
}

// Função de ordenação por insertion sort
void insertion_sort(Item *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}