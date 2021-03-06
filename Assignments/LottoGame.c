/*  This is a program that will play the lotto game. 
    It will allow the user to enter six numbers of their choice and give them a set of options, each performing a specific requirement. 
    This program will display a simple menu to the user and the user will choose which option they want to pick. 
    Once the user selects the option to enter their preferred numbers, the numbers will be shown onto the screen from the smallest to the highest. 
    Then the program will compare these selected numbers with the winning numbers and will output a message, which tells the user which prize they have won.
    Author: Amar Plakalo
    Date: 23 February 2020, updated 15/03/2021
    Used Visual Studio Code on Windows 10
*/

#include <stdio.h>

#define NUMBERS 6
#define NUMBERS2 43


// Function Signatures. These are the functions that we will be using in this lotto game

    void selected_numbers(int*,int*,int*,int*,int*,int*,int*); // Function to input numbers in the array

    void display_numbers(int*); // Function that displays these numbers to screen

    void ascending_order(int*); // Function that sorts these numbers in ascending order

    void compare_numbers(int*,int*); // Function which compares the winning numbers to your selected numbers and outputs the prize that you have received
    
    void frequency_numbers(int*); // Function which counts how many times a number was entered without exiting the program

    int exit_program(int*,int*,int*); // Function that quits the program or redirects user back to menu.
    

int main()
{

        int winningnumbers[NUMBERS] = {1,3,5,7,9,11}; // These are the winning numbers of the lotto
    
        int selectednumbers[NUMBERS]; // These are the numbers that the user selects
        
        int countnumbers[NUMBERS2] = {0}; // This will store each element that is entered and it will check the frequency of it
        
        int remembernumbers[NUMBERS2] = {0}; // This will help store the value of countnumbers[NUMBERS2] so that it does not get overwritten
    
        int option; // This is the option that the user chooses in the main menu
    
        int exit = 0; // This is a variable that is set to 0. It is used when the user wants to exit the program

        int counter = 1;
        
        int second_option = 0; // This is needed in order to avoid the user picking option 1 at the start
        
        int third_option = 0; // This is needed in order to avoid the user picking option 1 at the start
        
        int fourth_option = 0; // This is needed in order to avoid the user picking option 1 at the start
        
        int fifth_option = 0; // This is needed in order to avoid the user picking option 1 at the start


    while (counter == 1) // This do statement will ensure that the code in the body of this statement will be executed at least once
    {
        printf("\nLotto Game: Main Menu\n");
        printf("\n1.Enter your six numbers from 1 to 42 inclusive\n");
        printf("\n2.Display the numbers that you have selected\n");
        printf("\n3.Sort your selected numbers in ascending order\n");
        printf("\n4.Compare your selected numbers with the winning numbers.\n");
        printf("\n5.Frequency of the numbers selected by the user\n");
        printf("\n6.Exit\n");
    
        scanf("%d", &option); // Records the option that the user picked
        int ch;
        if( ( ch = getchar() ) != '\n' && ch != EOF )
        {
            printf("Incorrect number entered\n");
            option = 0;
        }
        
        switch(option) // This switch will be made up of six cases that represent the six menu choices. Each case will perform the specific menu option that the user chooses
        {
            case 1: // This is if the user enters option 1, which asks the user to enter six numbers
            {
                selected_numbers(selectednumbers,countnumbers,&option,&second_option,&third_option,&fourth_option,&fifth_option); // This function will be returning two arrays and a variable
                    
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
                int new_counter = 1;
    
                new_counter = exit_program(&exit,&option,&counter); // Returns the option that the user picked in the function
                if(new_counter == 0) // if the value returned from the function is 0
                {
                    counter = 0; // stop the program
                    break;
                }
                else // otherwise
                {
                    counter = 1; // let the menu reappear
                    break;
                }
            }
        
            default: // This is if the user entered anything that is not within the range of 1-6. 
            {
                printf("\nYou have not selected a number from the screen. Try again\n");
            
                break;
            }
        
        } // End switch statement
    }
    
    getchar();
    return 0;
}

// All functions used are below. There is a function for each option selected.
    
/* Implement selected_numbers() function. This function will store six numbers in the array so that we can perform other tasks that this program contains
*/

void selected_numbers(int *selectednumbers2, int *count_numbers, int *menu_option, int *second_option, int *third_option, int *fourth_option, int *fifth_option)
{
    printf("\nEnter six numbers of your choice from 1 to 42 inclusive: \n");
    int elements_to_save[NUMBERS] = {}; // This element will be saved so that the array isn't filled with incorrect numbers
    int element_repeated = 0; // to check whether an element was repeated. If it was, don't put into the new array.
    
    for(int i = 0; i < NUMBERS; i++)
    {
        scanf("%d", &*(elements_to_save + i)); // Scans the number entered
        if(*(elements_to_save + i) <= 0 || *(elements_to_save + i) > 42) // This is to error check if the number selected is less than or equal to 0 or greater than 42
        {
            printf("\nYou are not allowed to enter a number less than 1 and higher than 42. You are being redirected back to the main menu\n");
            
            *second_option = -1;
            *third_option = -1;  
            *fourth_option = -1; 
            *fifth_option = -1;
            element_repeated = 1;
        
            *menu_option = 1;
            
            break; // Break statement and return to main menu
        }
    }
    for(int i = 0; i < NUMBERS; i++)
    {
        for(int j = i + 1; j < NUMBERS; j++)
        {
            if(*(elements_to_save + i) == *(elements_to_save + j) && *(elements_to_save + i) > 0)
            {
                printf("%d was repeated. Enter the numbers again!\n", *(elements_to_save + i));
                *second_option = -1;
                *third_option = -1;  
                *fourth_option = -1; 
                *fifth_option = -1;
                element_repeated = 1;
            }
        }
    }

    if (element_repeated == 0)
    {
        for(int i = 0; i < NUMBERS; i++)
        {
            *(selectednumbers2 + i) = *(elements_to_save + i);
            *(count_numbers + *(selectednumbers2 + i)) = *(count_numbers + *(selectednumbers2 + i)) + 1;
        }
    }
}

/* Implement display_numbers() function. This function will display the numbers that the user has entered. 
*/

void display_numbers(int *displaynumbers) // This function will return the output of the numbers selected
{
    printf("\nThese are the numbers that you have selected: \n");
        
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
    int j = 0;

    // Insertion Sort is the sorting algorithm used below
    
    for(int i = 1; i < NUMBERS; i++)
    {
        j = i;
        while(*(ascendingorder + (i-1)) > *(ascendingorder + j)  && i > 0) // If the number is less than the previous number, execute this statement
        {
            temp = *(ascendingorder + i); // Store the smaller number in the variable temp
                
            *(ascendingorder + i) = *(ascendingorder + (i-1)); // Store the greater value in the position ahead
                
            *(ascendingorder + (i-1)) = temp; // Store the smaller value in the position behind
            i = i-1;
            j = j-1; 
        } 
    }
    
    printf("\nNumbers successfully sorted in order\n");
    
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

int exit_program(int *choice,int *menu_option,int *counter_var) // This function returns the choice that the user made. 
                                                                //It also returns to menu if the user wants to play the lotto game again
{
    printf("\nAre you sure that you want to quit this program? If so, press the number 6 again. If you wish to return to main menu, press 1 \n");
    scanf("%d", & *choice); // Listens for the answer from the user
    getchar();
    
    switch(*choice) // switch goes through the cases and checks to see what the program should do
    {
        case 1: // If user chose option 1
        {
            printf("You are returning back to the main menu\n"); // Message printed to screen telling the user that they are returning back to the main menu
            *menu_option = 1; // the option is set to 1 meaning that the menu can reappear again
            *counter_var = 1; // this value is set to 1 and is returned back
            return *counter_var; // return the value
        }
        case 6: // if user chose option 6
        {
            printf("Thanks for playing. Bye!\n"); // Thank you message
            *counter_var = 0; // Value of 0 will be returned
            return *counter_var; // return the value
        }
        
        default: // If none of the options were selected
        {
            printf("The option entered is not one that was specified. The program will return back to the main menu\n"); // message printed to tell user about the mistake
            *menu_option = 1; // sets value to 1 so that the program goes back to the main menu
            *counter_var = 1; // value of 1 will be returned back to the main
            return *counter_var; // return the value
            
        }
    }

}
