#include <stdio.h>
#include <stdlib.h>
// cau truc phan tu Node cua danh sach lien ket
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// cau truc hang doi
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;
// ham khoi tao hang rong
Queue createQueue() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}
// ham kiem tra hang doi rong
int isEmpty(Queue q) {
    return (q.front == NULL);
}

int main(void) {
    Queue q = createQueue();
    if (isEmpty(q)) {
        printf("Hang doi dang rong.\n");
    } else {
        printf("Hang doi khong rong.\n");
    }
    return 0;
}