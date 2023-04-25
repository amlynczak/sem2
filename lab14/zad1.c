#include<stdio.h>
#include<string.h>

struct dane_student{
    int rekord;
    char nazwisko[15];
    char imie[15];
    int nr_indeks;
    char grupa[5];
    int nr_porzadkowy;
};

typedef struct dane_student person_data;

void przypisanie(char *haslo, char psswrd[10]){
    if(strcmp(haslo,psswrd) != 0){
        printf("niepoprawne haslo \nwprowadz ponownie:\n");
        scanf("%s", psswrd);
        przypisanie(haslo, psswrd);
    }else{
        printf("poprawne haslo\n");
        person_data temp;
        printf("podaj imie i nazwisko:\n");
        scanf("%s %s", temp.imie, temp.nazwisko);
        printf("podaj grupe:\n");
        scanf("%s", temp.grupa);
        printf("podaj numer indeksu: \n");
        scanf("%d", &temp.nr_indeks);

        FILE *fp = fopen("baza.txt", "ab+");
        if(fp){
            fputc()
        }
    }
}