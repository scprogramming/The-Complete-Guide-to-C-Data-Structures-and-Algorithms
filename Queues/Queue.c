#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct queue{
	struct node *front;
	struct node *rear;
	int size;	
};

void init(struct queue *queue){
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

void enqueue(int data, struct queue *queue){
	struct node *node = malloc(sizeof(struct node));
	node->data = data;
	
	if (queue->size == 0){
		node->next = NULL;
		queue->front = node;
		queue->rear = node;
		queue->size++;
	}else{
		node->next = NULL;
		queue->rear->next = node;
		queue->rear = node;
		queue->size++;
	}
	
}

int dequeue(struct queue *queue){

	int data = -1;
	if (queue->size != 0){
		data = queue->front->data;
		queue->front = queue->front->next;
		queue->size--;
	}else{
		printf("Cannot dequeue from empty queue!\n");
		exit(0);
	}
	
	return data;
}

int peek(struct queue *queue){

	int data = -1;
	if (queue->size != 0){
		data = queue->front->data;
	}else{
		printf("Cannot peek from empty queue!\n");
		exit(0);
	}
	
	return data;
}


void print(struct queue *queue){
	struct node *temp;
	temp = queue->front;
	
	while (temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int main(){
	
	int n;
	struct queue *q = malloc(sizeof(*q));

	init(q);

	n = 5;
	enqueue(n,q);
	n = 6;
	enqueue(n,q);
	n = 7;
	enqueue(n,q);

	print(q);
	printf("Pop: %d\n",dequeue(q));
	print(q);
	
	return 1;
}



