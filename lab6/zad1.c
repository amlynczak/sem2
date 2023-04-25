#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

void pierw(char t[], int n){
    *t = '0';
    *(t+1) = '0';
        for(int i=2; i<n; i++){
            if(*(t+i) != '0'){
                for(int j=i+1; j<n; j++){
                    if(j%i == 0) *(t+j) = '0';
                    }
                }
            }
    }





int main(){
    int n;
    printf("podaj zakres gorny poszukiwan: \n");
    scanf("%d", &n);
    
    char *ptr = malloc(n*sizeof(char));
    memset(ptr, '1', n*sizeof(char));
    
    /*for(int i=0; i<n; i++){
        printf("%c |", *(ptr+i));
    }
    printf("\n");*/
    
    pierw(ptr, n);
    
    for(int i=0; i<n; i++){
        printf("%c |", *(ptr+i));
    }
    printf("\n"); //wypisuje 1 tam gdzie jest liczba pierwsza
    
    int k=0;
    for(int i=0; i<n; i++){
        if(*(ptr+i) == '1') k++;
        } //zlicza ile jest liczb pierwszych
    
    int num[k], p=0;
    
    for(int i=0; i<n; i++){
        if(*(ptr+i) == '1'){
            num[p] = i;
            p++;
            }
        }// wypelnia tablice num liczbami pierwsszymi
    
    printf("w danym przedziale jest %d liczb pierwszych. \nSa to:\n", k);
    for(int i=0; i<k; i++){
        printf(" %d ", num[i]);
        }
    printf("\n");
    
    
    
    }
