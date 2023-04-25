#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 4
#define M 5

void przesun(int n, int m, char t[n][m]){
    char t1[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            t1[i][j] = t[i][j];
            }
        }
    
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            t[i][j] = *(&t1[i][j] - 1);
            }
        }

    t[0][0] = t1[n-1][m-1];
    
    
        
    }

int main(){
    char litery[] = "qwertyuioplkjhgfdsazxcvbnm";
    char tab[N][M];
    srand(time(NULL));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tab[i][j] = litery[rand()%((sizeof(litery)/sizeof(*litery))-1)];
            }
        }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf(" %c |", tab[i][j]);
            }
        printf("\n");
        }
    printf("\n\n");
    
    przesun(N, M, tab);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf(" %c |", tab[i][j]);
            }
        printf("\n");
        }
    printf("\n");
    
    int P;
    printf("podaj liczbe przesuniec: \n");
    do{
        scanf("%d", &P);
        if(P>= N*M) printf("bledna liczba\n");
        }while(P>= N*M);
        
    for(int i=0; i<P; i++) przesun(N, M, tab);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf(" %c |", tab[i][j]);
            }
        printf("\n");
        }
    printf("\n");

    
    }
