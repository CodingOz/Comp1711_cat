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

        //variables for B 
        FITNESS_DATA datalist[500];
        int Buffer_size = 200;
        char Buffer_for_lines[Buffer_size];
        int count = 0;


        //choice = toupper(choice);
        switch (choice)
        {
        case 'A':
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
            count = 0;
            while (fgets(Buffer_for_lines,Buffer_size,file))
            {
                count++;
            }
            printf("Total records: %i\n", count);
            file = fopen(filename, "r");
            if (file == NULL)
            {
                printf("Error: could not open file\n");
                return 1;
            }

            break;
        case 'C':
            while (fgets(Buffer_for_lines,Buffer_size,file))
            {
                
            }
            
            break;
        case 'D':
            printf("d");
            break;
        case 'E':
            printf("e");
            break;
        case 'F':
            printf("f");
            break;
        case 'Q':
            return 0;
            break;
        default:
            printf("not recognised\n");
            break;
        }
    }
}