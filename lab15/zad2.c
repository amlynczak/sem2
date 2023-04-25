#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

float f_rand(float min, float max){
    float r = (float) rand()/RAND_MAX;
    return r*(max-min) + min;
}

int main(){
    srand(time(NULL));
    float tab[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tab[i][j] = f_rand(1, 100);
        }
    }
    /*for(int i=0; i<N; i=i+50){
        for(int j=0; j<N; j++){
            printf("%f |", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    
    FILE *fp1 = fopen("plik.bin", "wb+");
    if(!fp1){
        printf("nie mozna utworzyc pliku binarnego");
    }else{
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                fprintf(fp1,"%f ",tab[i][j]);
            }
            fprintf(fp1,"\n");
        }
    }

    int lenght_fp1 = ftell(fp1);
    printf("dlugosci pliku binarnego: %d\n", lenght_fp1);

    fclose(fp1);
    
    FILE *fp2 = fopen("plik.txt", "w+");
    if(!fp2){
        printf("nie mozna utworzyc pliku tekstowego");
    }else{
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                fprintf(fp2,"%f ",tab[i][j]);
            }
            fprintf(fp2,"\n");
        }
    }

    int lenght_fp2 = ftell(fp2);
    printf("dlugosc pliku tekstowego: %d\n", lenght_fp2);
    fclose(fp2);
        
    fp1 = fopen("plik.bin", "wb+");
    float temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            fscanf(fp1, "%f", &temp);
            /*printf("%f |", temp);*/
        }
    }
    fclose(fp1);

    fp2 = fopen("plik.txt", "wb+");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            fscanf(fp2, "%f", &temp);
            /*printf("%f |", temp);*/
        }
    }
    fclose(fp2);

    fp1 = fopen("plik.bin", "wb+");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j){
                fprintf(fp1, "%d", 0);
            }
        }
    }
    fclose(fp1);
    
    
}
