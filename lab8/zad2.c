#include<stdio.h>

int add2(int *a, int *b){
    return *a + *b;    
    }
    
int comp2(int *a, int *b){
    if(*a > *b) return *a;
    if(*a < *b) return *b;
    return *a;    
    }
    
int add2_or_comp2(int a, int b, int(*f)(int *x, int *y)){
    int k = (*f)(&a, &b);
    return k;
    }
    
int main(){
    int x, y;
    printf("podaj dwie wartosci\n");
    scanf("%d %d", &x, &y);
    
    int dodaj = add2_or_comp2(x, y, add2);
    printf("z funkcja add2: %d\n", dodaj);
    
    int porownaj = add2_or_comp2(x, y, comp2);
    printf("z funckja comp2: %d\n", porownaj);
    
    
    }
