#include<stdio.h>
#include<string.h>


int main(){
    char tekst[] = "Ile  i które z samoglosek znajdziesz  w tym zdaniu ?!";
    char *p = tekst;
    char samogloski[] = "aeiouy";
    int ilosc[6];
    int licznik_=0; //liczy spacje
    int licznik_i=0; //liczy znaki interpunkcyjne
    int licznik_sa=0; //samogloski
    int licznik_sp=0; //spolgloski

    
    while(*p != '\0'){
        switch(*p){
            case(' '): ++licznik_; break;
            case('a'): ++ilosc[0]; ++licznik_sa; break;
            case('e'): ++ilosc[1]; ++licznik_sa; break;
            case('i'): ++ilosc[2]; ++licznik_sa; break;
            case('o'): ++ilosc[3]; ++licznik_sa; break;
            case('u'): ++ilosc[4]; ++licznik_sa; break;
            case('y'): ++ilosc[5]; ++licznik_sa; break;
            case('?'): ++licznik_i; break;
            default: ++licznik_sp; break;
            }
        
        ++p;
        }
        
        
    for(int i=0; i<=5; i++){
        printf("litera %c, %d razy \n", samogloski[i], ilosc[i]);
        }
    printf("liter: %d, \nsamoglosek: %d, \nspolglosek: %d, \nznakow interpunkcyjnych: %d, \nspacji: %d, \n", licznik_sa+licznik_sp, licznik_sa, licznik_sp, licznik_i, licznik_);
    }
