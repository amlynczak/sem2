#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10



int suma(int *t, int roz, int start, int end){
    int s=0, max = *(t+start), min = *(t+start);
    for(int i =start; i<=end && i<roz; i++){
        if(*(t+i)>max) max = *(t+i);
        if(*(t+i)<min) min = *(t+i);
        s = s + *(t+i);
        }
        
    printf("suma: %d, najwieksza wartosc: %d, najmiejsza wartosc: %d \n", s, max, min);
    
    return 0;
    }
    
    
int main(void){
    int tab[N];
    int *p = NULL;
    srand(time(NULL));
    
    for(p=tab; p < tab+N; p++){
        int s = rand()%35;
        while(s<10) s=rand()%35;
        *p = s;
        printf("%d |", *p);
        }
    printf("\n");
    
    int pocz, kon; //poczatek i koniec wyszukiwania
    
    do{
    printf("podaj indeks rozpoczecia: ");
    scanf("%d", &pocz);
    if(pocz<0 || pocz>N-1) printf("bledna wartosc \n");
    }while(pocz<0 || pocz>N-1);
    do{
    printf("podaj indeks konca: ");
    scanf("%d", &kon);
    if(kon<pocz || kon>N) printf("bledna wartosc \n");
    }while(kon<pocz || kon>N);
    suma(tab, (sizeof tab / sizeof *tab), pocz, kon);

    
    }
