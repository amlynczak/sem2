#include <stdio.h>
#include <malloc.h>
#define PUSH insert_item_begin

typedef struct tnode {
 int value;
 struct tnode *next;
}node;

node * insert_item_begin (node * top, int val){
    node *new_top = malloc(sizeof(node));
    new_top->next=top;
    new_top->value = val;
    return new_top;
};
void print_list (node *top) {
    printf("Lista od poczatku -> {");
    for (top; top; top = top->next)
        printf("%d, ", top->value);
    printf("}\n");
};
int pop (node **p){
    node *top = *p;
    *p = top->next;
    free(top);
};

int main(int argc, char *argv[]){
	node *top=NULL;

	printf("Wstawiam elementy na stos.\n");
	top=PUSH(top, 8);
	top=PUSH(top, 23);
	top=PUSH(top, 123);
	printf("Wypisuje zawartosc stosu.\n");
    print_list(top);
    printf("Usuwam elementy ze stosu.\n");
    pop(&top);
    printf("Wypisuje zawartosc stosu.\n");
    print_list(top);
    pop(&top);
    printf("Wypisuje zawartosc stosu.\n");
    print_list(top);
    printf("Wstawiam element na stos element 1223.\n");
    top=PUSH(top, 1223);
    printf("Wstawiam element na stos element 12.\n");
    top=PUSH(top, 12);
    printf("Wstawiam element na stos element 787.\n");
    top=PUSH(top, 787);
    printf("Wypisuje zawartosc stosu.\n");
    print_list(top);
}
