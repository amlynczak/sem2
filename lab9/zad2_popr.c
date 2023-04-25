#include<stdio.h>
#include<math.h>
#include<string.h>

double fun0(double x){return log(x);}
double fun1(double x){return x*x;}
double fun2(double x){return sin(x);}
double fun3( double x){return cos(x);}

double (**find_max(double (*t[])(), int n, double w))(double){
    double max = t[0](w);
    double (**wsk)();
    for(int i=1; i<n; i++){
        if(t[i](w) > max){
            max = t[i](w);
            }
        }
    for(int i=0; i<n; i++){
        if(t[i](w) == max){
            *wsk = t[i];
            }
        }
    return wsk;
    }

int main(){
    char *nazwy[]={"log", "pow", "sin", "cos"};
    double data[8] = {3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0};
    
    double (*TAB_FUN[5])();
    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;
    
    double (**wsk_fun)() = TAB_FUN;
    char **str = nazwy;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            printf("%s (%lf) = %lf", *(str + i), data[j], (**(wsk_fun+i))(data[j]));
            printf("\n");
            }
        printf("\n");
        }
        
    double x = 0.5;
    double (**var)() = find_max(TAB_FUN, 5, x);
    int k; //idneks funkcji w tablicy z nazwami
    if(*var == TAB_FUN[0]) k = 0;
    if(*var == TAB_FUN[1]) k = 1;
    if(*var == TAB_FUN[2]) k = 2;
    if(*var == TAB_FUN[3]) k = 3;
    
    printf("dla x= %lf najwieksza wartosc rowna %.3lf przyjmuje dla funkcji %s\n", x, (**var)(x), nazwy[k]);
        
    } 
