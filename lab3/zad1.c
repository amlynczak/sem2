#include<stdio.h>
#include<string.h>

void wytnij(char *t1, char *t2, int roz1, int roz2){
    printf("tekst 1: %s \n", t1);
    printf("tekst 2: %s \n", t2);
    for(int i=0; i<roz2; i++){
        for(int j=0; j<roz1; j++){
            if(*(t1+j) == *(t2+i)){
                *(t1+j) = ' ';
                }
            }
        }
    
    printf("tekst po usunieciu: %s \n", t1);
    }
    
    
int main(){
    char tekst1[] = "abacadaeafaaa";
    char tekst2[] = "bcdef";
    
    wytnij(tekst1, tekst2, (sizeof tekst1/sizeof *tekst1), (sizeof tekst2/sizeof *tekst2));
    }
