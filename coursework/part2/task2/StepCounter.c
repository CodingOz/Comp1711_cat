#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

char tokenise(FILE *file){
    int count = 0;
    char *tempdate;
    char *temptime;
    char *tempsteps;
    FITNESS_DATA templist[500];
    int Buffer_size = 200;
    char Buffer_for_lines[Buffer_size];
    int *count = 0;
    while (fgets(Buffer_for_lines,Buffer_size,file))
    {
    char *inputCopy = strdup(Buffer_for_lines);
    char *token = strtok(inputCopy, ",");
    if (token != NULL)
    {
        tempdate = token; 
    }
    token = strtok(NULL, ",");
    if (token != NULL) {
        temptime = token;
    }
    token = strtok(NULL, ",");
    if (token != NULL) {
        tempsteps = token;
    }

    strcpy(templist[count].date, tempdate);
    strcpy(templist[count].time, temptime);
    int tempstep = atoi(tempsteps);
    templist[count].steps = tempstep;

    count++;
    }
    return templist;

}



int main()
{

    while (1==1)
    {
        char choice; 
        printf("A: open file\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit.\n");
        scanf("%s", &choice);

        //variables for A
        char filename[200];

        //variables for B 
        int Buffer_size = 200;
        char Buffer_for_lines[Buffer_size];
        int count = 0;
        //variables for C
        FITNESS_DATA datalist[500];
        FITNESS_DATA *templist[500];
        char *date;
        char *time;
        char *steps;
        int length;
        int lowest;
        char *lowest_date;
        char *lowest_time;


        //choice = toupper(choice);
        switch (choice)
        {
        case 'A':
        case 'a':
            printf("input filename: ");
            scanf("%s", filename);
            
            FILE *file = fopen(filename, "r");
            if (file == NULL)
            {
                printf("Error: could not open file\n");
                return 1;
            }
            break;
        
        case 'B':
        case 'b':
            count = 0;
            while (fgets(Buffer_for_lines,Buffer_size,file))
            {
                count++;
            }
            printf("Total records: %i\n", count);
            //reopens file
            file = fopen(filename, "r");
            break;

        case 'C':
        case 'c':
            count = 0;
            templist = tokenise(file);
            /*while (fgets(Buffer_for_lines,Buffer_size,file))
            {
                char *inputCopy = strdup(Buffer_for_lines);
                char *token = strtok(inputCopy, ",");
                if (token != NULL)
                {
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
            */

            //length = sizeof(array);
            lowest = datalist[0].steps;
            lowest_date = datalist[0].date;
            lowest_time = datalist[0].time;            
            for (count = 0; count < length; count++)
            {
                if (datalist[count].steps < lowest){
                    lowest = datalist[count].steps;
                    lowest_date = datalist[count].date;
                    lowest_time = datalist[count].time;
                }

            }
            printf("Fewest steps: %s %s\n", lowest_date, lowest_time);

            //reopens file
            fclose(file);
            file = fopen(filename, "r");
            break;

        case 'D':
        case 'd':
            printf("d");
            break;
        case 'E':
        case 'e':
            printf("e");
            break;
        case 'F':
        case 'f':
            printf("f");
            break;
        case 'Q':
        case 'q':
            return 0;
            break;
        default:
            printf("not recognised\n");
            break;
        }
    }
}