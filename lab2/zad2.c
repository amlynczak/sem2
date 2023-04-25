#include<stdio.h>


void counting_sort(char tabA[], int rozA, int k){
    int i=0;
    char tabC[k];
    char tabB[rozA];
    while(i<=k){
        *(tabC + i) = 0;
        ++i;
        }
    i=0;
    while(i<=rozA){
        *(tabC + *(tabA + i)) = *(tabC + *(tabA + i)) + 1;
        ++i;
        }
    for(int i=0; i<(sizeof tabC/sizeof *tabC); i++) printf(" %c ", tabC[i]);
    i=1;
    while(i<= k){
        *(tabC + i) = *(tabC + i) + *(tabC + i -1);
        ++i;
        }
    for(int i=0; i<(sizeof tabC/sizeof *tabC); i++) printf(" %c ", tabC[i]);
    i=rozA;
    while(i>=1){
        *(tabB + *(tabC + *(tabA +i))) = *(tabA + i);
        *(tabC + *(tabA + i)) = *(tabC + *(tabA + i)) - 1;
        --i;
        }
    for(int i=0; i<(sizeof tabC/sizeof *tabC); i++) printf(" %c ", tabC[i]);
    }
    
int main(){
    char tab1[] = {'m', 'q', 's', 'k', 'i', 'r', 'd', 'k'};
    
    
    counting_sort(tab1, (sizeof tab1/sizeof *tab1), 4);
    
    
    }
