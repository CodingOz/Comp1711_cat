#include <stdio.h>

int main(){
    /*task 1
    int num;
    printf("enter number: ");
    scanf("%d", num);
    if (num > 0){
        printf("number is positive\n");
    }
    else if (num < 0){
        printf("number is negative\n");
    }
    else{
        printf("number is 0\n");
    }*/

    /*task 2
    int num;
    printf("enter number: \n");
    scanf("%d", num);
    if ((num%4) == 0){
        printf("number is divisible by 4")l;
    }
    if ((num%5) == 0){
        printf("number is divisible by 5");
    }*/


    /*task 3
    int grade;
    int pass = 50;
    int first = 70;
    printf("What's your grade: ");
    scanf("%d", &grade);
    if ((grade < 0) || (100 < grade)){
        printf("mark invalad");
    }
    else if (first<=grade){
        printf("%d is a distinction!\n", grade);
    }
    else if (pass<=grade){
        printf("%d is a pass\n", grade);
    }
    else{
        printf("%d is a fail\n", grade);
    }
    return 0;
    */

   /*task 4

    int temp;
    int high = 40;
    int low = -10;
    printf("What's your grade: ");
    scanf("%d", &temp);
    if (temp>low && temp<high){
        printf("verafied");
    }
    else{
        printf("not verafied");
    }
    */

   /*task 5 

    int item;
     printf("What's your choice: ");
    scanf("%d", &item);

    switch (item)
    {
    case 1:
        printf("1 was selected\n");
        break;    

    case 2:
        printf("2 was selected\n");
        break;    

    case 3:
        printf("3 was selected\n");
        break;
    case 4:
        printf("4 was selected\n");
        break;    
    case 5:
        printf("5 was selected\n");
        break;

    default:
    printf("incorrect selection");
        break;
    } */

    /*task 6
    int item = 0;
    while (item != -1){
        int item;
        printf("What's your number: ");
        scanf("%d", &item);
        if (item == -1){
            printf("bye");
        }
        else if (item >= 0 && item <= 100){
            printf("in range");
        }
        else{
            printf("out of range");
        }
    }*/


    return 0;
}