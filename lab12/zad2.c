#include<stdio.h>
#include<string.h>

void automat(char t[], int n){
    char tab_p[n];
    for(int i=0; i<n; i++){
        tab_p[i] = '_';
    }
    for(int i=1; i<(n-1); i++){
        if(t[i]=='_'){
            if(t[i-1]=='_'){
                if(t[i+1]=='_'){
                    tab_p[i] = '_';
                }else{
                    tab_p[i] = 'x';
                }
            }else{
                if(t[i+1]=='_'){
                    tab_p[i] = 'x';
                }else{
                    tab_p[i] = '_';
                }
            }
        }else{
            if(t[i-1] == '_'){
                if(t[i+1]=='_'){
                    tab_p[i]='x';
                }else{
                    tab_p[i]='x';
                }
            }else{
                if(t[i+1]=='_'){
                    tab_p[i]='_';
                }else{
                    tab_p[i]='_';
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        t[i] = tab_p[i];
    }
}

int sprawdzam(char t1[], char t2[], int n){
    for(int i=n; i>0; i--){
        if(t1[i]==t2[i]){
            sprawdzam(t1, t2, n-i);
        }else{
            return 0;
        }
    }
    return 1;
}

int main(){
    char tab[] = "_________________x_________________";
    printf("%s \n", tab);
    int roz = sizeof(tab)/sizeof(*tab);
    
    automat(tab, roz);

    printf("%s \n", tab);

    char tab_e[] = "_x_x_x_x_x_x_x_x_x_x_x_x_x_x_x_x_x_";
    int k =0; //liczba krokow
    int z = sprawdzam(tab, tab_e, roz);
    printf("%d \n", z);

    while(sprawdzam(tab, tab_e, roz)==0){
        automat(tab, roz);
        k++;
    }

}