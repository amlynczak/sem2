#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float f_rand(float min, float max){
    float r = (float) rand()/RAND_MAX;
    return r*(max-min) + min;
}

float fun_srednia(float t[], int n){
    float srednia = 0;
    for(int i=0; i<n; i++){
        srednia = srednia + t[i];
    }
    return srednia/n;
}

struct elast_tab{
    int licznik;
    float wyn_srednia;
    float (*wsk_fun_srednia)(float);
    float wyniki[];
};

struct elast_tab *alokacja(int n){
    int x = sizeof(int) + sizeof(float)*(n+2);
    struct elast_tab *wsk = malloc(100);
    return wsk;
}

int main(){
    srand(time(NULL));
    int dlugosci_eleast[]={10, 4, 5, 4, 7};

    struct elast_tab *Tab_wsk_elast[5];
    for(int i=0; i<5; i++){
        Tab_wsk_elast[i] = alokacja(dlugosci_eleast[i]);
        (*Tab_wsk_elast[i]).licznik = dlugosci_eleast[i];
        for(int j=0; j<dlugosci_eleast[i]; j++){
            (*Tab_wsk_elast[i]).wyniki[j] = f_rand(0,100);
        }
        (*Tab_wsk_elast[i]).wyn_srednia = fun_srednia((*Tab_wsk_elast[i]).wyniki, (*Tab_wsk_elast[i]).licznik);
    }

    for(int i=0; i<5; i++){
        printf("struct %d \n", i+1);
        printf("liczba danych w tablicy: %d\n", (*Tab_wsk_elast[i]).licznik);
        printf("tablica wyniki:\n" );
        for(int j=0; j<dlugosci_eleast[i]; j++){
            printf("%f |", (*Tab_wsk_elast[i]).wyniki[j]);
        }
        printf("\n");
        printf("sredni wynik: %f", (*Tab_wsk_elast[i]).wyn_srednia);
        printf("\n");
    }
    

}