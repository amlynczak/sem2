#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct liczba{
    char znak;
    union{
        int i;
        double d;
        }liczba;
    };
    
int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
    }
    
double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}

void wypisz(struct liczba a[], int n){
    for(int i=0; i<n; i++){
        if(a[i].znak == 'i') printf("int: %d |", a[i].liczba.i);
        if(a[i].znak == 'd') printf("double: %lf |", a[i].liczba.d);
        if((i+1)%5 == 0) printf("\n");
        }
    printf("\n");
    }
    
int cmp(const void *c1, const void *c2){
    if(((struct liczba*)c1)->znak == ((struct liczba*)c2)->znak){
        if(((struct liczba*)c1)->znak == 'i'){
            if(((struct liczba*)c1)->liczba.i > ((struct liczba*)c2)->liczba.i) return 1;
            if(((struct liczba*)c1)->liczba.i < ((struct liczba*)c2)->liczba.i) return -1;
            return 0;
            }
        if(((struct liczba*)c1)->znak == 'd'){
            if(((struct liczba*)c1)->liczba.d > ((struct liczba*)c2)->liczba.d) return -1;
            if(((struct liczba*)c1)->liczba.d < ((struct liczba*)c2)->liczba.d) return 1;
            return 0;
            }
        }else{
            if(((struct liczba*)c1)->znak == 'i') return -1;
            if(((struct liczba*)c1)->znak == 'd') return 1;
            return 0;
            }
    return 0;
    }
    
int main(){
    srand(time(NULL));
    struct liczba tab[100];
    int los;
    for(int i=0; i<100; i++){
        los = rand()%2;
        if(los == 0){
            tab[i].znak = 'i';
            tab[i].liczba.i = i_rand(-5, 5);
            }
        if(los == 1){
            tab[i].znak = 'd';
            tab[i].liczba.d = d_rand(-5, 5);
            }
        }
        
    wypisz(tab, 100);
    printf("\n");
    
    qsort(tab, sizeof(tab)/sizeof(*tab), sizeof(*tab), cmp);
    
    wypisz(tab, 100);
    
    }
