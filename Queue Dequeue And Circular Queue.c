/*
this prg is to implement a normal queue circular queue
implement queue using struct
the functions are isempty() isful() enqueue() dequeue() peek() display()
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
#define SIZE 5
typedef struct {
	int rear;
	int front;
	int arr[MAX];
} queue_1,cqueue_1,dqueue_1;

void create_queue(queue_1 *q) {
	q->front=-1;
	q->rear=-1;
}

bool isempty(queue_1 *q) {
	return q->front==-1;
}

bool isfull(queue_1 *q) {
	return q->rear==MAX-1;
}

void enqueue(queue_1 *q,int item) {
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
int dequeue(queue_1 *q) {
	int item;
	if (isempty(q)) {
		printf("Queue is empty...\n");
	}
	item=q->arr[q->front];
	q->front++;
	if (q->front >q->rear) {
		q->front=q->rear=1;
	}
	return item;
}

void display(queue_1 *q) {
	if (isempty(q)) {
		printf("Queue Is empty\n");
		return;
	}
	for(int i=q->front; i<=q->rear; i++) {
		printf("%d\t",q->arr[i]);
	}
	printf("\n");
}

void queue_fu() {
	int choices=0;
	queue_1 que;
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


void create_cqueue(cqueue_1 *cq) {
	cq->front=-1;
	cq->rear=-1;
}

bool issfull(cqueue_1 *cq) {
	return ((cq->rear+1)%SIZE==cq->front);
}
bool issempty(cqueue_1 *cq) {
	return cq->front==-1;
}

void cenqueue(cqueue_1 *cq,int item) {
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
int cdequeue(cqueue_1 *cq) {
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
void cdisplay(cqueue_1 *cq) {
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
			for(int i=cq->front; i<MAX; i++) {
				printf("%d\n",cq->arr[i]);
			}
			for(int i=0; i<=cq->rear; i++) {
				printf("%d\n",cq->arr[i]);
			}
		}
	}

}

void cqueue_fu() {
	cqueue_1 cque;
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

//double ended queue started here
void create_dqueue(dqueue_1 *dq) {
	dq->front=-1;
	dq->rear=-1;
}
void insert_at_fr(dqueue_1 *dq,int value) {
	if((dq->front==0 && dq->rear==MAX-1)||(dq->front==dq->rear)) {
		printf("Deque overflowing...\n");
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
void insert_at_rr(dqueue_1 *dq,int value) {
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

int deletefront(queue_1 *dq) {
	if (dq->front==-1) {
		printf("Deque underflow \n");
		return -1;
	}
	else {
		int value   =dq->arr[dq->front];
		if(dq->front=dq->rear) {
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

int deleterear(queue_1 *dq) {
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

void ddisplay(dqueue_1 *dq) {
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

void dqueue_fu() {
	dqueue_1 dque;
	int choic=0;
	create_dqueue(&dque);
	while(choic!=3) {
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


void main() {
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

}