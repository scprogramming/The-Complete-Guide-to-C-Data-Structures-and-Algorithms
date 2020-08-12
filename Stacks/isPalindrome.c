#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct stack{
	struct node *top;
	int size;	
};

void init(struct stack *stack){
	stack->top = NULL;
	stack->size = 0;
}

void push(int item, struct stack *stack){

	struct node *node = malloc(sizeof(struct node));
	node->data = item;
	node->next = stack->top;
	stack->top = node;

	stack->size++;
}

int pop(struct stack *stack){
	int data = -1;

	if (stack->size != 0) {
		data = stack->top->data;
		stack->top = stack->top->next;
		stack->size--;
	}else{
		printf("Cannot pop from empty stack!\n");
		exit(0);
	}

	return data;
}

int peek(struct stack *stack){
	int data = -1;

	if (stack->size != 0) {
		data = stack->top->data;
	}else{
		printf("Cannot pop from empty stack!\n");
		exit(0);
	}

	return data;
}

int isEmpty(struct stack *stack){
	if (stack->size == 0){
		return 1;
	}else{
		return 0;
	}
}

void print(struct stack *stack){
	struct node *temp;
	temp = stack->top;

	while (temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}
int isPalindrome(char *text){
	char *t;
	int charInt;
	struct stack *s;
	init(s);

	for (t=text; *t!= '\0';t++){
		charInt = *t - '0';
		printf("%d\n",charInt);
	}
	return 0;
}


int main()
{
	char n;
	char *text = "Test\0";
	isPalindrome(text);
}


