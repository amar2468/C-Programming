/* Program that lets user enter or generate a four digit code. Then, this code is encryped and compared with the access_code. If it is correct
then the user is displayed a message which says that the code entered was correct. If it is incorrect, a message stating that the 
code is incorrect will be displayed to screen. The number of times a code was guessed correctly and incorrectly will be displayed to screen.
The user also has an option to decrypt the encrypted code.
Author: Amar Plakalo
Used Visual Studio Code on Windows 10
Date: 22 April 2020 updated 13/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size of 4 is defined so that it can be used throughout the program
#define SIZE2 2 // Size of 2 is also needed in this program

// Structure that we will need in the program

struct code_counter
{
    int correct_code; // Records amount of correct times code was entered
    int wrong_code;// Records amount of wrong times code was entered
};

// Function Signatures

void enter_code(int*); // This function will ask the user whether they want to enter a code or generate one.

void encrypt_code(int*); // This function will encrypt the code that the user entered or generated.

void code_match(int*,int*,int*,int*); // This function will compare the encrypted code with the access_code

void decrypt_code(int*); // This function will decrypt the encrypted code entered or generated by the user

void correct_incorrect(int*,int*); // This function will count the number of correct and incorrect times a code was entered

int exit_program(); // This function will ask the user whether they want to exit from the program or return to main menu

int main()
{ // Begin main()
    int access_code[SIZE] = {4,5,2,3}; // This code is the default access code. This code will be compared with the entered or generated code

    int my_code[SIZE]; // This is the code that the user enters or generates

    int option; // This records the menu option that the user picks

    int correct = 0; // This records the amount of correct times a user guesses a code.

    int incorrect = 0; // This records the amount of incorrect times a user guesses a code

    int second_option = 0; // The second option is set to 0 so that the user does not pick option any option at the start apart from option 1,5,6

    int third_option = 0; // The third option is set to 0 so that the user does not pick option any option at the start apart from option 1,5,6

    int fourth_option = 0; // The fourth option is set to 0 so that the user does not pick option any option at the start apart from option 1,5,6
    
    int counter = 1;

    while(counter == 1)
    {
        printf("\nMain Menu\n");
        printf("\n1.Enter a code or generate a random code\n");
        printf("\n2.Encrypt a code\n");
        printf("\n3.Check if encrypted code matches access_code\n");
        printf("\n4.Decrypt code\n");
        printf("\n5.Display number of times code was correct and incorrect\n");
        printf("\n6.Exit program\n");
        scanf("%d", &option); // Records the option chosen by the user

        switch(option) // This switch statement consists of cases where each case represents a menu choice. Each case calls a function that does a certain thing
        {
            case 1: // Menu option 1 calls the enter_code function and allows user to either enter code or generate it
            { // Start case 1
                enter_code(my_code); // Function called so that user can enter the code

                second_option++; // Once option 1 is done, the user has the choice to choose option 2

                break; // Case statement ends
            } // End case 1

            case 2: // Menu option 2 calls the encrypt_code function which encrypts the code entered or generated
            { // Start case 2
                if(second_option > 0) // If option 2 is selected after option 1
                { // Start if statement 
                    encrypt_code(my_code); // Calls function which encrypts the code that is entered or generated
                    second_option = 0; // second option is set to 0 so that the user does not encrypt an already encrypted code
                    third_option++; // User is allowed to use option 3
                    break; // End this part of the case statement
                } // End if statement

                else // If option 2 is selected before option 1
                { // Begin else
                    printf("\nYou must choose option 1 first\n"); // Error message displayed
                    break; // End second part of case statement
                } // End else
                
            } // End case 2

            case 3: // Menu option 3 calls code_match function which compares the code entered or generated with the access_code and displays message that code is correct or that code is not correct
            { // Start case 3
                if(third_option > 0) // If option 3 is selected after option 2
                { // Begin if statement
                    code_match(access_code,my_code,&correct,&incorrect); // Call function that will compare the access code with the code entered or generated
                    third_option = 0; // third menu option is set to 0 so that user does not compare the code again once he compares it once
                    fourth_option++; // Now, user can choose option 4
                    break; // End this part of the case statement
                } // End if statement

                else // If option 3 is selected before option 1 or option 2
                { // Begin else
                    printf("\nYou must choose option 1 first\n"); // Error message displayed
                    break; // End this part of case statement
                } // End else
                
            } // End case 3

            case 4: // Menu option 4 calls decrypt_code function that will decrypt an already encrypted code
            { // Begin case 4
                if(fourth_option > 0) // If option 4 is selected after option 1
                { // Begin if statement
                    decrypt_code(my_code); // Calls the function that will decrypt the code entered or generated
                    fourth_option = 0; // Now, user cannot chooses option four once he has done it once
                    break; // End this part of case statement
                } // End if statement

                else // If option 4 is selected before option 1
                { // Begin else statement
                    printf("\nYou must choose option 1 first\n"); // Error message displayed
                    break; // End this part of case statement
                } // End else statement
                
            } // End case 4

            case 5: // Menu option 5 will call correct_incorrect function that will count number of correct and incorrect times a code was entered
            { // Begin case 5
                correct_incorrect(&correct,&incorrect); // Call function correct_incorrect which will count number of correct and incorrect time a code was entered
                break; // End case
            } // End case 5

            case 6: // Menu option 6 will run the exit_program function which will ask the user whether they want to exit from the program.
            { // Begin case 6
                int new_counter;
                new_counter = exit_program(); // Call function exit_program which will ask user if they want to exit from program
                if (new_counter == 1)
                {
                    counter = 1;
                    break;
                }
                else if(new_counter == 0)
                {
                    counter = 0;
                    break;
                }
                break; // End
            } // End case 6

            default: // If a menu option that is not from 1-6 is entered
            { // Start default
                printf("\nYou have entered an option that is not between 1-6. Try again\n"); // Error message
                scanf("%c", &option); // Scans for a character if it was entered
                break;
            } // End default
        } // End switch statement
    }

    getchar(); // This ensures that the program does not crash
    return 0;

} // End main()

// All functions are below.

/*  Implement function enter_code. This function will give the user an option of whether they want to enter a code or generate one.
    The user can only use numbers from 0-9
*/

void enter_code(int *code_entered) // Function that allows user to enter a code or generate one
{ // Begin enter_code()
    int choice; // variable that will store the option chosen by the user

    printf("\nPress 1 to enter the code or press 2 to generate the code\n"); // Message that asks user to enter 1 or 2
    scanf("%d", &choice); // Records the response and stores it in the variable named "choice".

    switch(choice) // Switch statement which consists of two cases which either allows user to enter the code or generates one
    { // Begin switch
        case 1: // This is if user chose to enter a code
        { // Begin case 1
            printf("\nEnter the four digit code\n"); // Asks user to enter the code
            for(int i = 0; i < SIZE; i++) // For loop that runs 4 times and records the code entered
            { // Begin for loop
                scanf("%d", & *(code_entered + i)); // Scans the integer entered and puts it into the array the stores the code
                while(*(code_entered + i) < 0 || *(code_entered + i) > 9) // While loop that will be executed if a number is not between 0-9
                { // Begin while
                    printf("\nYou must only choose a number from 0-9\n"); // Error message
                    scanf("%d", & *(code_entered + i)); // Forces user to enter a different number
                } // End while
            } // End case 1
            break; // End of execution
        } // End case 1

        case 2: // This is if user chose to generate a code
        { // Begin case 2
            srand(time(0)); // randomises the numbers that are generated so that the same numbers are not chosen
            printf("\nThe generated code is \n"); // Message displayed to screen
            for(int i = 0; i < SIZE; i++) // For loop that runs four times and puts the generated code into the array that stores the code entered
            { // Begin for loop
                *(code_entered + i) = rand () % 10; // Put the random number into the array
                printf("%d\n", *(code_entered + i)); // Present the number to screen
            } // End for loop
            break; // End this execution
        } // End case 2

        default: // If option 1 or 2 is not picked
        { // Begin default
            printf("\nReturning back to main menu\n"); // Error message displayed
            return;
        } // End default
    } // End switch statement

} // End enter_code() function

/*  Implement encrypt_code function. This function will take the code entered and encrypt it using its algorithm. The encrypted code will
    be displayed to screen so that the user can see it
*/

void encrypt_code(int *user_code) // Begin encrypt_code () function
{ // Begin encrypt_code() function
    int temp; // Variable created that will store the temporary value so that the values can be switched without being overwritten

    for(int i = 0; i < SIZE2; i++) // For loop that runs 2 times so that the positions can be switched successfully
    { // Begin for loop
        temp = *(user_code + i); // Store the value of the first position into temp variable
        *(user_code + i) = *(user_code + i + 2); // Store value of the (current position + 2) into the current position
        *(user_code + i + 2) = temp; // Store temp value into (current position + 2)
        (*(user_code + i))++; // Increment current position
        (*(user_code + i + 2))++; // Increment (current position + 2)

        
        if(*(user_code + i) == 10) // If after encryption, the value of the current position is 10, turn it into 0
        { // Begin if
            *(user_code + i) = 0; // Set the value inside the current position to be 0
        } // End if

        if(*(user_code + i + 2) == 10) // If after encryption, the value of the (current position + 2) is 10, turn it into 0
        { // Begin if
            *(user_code + i + 2) = 0; // Set the value inside the (current position + 2) to be 0
        } // End if

    } // End for loop

    printf("\nThe encrypted code is \n"); // Message displayed to output
    for(int i = 0; i < SIZE; i++) // For loop that runs four times and prints the array after encryption
    { // Begin for loop
        printf("%d\n", *(user_code + i)); // Print value in current position of the array
    } // End loop

} // End encrypt_code() function

/* Implement code_match() function. This function will compare the entered or generated code with the access code. If it matches it,
a message that says that the code is correct will be displayed. If it does not match the access code, then the user will see a message
on screen that says that it did not match the access code
*/

void code_match(int *default_code,int *inputted_code,int *no_correct,int *no_incorrect) // Function that will match encrypted code with access_code
{ // Begin code_match() function
    int counter = 0; // This variable will be used to record amount of correct and incorrect times a code was entered

    for(int i = 0; i < SIZE; i++) // For loop which runs four times and compares the codes
    { // Begin for loop
        if(*(default_code + i) == *(inputted_code + i)) // If the number in the first position of the default code is equal to the number in the first position of the entered code
        { // Begin if statement
            counter++; // Increment counter
        } // End if statement
    } // End for loop

    if(counter == 4) // If the two codes had all numbers matched
    { // Begin if statement
        printf("\nCorrect Code Entered\n"); // Message displayed if correct code was entered
        (*no_correct)++; // Increment the counter for the number of times code was correct by one. This will be used in the correct_incorrect() function

    } // End if statement
    else // If two codes did not have all numbers matched
    { // Begin else
        printf("\nWrong Code Entered\n"); // Message displayed if incorrect code was entered
        (*no_incorrect)++; // Increment the counter for the number of times code was incorrect by one. This will be used in the correct_incorrect() function
    } // End else
    
} // End code_match() function

void decrypt_code(int *input_code) // This function will decrypt an already encrypted code
{ // Begin decrypt_code()
    int temp = 0; // Variable that will store a value that is to be switched with a different value

    for(int i = 0; i < SIZE2; i++) // For loop which will be run twice and it will decrypt the code using the decryption algorithm
    { // Begin for loop
        (*(input_code + i))--; // Decrement the current position value by one
        (*(input_code + i + 2)) --; // Decrement the (current position + 2 ) value by one
        temp = *(input_code + i); // Store the value in the current position in the temp variable
        *(input_code + i) = *(input_code + i + 2); // Store the value in the (current position + 2) into the current position
        *(input_code + i + 2) = temp; // Store the value of temp into the (current position + 2)

        if(*(input_code + i) == -1) // If after decryption, the value of the current position is -1, turn it into 9
        { // Begin if
            *(input_code + i) = 9; // Set value inside current position to be 9
        } // End if
        if(*(input_code + i + 2) == -1) // If after decryption, the value of the (current position + 2) is -1, turn it into 9
        { // Begin if
            *(input_code + i + 2) = 9; // Set value inside (current position + 2) to be 9
        } // End if
    } // End for loop

    printf("\nThis is the decrypted code\n"); // Message displayed when printing out the decrypted code
    for(int i = 0; i < SIZE;i++) // For loop that runs 4 times and prints each value of decrypted code to screen
    { // Begin for loop
        printf("%d\n", *(input_code + i)); // Print value to screen
    } // End for loop
} // End decrypt_code() function

void correct_incorrect(int *correct_attempts,int *incorrect_attempts) // This function will show the user the amount of correct and incorrect times they guessed a code
{ // Begin correct_incorrect()
    struct code_counter person; // Create a variable called person that represents the user who is guessing the code

    person.correct_code = *correct_attempts; // *correct_attemepts has recorded the amount of correct times a code was entered in the previous functions and this value is stored into the structure variable called correct_code

    person.wrong_code = *incorrect_attempts; // *correct_attemepts has recorded the amount of incorrect times a code was entered in the previous functions and this value is stored into the structure variable called wrong_code

    printf("\nThe number of correct attempts is %d\n",person.correct_code); // Prints amount of correct attempts by user

    printf("\nThe number of incorrect attempts is %d\n", person.wrong_code); // Prints amount of wrong attempts by user
} // End correct_incorrect() function

int exit_program() // This function will ask the user whether they want to quit the program
{ // Begin exit_program()
    int returned_counter = 0;
    int answer_to_exit;
    printf("Do you want to exit the program? If yes, type the number 6. Otherwise, type the number 1:");
    scanf("%d",&answer_to_exit);
    getchar();
    if(answer_to_exit == 6) // If the user chooses 6
    {
        returned_counter = 0; // this will be returned and the while loop will not execute, meaning that the program ends
        return returned_counter; // return the value
    }
    else if(answer_to_exit == 1) // If user chooses 1
    {
        printf("Back to menu: "); 
        returned_counter = 1; // allows the user to user the program again if they want
        return returned_counter; // returns value
    }

} // End exit_program() function
