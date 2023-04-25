#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct zxy{
    char *tekst;
    struct zxy *wsk;    
    };
    
int main(){
    struct zxy a;
    struct zxy b;
    struct zxy c;
    
    a.wsk = &b;
    b.wsk = &c;
    c.wsk = &a;
    
    //sekcja z uzwaniem a
    
    a.tekst = "nazwisko";
    (a.wsk)->tekst = "imie";
    ((a.wsk)->wsk)->tekst = "miejsce zamieszkania";
    
    //sekcja z uzywaniem b
    
    printf("a: %s \nb: %s \nc: %s \n", (((b.wsk)->wsk)->tekst), b.tekst, (b.wsk)->tekst);
    printf("\n");
    
    //sekcja z uzywaniem c
    
    char *pa = (c.wsk)->tekst;
    char *pb = ((c.wsk)->wsk)->tekst;
    char *pc = c.tekst;
    int i=0;

    while(*(pa+i)){
        *(pa+i) = toupper(*(pa+i));
        i++;
    }
    i=0;
    while(*(pb+i)){
        *(pb+i) = toupper(*(pb+i));
        i++;
        }
    i=0;
    while(*(pc+i)){
        *(pc+i) = toupper(*(pc+i));
        i++;
        }
    
    printf("a: %s \nb: %s \nc: %s \n", a.tekst, b.tekst, c.tekst);
    
    }
