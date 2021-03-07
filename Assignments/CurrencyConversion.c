/*  Program that lets you pick the currency between euro and dollar and converts it to either euro or dollar, depending on which one you picked.
    After selecting a currency, you will be asked to enter three amounts into a floating-point array
    Author: Amar plakalo
    Used Visual Studio Code on Windows 10
    Date: 20 February 2020 updated 07/03/2021
*/

#include <stdio.h>


#define SIZE 3



float change_to_Euro(float array[SIZE]); // converts US Dollars into Euro

float change_to_Dollar(float array[SIZE]); // Converts Euro into US Dollars

int main()
{
    float array[SIZE];
    int option;
    int i;
    int exitprogram = 3;
    float average;
    
    printf("\nMain Menu: \n");
    printf("\n1.Choose the Euro currency\n");
    printf("\n2.Choose the US Dollar Currency\n");
    printf("\n3. Exit the program\n");
    scanf("%d", &option); // Scan which option in the menu you have chosen
    
    if(option == 1)
    {
        printf("\nEnter the values in euros to be converted into US Dollars\n");
        
        for(i = 0; i < SIZE; i++)
        {
            scanf("%f", &array[i]);

        }
        
        
        // Call Function change_to_Dollar() and pass the array into it. Once it is passed, the function should return the average back to the int main() 
        average = change_to_Dollar(array);
        printf("\nThe average of the values converted to US Dollar is %f\n", average);
        
    }
    
    else if(option == 2)
    {
        printf("\nEnter the values in dollars to be converted into Euro\n");
        
        for(i = 0; i < SIZE; i++)
        {
            scanf("%f", &array[i]);
        }
        
        // Call function change_to_Euro() and pass the array into this function. When you pass it, the function should return the average back into the main()
    
        average = change_to_Euro(array);
    
        printf("\nThe average of the values converted into Euro is %f\n", average);
    
        
    }
    
    else if(option == 3)
    {
        printf("\nAre you sure that you want to quit the program? If yes, press 3 again\n");
        scanf("%d", &exitprogram);
        
        if(exitprogram == 3)
        {
            return 0;
        }
    }
    


    getchar();
    return 0;
}

/* Implement the function change_to_Dollar() and pass the array into it. Once passed, the function will find the average and return this value into the main()
*/

float change_to_Dollar(float array1[SIZE])
{
    int i;
    float avg;
    float total = 0;
    float convertedvalue[SIZE];
    
    for(i = 0; i < SIZE; i++)
    {
        convertedvalue[i] = array1[i] * 1.19;
        total = total + convertedvalue[i];
        
    }
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\nEuro converted to dollar = %f\n", convertedvalue[i]);
    }
    
    avg = total / 3.0;
    
    getchar();
    return avg;
}

float change_to_Euro(float array2[SIZE])
{
    int i;
    float avg2;
    float total2 = 0;
    float convertedvalue2[SIZE];
    
    for(i = 0; i < SIZE; i++)
    {
        convertedvalue2[i] = array2[i] * 0.84;
        total2 = total2 + convertedvalue2[i];
    }
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\nUS Dollar converted to euro = %f\n", convertedvalue2[i]);
    }
    
    avg2 = total2 / 3.0;
    
    getchar();
    return avg2;
}
