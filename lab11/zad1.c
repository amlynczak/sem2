#include<stdio.h>
#include<math.h>

struct zespolona{
    float Rz;
    float Im;
    };
    
void kalkulator(struct zespolona a, struct zespolona b, char dzial){
    struct zespolona wynik;
    if(dzial == '+'){
        wynik.Rz = a.Rz + b.Rz;
        wynik.Im = a.Im + b.Im;
        printf("dodawanie: \nwynik: %.2f + %.2fi \n", wynik.Rz, wynik.Im);
        }
    if(dzial == '-'){
        wynik.Rz = a.Rz - b.Rz;
        wynik.Im = a.Im - b.Im;
        printf("odejmowanie: \nwynik: %.2f + %.2fi \n", wynik.Rz, wynik.Im);
        }
    if(dzial == '*'){
        wynik.Rz = a.Rz * b.Rz - a.Im * b.Im;
        wynik.Im = a.Im * b.Rz + b.Im * a.Rz;
        printf("mnozenie \nwynik: %.2f + %.2fi \n", wynik.Rz, wynik.Im);
        }
    if(dzial == '/'){
        wynik.Rz = (a.Rz * b.Rz - a.Im * (-b.Im))/(pow(b.Rz,2)+pow(b.Im, 2));
        wynik.Im = (a.Im * b.Rz + (-b.Im) * a.Rz)/(pow(b.Rz,2)+pow(b.Im, 2));
        printf("dzielenie: \nwynik: %.5f + %.5fi \n", wynik.Rz, wynik.Im);
        }
    }
    
int main(){
    struct zespolona z;
    struct zespolona w;
    
    printf("podaj czesc rzeczywista pierwszej liczby:\n");
    scanf("%f", &z.Rz);
    printf("podaj czesc urojona pierwszej liczby:\n");
    scanf("%f", &z.Im);
    printf("podaj czesc rzeczywista drugiej liczby:\n");
    scanf("%f", &w.Rz);
    printf("podaj czesc urojona drugiej liczby:\n");
    scanf("%f", &w.Im);
    
    printf("z = %.2f + %.2fi \nw = %.2f + %.2fi \n", z.Rz, z.Im, w.Rz, w.Im);
    
    kalkulator(z, w, '+');
    kalkulator(z, w, '-');
    kalkulator(z, w, '*');
    kalkulator(z, w, '/');
    }
