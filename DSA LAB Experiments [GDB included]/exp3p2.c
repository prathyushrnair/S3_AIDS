#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int rear;
    int front;
    int arr[MAX];
} dqueue_1;

// Deque Functions
void create_dqueue(dqueue_1 *dq) {
    dq->front = -1;
    dq->rear = -1;
}

bool is_empty(dqueue_1 *dq) {
    return dq->front == -1;
}

bool is_full(dqueue_1 *dq) {
    return (dq->front == 0 && dq->rear == MAX-1) || (dq->front == dq->rear + 1);
}

void insert_at_front(dqueue_1 *dq, int value) {
    if(is_full(dq)) {
        printf("Deque is full\n");
        return;
    }
    if(dq->front == -1) {
        dq->front = dq->rear = 0;
    }
    else if(dq->front == 0) {
        dq->front = MAX - 1;
    }
    else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
    printf("Inserted %d at front\n", value);
}

void insert_at_rear(dqueue_1 *dq, int value) {
    if(is_full(dq)) {
        printf("Deque is full\n");
        return;
    }
    if(dq->front == -1) {
        dq->front = dq->rear = 0;
    }
    else if(dq->rear == MAX-1) {
        dq->rear = 0;
    }
    else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear\n", value);
}

int delete_front(dqueue_1 *dq) {
    if(is_empty(dq)) {
        printf("Deque underflow\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if(dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else if(dq->front == MAX-1) {
        dq->front = 0;
    }
    else {
        dq->front++;
    }
    printf("Deleted %d from front\n", value);
    return value;
}

int delete_rear(dqueue_1 *dq) {
    if(is_empty(dq)) {
        printf("Deque underflow\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if(dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else if(dq->rear == 0) {
        dq->rear = MAX-1;
    }
    else {
        dq->rear--;
    }
    printf("Deleted %d from rear\n", value);
    return value;
}

void display_deque(dqueue_1 *dq) {
    if(is_empty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    if(dq->rear >= dq->front) {
        for(int i = dq->front; i <= dq->rear; i++) {
            printf("%d ", dq->arr[i]);
        }
    }
    else {
        for(int i = dq->front; i < MAX; i++) {
            printf("%d ", dq->arr[i]);
        }
        for(int i = 0; i <= dq->rear; i++) {
            printf("%d ", dq->arr[i]);
        }
    }
    printf("\n");
}

// Deque Menu Function
void deque_menu() {
    dqueue_1 dque;
    create_dqueue(&dque);
    int choice, value;

    while(1) {
        printf("\nDouble-Ended Queue Operations:\n");
        printf("1. Insert at front\n2. Insert at rear\n");
        printf("3. Delete from front\n4. Delete from rear\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insert_at_front(&dque, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insert_at_rear(&dque, value);
                break;
            case 3:
                value = delete_front(&dque);
                if(value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 4:
                value = delete_rear(&dque);
                if(value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 5:
                display_deque(&dque);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}
