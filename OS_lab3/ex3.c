#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node;

typedef struct node_t {
	int value;
	node *next;
} node;

typedef struct list_t {
	node *head;
} list;

void print_list(list *l){
	printf("OK\n");
	for(node *i = l->head; i->next != 0; i = i->next){ 
		printf("%d ", i -> value);
	}
	printf("\n");
}

void insert_node(list *l, int n, int value){ // n - number of node, after wich we should insert new node with value value
	if(l -> head == 0){
		l -> head = (node*) malloc(sizeof(node));
		return;
	}
	node *nod = l -> head;
	for(int i = 0; i < n; i++){
	     nod = nod -> next;
	}
	node *new_node = (node*) malloc(sizeof(node));
	new_node = (node *){value, nod->next};
	nod -> next = new_node;
}

void delete_node(list *l, int n){ // delete node with number n from list 
	node *nod = l -> head;
	for(int i = 0; i < n - 1; i++){
		nod = nod -> next;
	}
	if(n == 0){
		l -> head = l -> head -> next;
	}
	else{
		node *x = nod -> next -> next;
		free(nod -> next);
		nod -> next = x;
	}
}

int main(){	
	list *l;
	printf("OK1\n");
	l -> head = (node*)0;
	printf("OK2\n");
	print_list(l);
	insert_node(l, 2, 0);
	print_list(l);
	insert_node(l, 5, 0);
	print_list(l);
	insert_node(l, 3, 1);
	print_list(l);
}
