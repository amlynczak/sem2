#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node{
    char litera;
    struct node *next;
};

struct node *dodaj_na_poczatek(struct node *head, char val){
    struct node *temp = malloc(sizeof(struct node));
    temp -> litera= val;
    temp -> next = head;
    return temp;
}

void print_list(struct node *elem){
    if(!elem){
        printf ("Lista jest pusta \n");
    }
    for (; elem ; elem = elem -> next ){
        printf ("%c" , elem -> litera);
    }
    printf("\n");
}

struct node *odwracaj_liste(struct node *head){
    struct node *cur = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

char *zapisz_liste(struct node *head){
    struct node *elem = head; 
    int k=0;
    for(; elem; elem = elem->next){
        k++;
    }
    char *ptr = malloc(k*(sizeof(struct node)));
    for(int i=0; i<k; i++){
        *(ptr+i) = head->litera;
        head = head->next;
    }
    return ptr;
}

struct node *zwolnij(struct node *head){
    while(head){
        struct node *next = head -> next;
        free(head);
        head = next;
    }
    return NULL;
}


int main(int argc, char **argv){
    struct node *head = dodaj_na_poczatek(NULL, *argv[1]);
    for(int i=2; i<argc; i++){
        head = dodaj_na_poczatek(head, *argv[i]);
    }
    
    print_list(head);
    
    char *wyraz = zapisz_liste(head);
    
    head = odwracaj_liste(head);
    print_list(head);
    
    char *odwrot = zapisz_liste(head);
    
    //printf("%s, %s\n", wyraz, odwrot);
    
    if(strcmp(wyraz, odwrot) == 0){
        printf("\npodany wyraz to palindrom\n");
    }else{
        printf("podany wyraz nie jest palindromem\n");
    }
    
    head = zwolnij(head);
    
}
