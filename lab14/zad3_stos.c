#include<stdio.h>
#include<stdlib.h>

typedef struct tnode {
 int value;
 struct tnode *next;
}node;

node *insert_item_begin (node * top, int val){
    node *new_top = malloc(sizeof(node));
    new_top->next=top;
    new_top->value = val;
    return new_top;
};
void print_list (node *top) {
    printf("Lista od poczatku -> {");
    for(top; top; top = top->next){
        printf("%d, ", top->value);
    }
    printf("}\n");
};
int pop (node **p){
    node *top = *p;
    *p = top->next;
    free(top);
};