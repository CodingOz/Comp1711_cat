#include <stdio.h>
#include <stdbool.h>
#include <string.h>ga


int circleArea(float radius)
{
    float area = radius*radius*3.14;
    return area;
}


int spherevolume(float radius)
{
    float volume = (4*radius*radius*radius*3.14)/3;
    return volume;
}


int stringlength(char word)
{
    bool done = false;
    int count = 0;
    while (done == false)
    {
        char a = word[&count];
        if (a == '\0'){
            return count;
        }
        else{
            count++;
        }
    }
}

bool primecheck(int num)
{
    int number = num;
    int count = 2;
    while (count < num){
        if (number % count == 0){
            return false;
        }
        else{
            count++;
        }
    }
    return true;
}

char* concatStrings(char* str1, char* str2)
{
    //int length = strlen(str1)+strlen(str2);
    static char newstr[1000];
    int count1 = 0;
    int count2 = 0;
    while (count2<strlen(str1)){
        newstr[count2] = str1[count1];
        count1++;
        count2++;
    }
    int count1b = 0;
    int count2b = 0;
    while (count2<strlen(str2)){
        newstr[count2b+strlen(str1)] = str2[count1b];
        count1b++;
        count2b++;
    } 
    return newstr;
}

int main()
{

}
