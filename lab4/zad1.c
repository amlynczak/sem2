#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sumy_i(int n, int t[n][n]){
    int sum_all = 0, sum_down = 0, sum_up = 0, sum_diag = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum_all = sum_all + t[i][j];
            }
       }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            sum_down = sum_down + t[i][j];
            }
        }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum_up = sum_up + t[i][j];
            }
        }
    for(int i=0; i<n; i++){
        sum_diag = sum_diag + t[i][i];
        } 
    printf("suma wszystkich: %d, \nsuma dolnych: %d, \nsuma gornych: %d, \nsuma przekatnej: %d\n", sum_all, sum_down, sum_up, sum_diag);
    }

/*void sumy_wsk(int n, int t[n][n]){
    int sum_all = 0, sum_down = 0, sum_up = 0, sum_diag = 0;
    int *(*p) = t;
    for( ;*(*p) != '\0'; p++){
        sum_all = sum_all + *(*p);
        }
    printf("%d\n", sum_all);
    
    
    }*/




int main(){
    srand(time(NULL));
    int roz, min, max;
    printf("podaj rozmiar tablicy: \n");
    scanf("%d", &roz);
    printf("podaj przedzial liczb wpisywanych w tablice: \n");
    scanf("%d %d", &min, &max);
    int tab[roz][roz];
    for(int i=0; i<roz; i++){
        for(int j=0; j<roz; j++){
            do{
                tab[i][j] = rand()%max;
                }while(tab[i][j] < min);
            printf("%d |", tab[i][j]);
            }
        printf("\n");
        }
    printf("\n");
    sumy_i(roz, tab);
    //sumy_wsk(roz, tab);
    }
    
