#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
    int value;
    struct tnode *next;
} node;

node *dodaj_na_poczatek(node **head, int val){
    node *temp = malloc(sizeof(node));
    temp -> value = val;
    temp -> next = *head;
    return temp;
}

void print_list(node *elem){
    if(!elem){
        printf ("Lista jest pusta \n");
    }
    for (; elem ; elem = elem -> next ){
        printf ("%d |" , elem -> value);
    }
    printf("\n");
}

node *zwolnij(node **head){
    while(*head){
        node *next = (*head) -> next;
        free(*head);
        *head = next;
    }
    return NULL;
}

node *dodaj_na_koniec(node **head, int val){
    node *temp = malloc(sizeof(node));
    temp -> value = val;
    temp -> next = NULL;
    
    if(*head){
        node *ele = *head;
        for(; ele -> next; ele= ele -> next);
        ele -> next = temp;
    }else{
        *head = temp;
    }
    return *head;
}

node *dodaj_do_posortowanej_ros(node **head, int val){
    node *elem = malloc(sizeof(node));
    if(!elem){
        return *head;
    }
    elem->value = val;
    elem->next = NULL;
    if(*head){
        if((*head)->value > val){
            elem->next=*head;
            *head = elem;
        }else{
            node *tp = *head;
            for(;tp->next && tp->next->value < val; tp = tp -> next);
            elem->next = tp->next;
            tp->next = elem;
        }
    }else{
        *head = elem;
    }
    return *head;
}

node *dodaj_do_posortowanej_mal(node **head, int val){
    node *elem = malloc(sizeof(node));
    if(!elem){
        return *head;
    }
    elem->value = val;
    elem->next = NULL;
    if(*head){
        if((*head)->value < val){
            elem->next=*head;
            *head = elem;
        }else{
            node *tp = *head;
            for(;tp->next && tp->next->value > val; tp = tp -> next);
            elem->next = tp->next;
            tp->next = elem;
        }
    }else{
        *head = elem;
    }
    return *head;
}

node *szukaj(node *elem, int val){
    for(; elem && elem->value != val; elem = elem -> next);
    return elem;
}

node *usun(struct tnode **head, int val){
    struct tnode *cur = *head;
    struct tnode *prev = NULL;
    for(; cur && cur->value != val; prev = cur, cur = cur ->next);
    
    if(!cur) return *head;
    if(!prev){
        *head = (*head) -> next;
    }else{
        prev->next = cur->next;
    }
    free(cur);
    return *head;
}

int main(){
    node **head;
    *head = dodaj_na_poczatek(head, 23);
    *head = dodaj_na_poczatek(head, 13);
    *head = dodaj_na_poczatek(head, 67);
    *head = dodaj_na_poczatek(head, 3);
    *head = dodaj_na_poczatek(head, 123);
    
    print_list(*head);
    
    *head = zwolnij(head); //pierwsze zwolnienie
    
    printf("\n");
    print_list(*head);
    
    *head = dodaj_na_koniec(head, 23);
    *head = dodaj_na_koniec(head, 13);
    *head = dodaj_na_koniec(head, 67);
    *head = dodaj_na_koniec(head, 3);
    *head = dodaj_na_koniec(head, 123);
    
    print_list(*head);
    printf("\n");
    
    *head = zwolnij(head); //drugie zwolnienie
    
    *head = dodaj_do_posortowanej_ros(NULL, 23);
    *head = dodaj_do_posortowanej_ros(head, 13);
    *head = dodaj_do_posortowanej_ros(head, 67);
    *head = dodaj_do_posortowanej_ros(head, 3);
    *head = dodaj_do_posortowanej_ros(head, 123);
    
    print_list(*head);
    printf("\n");
    
    *head = zwolnij(head); //trzecie zwolnienie
    
    *head = dodaj_do_posortowanej_mal(NULL, 23);
    *head = dodaj_do_posortowanej_mal(head, 13);
    *head = dodaj_do_posortowanej_mal(head, 67);
    *head = dodaj_do_posortowanej_mal(head, 3);
    *head = dodaj_do_posortowanej_mal(head, 123);
    
    print_list(*head);
    
    node *szukane = szukaj(*head, 67);
    
    *head = usun(head, szukane->value);
    
    printf("\n");
    print_list(*head);
    
    *head = zwolnij(head);
}
