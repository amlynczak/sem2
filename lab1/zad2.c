#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float f_rand(float min, float max){
    float r = (float) rand()/RAND_MAX;
    return r*(max-min) + min;
}

float suma(int n, float t[]){
    float min = t[0];
    float max = t[0];
    float suma1 = 0;
    float srednia;
    for(int i=0; i<n; i++){
        if(t[i]>max) max = t[i];
        if(t[i]<min) min = t[i];
        suma1 = suma1 + t[i];
        } 
    srednia = suma1/n;
    
    float max_od = fabs(t[0]-srednia), min_od = fabs(t[0]-srednia);
    for(int i=0; i<n; i++){
        if(fabs(t[i]-srednia)<min_od) min_od = fabs(t[i]-srednia);
        if(fabs(t[i]-srednia)>max_od) max_od = fabs(t[i]-srednia);
        }
    
    printf("suma: %f, \nsrednia: %f, \nwartosc minimalna: %f, \nwartosc maksymalna: %f, \nminimalne odchylenie: %f, \nmaksymalne odchylenie: %f \n", suma1, srednia, min, max, min_od, max_od);
    return 0;
    }

float suma_wsk(int n, float *t){
    float min = *t;
    float max = *t;
    float suma1 = 0;
    float srednia;
    for(int i=0; i<n; i++){
        if(*t>max) max = *t;
        if(*t<min) min = *t;
        suma1 = suma1 + *t;
        t++;
        }
    srednia = suma1/n;
    //float max_od = fabs(t*-srednia), min_od = fabs(t*-srednia);
    printf("suma: %f, \nsrednia: %f, \nwartosc minimalna: %f, \nwartosc maksymalna: %f\n", suma1, srednia, min, max);
    return 0;
    
    
    }


int main(){
    float tab[15];
    srand(time(0));
    for(int i=0; i<15; i++){
        tab[i] = f_rand(4.0, 20.0);
        }    
    for(int i=0; i<15; i++)printf("| %f |", tab[i]);
    printf("\n");
    
    suma(4, tab);
    suma_wsk(4, tab);
    
    }
