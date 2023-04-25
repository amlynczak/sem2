#include<stdio.h>
#include<stdlib.h>
#include "zad3_stos.h"
#include "zad3_stos.c"


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