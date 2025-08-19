#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
#define SIZE 5
#include "queue.h"
//implementing double ended queues menu with function calls
void dqueue_fu() {
	DQueue dque;
	int choic=0;
	create_dqueue(&dque);
	while(1) {
		printf(" 1.Insert at front\n 2.Insert at Rear\n 3.Delete at rear\n");
		printf(" 4.Delete At front\n 5.Exit\n");
		printf("Enter choice from above\n");
		scanf("%d",&choic);
		if (choic==1) {
			printf("Insert at front selected\n");
			insert_at_fr(&dque,30);
			ddisplay(&dque);

		}
		else if(choic==2) {
			printf("Insert at rear selected\n");
			insert_at_rr(&dque,60);
			ddisplay(&dque);
		}
		else if(choic==3) {
			printf("Delete at rear selected\n");
			deleterear(&dque);
			ddisplay(&dque);
		}
		else if(choic==4) {
			printf("Delete at front selected\n");
			deletefront(&dque);
			ddisplay(&dque);
		}
		else {
			break;
		}
	}
}
//implementing Circular Queues menu with function calls
void cqueue_fu() {
	CQueue cque;
	int choice;
	printf("Intialising a circular queue\n");
	create_cqueue(&cque);
	while(choice!=3) {
		printf(" 1.Enqueue\n 2.Dequeue\n ELSE. BREAK\n");
		printf("Enter the choices from above\n");
		scanf("%d",&choice);
		if (choice==1) {
			printf("Enqueue FN is activated\n");
			cenqueue(&cque,10);
			cenqueue(&cque,20);
			cenqueue(&cque,30);
			cenqueue(&cque,50);
			cdisplay(&cque);
		}
		else if(choice==2) {
			printf("Dequeue fn is activated\n");
			cdequeue(&cque);
			cdisplay(&cque);
		}
		else {
			break;
		}
	}
}
//implementing queues menu with function calls
void queue_fu() {
	int choices=0;
	Queue que;
	printf("Intialising a Queue\n");
	create_queue(&que);
	while(choices!=3) {
		printf(" 1.Enqueue\n 2.Dequeue\n Else. Break\n");
		printf("Enter the choices from above\n");
		scanf("%d",&choices);
		if (choices==1) {
			printf("Enqueue Fn activated\n");
			enqueue(&que,10);
			enqueue(&que,50);
			enqueue(&que,80);
			display(&que);
		}
		else if (choices==2) {
			printf("dequeue fn activated\n");
			dequeue(&que);
			display(&que);
		}
		else {
			break;
		}
	}

}
//MAIN FUNCTION...
int main() {
	int c;
	while(c>3) {
		printf("Enter choice 1 2 3 else to break\n");
		scanf("%d",&c);
		if (c==1) {
			queue_fu();
		}
		else if(c==2) {
			cqueue_fu();
		}
		else if(c==3) {
			dqueue_fu();
		}
		else {
			break;
		}
	}
	return 0;
}

