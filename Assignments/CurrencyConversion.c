/*  Program that lets you pick the currency between euro and dollar and converts it to either euro or dollar, depending on which one you picked.
    After selecting a currency, you will be asked to enter three amounts into a floating-point array
    Author: Amar plakalo
    Used Visual Studio Code on Windows 10
    Date: 20 February 2020 updated 16/03/2021
*/

#include <stdio.h>

#define SIZE 50

float change_to_Euro(float array[SIZE],int); // converts US Dollars into Euro

float change_to_Dollar(float array[SIZE],int); // Converts Euro into US Dollars

int main()
{
    float array[SIZE]; // stores the values that the user enters and this will be passed into the function to be converted
    int option; // records the option chosen by the user
    float average; // records the average when the values are converted
    int counter = 1; // When value is 1, the loop will continually show a menu. If the user wishes to exit the program, the counter will go to 0
    int no_of_values = 0; // This variable stores the amount of questions the user wishes to ask.

    while(counter == 1) // Continually reappears while counter value is 1
    {
    
        printf("\nMain Menu: \n");
        printf("\n1.Choose the Euro currency\n");
        printf("\n2.Choose the US Dollar Currency\n");
        printf("\n3.Exit the program\n");
        scanf("%d", &option); // Scan which option in the menu you have chosen
        
        if(option == 1) // If the user chose option 1
        {
            printf("How many values do you wish to enter? Maximum number of values you are allowed to input is 50: "); 
            scanf("%d",&no_of_values); // the number of values the user wishes to enter is stored in this variable.
            printf("\nEnter values in euros to be converted into US Dollars\n");
            
            for(int i = 0; i < no_of_values; i++)
            {
                scanf("%f", &array[i]); // stores the values that are to be converted into dollars

            }
            
            
            // Call Function change_to_Dollar() and pass the array into it. Once it is passed, the function should return the average back to the int main() 
            average = change_to_Dollar(array,no_of_values); // passes array and the number of values entered by the user into the function
            printf("\nThe average of the values converted to US Dollar is %.2f\n", average); // prints the average returned from the function
            
        }
        
        else if(option == 2) // If user chose option 2
        {
            printf("How many values do you wish to enter?");
            scanf("%d",&no_of_values); // number of values they wish to enter is saved in the variable
            
            printf("\nEnter three values in dollars to be converted into Euro\n");
            
            for(int i = 0; i < no_of_values; i++)
            {
                scanf("%f", &array[i]); // all values entered are stored inside the array
            }
            
            // Call function change_to_Euro() and pass the array into this function. When you pass it, the function should return the average back into the main()
        
            average = change_to_Euro(array,no_of_values); // passes array and the number of values entered by the user into the function
        
            printf("\nThe average of the values converted into Euro is %.2f\n", average); // average returned from the function is printed to screen.
        
            
        }
        
        else if(option == 3) // If option 3 is entered
        {
            int quit_program; // this checks whether the value is 3. If it is, the program will end.
            printf("\nAre you sure that you want to quit the program? If yes, press 3 again\n");
            scanf("%d", &quit_program); // the value entered by the user is stored
            if (quit_program == 3) // if the user entered 3
            {
                counter = 0; // stop the program
            }
            else // otherwise 
            {
                printf("You are redirected back to the main menu: ");
                counter = 1; // back to the main menu
            }
        }
        else // If none of the options were chosen
        {
            printf("None of the options have been selected. Pick a valid option: "); // error message and the user is returned back to the main menu

        }
    }
    


    getchar();
    return 0;
}

/* Implement the function change_to_Dollar() and pass the array into it as well as the number of values entered by the user. 
   Once passed, the function will find the average and return this value into the main()
*/

float change_to_Dollar(float array1[SIZE],int number_of_values) // Function with a return type of float
{
    float avg;
    float total = 0;
    float convertedvalue[SIZE];
    
    for(int i = 0; i < number_of_values; i++)
    {
        convertedvalue[i] = array1[i] * 1.19; // multiply the value entered by the user with the exchange rate from euro to dollar.
        total = total + convertedvalue[i]; // add the total that you got from the above calculation into the total variable to keep count of the total.
        
    }
    
    for(int i = 0; i < number_of_values; i++)
    {
        printf("\n%.2f Euro -> %.2f Dollars\n", array1[i],convertedvalue[i]); // print the values that were converted
    }
    
    avg = total / number_of_values; //average is calculated by dividing the total with the amount of values entered
    
    getchar();
    return avg;
}

float change_to_Euro(float array2[SIZE],int numb_of_values) // Function with return type float has two arguments - an array and the number of values entered
{
    float avg2; // Calculates the average when you divide the total of the converted values with the number of values entered
    float total2 = 0; // Keeps track of the total
    float convertedvalue2[SIZE]; // array of int type that stores the converted values
    
    for(int i = 0; i < numb_of_values; i++)
    {
        convertedvalue2[i] = array2[i] * 0.84; // Multiply the value entered by the user with the conversion rate for a euro.
        total2 = total2 + convertedvalue2[i]; // add the converted value to the total and keep track.
    }
    
    for(int i = 0; i < numb_of_values; i++)
    {
        printf("\n%.2f US Dollar -> %.2f Euro\n", array2[i],convertedvalue2[i]); // presents the user with the converted values
    }
    
    avg2 = total2 / numb_of_values; // divides total with the number of values to get an average
    
    getchar();
    return avg2;
}
