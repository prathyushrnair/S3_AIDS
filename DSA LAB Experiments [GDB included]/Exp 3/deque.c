#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
void create_dqueue(DQueue *dq) {
	dq->front=-1;
	dq->rear=-1;
}
void insert_at_fr(DQueue *dq,int value) {
	if((dq->front==0 && dq->rear==MAX-1)) {
		printf("Deque overflowing...\n");
	}
	else if (dq->front==dq->rear==-1){
	    dq->front=dq->rear=0;
	    dq->arr[dq->front]=value;
	}
	else {
		if(dq->front==-1) {
			dq->front=dq->rear=0;
		}
		else if(dq->front==0) {
			dq->front=MAX-1;
		}
		else {
			dq->front--;
		}
		dq->arr[dq->front]=value;
	}
}
void insert_at_rr(DQueue *dq,int value) {
	if((dq->front==0 && dq->rear==MAX-1)||(dq->front==dq->rear+1)) {
		printf("underflow error at insertion at rr\n");
	}
	else {
		if(dq->front==-1) {
			dq->front=dq->rear=0;
		}
		else if(dq->rear==MAX-1) {
			dq->rear=0;
		}
		else {
			dq->rear++;
		}
		dq->arr[dq->rear]=value;
	}
}

int deletefront(DQueue *dq) {
	if (dq->front==-1) {
		printf("Deque underflow \n");
		return -1;
	}
	else {
		int value =dq->arr[dq->front];
		if(dq->front==dq->rear) {
			dq->front=dq->rear=-1;
		}
		else if(dq->front==MAX-1) {
			dq->front=0;
		}
		else {
			dq->front++;
		}
		return value;
	}
}

int deleterear(DQueue *dq) {
	if (dq->front==-1) {
		printf("Deque underflow \n");
		return -1;
	}
	else {
		int value=dq->arr[dq->rear];
		if(dq->front==dq->rear) {
			dq->front=dq->rear-1;
		}
		else if(dq->rear==0) {
			dq->rear=MAX-1;
		}
		else {
			dq->rear--;
		}
		return value;
	}
}

void ddisplay(DQueue *dq) {
	if(dq->front==-1) {
		printf("Deque is empty\n");
		return;
	}
	if(dq->front <= dq->rear) {
		for(int i=dq->front; i<=dq->rear; i++) {
			printf("%d",dq->arr[i]);
		}
	}
	else {
		for(int i=dq->front; i<MAX; i++) {
			printf("%d",dq->arr[i]);
		}
		for(int i=0; i<=dq->rear; i++) {
			printf("%d",dq->arr[i]);
		}
	}
	printf("\n");
}
