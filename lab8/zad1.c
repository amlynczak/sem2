#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void blad(){
    printf("blednie podane argumenty\n");
    printf("dostepne dzialania: +(dodawanie), -(odejmowanie), m(mnozenie), /(dzielenie), ^(potegowanie), s(pierwiastkowanie)\n");
    printf("poprwane podanie:\n<liczba> s dla pierwiastkowania, np: 4 s\n<liczba> <dzialanie> <liczba> dla reszty dzialan, np: 21.2 + 13\n");
    }

int main(int argc, char *argv[]){
    double wynik;
    if(argc == 4){
        if(*argv[2] == '+'){
            printf("dodawanie\n");
            wynik = atof(argv[1]) + atof(argv[3]);
            printf("twoj wynik: %lf \n", wynik);
            }else if(*argv[2] == '-'){
                printf("odejmowanie\n");
                wynik = atof(argv[1]) - atof(argv[3]);
                printf("twoj wynik: %lf \n", wynik);
            }else if(*argv[2] == 'm'){
                printf("mnozenie\n");
                wynik = atof(argv[1]) * atof(argv[3]);
                printf("twoj wynik: %lf \n", wynik);
            }else if(*argv[2] == '/'){
            printf("dzielenie\n");
                if(*argv[3] == '0'){
                    printf("nie mozna dzielic przez 0\n");
                    }else{
                    wynik = atof(argv[1])/atof(argv[3]);
                    printf("twoj wynik: %lf \n", wynik);
                    }
            }else if(*argv[2] == '^'){
                printf("potegowanie\n");
                wynik = pow(atof(argv[1]),atof(argv[3]));
                printf("twoj wynik: %lf \n", wynik);
            }else{blad();}
        }else if(argc == 3){
            if(*argv[2] == 's'){
                printf("pierwiastkowanie\n");
                wynik = sqrt(atof(argv[1]));
                printf("twoj wynik: %lf \n", wynik);
                }else{blad();}
        }else{blad();}
    
    }
