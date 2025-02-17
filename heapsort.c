#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t = A; A = B; B = t; }

static Item *pq;
static int N;

void fixDown(int k, int N) {
    int j;
    while (2*k <= N) {
        j = 2*k;
        if (j < N && less(pq[j], pq[j+1])) j++;
        if (!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }
}
 
void heap_sort(Item *v, int l, int r) {
    pq = v + l - 1; // fila de prioridades construída em v
    // uma posição anterior a v[l]
    // se l = 0 -> pq[1] = v[0]
    N = r - l + 1;

    for (int k = N / 2; k >= 1; k--) //conserta heap
    {
        fixDown(k, N);
    }

    while (N > 1) //ordena heap
    {
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}

int main() {
    Item v[] = {5, 2, 8, 1, 9};
    int n = sizeof(v) / sizeof(v[0]);

    heap_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}