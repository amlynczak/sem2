#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode{
    char *slowo;
    int licznik;
    struct tnode *next;
};

struct tnode *dodaj_do_posortowanej_ros(struct tnode *head, char *val){
    struct tnode *elem = malloc(sizeof(struct tnode));
    if(!elem){
        return head;
    }
    elem->slowo= val;
    elem->next = NULL;
    if(head){
        if(strcmp(head->slowo, val) == 1){
            elem->next=head;
            head = elem;
        }else if(strcmp(head->slowo, val) == 0){
            (head->licznik)++;
        }else{
            struct tnode *tp = head;
            for(;tp->next && strcmp(tp->next->slowo, val) == -1; tp = tp -> next);
            elem->next = tp->next;
            tp->next = elem;
        }
    }else{
        head = elem;
    }
    return head;
}

void print_list(struct tnode *elem){
    if(!elem){
        printf ("Lista jest pusta \n");
    }
    for (; elem ; elem = elem -> next ){
        printf ("%s" , elem -> slowo);
    }
    printf("\n");
}

struct node *zwolnij(struct tnode *head){
    while(head){
        struct tnode *next = head -> next;
        free(head);
        head = next;
    }
    return NULL;
}


int main(){
    struct tnode *head;
    char *dane_slowo = malloc(100);
    FILE *fp = fopen("plik_wejsciowy.txt", "r");
    if(!fp){
        printf("blad odczytu");
    }else{
        while(fscanf(fp, "%s ", dane_slowo)!= EOF){
            head = dodaj_do_posortowanej_ros(head, dane_slowo);
            free(dane_slowo);
            dane_slowo = malloc(100);
        }
    }
    free(dane_slowo);
    fclose(fp);

    print_list(head);

    FILE *wyjscie = fopen("plik_wyjsciowy.txt", "w");
    if(!wyjscie){
        printf("blad odczytu\n");
    }else{
        struct tnode *temp = head;
        while(temp){
            fprintf(wyjscie, "%s :%d \n", temp->slowo, temp->licznik);
            temp = temp->next;
        }
    }
    fclose(wyjscie);
    zwolnij(head);



}
