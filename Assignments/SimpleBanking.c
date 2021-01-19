/* Program that makes a banking system where a user can create an account, check information, withdraw and deposit money and log out when he/she is done
    Author: Amar Plakalo
    Date: 01 December 2019
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Declare variables needed
    
    int option,age;
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
            printf("\nWhat is your name?\n");
            getchar();
            scanf("%c", &name);
            getchar();
            getchar();
           
            printf("\nHow old are you?\n");
            getchar();
            scanf("%d", &age);
            if(age < 18)
            {
                printf("\nYou are too young to create an account with us. You must be 18 or higher\n");
                
            }
            else
            {
                printf("\nCongrats! You have created your first bank account. Use it wisely and earn a lot of money\n");
            }
            
            break;
            
        }
        
        case 2: // Cash deposit
        {
            printf("\nHow much cash do you wish to deposit in your newly created bank account? \n");
            scanf("%f", &cashdeposit);
            printf("\nTo confirm, You have chosen to deposit %f into your bank account\n", cashdeposit);
            
            break;
        }
        
        case 3: // Cash withdrawal
        {
            printf("\nHow much money do you want to withdraw from your account?\n");
            scanf("%f", &cashwithdraw);
            printf("\nTo confirm, You wish to withdraw %f from your account\n", cashwithdraw);
            break;
        }
        
        accountbalance = currentbalance + (cashdeposit - cashwithdraw);
        
        case 4: // Display account information
        {
            currentbalance = cashdeposit - cashwithdraw;
            accountbalance = currentbalance;
            printf("\nYour account balance is %f\n", accountbalance);
            printf("\nAmount deposited: %f\n", cashdeposit);
            printf("\nAmount withdrawn: %f\n", cashwithdraw);
        
            break;
        }
        
        case 5: // Logout
        {
            printf("\nDo you really want to logout? If yes, press y\n");
            scanf("%c", &logout);
            break;
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
