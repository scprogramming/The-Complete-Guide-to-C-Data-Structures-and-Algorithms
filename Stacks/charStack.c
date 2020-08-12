#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
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

void push(char item, struct stack *stack){

	struct node *node = malloc(sizeof(struct node));
	node->data = item;
	node->next = stack->top;
	stack->top = node;

	stack->size++;
}

char pop(struct stack *stack){
	char data;

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

char peek(struct stack *stack){
	char data;

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
		printf("%c\n",temp->data);
		temp = temp->next;
	}
}

int main()
{
	char n;
	struct stack *s = malloc(sizeof(*s));

	init(s);

	n = 'A';
	push(n,s);
	n = 'B';
	push(n,s);
	n = 'C';
	push(n,s);

	printf("Peek:%c\n",peek(s));
	print(s);
	printf("Pop:%c\n",pop(s));
	print(s);
	printf("IsEmpty:%d\n",isEmpty(s));
}

