#include<stdio.h>

int biggest(int *t, int n){
    int max=*t;
    for(int i=0; i<n; i++){
        if(*(t+i) > max) max = *(t+i);
        }
    
    return max;    
    }


int main(){
    int TAB[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    int dodatnie[] = {12, 14, 18, 35, 2, 7};
    int ujemne[] = {-4, -10, -15, -18, -22};
    int n=55, p=0, suma=0; 
    int wyniki[n]; //tablica na wszystkie mozliwe sumy spojnych fragmentow
    
    printf("dla liczb dodatnich sumuje wszystkie elementy\n");
    for(int i=0; i<(sizeof(dodatnie)/sizeof(int)); i++) printf("%d |", dodatnie[i]);
    printf("\n");
    for(int i=0; i<(sizeof(dodatnie)/sizeof(int)); i++){
        suma = suma + dodatnie[i];
        }
    printf("%d \n", suma);
    
    printf("dla liczb ujemnych wyszukuje najwiekszej wartosci\n");
    for(int i=0; i<(sizeof(ujemne)/sizeof(int)); i++) printf("%d |", ujemne[i]);
    printf("\n");
    suma = biggest(ujemne, sizeof(ujemne)/sizeof(int));
    printf("%d \n", suma);
    
    printf("testuje algorytm\n");
    for(int i=0; i<(sizeof(TAB)/sizeof(int)); i++) printf("%d |", TAB[i]);
    printf("\n");
    for(int i=0; i<10; i++){
        wyniki[p] = TAB[i];
        p++;
        suma = TAB[i];
        for(int j=1; j<10-i; j++){
            suma = suma+TAB[i+j];
            wyniki[p] = suma;
            p++;
            }
        }
    
    /*for(int i=0; i<55; i++){
        printf("%d |", wyniki[i]);
        }
    printf("\n");*/ // wypisuje sumy
    
    int x = biggest(wyniki, 55);
    printf("najwszieksza suma spjnego fragmentu: %d \n", x);
    }
