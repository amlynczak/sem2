#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct point{
    double x;    
    double y;
    };
    
struct vert_AC{
    struct point A;
    struct point C;
    };
    
struct rect{
    struct vert_AC przekatna;
    double pole;
    double obwod;    
    };
    
double rect_per(struct vert_AC a){
    double obw;
    obw = 2*fabs(a.A.x - a.C.x) + 2*fabs(a.A.y - a.C.y);
    return obw;
    }
    
double rect_area(struct vert_AC a){
    double pole;
    pole = fabs(a.A.x - a.C.x)*fabs(a.A.y - a.C.y);
    return pole;    
    }
    
void fill_tab(struct rect *a){
    ((struct rect *)a)->pole = rect_area(((struct rect *)a) -> przekatna);
    ((struct rect *)a)->obwod = rect_per(((struct rect *)a) -> przekatna);   
    }
    
double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
    }
    
void sort(struct rect *a, int size){
    struct rect temp;
    struct rect min = *a;
    int k;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            if(a[j].pole < min.pole){
                min = a[j];
                k = j;
                }
            if(a[j].pole == min.pole){
                if(a[j].obwod < min.obwod){
                    min = a[j];
                    k = j;
                    }
                }
            }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
        }
    
    
    }
    
int main(int argc, char *argv[]){
    srand(time(NULL));
    int n = atoi(argv[1]);
    struct rect tab_rect[n];
    
    for(int i=0; i<n; i++){
        tab_rect[i].przekatna.A.x = d_rand(1, 100);
        tab_rect[i].przekatna.A.y = d_rand(1, 100);
        tab_rect[i].przekatna.C.x = d_rand(1, 100);
        tab_rect[i].przekatna.C.y = d_rand(1, 100);
        }
        
    for(int i=0; i<n; i++){
        fill_tab(&tab_rect[i]);
        }
        
    for(int i=0; i<n; i++){
        printf("prostokat numer %d: \n", i+1);
        printf(" punkt A: %lf, %lf |", tab_rect[i].przekatna.A.x, tab_rect[i].przekatna.A.y);
        printf(" punkt B: %lf, %lf |", tab_rect[i].przekatna.C.x, tab_rect[i].przekatna.A.y);
        printf(" punkt C: %lf, %lf |", tab_rect[i].przekatna.C.x, tab_rect[i].przekatna.C.y);
        printf(" punkt D: %lf, %lf \n", tab_rect[i].przekatna.A.x, tab_rect[i].przekatna.C.y);
        printf("pole: %lf, obwod: %lf \n\n", tab_rect[i].pole, tab_rect[i].obwod);
        }
        
    sort(tab_rect, sizeof(tab_rect)/sizeof(*tab_rect));
    
    for(int i=0; i<n; i++){
        printf("prostokat numer %d: \n", i+1);
        printf(" punkt A: %lf, %lf |", tab_rect[i].przekatna.A.x, tab_rect[i].przekatna.A.y);
        printf(" punkt B: %lf, %lf |", tab_rect[i].przekatna.C.x, tab_rect[i].przekatna.A.y);
        printf(" punkt C: %lf, %lf |", tab_rect[i].przekatna.C.x, tab_rect[i].przekatna.C.y);
        printf(" punkt D: %lf, %lf \n", tab_rect[i].przekatna.A.x, tab_rect[i].przekatna.C.y);
        printf("pole: %lf, obwod: %lf \n\n", tab_rect[i].pole, tab_rect[i].obwod);
        }
    
    }
