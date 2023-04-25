#include<stdio.h>
#include<string.h>

int main(){
    char znaki[80];
    
    /*scanf("%s", znaki);
    printf("%s \n", znaki);*/
    
    
    //gets(znaki); // ostrzezenie ze jest niebezpieczny
    
    
    fgets(znaki, 80, stdin);
    printf("%s \n", znaki);
    
    
    
    
    }
