#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random_num(int max, int min){
    return rand()%(max - min + 1) + min;

}

int main(){

    int rows, columns, rows_new;
    printf("podaj liczbe kolumn wierszy oraz kolumn: ");
    scanf("%d %d", &rows, &columns);

    int **array_1=malloc(rows*sizeof(int));
    for(int i=0;i<rows;i++){
        array_1[i]=malloc(columns*sizeof(int));
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            array_1[i][j]=random_num(1,9);
            printf("%3d |", array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    rows_new = random_num(3,7);

    if(rows_new > rows){
        array_1 = realloc(array_1, rows_new * sizeof(*array_1));
    

        for(int i=rows+1; i<rows_new; i++){
            array_1[i] = malloc(columns*sizeof(int));
            }
        for(int i=rows+1; i<rows_new; i++){
            for(int j=0; j<columns; j++){
                array_1[i][j] = 0;
                }
            }
        }
        
    for(int i=0; i<rows_new; i++){
        for(int j=0; j<columns; j++){
            printf("%3d |", array_1[i][j]);
            }
        printf("\n");
        }
    
    free(array_1);
    
    
    int **array_2 = malloc(rows*sizeof(int));
    *array_2 = malloc(rows*columns*sizeof(int));
    for(int i=0; i<columns; i++){
        array_2[i] = *array_2 + i*columns;
        }
    
    
    for(int i=0; i<columns*rows; i++){
        *array_2[i] = random_num(1,9);
        }
        
    array_2 = realloc(array_2, rows_new*sizeof(int));
    
    for(int i=0; i<rows_new; i++){
        for(int j=0; j<columns; j++){
            printf("%d |", array_2[i][j]);
            }
        printf("\n");
        }
    
    free(array_2);   
        
        
        
        
}
