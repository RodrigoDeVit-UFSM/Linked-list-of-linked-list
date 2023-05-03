#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct onlist {
		char name[10];
		struct onlist* next;
	};

struct list{
		int info;
		struct onlist* listonlist;
		struct list* next;
	};

typedef struct list List;

List* init (void) {
	return NULL;
}

List* insert (List* l, int i)
{
	List* newnode = (List*) malloc(sizeof(List));
	newnode->info = i;
	newnode->next = l;
	struct onlist* x = (struct onlist*) malloc(sizeof(struct onlist));
	strcpy(x->name, "AAA");
	x->next = NULL;
	struct onlist* y = (struct onlist*) malloc(sizeof(struct onlist));
	strcpy(y->name, "BBB");
	y->next = x;
	struct onlist* z = (struct onlist*) malloc(sizeof(struct onlist));
	strcpy(z->name, "CCC");
	z->next = y;
	newnode->listonlist= z;
	return newnode;
}

void print (List* l) {
	for (List* p = l; p != NULL; p = p->next) {  
		printf("info = %d ", p->info);  
		struct onlist* x = p->listonlist;
		for(int i=0;i<3;i++) {
			printf("name = %s ", x->name);
			x = x->next;
		}
		puts("");
	}
	puts("");
}

int isempty (List* l) {
	if (l == NULL)
		return 1;
	else
		return 0;
}

int main (void) {
	List* l; 
	l = init(); 
	l = insert(l, 23); 
	l = insert(l, 45); 
	l = insert(l, 56); 
	l = insert(l, 78); 
	print(l); 

	return 0;
}
