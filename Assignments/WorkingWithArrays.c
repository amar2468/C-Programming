/* Program that copies the contents of adam array into sarah, replace all blank elements in sarah array with underline character and display contents of sarah array to standard output
    Author: Amar Plakalo
    Date: 02 December 2019
*/

#include <stdio.h>
#define SIZE 10

int main()
{
    // Declare variables needed
    
    char adam[] = {'Y','E','S',' ','W','E',' ','C','A','N'};
    
    char sarah[SIZE];
    
    int i;
    
    // Part 1: Copy contents of adam array into sarah
    
    for(i = 0; i < SIZE; i++)
    { // Begin for loop
        *(sarah + i) = *(adam + i);
    } // End for loop
        
    
    // Part 2: Replace all blank elements in sarah array with the underline character _
    
    for(i = 0; i < SIZE; i++)
    {
        if(*(sarah + i) == ' ')
        {
            *(sarah + i) = '_';
        }
        
    }
    
    // Part 3: Display contents of sarah array to standard output
    
    
    for(i = 0; i < SIZE; i++)
    { // Begin for loop
        printf("%c", *(sarah + i));
    } // End for loop

    
    getchar();
    getchar();
    return 0;
} // End main()
