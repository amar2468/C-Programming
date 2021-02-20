/*  Program that allows user to create an account, deposit money, withdraw money, display information and log off.
    This is a simple banking app that a user can use to easily.
    Author: Amar Plakalo
    Date - Updated: 20 February 2021
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Declare variables needed
    
    int option,age,option_1_completed = 0;
    char name,logout;
    float cashdeposit,cashwithdraw,accountbalance,currentbalance;
    
    
do
{    
    
    printf("Welcome to Bank for the Future: \n");
    printf("\nMain Menu: \n");
    printf("\n1.Create an account: \n");
    printf("\n2.Cash Deposit: \n");
    printf("\n3.Cash Withdrawal: \n");
    printf("\n4.Display account information: \n");
    printf("\n5.Logout\n");
    printf("\n6.Clear output screen and display available options\n");
    
    scanf("%d", &option);
    
    switch(option)
    {
        case 1: // Create an account
        {
            if (option_1_completed == 0)
            {
                printf("\nWhat is your name?\n");
                getchar();
                scanf("%c", &name);
                getchar();
                getchar();
            
                printf("\nHow old are you?\n");
                getchar();
                scanf("%d", &age);

                printf("How much money do you wish to put into your bank account? ");
                getchar();
                scanf("%f",&accountbalance);

                if(accountbalance < 0)
                {
                    printf("You cannot put deposit a minus number into your account. Only positive numbers: ");
                    accountbalance = 0;
                    option_1_completed = 0;
                    break;

                }
                else if(accountbalance > 0)
                {
                    printf("You successfully put %f into your account. Well done!!!",accountbalance);
                    option_1_completed = 1;
                    break;
                }
                if(age < 18)
                {
                    printf("\nYou are too young to create an account with us. You must be 18 or higher\n");
                    option_1_completed = 0;
                    
                }
                else
                {
                    printf("\nCongrats! You have created your first bank account. Use it wisely and earn a lot of money\n");
                    option_1_completed = 1;
                }
            
                break;
            }
            else if(option_1_completed == 1)
            {
                printf("You already created an account. You cannot create one again: ");
                break;
            }
            
        }
        
        case 2: // Cash deposit
        {
            printf("\nHow much cash do you wish to deposit in your newly created bank account? \n");
            scanf("%f", &cashdeposit);
            if (cashdeposit < 0)
            {
                printf("You cannot deposit a negative number: ");
                break;
            }
            else if(cashdeposit > 0)
            {
                printf("\nTo confirm, You have chosen to deposit %f into your bank account\n", cashdeposit);
                accountbalance = accountbalance + cashdeposit;
                break;
            }
        }
        
        case 3: // Cash withdrawal
        {
            printf("\nHow much money do you want to withdraw from your account?\n");
            scanf("%f", &cashwithdraw);
            if(accountbalance < 0)
            {
                printf("You cannot withdraw the money from the account because the balance is less than 0: ");
                break;
            }
            else if(accountbalance > 0)
            {
                printf("\nTo confirm, You wish to withdraw %f from your account\n", cashwithdraw);
                accountbalance = accountbalance - cashwithdraw;
                break;
            }
        }

    
        
        case 4: // Display account information
        {
            printf("\nYour account balance is %f\n", accountbalance);
            printf("\nAmount deposited: %f\n", cashdeposit);
            printf("\nAmount withdrawn: %f\n", cashwithdraw);
        
            break;
        }
        
        case 5: // Logout
        {
            if(option_1_completed == 1)
            { 
                printf("\nDo you really want to logout? If yes, press y\n");
                getchar();
                scanf("%c", &logout);
                if(logout == 'y' || logout == 'Y')
                {
                    printf("Thanks for using the app!!! Press any button to exit: ");
                    break;
                }
                else if(logout == 'n' || logout == 'N')
                {
                    printf("Ok. Enter any button to return back to main menu: ");
                    scanf("%d",&option);
                }
            }
            else if(option_1_completed == 0)
            {
                printf("You have not created an account - you cannot log out: \n");
                printf("Press any button to return back to main menu: ");
                scanf("%d", &option);
                
            }
        }
        
        case 6: // Clear output and display available options
        {
            system("cls");
            break;
        }
    } // End switch statement
}
while(option == 1 || option == 2 || option == 3 || option == 4);

    getchar();
    getchar();
    return 0;
}
