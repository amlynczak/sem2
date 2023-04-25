#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fun(char t[], char z, int n, int k){
    int x=0;
    for(int i=n; i<k; i++){
        if(z == t[i]){
            x++;
            printf("indeks: %d \n", i);
            }
        }
    printf("krotnosc: %d \n", x);
        
    
    }


int main(){
    srand(time(NULL));
    int N, k;
    char all[] = "()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}";
    char znaki[N];
    int min, max;
    
    printf("podaj dlugosc tablicy: \n");
    scanf("%d", &N);
    printf("podaj zakres: \n");
    scanf("%d %d", &min, &max);
    
    for(int i=0; i<N; i++){
        do{
            k = rand()%max;
            }while(k<min);
        znaki[i] = all[k];
        printf("%c ", znaki[i]);
        }
    printf("\n");
    
    fun(znaki, 'I' , 2, 5);
    }
