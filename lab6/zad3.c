#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int sort(const int *a, const int *b){
    if(*a<*b) return -1;
    if(*a>*b) return 1;
    return 0;
    }
    
/*void normalizacja(int t[], int n, int k){
    float tab[n][k];
    int suma=0;
    for(int i=0; i<n*k; i++){
        suma = suma + *(t+i);
        }
    for(int i=0; i<n*k; i++){
        *(tab + i) = (float)(*(t+i))/(float)suma;
        }
    for(int i=0; i<n*k; i++){
        printf("%d |", *(tab+i));
        }
    printf("\n");    
        
    }*/


int main(int argc, char **argv){
    int n1 = atoi(argv[1]), n2 = atoi(argv[2]); //rozmiar tablicy
    int min = atoi(argv[3]), max = atoi(argv[4]); //przedzial losowania
    
    int *ptr = malloc(n1*n2*sizeof(int));
    
    srand(time(NULL));
    
    for(int i=0; i<n1*n2; i++){
        *(ptr+i) = rand()%(max-min+1) + min;
        }
    
    for(int i=0; i<n1*n2; i++){
        printf("%d |", *(ptr+i));
        }
    printf("\n");
    
    
    qsort(ptr, n1*n2, sizeof(int), ( int( * )( const void *, const void * ) ) sort);
    
    for(int i=0; i<n1*n2; i++){
        printf("%d |", *(ptr+i));
        }
    printf("\n");
    
    //normalizacja(ptr, n1, n2); //funkcjia nie dziala
    }
