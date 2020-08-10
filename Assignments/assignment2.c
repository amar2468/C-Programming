/* This is a program that will play the lotto game. It will allow the user to enter six numbers of their choice and give them a set of options, each performing a specific requirement. This program will display a simple menu to the user and the user will
    choose which option they want to pick. Once the user selects the option to enter their preferred numbers, the numbers will be shown onto the screen from the smallest to the highest. Then the program will compare these selected numbers with the 
    winning numbers and will output a message, which tells the user which prize they have won.
    Author: Amar Plakalo
    Date: 23 February 2020, updated 08/03/2020
    Used Borland Compiler on Windows 10
*/

#include <stdio.h>

#define NUMBERS 6
#define NUMBERS2 43


// Function Signatures. These are the functions that we will be using in this lotto game

    void selected_numbers(int*,int*,int*); // Function to input numbers in the array

    void display_numbers(int*); // Function that displays these numbers to screen

    void ascending_order(int*); // Function that sorts these numbers in ascending order

    void compare_numbers(int*,int*); // Function which compares the winning numbers to your selected numbers and outputs the prize that you have received
    
    void frequency_numbers(int*); // Function which counts how many times a number was entered without exiting the program

    void exit_program(int*, int*); // Function that quits the program or redirects user back to menu.
    

int main()
{

        int winningnumbers[NUMBERS] = {1,3,5,7,9,11}; // These are the winning numbers of the lotto
    
        int selectednumbers[NUMBERS]; // These are the numbers that the user selects
        
        int countnumbers[NUMBERS2] = {0}; // This will store each element that is entered and it will check the frequency of it
        
        int remembernumbers[NUMBERS2] = {0}; // This will help store the value of countnumbers[NUMBERS2] so that it does not get overwritten
    
        int option; // This is the option that the user chooses in the main menu
    
        int exit = 0; // This is a variable that is set to 0. It is used when the user wants to exit the program
        
        int second_option = 0; // This is needed in order to avoid the user picking option 1 at the start
        
        int third_option = 0; // This is needed in order to avoid the user picking option 1 at the start
        
        int fourth_option = 0; // This is needed in order to avoid the user picking option 1 at the start
        
        int fifth_option = 0; // This is needed in order to avoid the user picking option 1 at the start


    do // This do statement will ensure that the code in the body of this statement will be executed at least once
    {
        printf("\nLotto Game: Main Menu\n");
        printf("\n1.Enter your six numbers from 1 to 42 inclusive\n");
        printf("\n2.Display the numbers that you have selected\n");
        printf("\n3.Sort your selected numbers in ascending order\n");
        printf("\n4.Compare your selected numbers with the winning numbers.\n");
        printf("\n5.Frequency of the numbers selected by the user\n");
        printf("\n6.Exit\n");
    
        scanf("%d", &option); // Records the option that the user picked
 
        
            switch(option) // This switch will be made up of six cases that represent the six menu choices. Each case will perform the specific menu option that the user chooses
            {
                case 1: // This is if the user enters option 1, which asks the user to enter six numbers
                {
                    printf("\nEnter six numbers of your choice from 1 to 42 inclusive: \n");
            
                    selected_numbers(selectednumbers,countnumbers,&option); // This function will be returning two arrays and a variable
                    
                    second_option++; // Incremented in order to enable user to pick options 2 or 3 or 4 or 5
                    third_option++;  // Incremented in order to enable user to pick options 2 or 3 or 4 or 5
                    fourth_option++; // Incremented in order to enable user to pick options 2 or 3 or 4 or 5
                    fifth_option++; // Incremented in order to enable user to pick options 2 or 3 or 4 or 5
                
                    break; // This is required in order to quit the case after it is completed
                        
                }
        
                case 2: // This is if the user enters option 2, which displays these numbers to screen
                {
                    if(second_option > 0)
                    {
                        printf("\nThese are the numbers that you have selected: \n");
            
                        display_numbers(selectednumbers); // The numbers entered in option 1 will be returned to this function and displayed to screen
            
                        break; // Breaks the case so that we can move on to the next option
                    }
                    
                    else
                    {
                        printf("\nYou must pick option 1 first\n"); // Error message if option 1 was not picked
                        break;
                    }
                    
                }
        
                case 3: // This is if the user enters option 3, which sorts the selected numbers in ascending order
                {
                    if(third_option > 0)
                    {  
                        ascending_order(selectednumbers); // This function will return the array in order
                
                        printf("\nNumbers successfully sorted in order\n");
            
                        break; // Required to break the case
                    }
                    
                    else
                    {
                        printf("\nYou must pick option 1 first\n"); // Error message if option 1 was not picked
                        break;
                    }
                }
        
                case 4: // This is if the user enters option 4, which compares the users numbers with the winning array.
                {
                    if(fourth_option > 0)
                    {
                        
                        compare_numbers(winningnumbers,selectednumbers); // Function passes two arrays so that they can be compared
                        break;
                    }
                    else
                    {
                        printf("\nYou must pick option 1 first\n"); // Error message if option 1 was not picked
                        break;
                    }
                }
        
                case 5: // This is if the user enters option 5, which counts the frequency of the numbers entered by the user.
                {
                    if(fifth_option > 0)
                    {
                        
                        for(int i = 0; i < NUMBERS2; i++)
                        {
                            *(remembernumbers + i) = *(countnumbers+ i); // Copies the content of the array count numbers into the array remembernumbers. This is here so that the numbers entered by the user don't get overwritten each time the user enters new numbers
                        }
                
                        frequency_numbers(remembernumbers); // Returns the array of numbers that counts the frequency of the numbers entered
            
                        break;
                    }
                    
                    else
                    {
                        printf("\nYou must pick option 1 first\n"); // Error message if option 1 was not picked
                        break;
                    }
                }
        
                case 6: // This is if the user enters option 6, which will give the user a choice of whether they want to exit the program or return back to the main menu
                {
    
                    exit_program(&exit,&option); // Returns the option that the user picked in the function
                
                    break;
                }
        
                default: // This is if the user entered anything that is not within the range of 1-6. 
                {
                    printf("\nYou have not selected a number from the screen. Try again\n");
            
                    break;
                }
        
            } // End switch statement
    } // End do
    
    while(option != 6); // Program will not end until option is 6
    
    getchar();
    return 0;
}

// All functions used are below. There is a function for each option selected.
    
/* Implement selected_numbers() function. This function will store six numbers in the array so that we can perform other tasks that this program contains
*/

void selected_numbers(int *selectednumbers2, int *count_numbers, int *menu_option) // This function will return the selected numbers and the count of the numbers. This count will be used in order to calculate the frequency
{
    
    for(int i = 0; i < NUMBERS; i++)
    {
        scanf("%d", & *(selectednumbers2 + i)); // Scans the number entered

        *(count_numbers + *(selectednumbers2 + i)) = *(count_numbers + *(selectednumbers2 + i)) + 1; // The counts numbers gets incremented to find out the frequency of each of the numbers entered while the lotto game was being played
       
        
        if(*(selectednumbers2 + i) <= 0 || *(selectednumbers2 + i) > 42) // This is to error check if the number selected is less than or equal to 0 or greater than 42
        {
            printf("\nYou are not allowed to enter a number less than 1 and higher than 42. You are being redirected back to the main menu\n");
            
            *menu_option = 1; // Return to main menu
            
            break; // Break statement and return to main menu
        }
        
        
    }

    for(int i = 0; i < NUMBERS; i++)
    {
        for(int j = i + 1; j < NUMBERS; j++)
        {
            if(*(selectednumbers2 + i) == *(selectednumbers2 + j)) // If an element is the same as the element ahead, do this statement
            {
                printf("You have repeated the number %d\nEnter your numbers again\n", *(selectednumbers2 + i)); // Prints out an error message that tells you that you have repeated a number 
            }
            
        }
        
    }
    
    //This for loop will initialise all elements in the array with zeros. This will mean that the user will have to rewrite all his/her numbers
    
    for(int i = 0; i < NUMBERS; i++) 
    {
        for(int j = i + 1; j < NUMBERS; j++)
        {
            if(*(selectednumbers2 + i) == *(selectednumbers2 + j) || *(selectednumbers2 + i) <= 0 || *(selectednumbers2 + i) > 42) // If the number is equal to the next one
            { // Set all elements to 0
                
                *(selectednumbers2 + 0) = 0;
                *(selectednumbers2 + 1) = 0;
                *(selectednumbers2 + 2) = 0;
                *(selectednumbers2 + 3) = 0;
                *(selectednumbers2 + 4) = 0;
                *(selectednumbers2 + 5) = 0;
                
                
            }
        }
    }
    

    
}

/* Implement display_numbers() function. This function will display the numbers that the user has entered. 
*/

void display_numbers(int *displaynumbers) // This function will return the output of the numbers selected
{
    
    for(int i = 0; i < NUMBERS; i++)
    {
        printf("%d\n", *(displaynumbers + i)); // Prints each element of the array
    }
    
    
}

/* Implement ascending_order() function. This function will sort the elements from the smallest to the highest.
*/

void ascending_order(int *ascendingorder) // This function will return a sorted array back to main()
{
    int temp; // Temporary variable that is used to store the current number in the array


    
    for(int i = 0; i < NUMBERS; i++)
    {
        for(int j = i + 1; j < NUMBERS; j++)
        {
            if(*(ascendingorder + j) < *(ascendingorder + i)) // If the number is less than the previous number, execute this statement
            {
                temp = *(ascendingorder + j); // Store the smaller number in the variable temp
                
                *(ascendingorder + j) = *(ascendingorder + i); // Store the greater value in the position ahead
                
                *(ascendingorder + i) = temp; // Store the smaller value in the position behind
            
            }
        } 
    }
    
}

/* Implement compare_numbers() function. This function will compare the numbers that the user entered with the winning numbers. 
*/

void compare_numbers(int *winnumbers,int *enterednumbers) // This function will return the winning numbers and the entered numbers and announce the prize that the user won. If no prize, a message will be displayed
{
    int score = 0; // Counts the amount of correct numbers chosen by the user
    
    for(int i = 0; i < NUMBERS; i++)
    {
        for(int j = 0; j < NUMBERS; j++)
        {
            
            if(*(enterednumbers + i) == *(winnumbers + j))
            {
                score++; // Incremented each time user guesses right
            }
        }
    }
    
    
    printf("\nThese are your selected numbers in order\n");
    
    for(int i = 0; i < NUMBERS; i++)
    {
        printf("%d\n", *(enterednumbers + i));
    }
        
        if(score == 6) //If all of the users numbers match all of the winning numbers, this will be displayed
        {
            printf("\nYou have received the Jackpot. Congrats!\n");
        }   
        
        else if(score == 5) //If five of the users numbers match five of the winning numbers, this will be displayed
        {
            printf("\nYou have received a new car. Congrats!\n");
        }
        
        else if(score == 4) // If four of the users numbers match four of the winning numbers, this will be displayed
        {
            printf("\nYou have received a weekend away. Congrats\n");
        }
        
        else if(score == 3) // If three of the users numbers match three of the winning numbers, this will be displayed
        {
            printf("\nYou have received a cinema pass. Congrats\n");
        }
        
        else // This will be printed if the user did not win any prize
        {
            printf("\nYou have not won a prize.\n");
        }
        
        
    
}

/* Implement frequency_numbers() function. The job that this function must do is to count the number of times a number has been entered while the lotto game was played. If the user quits the lotto game and starts again, the number count
will be back to zero and the record of the numbers entered will be erased.
*/

void frequency_numbers(int *remember_numbers) // This will return to main() the amount of times a number was entered
{
    for(int i = 0; i < NUMBERS2; i++)
    {
        if(*(remember_numbers + i) != 0)
        {
            printf("\n%d has been selected %d times\n", i, *(remember_numbers + i)); // Prints out how many times a number occurred
        }
    }
}



/*  Implement exit_program() function. This function will either quit the program for the user or redirect him/her to the main menu, depending on their choice.
*/

void exit_program(int *choice, int *menuoption) // This function returns the choice that the user made. It also returns to menu if the user wants to play the lotto game again
{
    printf("\nAre you sure that you want to quit this program? If so, press the number 6 again. If you wish to return to main menu, press 1 \n");
    scanf("%d", & *choice);
    getchar();
    
    if(*choice == 6) // If user presses six when asked do they want to exit program
    {
        printf("\nThanks for playing! Press enter to exit\n");
        
    }
    
    else if(*choice == 1) // If user presses one when asked do they want to exit program
    {
        printf("\nYou are now returning to the main menu. Good luck!\n");
        
        *menuoption = 1;
            
    }
    
    else // If the user does not choose 1 or 6
    {
        printf("\nReturning to the main menu\n");
        
        return;
    }

}