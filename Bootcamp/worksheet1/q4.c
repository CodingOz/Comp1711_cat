#include<stdio.h>
int main () 
{
    int num1;
    printf("Insert a radius: ");
    scanf("%d", &num1);
    int area = num1 * num1 * 3.14;
    printf("area are %d \n", area);
    return 0;
}