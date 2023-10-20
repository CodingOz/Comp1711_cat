#include <stdio.h>

int main(){
    float temperature;
    float hot = 20;
    float cold = 10;
    printf("What's the temperature today");
    scanf("%f", &temperature);

    if (temperature>hot){
        printf("no need for a jacket\n");
    }
    else if (temperature > cold){
        printf("might want a jacket\n");
    }
    else{
        printf("you need a jacket\n");
    }
    return 0;
}