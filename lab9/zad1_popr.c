#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Klient{
    char imie[20];
    char nazwisko[20];
    char kod[6];
    int wiek;
    };

int crtr_cmp1 (const void *c1 , const void *c2 ){
    if(strcmp(((struct Klient*)c1)->nazwisko,((struct Klient*)c2)->nazwisko)==0){
        return strcmp((( struct Klient *)c1)->imie, ((struct Klient *)c2)->imie);
    }else{
        return strcmp((( struct Klient *)c1)->nazwisko, ((struct Klient *)c2)->nazwisko);
    }
}



int main(){
    
    struct Klient tab[] = {{"Jan", "Kowalski", "34-650", 28},{"Jakub", "Nowak", "23-420", 23},
        {"Piotr", "Curie", "12-345", 65},{"Maria", "Curie", "12-654", 23},{"Adam", "Moneta", "56-876", 88}};
    
    /*struct tab[0] = {"Jan", "Kowalski", "34-650", 28};
    Klient tab[1] = {"Jakub", "Nowak", "23-420", 23};
    Klient tab[2] = {"Piotr", "Curie", "12-345", 65};
    KLient tab[3] = {"Maria", "Curie", "12-654", 23};
    Klient tab[4] = {"Adam", "Moneta", "56-876", 88};*/
    
    
    for(int i=0; i<5; i++){
        printf("%s %s %s %d \n", tab[i].imie, tab[i].nazwisko, tab[i].kod, tab[i].wiek);
        }
    printf("\n");
    
    qsort (tab, sizeof(tab)/sizeof(*tab), sizeof(*tab), crtr_cmp1);

    for(int i=0; i<5; i++){
        printf("%s %s %s %d \n", tab[i].imie, tab[i].nazwisko, tab[i].kod, tab[i].wiek);
        }
        
    }
