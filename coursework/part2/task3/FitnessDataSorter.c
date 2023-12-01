#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;
// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}
int main() {
    char delimiter = ',';
    FitnessData datalist[500];
    char *date;
    char *time;
    int *steps;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: invalid file");
        return 1;
    }
    char *tempdate;
    char *temptime;
    char *tempsteps;
    int Buffer_size = 200;
    char Buffer_for_lines[Buffer_size];
    int count = 0;
    int len = 0;
    //tokenises the record
    while (fgets(Buffer_for_lines,Buffer_size,file))
    {
        char *inputCopy = strdup(Buffer_for_lines);
        char *token = strtok(inputCopy, ",");
        if (token != NULL)
        {
            tempdate = token; 
        }
        else{
            printf("Error: invalid file");
            return 1;
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            temptime = token;
        }
        else{
            printf("Error: invalid file");
            return 1;
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            tempsteps = token;
        }
        else{
            printf("Error: invalid file");
            return 1;
        }

        strcpy(datalist[count].date, tempdate);
        strcpy(datalist[count].time, temptime);
        int tempstep = atoi(tempsteps);
        datalist[count].steps = tempstep;
        count++;
    }
    len = count;
    int i;
    //validates the file
    for (i = 0; i<len; i++){
        //checks date value format
        if ((strlen(datalist[i].date) != 10) || (datalist[i].date[4] != '-') || (datalist[i].date[7] != '-'))
        {
           printf("Error: invalid file");
           return 1;
        }
        //check time value format
        if ((strlen(datalist[i].time) != 5) || (datalist[i].time[2] != ':'))
        {
           printf("Error: invalid file");
           return 1;
        }
        //checks steps are in reasonable range 
        if ((0 > datalist[i].steps) || (datalist[i].steps > 5000))
        {
           printf("Error: invalid file");
           return 1;
        }        
    }
    //sorts array with bouble sort
    int change = 1;
    FitnessData temp;
    while (change != 0)
    {
        change = 0;
        for (i = 0; i<len-1; i++){
            if (datalist[i].steps<datalist[i+1].steps){
                temp = datalist[i];
                datalist[i] = datalist[i+1];
                datalist[i+1] = temp;
                change = 1;
            }
        }
    }

    //saves to file
    char *newfilename = strcat(filename, ".tsv");
    FILE *writefile = fopen(newfilename, "w");
    for (i = 0; i<len; i++){
        fprintf(writefile,"%s\t%s\t%i\n", datalist[i].date, datalist[i].time, datalist[i].steps);
        printf("%s\t%s\t%i\n", datalist[i].date, datalist[i].time, datalist[i].steps);
    }
}
