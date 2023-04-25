#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max)
{
    return rand()%(max-min+1)+min;
}


int main()
{
    srand(time(0));
    printf("Podaj wymiary tablic:\n");
    int rows, columns;
    scanf("%d %d", &rows, &columns);
    //alokacja pierwsza metoda
    int **array_1=malloc(rows*sizeof(int));
    for(int i=0;i<rows;i++)
    {
        array_1[i]=malloc(columns*sizeof(int));
    }
    printf("Wypisanie wartosci pierwszej tablicy za pomoca pierwszej metody alokacji:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            array_1[i][j]=i_rand(1,9);
            printf("%d ", array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //alokacja druga metoda
    int **array_2=malloc(rows*sizeof(int));
    array_2[0]=malloc(columns*rows*sizeof(int));
    for(int i=0;i<rows*columns;i++)
    {
        array_2[0][i]=i_rand(1,9);
    }
    for(int i=1;i<rows;i++)
    {
        array_2[i]=array_2[i-1]+columns;
    }
    printf("Wypisanie wartosci drugiej tablicy za pomoca drugiej metody alokacji:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ", array_2[i][j]);
        }
        printf("\n");
    }
    int rows_new=i_rand(3,7);
    printf("Nowa ilosc wierszy : %d\n", rows_new);
    if(rows_new > rows)
    {
        array_1 = realloc(array_1, rows_new * sizeof(array_1[0]));

    for(int i = rows; i < rows_new; i++)
        {
            array_1[i] = malloc(columns * sizeof(int));

            for(int j = 0; j < columns; j++)
            {
                    array_1[i][j] = 0;
        }
            }
            array_2 = realloc(array_2, rows_new * sizeof(array_2[0]));
            array_2[0] = realloc(array_2[0], rows_new * columns * sizeof(int));

    for(int i = 1; i < rows_new; i++)
        {
            array_2[i] = array_2[i - 1] + columns;
            if(i < rows) continue;
            for(int j = 0; j < columns; j++)
            {
                    array_2[i][j] = 0;
            }
        }


    }
    else if(rows_new < rows)
    {
        for(int i = rows - 1; i >= rows_new; i--){
            free(array_1[i]);
        }

        array_1 = realloc(array_1, rows_new * sizeof(array_1[0]));


        array_2 = realloc(array_2, rows_new * sizeof(array_2[0]));
        array_2[0] = realloc(array_2[0], rows_new * columns * sizeof(int));
    }
    printf("Wypisanie obu tablic po ustaleniu nowej ilosci wierszy:\n");
    for(int i=0;i<rows_new;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ", array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<rows_new;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ", array_2[i][j]);
        }
        printf("\n");
    }
    free(array_2[0]);
    free(array_2);
    for(int i=0;i<rows_new;i++)
    {
        free(array_1[i]);
    }
    free(array_1);
    return 0;




}
