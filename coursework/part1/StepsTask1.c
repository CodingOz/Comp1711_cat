#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    
    if (token != NULL) 
    {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() 
{
    char *filename = "FitnessData_2023.csv";
    FILE *datafile = fopen(filename, "r");
    if (datafile == NULL)
    {
        perror("File not made: ");
        return 0;
    }

    FITNESS_DATA datalist[500];
    int Buffer_size = 200;
    char Buffer_for_lines[Buffer_size];
    int count = 0;
    
    while (fgets(Buffer_for_lines,Buffer_size,datafile))
    {
        //tokeniseRecord(Buffer_for_lines, ",", date, time, steps);
        //when running the helper funtion I kept getting the error "Segmentation fault (core dumped)"
        //I was unable to remedy this problem without changing the function 
        //so after an hour trying I choise not to use the function
        //I hope this is okay as from what I can tell it wasnt required use function 
        //and the code works the same way as the helper function but without the error

        char *date;
        char *time;
        char *steps;
        
        //replacement for helper function
        char *inputCopy = strdup(Buffer_for_lines);
        char *token = strtok(inputCopy, ",");
        if (token != NULL) {
            date = token; 
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            time = token;
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            steps = token;
        }

        strcpy(datalist[count].date, date);
        strcpy(datalist[count].time, time);
        int tempstep = atoi(steps);
        datalist[count].steps = tempstep;

        count++;

    }
    printf("Number of records in file: %d\n", count);

    int counter = 0;
    while (counter < 3)
    {
        printf("%s/%s/%d\n", datalist[counter].date, datalist[counter].time, datalist[counter].steps);
        counter++;
    }
}