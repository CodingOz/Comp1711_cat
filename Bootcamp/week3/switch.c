#include <stdio.h>

int main(){
    int label = 2;
    switch (label)
    {
    case 0:
        printf("0 was selected\n");
        break;

    case 1:
        printf("1 was selected\n");
        break;    

    case 2:
        printf("2 was selected\n");
        break;    

    case 3:
        printf("3 was selected\n");
        break;

    default:
    printf("incorrect selection");
        break;
    }
}