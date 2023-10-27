#include <stdio.h>

struct student
{
    char name[20];
    char student_id [11];
    unsigned mark;
};


typedef struct 
{
    int x;
    int y;
}point;


int question1(){
    point points[11];
    int i;
    for (i = 0; i<2; i++){
        printf("enter x:");
        scanf("%i\n", &points[i].x);
        printf("enter y:");
        scanf("%i\n", &points[i].y);
    }
    for (i = 0; i<2; i++){
        printf("coordinate %i: (%i,%i)\n", i+1, points[i].x, points[i].y);
    }
    return 0;
}




int main(){
    question1();
    struct student newstudent = {.name = "sam", .student_id = "2348735555", .mark = 12};
    printf("name: %s\n", newstudent.name);
    return 0;
}