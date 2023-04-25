#include<stdio.h>

void zamiana(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    }
    
int* max_wsk(int t[], int n, int p){ //n to rozmiar tablicy, p to poczatek poszukiwania

    int *max = t+p;
    for(int i=p; i<=(n-p+1); i++){
        if(*max<t[i]) *max = t[i];
        }
    //printf("%d, %p \n", *max, max);
    return max;
    }
    
void sort(int *tab, int n){
    for(int i=1; i<n-1; i++){
        if(*max_wsk(tab, n, i) > tab[i-1]){ 
            zamiana(max_wsk(tab, n, i), tab+i-1);
            printf("a\n");
            }else{
            zamiana(max_wsk(tab, n, i), tab+i);
            printf("b\n");
            }
        
        
        
        }
    }
    

    
    
int main(){
    int tab[]={1, 4, 6, 8, 14, 11, 18, 7, 6, 10};
    //for(int i=0; i<10; i++) printf(" %d |", tab1[i]);

    int *max1 = max_wsk(tab, (sizeof tab/sizeof *tab), 1);
    printf("%d \n", *max1);
    zamiana(tab, max1);
    printf("%d \n", tab[0]); // zwraca najwieksza wartosc tablicy, ktora jest pod 0
    sort(tab, (sizeof tab/sizeof *tab));
    for(int i=0; i<10; i++) printf(" %d |", tab[i]);
    
    return 0;
    
    
    
    
    }
