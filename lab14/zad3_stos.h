#ifndef _STOS_H_
#define _STOS_H_
#include "zad3_stos.c"

/*typedef struct tnode
{
int value;
struct tnode * next;
}node;*/

node *insert_item_begin(node * root, int val);
void print_list(node * root);
int pop(node ** root);
node * find_in_stack(node * root, int val);