#include<stdio.h>
#include<time.h>
#include<stdlib.h>




int main(){
    srand(time(NULL));
    int k, n;
    k = rand()%20 + 5;
    n = rand()%20 + 5;
    int Tab_1[n], Tab_2[k];
    
    for(int i=0; i<n; i++){
        do{
            Tab_1[i] = rand()%10;
            }while(Tab_1[i]<Tab_1[i-1]);
        }
    
    for(int i=0; i<k; i++){
        do{
            Tab_2[i] = rand()%10;
            }while(Tab_2[i]<Tab_2[i-1]);
        }
        
    for(int i=0; i<n; i++) printf(" %d |", Tab_1[i]);
    printf("\n");
    
    for(int i=0; i<k; i++) printf(" %d |", Tab_2[i]);  
    printf("\n");
    
    int powt_1=0, powt_2=0;
    
    for(int i=0; i<n-1; i++){
        if(Tab_1[i] == Tab_1[i+1]) powt_1++;
        }
        
    for(int i=0; i<k-1; i++){
        if(Tab_2[i] == Tab_2[i+1]) powt_2++;
        }
    
    int roz = (n-powt_1) + (k-powt_2);
    int Tab_wyn[roz];
    int *p1 = Tab_1, *p2 = Tab_2;
    int j=0;
    
    while(*p1 != '\0' || *p2 != '\0'){
        if(*p1 < *p2){
            Tab_wyn[j] = *p1;
            p1++;
            j++;
            }
        if(*p2 < *p1){
            Tab_wyn[j] = *p2;
            p2++;
            j++;
            }
        }
        
    for(int i=0; i<roz; i++) printf(" %d |", Tab_wyn[i]);
    printf("\n");
    
    }
