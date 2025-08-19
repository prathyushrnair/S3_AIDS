#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void create_cqueue(CQueue *cq) {
	cq->front=-1;
	cq->rear=-1;
}

bool issfull(CQueue *cq) {
	return ((cq->rear+1)%SIZE==cq->front);
}
bool issempty(CQueue *cq) {
	return cq->front==-1;
}

void cenqueue(CQueue *cq,int item) {
	if (issfull(cq)) { //' ss ' for circular queue
		printf("The circular queue is full\n");
		return;
	}
	if (cq->front==-1) { //case where cqueue is empty
		cq->front=0;
	}
	cq->rear=(cq->rear+1)%SIZE;
	cq->arr[cq->rear]=item;
	printf("enqueued %d to arr\n",cq->arr[cq->rear]);
}
int cdequeue(CQueue *cq) {
	if(cq->front==-1) {
		printf("Underflowing error\n");
		return -1;
	}
	int value=cq->arr[cq->front];
	if (cq->front==cq->rear) {
		cq->front=-1;
		cq->rear=-1;
	}
	else {
		cq->front=(cq->front+1)%SIZE;
	}
	printf("Element %d is popped\n",value);
	return value;
}
void cdisplay(CQueue *cq) {
	if (cq->front==-1) {
		printf("Nothing to display\n");
		return;
	}
	else {
		printf("Elements in the circular queue are \n");
		if (cq->rear>= cq->front) {
			for(int i=cq->front; i<=cq->rear; i++) {
				printf("%d\n",cq->arr[i]);
			}
		}
		else {
			for(int i=cq->front; i<SIZE; i++) {
				printf("%d\n",cq->arr[i]);
			}
			for(int i=0; i<=cq->rear; i++) {
				printf("%d\n",cq->arr[i]);
			}
		}
	}

}
