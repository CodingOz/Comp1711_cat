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
        printf("A: Specify the filename to be imported – you need to check that the file opened correctly.\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit.\n");
        scanf("%c", &choice);
        //choice = toupper(choice);
        switch (choice)
        {
        case 'A':
            printf("");
            break;
        case 'B':
            printf("");
            break;
        case 'C':
            printf("");
            break;
        case 'D':
            printf("");
            break;
        case 'E':
            printf("");
            break;
        case 'F':
            printf("");
            break;
        case 'Q':
            return 0;
            break;
        default:
            break;
        }
    }
}