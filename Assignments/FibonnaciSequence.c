/* Program that implements fibonnaci sequence. The user is asked to enter the amount of terms they wish to see on screen. Then, the program prints out the fibonacci
   sequence.
   Author: Amar Plakalo
   Date: 17/08/2020 - Updated 17/03/2021
*/

#include <stdio.h>

int main()
{
    int option = 0; // keeps track of the option entered by the user

    do // Guaranteed to run at least once because the do.. part of the program has to execute once at least. This is perfect for menu programs
    {
        printf("Fibonnaci Sequence Menu\n");
        printf("\n1.Enter the number of terms to display in the sequence\n");
        printf("\n2.End Program\n");
        scanf("%d", &option); // looks for the option entered by the user

        
        fflush(stdin); // Flushes the output buffer

        switch(option) // This switch statement will check all the possibilities that occur if an option is selected
        {
            case 1: // If the user chose option 1
            { 
                int no_of_terms = 0; // declaring the number of terms and setting value to 0. This is because I want to ask the user how many values they want to enter
                
                int i; // index variable
                
                int nextnumber; // This keeps track of the next number in line
            
                int previousnumber = 0; // this looks at the previous number in line
            
                int currentnumber = 1; // this is the current number
                
                printf("\nEnter number of terms\n");
                scanf("%d", &no_of_terms); // saves the number of terms entered

                for(i = 0; i < no_of_terms; i++) // iterate over the number of terms entered by the user
                {
                    if(i <= 1) // if the value in line is less than or equal to 1
                    {
                        currentnumber = i; // make this the current number
                    }
                    else // Otherwise
                    {
                        nextnumber = currentnumber + previousnumber; // add the current number with the previous one, in order to get the next one.

                        previousnumber = currentnumber; // the current number in line will now become the previous one

                        currentnumber = nextnumber; // the next number in line will now become the current one
                    }

                    printf("%d, ", currentnumber); // print the current number in line
                }

                break;
            }

            case 2: // If option 2 is selected
            {
                printf("\nProgram Ended\n"); // message to notify user that program has ended
                break;

            }

            default: // If none of the options were selected
            {
                printf("\nWrong option\n"); // notify user that none of the options were selected

                break;
            }

        }
    }

    

    while(option != 2); // Will run while the option is not 2. If it is, the program ends

    getchar();
    return 0;
}
