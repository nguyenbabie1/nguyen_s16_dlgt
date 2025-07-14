#include <stdio.h>
#include <stdlib.h>
// Node phan tu trong danh sach liem ket
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// hang doi
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
// khoi tao hang doi
Queue createQueue(){
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}
// ham tao node moi
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Nhap so nguyen; ");
    scanf("%d", &newNode ->data);
    newNode->next = NULL;
    return newNode;
}
// ham them node vao hang doi
void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
// in hang doi
void printQueue(Queue q) {
    Node* current = q.front;
    printf("queue = {\n  front->");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");

    if (q.rear != NULL) {
        printf("  rear->%d->NULL\n", q.rear->data);
    } else {
        printf("  rear->NULL\n");
    }

    printf("}\n\n");
}
// ham xem phan tu dau tien
int peek(Queue q) {
    if (q.front == NULL) {
        printf("\nempty queue\n");
        return -1;
    } else {
        return q.front->data;
    }
}

int main(void) {
    Queue q = createQueue();

    printQueue(q);
    int value = peek(q);
    if (value != -1) {
        printf("Phan tu dau tien trong hang doi: %d\n", value);
    }

    enqueue(&q);
    enqueue(&q);
    enqueue(&q);
    printQueue(q);
    value = peek(q);
    if (value != -1) {
        printf("Phan tu dau tien trong hang doi: %d\n", value);
    }
    return 0;
}