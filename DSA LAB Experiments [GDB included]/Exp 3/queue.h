#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX 10
#define SIZE 5

typedef struct {
	int rear;
	int front;
	int arr[MAX];
} Queue;

typedef struct {
	int rear;
	int front;
	int arr[SIZE];  //  Circular queue uses SIZE instead of MAX (size<max)
} CQueue;

typedef struct {
	int rear;
	int front;
	int arr[MAX];
} DQueue;

// Normal Queue functions
void create_queue(Queue *q);
bool isempty(Queue *q);
bool isfull(Queue *q);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
void display(Queue *q);

// Circular Queue functions
void create_cqueue(CQueue *cq);
bool issfull(CQueue *cq);
bool issempty(CQueue *cq);
void cenqueue(CQueue *cq, int item);
int cdequeue(CQueue *cq);
void cdisplay(CQueue *cq);

// Double-ended Queue functions
void create_dqueue(DQueue *dq);
void insert_at_fr(DQueue *dq, int value);
void insert_at_rr(DQueue *dq, int value);
int deletefront(DQueue *dq);
int deleterear(DQueue *dq);
void ddisplay(DQueue *dq);

#endif
