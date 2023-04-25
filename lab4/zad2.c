#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mnozenie(int n, int t1[n][n], int t2[n][n]){
    int t3[n][n];
    for(int i=0; i<n; i++){
        int wyn=0, tmp=0;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                tmp = t1[i][j] * t2[j][k];
                wyn = wyn + tmp;
                }
            t3[i][j] = wyn;
            }
        }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d |", t3[i][j]);
            }
        printf("\n");    
        }
    printf("\n");
    }



int main(){
    //srand(time(NULL));
    int tab1[4][4], tab2[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
                tab1[i][j] = rand()%4;
                tab1[i][j] = tab1[i][j];
            printf(" %d |", tab1[i][j]);
            }
        printf("\n");
        }
    printf("\n\n");
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
                tab2[i][j] = rand()%4;
            printf(" %d |", tab2[i][j]);
            }
        printf("\n");
        }
    printf("\n\n");
    
    mnozenie(4, tab1, tab2);
          
}
