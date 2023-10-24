#include <stdio.h>

int m(){
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror("error:");
        return 1;
    }
    //printf(file);
    fprintf(file, "hello world");
    fclose(file);
    return 0;
}



/*int makefile(char* filename, char* filecontent){
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        perror("error:");
        return 1;
    }
    fprintf(file, filecontent);
    fclose(file);
    return 0;
}*/


int squaral(int n){
    char filename[] = "squares.dat";
    FILE *file = fopen(filename, "a");
    if (file == NULL){
        perror("error: ");
        return 1;
    }
    int i;
    for (i = 1; i <= n; i++){
        int a = i*i;
        fprintf(file, "%d\n", i*i);
        }
    fclose(file);
    return 0;
}

int readfile(char* filename){
    
}

int main(){
    squaral(3);
}