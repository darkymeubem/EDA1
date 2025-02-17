#include <stdio.h>
#include <stdlib.h>

// Tree node structure
typedef struct TreeNode {
    int data;
    int priority;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Priority Queue structure
typedef struct {
    TreeNode **nodes;  // Array of pointers to TreeNodes
    int size;
    int capacity;
} PriorityQueue;

// Regular Queue for BFS
typedef struct {
    TreeNode **nodes;
    int front;
    int rear;
    int capacity;
} Queue;

// Priority Queue functions
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->nodes = malloc(sizeof(TreeNode*) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(TreeNode **a, TreeNode **b) {
    TreeNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq->nodes[parent]->priority < pq->nodes[idx]->priority) {
            swap(&pq->nodes[parent], &pq->nodes[idx]);
            idx = parent;
        } else break;
    }
}

void enqueuePQ(PriorityQueue *pq, TreeNode *node) {
    if (pq->size == pq->capacity) return;
    pq->nodes[pq->size] = node;
    heapifyUp(pq, pq->size);
    pq->size++;
}

// Regular Queue functions
Queue* createQueue(int capacity) {
    Queue* q = malloc(sizeof(Queue));
    q->nodes = malloc(sizeof(TreeNode*) * capacity);
    q->front = q->rear = -1;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue *q, TreeNode *node) {
    if (q->rear == q->capacity - 1) return;
    if (q->front == -1) q->front = 0;
    q->nodes[++q->rear] = node;
}

TreeNode* dequeue(Queue *q) {
    if (q->front == -1) return NULL;
    TreeNode *node = q->nodes[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return node;
}

// BFS traversal using regular queue
void BFS(TreeNode *root) {
    if (!root) return;
    Queue *q = createQueue(100);
    enqueue(q, root);
    
    while (q->front != -1) {
        TreeNode *node = dequeue(q);
        printf("%d ", node->data);
        
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
}

// Example usage
int main() {
    // Create a sample tree
    TreeNode *root = malloc(sizeof(TreeNode));
    root->data = 1;
    root->priority = 3;
    root->left = malloc(sizeof(TreeNode));
    root->left->data = 2;
    root->left->priority = 1;
    root->right = malloc(sizeof(TreeNode));
    root->right->data = 3;
    root->right->priority = 2;
    
    // Perform BFS
    printf("BFS traversal: ");
    BFS(root);
    printf("\n");
    
    return 0;
}