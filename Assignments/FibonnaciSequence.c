/* Program that implements fibonnaci sequence
Author: Amar Plakalo
Date: 17/08/2020
*/

#include <stdio.h>

int main()
{
    int option = 0;

    do
    {
        printf("Fibonnaci Sequence Menu\n");
        printf("\n1.Enter the number of terms to display in the sequence\n");
        printf("\n2.End Program\n");
        scanf("%d", &option);

        
        fflush(stdin);

        switch(option)
        {
            case 1:
            { 
                int no_of_terms = 0;
                
                int i;
                
                int nextnumber;
            
                int previousnumber = 0;
            
                int currentnumber = 1;
                
                printf("\nEnter number of terms\n");
                scanf("%d", &no_of_terms);

                for(i = 0; i < no_of_terms; i++)
                {
                    if(i <= 1)
                    {
                        currentnumber = i;
                    }
                    else
                    {
                        nextnumber = currentnumber + previousnumber;

                        previousnumber = currentnumber;

                        currentnumber = nextnumber;
                    }

                    printf("%d, ", currentnumber);
                }

                break;
            }

            case 2:
            {
                printf("\nProgram Ended\n");
                break;

            }

            default:
            {
                printf("\nWrong option\n");

                break;
            }

        }
    }

    

    while(option != 2);

    getchar();
    return 0;
}
