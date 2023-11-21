#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;


int main()
{

    while (1==1)
    {
        char choice; 
        printf("A: open file\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit.\n");
        scanf("%s", &choice);

        //variables for A
        char filename[200];
        char *tempdate;
        char *temptime;
        char *tempsteps;
        int Buffer_size = 200;
        char Buffer_for_lines[Buffer_size];
        int count = 0;
        int len;
        FITNESS_DATA datalist[500];
        //variables for C
        int lowest;
        char *lowest_date;
        char *lowest_time;
        //variables for D
        int highest;
        char *highest_date;
        char *highest_time;
        //variables for E
        float total;
        float tempaverage;
        float average;
        //variables for F
        int best;
        int currant;
        
        char *startdate;
        char *starttime;
        char *enddate;
        char *endtime;
        char *currantstartdate;
        char *currantstarttime;
        char *currantenddate;
        char *currantendtime;

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
            count = 0;
            //creats arrey with file values for later options B, C and D
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

                strcpy(datalist[count].date, tempdate);
                strcpy(datalist[count].time, temptime);
                int tempstep = atoi(tempsteps);
                datalist[count].steps = tempstep;
                count++;
            }
            len = count;
            //reopens file
            file = fopen(filename, "r");

            break;
        
        case 'B':
        case 'b':
            count = 0;
            while (fgets(Buffer_for_lines,Buffer_size,file))
            {
                count++;
            }
            len = count;
            printf("Total records: %i\n", len);
            //reopens file
            file = fopen(filename, "r");
            break;

        case 'C':
        case 'c':
            count = 0;
            lowest = datalist[count].steps;
            lowest_date = datalist[0].date;
            lowest_time = datalist[0].time;            
            for (count = 0; count < len; count++)
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
            count = 0;
            highest = -1;
            highest_date = datalist[0].date;
            highest_time = datalist[0].time;            
            for (count = 0; count < len; count++)
            {
                if (datalist[count].steps > highest){
                    highest = datalist[count].steps;
                    highest_date = datalist[count].date;
                    highest_time = datalist[count].time;
                }
            }
            printf("Largest steps: %s %s\n", highest_date, highest_time);
            //reopens file
            fclose(file);
            file = fopen(filename, "r");
            break;
        case 'E':
        case 'e':
            total = 0;
            for (count = 0; count < len; count++)
            {
                total = total + datalist[count].steps;
            }
            average = total/len;
            tempaverage = 110/3.0;

            printf("Mean step count: %f\n", average);
            //reopens file
            fclose(file);
            file = fopen(filename, "r");
            break;
        case 'F':
        case 'f':
            best = 0;
            currant = 0;
            for (count = 0; count < len; count++)
            {
                if (datalist[count].steps>500){
                    if (currant == 0){
                        currantstartdate = datalist[count].date;
                        currantstarttime = datalist[count].time;
                    }
                    currant++;
                }
                else{

                    currantenddate = datalist[count-1].date;
                    currantendtime = datalist[count-1].time;

                    if (currant>best){
                        best = currant;
                        startdate = currantstartdate;
                        starttime = currantstarttime;
                        enddate= currantenddate;
                        endtime = currantendtime;
                    }
                    currant = 0;
                }
            }
            printf("Longest period start: %s %s\n", startdate, starttime);
            printf("Longest period end: %s %s\n", enddate, endtime);
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