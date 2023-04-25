#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int los(int max, int min){
    return rand()%(max-min+1) + min;   
    }

int cmp(const int *a, const int *b){
    if(*a<*b) return -1;
    if(*a>*b) return 1;
    return 0;
    }
    
int krotnosc(int a, int t[], int n){
    int k=0;
    for(int i=0; i<n; i++){
        if(t[i] == a) k++;
        }
    return k;
    }

int main(){
    srand(time(NULL));
    int n=1000, x;
    int tab[n];
    
    for(int i=0; i<n; i++){
        tab[i] = los(100, -100);
        }   
    /*for(int i=0; i<n; i++) printf("%3d ", tab[i]);
    printf("\n");*/
    
    qsort( tab, n, sizeof(*tab),(int(*)(const void*, const void*))cmp);
    /*for(int i=0; i<n; i++) printf("%3d ", tab[i]);
    printf("\n");*/
    
    printf("podaj szukana wartosc: \n");
    scanf("%d", &x);
    int *p = bsearch (&x, tab, n, sizeof(int), (int(*)(const void*, const void*))cmp);
    if(p == NULL) printf("danej wartosci nie ma w tablicy\n");
    int k = krotnosc(x, tab, sizeof(tab)/sizeof(int));
    printf("liczba wystapien liczby %d w tablicy: %d\n", x, k);
    }
