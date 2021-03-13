/*  Program that allows user to create an account, log on, deposit money, withdraw money,pay a bill, display information and log off.
    This is a simple banking app that a user can use to easily.
    
    
    ****************************This is my personal project that I did***********************************
    Author: Amar Plakalo
    Date - Updated: 13 March 2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define SIZE 5


int main()
{
    // Declare variables needed
    
    int option,age,option_1_completed = 0;
    int log_on = 0;
    int company_acc_no = 0;
    int verify_my_acc_no = 0;
    int acc_number = 0;
    int pin_entered = 0;
    int index_deposit = 0;
    int index_withdraw = 0;
    float previous_deposits[SIZE];
    float previous_withdraws[SIZE];
    float bill_total = 0;
    char message[100];

    srand(time(0));
    int account_number = (rand() % (99999-10000 + 1)) + 10000;
    int pin = (rand() % (9999-1000 + 1)) + 1000;
    int counter = 1;
    char logout;
    char name[20];
    float cashdeposit,cashwithdraw,accountbalance;
    
    
while (counter == 1)
{    
    
    printf("\nWelcome to Bank for the Future: \n");
    printf("\nMain Menu: \n");
    printf("\n1.Create an account: \n");
    printf("\n2.Log into account: \n");
    printf("\n3.Cash Deposit: \n");
    printf("\n4.Cash Withdrawal: \n");
    printf("\n5.Pay a bill: \n");
    printf("\n6.Display account information: \n");
    printf("\n7.Logout\n");
    printf("\n8.Exit Program\n");
    printf("\n9.Clear output screen and display available options\n");
    
    scanf("%d", &option);
    
    switch(option)
    {
        case 1: // Create an account
        {
            if (option_1_completed == 0 && log_on == 0)
            {
                printf("\nWhat is your name?\n");
                scanf("%s", &name);
                getchar();
            
                printf("\nHow old are you?\n");
                scanf("%d", &age);
                getchar();
                if(age < 18)
                {
                    printf("\n------------------------------------------------------------------------\n");
                    printf("\nYou are too young to create an account with us. You must be 18 or higher\n");
                    printf("\n------------------------------------------------------------------------\n");
                    option_1_completed = 0;
                    break;
                    
                }
                else if(age >= 18)
                {
                    printf("\nCongrats! You have created your first bank account. Use it wisely and earn a lot of money\n");
                }

                printf("How much money do you wish to put into your bank account? ");
                scanf("%f",&accountbalance);

                printf("\n----------------------------------------------\n");

                if(accountbalance < 0)
                {
                    printf("\n------------------------------------------------------------------------------\n");
                    printf("You cannot put deposit a minus number into your account. Only positive numbers: \n");
                    printf("\n------------------------------------------------------------------------------\n");
                    accountbalance = 0;
                    option_1_completed = 0;
                    break;

                }
                else if(accountbalance > 0)
                {
                    printf("\n--------------------------------------------------------------------\n");
                    printf("You successfully put %.2f into your account. Well done!!!\n",accountbalance);
                    option_1_completed = 1;
                    printf("Your account number is : %d\n",account_number);
                    printf("Your PIN is %d. Keep this safe!!\n",pin);
                    printf("\n--------------------------------------------------------------------\n");
                    break;
                }
            
                break;
            }
            else if(option_1_completed == 1)
            {
                printf("\n-----------------------------------------------------------\n");
                printf("You already created an account. You cannot create one again: \n");
                printf("\n-----------------------------------------------------------\n");
                break;
            }
            
        }
        case 2: // Log on
        {
            if(option_1_completed == 1 && log_on == 0)
            {
                printf("Hello! Enter your account number and PIN in order to log on: \n");
                scanf("%d",&acc_number);
                getchar();
                scanf("%d",&pin_entered);
                getchar();
                if (acc_number == account_number)
                {
                    if (pin == pin_entered)
                    {
                        printf("\n------------------------------------------------------------\n");
                        printf("Well done. Correct account number and PIN. You are logged on: \n");
                        printf("\n------------------------------------------------------------\n");
                        log_on = 1;
                        break;
                    }
                    else if(pin != pin_entered)
                    {
                        printf("\n-------------\n");
                        printf("Incorrect PIN: \n");
                        printf("\n-------------\n");
                        log_on = 0;
                        break;
                    }
                }
                else if(acc_number != account_number)
                {
                    printf("\n------------------------\n");
                    printf("Incorrect account number: \n");
                    printf("\n------------------------\n");
                    log_on = 0;
                    break;
                }
            }
            else if(option_1_completed == 0)
            {
                printf("\n---------------------------------------\n");
                printf("You have not registered - cannot log in: \n");
                printf("\n---------------------------------------\n");
                log_on = 0;
                break;
            }
            else if(log_on == 1)
            {
                printf("\n-----------------------------------------------------\n");
                printf("You cannot log on because - you have already logged on!\n");
                printf("\n-----------------------------------------------------\n");
                log_on = 1;
                break;
            }
        }
        
        case 3: // Cash deposit
        {
            if(option_1_completed == 1 && log_on == 1)
            {
                printf("\nHow much cash do you wish to deposit? \n");
                scanf("%f", &cashdeposit);
                if (cashdeposit < 0)
                {
                    printf("\n------------------------------------\n");
                    printf("You cannot deposit a negative number: \n");
                    printf("\n------------------------------------\n");
                    break;
                }
                else if(cashdeposit > 0)
                {
                    printf("\n-----------------------------------------------------------------------------\n");
                    printf("\nTo confirm, You have chosen to deposit %.2f into your bank account\n", cashdeposit);
                    printf("\n-----------------------------------------------------------------------------\n");
                    accountbalance = accountbalance + cashdeposit;
                    previous_deposits[index_deposit] = cashdeposit;
                    index_deposit++;
                    if(index_deposit == 5)
                    {
                        index_deposit = 0;
                        break;
                    }
                    
                    break;
                }
            }
            else if(option_1_completed == 0)
            {
                printf("\n-------------------------------------------------------------\n");
                printf("You have not created an account - you cannot deposit cash yet: \n");
                printf("\n-------------------------------------------------------------\n");
                option_1_completed = 0;
                break;
            }
            else if(option_1_completed == 1 && log_on == 0)
            {
                printf("You haven't logged on - cannot deposit\n");
                break;
            }
        }
        
        case 4: // Cash withdrawal
        {
            if(option_1_completed == 1 && log_on == 1)
            {
                printf("\nHow much money do you want to withdraw from your account?\n");
                scanf("%f", &cashwithdraw);
                if(accountbalance < 0)
                {
                    printf("\n---------------------------------------------------------------------------------\n");
                    printf("You cannot withdraw the money from the account because the balance is less than 0: \n");
                    printf("\n---------------------------------------------------------------------------------\n");
                    break;
                }
                else if(accountbalance > 0)
                {
                    printf("\n-------------------------------------------------------------------\n");
                    printf("\nTo confirm, You wish to withdraw %.2f from your account\n", cashwithdraw);
                    printf("\n-------------------------------------------------------------------\n");
                    accountbalance = accountbalance - cashwithdraw;
                    previous_withdraws[index_withdraw] = cashwithdraw;
                    index_withdraw++;
                    if (index_withdraw == 5)
                    {
                        index_withdraw = 0;
                        break;
                    }
                    break;
                }
            }
            else if(option_1_completed == 0 && log_on == 0)
            {
                printf("\n-----------------------------------------------------------\n");
                printf("You cannot withdraw money - You have not created an account: \n");
                printf("\n-----------------------------------------------------------\n");
                option_1_completed = 0;
                break;
            }
            else if(option_1_completed == 1 && log_on == 0)
            {
                printf("You have not logged in - cannot withdraw\n");
                break;
            }
        }

        case 5: // Pay a bill
        {
            if(option_1_completed == 1  && log_on == 1)
            {
                printf("\nEnter the account number of the company: \n");
                scanf("%d",&company_acc_no);
                getchar();
                printf("\nEnter the bill amount that you are due to pay: \n");
                scanf("%f",&bill_total);
                if(accountbalance - bill_total >= 0)
                {

                    printf("\nWrite a short note, e.g. This is my payment for the electricity bill: \n");
                    getchar();
                    gets(message);

                    printf("\nEnter your account number to verify that this is you: \n");
                    scanf("%d", &verify_my_acc_no);


                    if (verify_my_acc_no == account_number)
                    {
                        printf("\n-------------------------\n");
                        printf("\nSuccessful transaction!!!\n");
                        accountbalance = accountbalance - bill_total;
                        previous_withdraws[index_withdraw] = bill_total;
                        index_withdraw++;
                        if (index_withdraw == 5)
                        {
                            index_withdraw = 0;
                            break;
                        }
                        
                        printf("\n-------------------------\n");
                        break;
                    }
                    else
                    {
                        printf("\n----------------------------------\n");
                        printf("\nIncorrect account number entered: \n");
                        printf("\n----------------------------------\n");
                        break;
                    }
                }
                else if(accountbalance - bill_total < 0)
                {
                    printf("\n---------------------------------------------------------------\n");
                    printf("You cannot pay for the bill - The account balance will go under 0: ");
                    printf("\n---------------------------------------------------------------\n");
                    break;
                }
            }
            else if(log_on == 0)
            {
                printf("\n--------------------------------------------\n");
                printf("You cannot pay a bill - You have not logged on: ");
                printf("\n--------------------------------------------\n");
                break;
            }
        }

    
        
        case 6: // Display account information
        {
            if(option_1_completed ==  1 && log_on == 1)
            {
                printf("\n------------------------------------------\n");
                printf("\nAccount Name - %s\n",name);
                printf("\nYour account balance - %.2f\n", accountbalance);
                printf("\nPrevious deposits - \n");
                for(int i = 0; i < index_deposit; i++)
                {
                    printf("%f,",previous_deposits[i]);
                }

                printf("\n");
                printf("\nPrevious withdraws - \n");
                for(int i = 0; i < index_withdraw; i++)
                {
                    printf("%f,",previous_withdraws[i]);
                }
                printf("\n------------------------------------------\n");
            
                break;
            }
            else if(option_1_completed == 0 || log_on == 0)
            {
                printf("\n----------------------------------------------------------------------------------\n");
                printf("You cannot display information about the account - You have not created an account: \n");
                printf("\n----------------------------------------------------------------------------------\n");
                option_1_completed = 0;
                break;
            }
        }
        
        case 7: // Logout
        {
            if(option_1_completed == 1 && log_on == 1)
            { 
                printf("\nDo you really want to logout? If Yes, press y and press n if No: \n");
                getchar();
                scanf("%c", &logout);
                if(logout == 'y' || logout == 'Y')
                {
                    printf("\n----------------------------------------------------\n");
                    printf("Thanks for using the app!!! Press any button to exit: \n");
                    printf("\n----------------------------------------------------\n");
                    counter = 0;
                    break;
                }
                else if(logout == 'n' || logout == 'N')
                {
                    printf("\n------------------------------------------------\n");
                    printf("Ok. Enter any button to return back to main menu: \n");
                    printf("\n------------------------------------------------\n");
                    break;
                }
                else
                {
                    printf("\n------------------------------------------\n");
                    printf("Not the correct option selected!!Try again: \n");
                    printf("\n------------------------------------------\n");
                    break;
                }
            }
            else if(option_1_completed == 1 && log_on == 0)
            {
                printf("\n-------------------------------------------\n");
                printf("You have not logged in - you cannot log out: \n");
                printf("\n-------------------------------------------\n");
                break;
                
            }
            else if(option_1_completed == 0 && log_on == 0)
            {
                printf("\n-------------------------------------------------\n");
                printf("You cannot log out- you haven't registered an account");
                printf("\n-------------------------------------------------\n");
                break;
            }
        }
        
        case 8: // Exit Program
        {
            int exit_program_option = 0;
            printf("Do you want to exit this program? If yes, choose number 8. Otherwise, press any other button to return back to the menu: ");
            scanf("%d",&exit_program_option);
            if (exit_program_option == 8) // if the user chose 8
            {
                printf("\n-----------------------------------------------------------------------\n");
                printf("\nThanks for using this app!!! Press any button and you're done!! Goodbye!!");
                printf("\n-----------------------------------------------------------------------\n");
                counter = 0; // this will stop the while loop from executing, which ends the program.
                break;
            }
            else
            {
                printf("\n--------------------\n");
                printf("Back to the main menu!");
                printf("\n--------------------\n");
                counter = 1; // this will let the while loop continue running as normal.
                break;
            }
        }

        case 9: // Clear output and display available options
        {
            system("cls"); // clears the screen for visibilty purposes
            break;
        }
        default:
        {
            printf("\n-------------------------------------------\n");
            printf("None of the options was selected. Try again: \n");
            printf("\n-------------------------------------------\n");
        }
    } // End switch statement
}

    getchar();
    getchar();
    return 0;
}
