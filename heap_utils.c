#include "heap_utils.h"

int *pq;
int *qp;
int N;

void fixUp(int k) {
    while (k > 1 && less(pq[k/2], pq[k])) {
        exch(pq[k/2], pq[k]);
        k = k/2;
    }
}

void fixDown(int k, int N) {
    int j;
    while(2*k <= N) {
        j = 2*k;
        if(j < N && less(pq[j], pq[j+1])) j++;
        if(!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }
}

int less(int i, int j) {
    return pq[i] < pq[j];
}

void exch(int i, int j) {
    int t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
    
    t = qp[pq[i]];
    qp[pq[i]] = qp[pq[j]];
    qp[pq[j]] = t;
}