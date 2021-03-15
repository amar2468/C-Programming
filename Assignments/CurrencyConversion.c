/*  Program that lets you pick the currency between euro and dollar and converts it to either euro or dollar, depending on which one you picked.
    After selecting a currency, you will be asked to enter three amounts into a floating-point array
    Author: Amar plakalo
    Used Visual Studio Code on Windows 10
    Date: 20 February 2020 updated 15/03/2021
*/

#include <stdio.h>

#define SIZE 50

float change_to_Euro(float array[SIZE],int); // converts US Dollars into Euro

float change_to_Dollar(float array[SIZE],int); // Converts Euro into US Dollars

int main()
{
    float array[SIZE];
    int option;
    int i;
    int exitprogram = 3;
    float average;
    int counter = 1;
    int no_of_values = 0;

    while(counter == 1)
    {
    
        printf("\nMain Menu: \n");
        printf("\n1.Choose the Euro currency\n");
        printf("\n2.Choose the US Dollar Currency\n");
        printf("\n3. Exit the program\n");
        scanf("%d", &option); // Scan which option in the menu you have chosen
        
        if(option == 1)
        {
            printf("How many values do you wish to enter? Maximum number of values you are allowed to input is 50: ");
            scanf("%d",&no_of_values);
            printf("\nEnter values in euros to be converted into US Dollars\n");
            
            for(i = 0; i < no_of_values; i++)
            {
                scanf("%f", &array[i]);

            }
            
            
            // Call Function change_to_Dollar() and pass the array into it. Once it is passed, the function should return the average back to the int main() 
            average = change_to_Dollar(array,no_of_values);
            printf("\nThe average of the values converted to US Dollar is %f\n", average);
            
        }
        
        else if(option == 2)
        {
            printf("How many values do you wish to enter?");
            scanf("%d",&no_of_values);
            
            printf("\nEnter three values in dollars to be converted into Euro\n");
            
            for(i = 0; i < no_of_values; i++)
            {
                scanf("%f", &array[i]);
            }
            
            // Call function change_to_Euro() and pass the array into this function. When you pass it, the function should return the average back into the main()
        
            average = change_to_Euro(array,no_of_values);
        
            printf("\nThe average of the values converted into Euro is %f\n", average);
        
            
        }
        
        else if(option == 3)
        {
            int quit_program;
            printf("\nAre you sure that you want to quit the program? If yes, press 3 again\n");
            scanf("%d", &quit_program);
            if (quit_program == 3)
            {
                counter = 0;
            }
            else
            {
                printf("You are redirected back to the main menu: ");
                counter = 1;
            }
        }
        else
        {
            printf("None of the options have been selected. Pick a valid option: ");

        }
    }
    


    getchar();
    return 0;
}

/* Implement the function change_to_Dollar() and pass the array into it. Once passed, the function will find the average and return this value into the main()
*/

float change_to_Dollar(float array1[SIZE],int number_of_values)
{
    int i;
    float avg;
    float total = 0;
    float convertedvalue[SIZE];
    
    for(i = 0; i < number_of_values; i++)
    {
        convertedvalue[i] = array1[i] * 1.19;
        total = total + convertedvalue[i];
        
    }
    
    for(i = 0; i < number_of_values; i++)
    {
        printf("\n%.2f Euro -> %.2f Dollars\n", array1[i],convertedvalue[i]);
    }
    
    avg = total / 3.0;
    
    getchar();
    return avg;
}

float change_to_Euro(float array2[SIZE],int numb_of_values)
{
    int i;
    float avg2;
    float total2 = 0;
    float convertedvalue2[SIZE];
    
    for(i = 0; i < numb_of_values; i++)
    {
        convertedvalue2[i] = array2[i] * 0.84;
        total2 = total2 + convertedvalue2[i];
    }
    
    for(i = 0; i < numb_of_values; i++)
    {
        printf("\n%.2f US Dollar -> %.2f Euro\n", array2[i],convertedvalue2[i]);
    }
    
    avg2 = total2 / 3.0;
    
    getchar();
    return avg2;
}
