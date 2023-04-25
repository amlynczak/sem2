#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct wektor_3D{
    double x;
    double y;
    double z;
    };
    
struct abc{
    struct wektor_3D wektor;
    double dlugosc;    
    };
    
double dlugosc(struct abc a){
    double dl;
    dl = sqrt(pow(a.wektor.x, 2) + pow(a.wektor.y, 2) + pow(a.wektor.z, 2));
    return dl;    
    }
    
double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
    }
    
int cmp(const void *c1, const void *c2){
    if((((struct abc *)c1) -> dlugosc) < (((struct abc *)c2) -> dlugosc)) return -1;
    if((((struct abc *)c1) -> dlugosc) > (((struct abc *)c2) -> dlugosc)) return 1;
    return 0;
    }
    
int main(){
    struct abc tab[10];
    for(int i=0; i<10; i++){
        tab[i].wektor.x = d_rand(1, 20);
        tab[i].wektor.y = d_rand(1, 20);
        tab[i].wektor.z = d_rand(1, 20);
        }
    for(int i=0; i<10; i++){
        tab[i].dlugosc = dlugosc(tab[i]);
        }
    
    for(int i=0; i<10; i++){
        printf("wektor %d: %lf, %lf, %lf; dlugosc: %lf \n", i+1, tab[i].wektor.x, tab[i].wektor.y, tab[i].wektor.z, tab[i].dlugosc);
        }
    printf("\n");
        
    qsort(tab, 10, sizeof(*tab),(int(*)(const void*, const void*))cmp);
    
    for(int i=0; i<10; i++){
        printf("wektor %d: %lf, %lf, %lf; dlugosc: %lf \n", i+1, tab[i].wektor.x, tab[i].wektor.y, tab[i].wektor.z, tab[i].dlugosc);
        }
    printf("\n");
    
    double d, t;
    printf("podaj dlugosc: ");
    scanf("%lf", &d);
    printf("podaj tolerancje: ");
    scanf("%lf", &t);
    
    double p1 = d - t/d;
    double p2 = d + t/d;
    int k1, k2;
    
    for(int i=0; i<10; i++){
        if(tab[i].dlugosc < p1) k1++;
        if(tab[i].dlugosc > p1){
            k2 = k1;
            for(int j=k1; j<10; j++){
                if(tab[j].dlugosc < p2) k2++;
                } 
            }
        }
    
    for(int i=k1; i<=k2; i++){
        printf("wektor %d: %lf, %lf, %lf; dlugosc: %lf \n", i+1, tab[i].wektor.x, tab[i].wektor.y, tab[i].wektor.z, tab[i].dlugosc);
        }
    
    
    }
