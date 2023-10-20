#include <stdio.h>

int main(){
    int grade;
    int pass = 40;
    int first = 70;
    printf("What's your grade: ");
    scanf("%d", &grade);
    if ((grade < 0) || (100 < grade)){
        printf("mark invalad");
    }
    else if (first<=grade){
        printf("%d is a first!\n", grade);
    }
    else if (pass<=grade){
        printf("%d is a pass\n", grade);
    }
    else{
        printf("%d is a fail\n", grade);
    }
    return 0;
}