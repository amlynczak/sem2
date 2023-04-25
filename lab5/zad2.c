#include<stdio.h>

int main(){
    int T[4][2];
    int k=4;
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            T[i][j] = k;
            k = k+2;
            }
        }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf(" %d |", *(T[i]+j));
            }
        printf("\n");
        }
    printf("\n\n"); 
    
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf(" %p |", T[i]+j);
            }
        printf("\n");
        }
    printf("\n\n"); // wypisanie za pomoca T[i] + j
    
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf(" %d |", *(*(T+i)+j));
            }
        printf("\n");
        }
    printf("\n\n");
    
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf(" %p |", (*(T+i)+j));
            }
        printf("\n");
        }
    printf("\n\n"); //wypisanie za pomoca *(T+i)+j
    
    /*int *(ws_T_2D) = T[0];
    //ws_T_2D = T;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf(" %d |", *(*(ws_T_2D +i)+j));
            }
        printf("\n");
        }
    printf("\n\n");
    
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf(" %p |", (*(ws_T_2D+i)+j));
            }
        printf("\n");
        }
    printf("\n\n");*/ //tutaj wskaznik na 2D nie dzialal
    
    int *ws_T_1D = T[2]; 
    
    for(int i=0; i<2; i++){
        printf(" %d |", *(ws_T_1D + i));
        }
    printf("\n\n");
    
    for(int i=0; i<2; i++){
        printf(" %p |", (ws_T_1D + i));
        }
    printf("\n\n");
    
    
    for(int i=0; i<4; i++){
        ws_T_1D = T[i];
        for(int j=0; j<2; j++){
            printf(" %d |", *(ws_T_1D + j));
            }
        printf("\n");
        }
    printf("\n\n");    
    
    for(int i=0; i<4; i++){
        ws_T_1D = T[i];
        for(int j=0; j<2; j++){
            printf(" %p |", (ws_T_1D + j));
            }
        printf("\n");
        }
    printf("\n\n");  
        
        
        
        
        
    }
