#include <stdio.h>

typedef struct node_t node;

typedef struct node_t {
	int value;
	node *next;
} node;

typedef struct list_t {
	node *head;
} list;

void print_list(list *l){
	for(node *i = l->head; i->next != 0; i = i->next){ 
		printf("%d ", *i);
	}
	printf("\n");
}

void insert_node(list *l, int n, int value){ // n - number of node, after wich we should insert new node with value value
	node nod = l -> head;
	for(int i = 0; i < n; i++){
	     nod = nod -> next;
	}
	new_node = (node*) malloc(sizeof(node));
	new_node = {value, nod->next};
	nod -> next = new_node;
}

e delete_node(list *l, int n){ // delete node with number n from list 
	node nod = l -> head;
	for(int i = 0; i < n - 1; i++){
		nod = nod -> next;
	}
	if(n == 0){
		l -> head = l -> head -> next;
	}
	else{
		node x = nod -> next -> next;
		free(nod -> next);
		nod -> next = x;
	}
}

int main(){	
}
