#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define SIZE 5

typedef struct {
    int rear;
    int front;
    int arr[MAX];
} queue_1, cqueue_1;

// Normal Queue Functions
void create_queue(queue_1 *q) {
    q->front = -1;
    q->rear = -1;
}

bool isempty(queue_1 *q) {
    return q->front == -1;
}

bool isfull(queue_1 *q) {
    return q->rear == MAX - 1;
}

void enqueue(queue_1 *q, int item) {
    if(isfull(q)) {
        printf("Queue Is FULL\n");
        return;
    }
    if(isempty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = item;
    printf("Enqueued %d to queue\n", item);
}

int dequeue(queue_1 *q) {
    if(isempty(q)) {
        printf("Queue is empty...\n");
        return -1;
    }
    int item = q->arr[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void display(queue_1 *q) {
    if(isempty(q)) {
        printf("Queue Is empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d\t", q->arr[i]);
    }
    printf("\n");
}

// Circular Queue Functions
void create_cqueue(cqueue_1 *cq) {
    cq->front = -1;
    cq->rear = -1;
}

bool issfull(cqueue_1 *cq) {
    return ((cq->rear + 1) % SIZE == cq->front);
}

bool issempty(cqueue_1 *cq) {
    return cq->front == -1;
}

void cenqueue(cqueue_1 *cq, int item) {
    if(issfull(cq)) {
        printf("The circular queue is full\n");
        return;
    }
    if(cq->front == -1) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % SIZE;
    cq->arr[cq->rear] = item;
    printf("Enqueued %d to circular queue\n", item);
}

int cdequeue(cqueue_1 *cq) {
    if(issempty(cq)) {
        printf("Underflow error\n");
        return -1;
    }
    int value = cq->arr[cq->front];
    if(cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % SIZE;
    }
    printf("Dequeued %d from circular queue\n", value);
    return value;
}

void cdisplay(cqueue_1 *cq) {
    if(issempty(cq)) {
        printf("Circular queue is empty\n");
        return;
    }
    printf("Elements in circular queue: ");
    if(cq->rear >= cq->front) {
        for(int i = cq->front; i <= cq->rear; i++) {
            printf("%d ", cq->arr[i]);
        }
    } else {
        for(int i = cq->front; i < SIZE; i++) {
            printf("%d ", cq->arr[i]);
        }
        for(int i = 0; i <= cq->rear; i++) {
            printf("%d ", cq->arr[i]);
        }
    }
    printf("\n");
}

// Queue Menu Function
void queue_menu() {
    queue_1 que;
    create_queue(&que);
    int choice, value;

    while(1) {
        printf("\nNormal Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&que, value);
                break;
            case 2:
                value = dequeue(&que);
                if(value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(&que);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

// Circular Queue Menu Function
void circular_queue_menu() {
    cqueue_1 cque;
    create_cqueue(&cque);
    int choice, value;

    while(1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                cenqueue(&cque, value);
                break;
            case 2:
                value = cdequeue(&cque);
                if(value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                cdisplay(&cque);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}
