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

int isPalindrome(char *text){
	char *c;
	
	struct stack *s = malloc(sizeof(*s));
	init(s);
	
	for (c = text; *c != '\0'; c++){
		push(*c,s);
	}
	
	c = text;
	int isPalindrome = 1;
	
	while (*c != '\0' && isPalindrome == 1){
		if (*c != pop(s)){
			isPalindrome = 0;
		}
		c++;
	}
	
	return isPalindrome;
}

int isBalanced(char *text){
	char *c;
	struct stack *s = malloc(sizeof(*s));
	init(s);
	
	c = text;
	int isBalanced = 1;
	
	while (*c != '\0' && isBalanced == 1){
		if (*c == '{' || *c == '(' || *c == '['){
			push(*c,s);
		}else if (*c == '}' || *c == ')' || *c == ']'){
			if (isEmpty(s) == 1){
				isBalanced = 0;
			}else if (*c == '}' && peek(s) != '{'){
				isBalanced = 0;
			}else if (*c == ')' && peek(s) != '('){
				isBalanced = 0;
			}else if (*c == ']' && peek(s) != '['){
				isBalanced = 0;
			}else{
				pop(s);
			}
		}
		c++;
	}
	
	if (isEmpty(s) == 0){
		isBalanced = 0;
	}
	
	return isBalanced;
	
}

int main()
{
	/*
	char *text = "Hello";
	printf("Is a palindrome:%d\n",isPalindrome(text));
	text = "racecar";
	printf("Is a palindrome:%d\n",isPalindrome(text));
	text = "racbecar";
	printf("Is a palindrome:%d\n",isPalindrome(text));
	text = "racebcar";
	printf("Is a palindrome:%d\n",isPalindrome(text));
	text = "mom";
	printf("Is a palindrome:%d\n",isPalindrome(text));
	*/
	
	char *text = "(a)";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "(a))";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "((a)";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "((texthere))";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "([a]";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "((a]";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "([a)]";
	printf("Is Balanced: %d\n",isBalanced(text));
	text = "([{allthebrackets}])";
	printf("Is Balanced: %d\n",isBalanced(text));
}

