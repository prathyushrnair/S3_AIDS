#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
void create_queue(Queue *q) {
	q->front=-1;
	q->rear=-1;
}

bool isempty(Queue *q) {
	return q->front==-1;
}

bool isfull(Queue *q) {
	return q->rear==MAX-1;
}

void enqueue(Queue *q,int item) {
	if(isfull(q)) {
		printf("Queue Is FULL\n");
		return;
	}

	if(isempty(q)) {
		q->front=0;
	}

	q->rear++;
	q->arr[q->rear]=item;
	printf("enqueue %d to queue Q\n",item);
}
int dequeue(Queue *q) {
	int item;
	if (isempty(q)) {
		printf("Queue is empty...\n");
		return -1;
	}
	item=q->arr[q->front];
	q->front++;
	if (q->front >q->rear) {
		q->front=q->rear=-1;
	}
	return item;
}

void display(Queue *q) {
	if (isempty(q)) {
		printf("Queue Is empty\n");
		return;
	}
	for(int i=q->front; i<=q->rear; i++) {
		printf("%d\t",q->arr[i]);
	}
	printf("\n");
}


