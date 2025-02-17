#ifndef HEAP_UTILS_H
#define HEAP_UTILS_H

int *pq;
int *qp;
int N;

void fixUp(int k);
void fixDown(int k, int N);
void exch(int i, int j);
int less(int i, int j);

#endif