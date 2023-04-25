#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define K 10

void wypisz_Tab(int *t, int roz){
    for(int *p = t; p < t+roz; p++){
        printf("%3d |", *p);
        }
    printf("\n");
    
    }
    
void suma_tab(int *t1, int *t2, int dl){
    int Tab[3][dl];
    for(int i=0; i<dl; i++){
        Tab[0][i] = *(t1+i);
        }
    wypisz_Tab(t1, dl);        
    for(int i=0; i<dl; i++){
        Tab[1][i] = *(t2+i);
        }
    wypisz_Tab(t2, dl);
    for(int i=0; i<dl; i++){
        Tab[2][i] = Tab[1][i] + Tab[0][i];
        printf("%3d |", Tab[2][i]);
        }
    printf("\n"); 
    /*for(int* p = Tab[2][0]; p< *(Tab[2] + roz); p++){
        printf("%3d |", *p);
        }*/
    }

int main(){
    int Tablica_1[K], Tablica_2[K];
    srand(time(NULL));
    for(int i=0; i<K; i++){
        Tablica_1[i] = rand()%50;
        Tablica_2[i] = rand()%50;
        }
        
    suma_tab(Tablica_1, Tablica_2, K);

    }
