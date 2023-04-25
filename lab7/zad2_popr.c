#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** wyrazy(char *t, int *size);

int scmpr ( const void * a , const void * b ) {
return strcmp (( const char *) a , ( const
char *) b ) ;
} 

int main(int argc, char *argv[]){
  if(argc == 2){
        int n = 0; //rozmiar
        char **tab = wyrazy(argv[1],&n);

        qsort (tab, n, sizeof(char), scmpr);

        for(int i=0; i<n; i++){
           printf("%s ",*(tab+i));
        }
        printf("\n");
    } 
    
    if(argc != 2) printf("zly tekst/n");

    return 0;
}

