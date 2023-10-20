#include <stdio.h>
#include <string.h>
int main()
{
    /* task 1
    int a;
    for (a=1; a<=20; a+=(2)){
        printf("a=%d\n",a);
    }
    */
    //printf("finaly a = %d\n",a);

    // task 2
    /*int a = 20;
    while (a >= 0){
        printf("%d\n",a);
        a -= 2;
    }
    */

   //task 3
   /*
    int a = 0;
    int x = 1;
    while (a < 10){
        int temp = x * x;
        printf("%d\n",temp);
        a += 1;
        x += 1;
    }
    */

   //array size 
   char string1[] = "hello";
   int N = strlen(string1);
   int array[N];
   int i;
   for (i = 0; i < N; i++){
    array[i] = i;
   }
   for (i = 0; i < N; i++){
    printf("%d\n", i);
   }

}