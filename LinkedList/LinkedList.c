#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct LinkedList{
	struct node *front;
	int size;	
};

void init(struct LinkedList *linkedlist){
	linkedlist->front = NULL;
	linkedlist->size = 0;
}

void insertFront(int data, struct LinkedList *linkedList){
	struct node *node = malloc(sizeof(struct node));
	node->data = data;
	node->next = linkedList->front;
	linkedList->front = node;
	
	linkedList->size++;
	
}	

int removeFront(struct LinkedList *linkedList){
	int data = -1;
	
	if (linkedList->size != 0){
		data = linkedList->front->data;
		linkedList->front = linkedList->front->next;
		linkedList->size--;
	}else{
		printf("Cannot remove from empty list!\n");
		exit(0);
	}
}


void insertRear(int data,struct LinkedList *linkedList){

	struct node *holder;
	struct node *node = malloc(sizeof(struct node));
	node->data = data;
	node->next = NULL;
	
	if (linkedList->size != 0){
		holder = linkedList->front;
		int i = 0;
		
		while (i != linkedList->size - 1){
			holder = holder->next;
			i++;
		}
		
		holder->next = node;
		linkedList->size++;
	}else{
		linkedList->front = node;
		linkedList->size++;
	}
	
}


int removeRear(struct LinkedList *linkedList){
	int data = -1;
	struct node *previous;
	struct node *holder;
	
	if (linkedList->size != 0){
		previous = linkedList->front;
		holder = linkedList->front;
		int i = 0;
		
		while (i != linkedList->size - 1){
			previous = holder;
			holder = holder->next;
			i++;
		}
		
		if (i == 0){
			linkedList->front = NULL;
			linkedList->size--;
		}else{
			data = holder->data;
			previous->next = NULL;
			linkedList->size--;
		}
		
	}else{
		printf("Cannot remove from empty list!\n");
		exit(0);
	}
	
	return data;
}

int contains(int item, struct LinkedList *linkedList){
	struct node *holder;
	int found = 0;
	
	holder = linkedList->front;
	
	while (holder != NULL && found == 0){
		if (holder->data == item){
			found = 1;
		}
		holder = holder->next;
	}
	
	return found;
}

void print(struct LinkedList *linkedList){
	struct node *temp;
	temp = linkedList->front;
	
	while (temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}


int main(){
	struct LinkedList *l = malloc(sizeof(*l));
	int n;
	
	init(l);
	
	n = 5;
	insertFront(n,l);
	n = 6;
	insertFront(n,l);
	n = 7;
	insertRear(n,l);
	
	print(l);
	
	printf("Found: %d\n",contains(10,l));
}




