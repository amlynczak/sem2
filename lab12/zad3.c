#include<stdio.h>
#include<stdarg.h>

void **va_tablice(int t1[], int t2[],...){
    int n=0;
    va_list ap;
    va_start(ap, t2);

    while(va_arg(ap, int)!= '\0'){
        n++;
    } 
    va_end(ap);
    va_start(ap, t2);

    int *tab[n];
    for(int i=0; i<n; i++){
        *tab[i] = (va_arg(ap, int));
    }
    return tab;
}

int main(){
    int tab_A[] = {3, 2, 5, 4};
    int tab_B[] = {12, 10, 13, 12, 18, 7};
    int tab_C[] = {22, 20};

    int **tab_all = va_tablice(tab_A, tab_B, tab_C);
}