/*  Program that allows user to create an account, deposit money, withdraw money, display information and log off.
    This is a simple banking app that a user can use to easily.
    Author: Amar Plakalo
    Date - Updated: 21 February 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    // Declare variables needed
    
    int option,age,option_1_completed = 0;
    int log_on = 0;
    srand(time(0));
    int account_number = (rand() % (99999-10000 + 1)) + 10000;
    int pin = (rand() % (9999-1000 + 1)) + 1000;
    int counter = 1;
    char name,logout;
    float cashdeposit,cashwithdraw,accountbalance;
    
    
while (counter == 1)
{    
    
    printf("\nWelcome to Bank for the Future: \n");
    printf("\nMain Menu: \n");
    printf("\n1.Create an account: \n");
    printf("\n2.Log into account: \n");
    printf("\n3.Cash Deposit: \n");
    printf("\n4.Cash Withdrawal: \n");
    printf("\n5.Display account information: \n");
    printf("\n6.Logout\n");
    printf("\n7.Clear output screen and display available options\n");
    
    scanf("%d", &option);
    
    switch(option)
    {
        case 1: // Create an account
        {
            if (option_1_completed == 0 && log_on == 0)
            {
                printf("\nWhat is your name?\n");
                getchar();
                scanf("%s", &name);
                getchar();
            
                printf("\nHow old are you?\n");
                getchar();
                scanf("%d", &age);
                if(age < 18)
                {
                    printf("\n------------------------------------------------------------------------\n");
                    printf("\nYou are too young to create an account with us. You must be 18 or higher\n");
                    printf("\n------------------------------------------------------------------------\n");
                    option_1_completed = 0;
                    break;
                    
                }
                else
                {
                    printf("\nCongrats! You have created your first bank account. Use it wisely and earn a lot of money\n");
                    option_1_completed = 1;
                }

                printf("How much money do you wish to put into your bank account? ");
                getchar();
                scanf("%f",&accountbalance);

                printf("\n----------------------------------------------\n");

                printf("Your account number is : %d\n",account_number);
                printf("Your PIN is %d. Keep this safe!!\n",pin);

                if(accountbalance < 0)
                {
                    printf("You cannot put deposit a minus number into your account. Only positive numbers: \n");
                    accountbalance = 0;
                    option_1_completed = 0;
                    break;

                }
                else if(accountbalance > 0)
                {
                    printf("You successfully put %f into your account. Well done!!!\n",accountbalance);
                    printf("\n-----------------------------------------------\n");
                    option_1_completed = 1;
                    break;
                }
            
                break;
            }
            else if(option_1_completed == 1)
            {
                printf("You already created an account. You cannot create one again: \n");
                break;
            }
            
        }
        case 2: // Log on
        {
            if(option_1_completed == 1 && log_on == 0)
            {
                printf("Hello! Enter your account number and PIN in order to log on: \n");
                getchar();
                scanf("%d",&acc_number);
                getchar();
                scanf("%d",&pin_entered);
                getchar();
                if (acc_number == account_number)
                {
                    if (pin == pin_entered)
                    {
                        printf("Well done. Correct account number and PIN. You are logged on: \n");
                        log_on = 1;
                        break;
                    }
                    else if(pin != pin_entered)
                    {
                        printf("Incorrect PIN: \n");
                        log_on = 0;
                        break;
                    }
                }
                else if(acc_number != account_number)
                {
                    printf("Incorrect account number: \n");
                    log_on = 0;
                    break;
                }
            else if(option_1_completed == 0)
            {
                printf("You have not registered - cannot log in: \n");
                log_on = 0;
                break;
            }
            else if(log_on == 1)
            {
                printf("You cannot log on because - you have already logged on!\n");
                log_on = 1;
                break;
            }
        }
        
        case 3: // Cash deposit
        {
            if(option_1_completed == 1)
            {
                printf("\nHow much cash do you wish to deposit in your newly created bank account? \n");
                scanf("%f", &cashdeposit);
                if (cashdeposit < 0)
                {
                    printf("You cannot deposit a negative number: \n");
                    break;
                }
                else if(cashdeposit > 0)
                {
                    printf("\nTo confirm, You have chosen to deposit %f into your bank account\n", cashdeposit);
                    accountbalance = accountbalance + cashdeposit;
                    break;
                }
            }
            else if(option_1_completed == 0)
            {
                print("You have not created an account - you cannot deposit cash yet: \n")
                option_1_completed = 0;
                break;
            }
        }
        
        case 4: // Cash withdrawal
        {
            if(option_1_completed == 1)
            {
                printf("\nHow much money do you want to withdraw from your account?\n");
                scanf("%f", &cashwithdraw);
                if(accountbalance < 0)
                {
                    printf("You cannot withdraw the money from the account because the balance is less than 0: \n");
                    break;
                }
                else if(accountbalance > 0)
                {
                    printf("\nTo confirm, You wish to withdraw %f from your account\n", cashwithdraw);
                    accountbalance = accountbalance - cashwithdraw;
                    break;
                }
            else if(option_1_completed == 0)
            {
                printf("You cannot withdraw money - You have not created an account: \n");
                option_1_completed = 0;
                break;
            }
        }

    
        
        case 5: // Display account information
        {
            if(option_1_completed == 1)
            {
                printf("\nYour account balance is %f\n", accountbalance);
                printf("\nAmount deposited: %f\n", cashdeposit);
                printf("\nAmount withdrawn: %f\n", cashwithdraw);
            
                break;
            }
            else if(option_1_completed == 0)
            {
                printf("You cannot display information about the account - You have not created an account: \n")
                option_1_completed = 0;
                break;
            }
        }
        
        case 6: // Logout
        {
            if(option_1_completed == 1)
            { 
                printf("\nDo you really want to logout? If Yes, press y and press n if No: \n");
                getchar();
                scanf("%c", &logout);
                if(logout == 'y' || logout == 'Y')
                {
                    printf("Thanks for using the app!!! Press any button to exit: \n");
                    counter = 0;
                    break;
                }
                else if(logout == 'n' || logout == 'N')
                {
                    printf("Ok. Enter any button to return back to main menu: \n");
                    scanf("%d",&option);
                }
            }
            else if(option_1_completed == 0)
            {
                printf("You have not created an account - you cannot log out: \n");
                printf("Press any button to return back to main menu: \n");
                scanf("%d", &option);
                
            }
        }
        
        case 7: // Clear output and display available options
        {
            system("cls");
            break;
        }
        default:
        {
            printf("None of the options was selected. Try again: \n");
        }
    } // End switch statement
}

    getchar();
    getchar();
    return 0;
}
