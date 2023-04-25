#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int value;
    struct tnode *next;
};

struct tnode *dodaj_na_poczatek(struct tnode *head, int val){
    struct tnode *temp = malloc(sizeof(struct tnode));
    temp -> value = val;
    temp -> next = head;
    return temp;
}

void print_list(struct tnode *elem){
    if(!elem){
        printf ("Lista jest pusta \n");
    }
    for (; elem ; elem = elem -> next ){
        printf ("%d |" , elem -> value);
    }
    printf("\n");
}

struct tnode *zwolnij(struct tnode *head){
    while(head){
        struct tnode *next = head -> next;
        free(head);
        head = next;
    }
    return NULL;
}

struct tnode *dodaj_na_koniec(struct tnode *head, int val){
    struct tnode *temp = malloc(sizeof(struct tnode));
    temp -> value = val;
    temp -> next = NULL;
    
    if(head){
        struct tnode *ele = head;
        for(; ele -> next; ele= ele -> next);
        ele -> next = temp;
    }else{
        head = temp;
    }
    return head;
}

struct tnode *dodaj_do_posortowanej_ros(struct tnode *head, int val){
    struct tnode *elem = malloc(sizeof(struct tnode));
    if(!elem){
        return head;
    }
    elem->value = val;
    elem->next = NULL;
    if(head){
        if(head->value > val){
            elem->next=head;
            head = elem;
        }else{
            struct tnode *tp = head;
            for(;tp->next && tp->next->value < val; tp = tp -> next);
            elem->next = tp->next;
            tp->next = elem;
        }
    }else{
        head = elem;
    }
    return head;
}

struct tnode *dodaj_do_posortowanej_mal(struct tnode *head, int val){
    struct tnode *elem = malloc(sizeof(struct tnode));
    if(!elem){
        return head;
    }
    elem->value = val;
    elem->next = NULL;
    if(head){
        if(head->value < val){
            elem->next=head;
            head = elem;
        }else{
            struct tnode *tp = head;
            for(;tp->next && tp->next->value > val; tp = tp -> next);
            elem->next = tp->next;
            tp->next = elem;
        }
    }else{
        head = elem;
    }
    return head;
}

struct tnode *szukaj(struct tnode *elem, int val){
    for(; elem && elem->value != val; elem = elem -> next);
    return elem;
}

struct tnode *usun(struct tnode *head, int val){
    struct tnode *cur = head;
    struct tnode *prev = NULL;
    for(; cur && cur->value != val; prev = cur, cur = cur ->next);
    
    if(!cur) return head;
    if(!prev){
        head = head -> next;
    }else{
        prev->next = cur->next;
    }
    free(cur);
    return head;
}

int main(){
    struct tnode *head = dodaj_na_poczatek(NULL, 23);
    head = dodaj_na_poczatek(head, 13);
    head = dodaj_na_poczatek(head, 67);
    head = dodaj_na_poczatek(head, 3);
    head = dodaj_na_poczatek(head, 123);
    
    print_list(head);
    
    head = zwolnij(head); //pierwsze zwolnienie
    
    printf("\n");
    print_list(head);
    
    head = dodaj_na_koniec(head, 23);
    head = dodaj_na_koniec(head, 13);
    head = dodaj_na_koniec(head, 67);
    head = dodaj_na_koniec(head, 3);
    head = dodaj_na_koniec(head, 123);
    
    print_list(head);
    printf("\n");
    
    head = zwolnij(head); //drugie zwolnienie
    
    head = dodaj_do_posortowanej_ros(NULL, 23);
    head = dodaj_do_posortowanej_ros(head, 13);
    head = dodaj_do_posortowanej_ros(head, 67);
    head = dodaj_do_posortowanej_ros(head, 3);
    head = dodaj_do_posortowanej_ros(head, 123);
    
    print_list(head);
    printf("\n");
    
    head = zwolnij(head); //trzecie zwolnienie
    
    head = dodaj_do_posortowanej_mal(NULL, 23);
    head = dodaj_do_posortowanej_mal(head, 13);
    head = dodaj_do_posortowanej_mal(head, 67);
    head = dodaj_do_posortowanej_mal(head, 3);
    head = dodaj_do_posortowanej_mal(head, 123);
    
    print_list(head);
    
    struct tnode *szukane = szukaj(head, 67);
    
    head = usun(head, szukane->value);
    
    printf("\n");
    print_list(head);
}
