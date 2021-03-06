/*  Program that allows user to create an account, log on, deposit money, withdraw money,pay a bill, display information and log off.
    This is a simple banking app that a user can use to easily.
    
    
    ****************************This is my personal project that I did***********************************
    Author: Amar Plakalo
    Date - Updated: 15 March 2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes

void create_account(int*,char*,int*,float*,int*,int*);
void log_into_account(int*,int*,int*,int*,int*);
void depositing_money(float*,float*,float*,int*);
void withdrawing_money(float*,float*,float*,int*);
void paying_your_bill(int*,float*,float*,char*,int*,int*,float*,int*);
void log_out_of_account(char*,int*,int*);
void exitprogram(int*);

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
                create_account(&option_1_completed,name,&age,&accountbalance,&account_number,&pin); // Function is called that executes and allows user to create 
                                                                                                                        // Account for themselves
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
                log_into_account(&log_on,&acc_number,&account_number,&pin_entered,&pin);
                break;
            }
            else if(option_1_completed == 0)
            {
                printf("\n---------------------------------------\n");
                printf("You have not registered - cannot log in: \n");
                printf("\n---------------------------------------\n");
                log_on = 0;
                break;
            }
            else if(option_1_completed == 1)
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
                depositing_money(&cashdeposit,&accountbalance,previous_deposits,&index_deposit);
                break;
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
                withdrawing_money(&cashwithdraw,&accountbalance,previous_withdraws,&index_withdraw);
                break;
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
                paying_your_bill(&company_acc_no,&bill_total,&accountbalance,message,&verify_my_acc_no,&account_number,previous_withdraws,&index_withdraw);
                break;
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
                printf("\nYour account balance - %.2f EUR\n", accountbalance);
                printf("\nPrevious deposits - \n");
                for(int i = 0; i < index_deposit; i++)
                {
                    printf("%.2f,",previous_deposits[i]);
                }
                printf("\n");
                printf("\nPrevious withdraws - \n");
                for(int i = 0; i < index_withdraw; i++)
                {
                    printf("%.2f,",previous_withdraws[i]);
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
                log_out_of_account(&logout,&counter,&log_on);
                break;
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
            exitprogram(&counter);
            break;
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

// Function implementation

void create_account(int *option1_finished,char *f_name,int *user_age,float *ac_balance,int *act_number,int *pin_number_user)
{
    printf("\nWhat is your name?\n");
    scanf("%s", &*f_name);
    getchar();

    printf("\nHow old are you?\n");
    scanf("%d", &*user_age);
    getchar();
    if(*user_age < 18)
    {
        printf("\n------------------------------------------------------------------------\n");
        printf("\nYou are too young to create an account with us. You must be 18 or higher\n");
        printf("\n------------------------------------------------------------------------\n");
        *option1_finished = 0;
        
        
    }
    else if(*user_age >= 18)
    {
        printf("\n-----------------------------------------------------------------------------------\n");
        printf("\nYou are 18 or over. You can now continue with the process of creating the account! \n");
        printf("\n-----------------------------------------------------------------------------------\n");
    }

    printf("\n------------------------------------------------------\n");
    printf("How much money do you wish to put into your bank account? ");
    printf("\n------------------------------------------------------\n");
    scanf("%f",&*ac_balance);

    if(*ac_balance < 0)
    {
        printf("\n------------------------------------------------------------------------------\n");
        printf("You cannot put deposit a minus number into your account. Only positive numbers: \n");
        printf("\n------------------------------------------------------------------------------\n");
        *ac_balance = 0;
        *option1_finished = 0;
        

    }
    else if(*ac_balance > 0)
    {
        printf("\n--------------------------------------------------------------------\n");
        printf("You successfully put %.2f EUR into your account. Well done!!!\n",*ac_balance);
        *option1_finished = 1;
        printf("Your account number is : %d\n",*act_number);
        printf("Your PIN is %d. Keep this safe!!\n",*pin_number_user);
        printf("\n--------------------------------------------------------------------\n");
       
    }
}
void log_into_account(int *logged_on,int *input_acc_number, int *real_acc, int *input_pin, int *real_pin)
{
    printf("Hello! Enter your account number and PIN in order to log on: \n");
    scanf("%d",&*input_acc_number);
    getchar();
    scanf("%d",&*input_pin);
    getchar();
    if (*input_acc_number == *real_acc)
    {
        if (*real_pin == *input_pin)
        {
            printf("\n------------------------------------------------------------\n");
            printf("Well done. Correct account number and PIN. You are logged on: \n");
            printf("\n------------------------------------------------------------\n");
            *logged_on = 1;
        }
        else if(*real_pin != *input_pin)
        {
            printf("\n-------------\n");
            printf("Incorrect PIN: \n");
            printf("\n-------------\n");
            *logged_on = 0;
        }
    }
    else if(*input_acc_number != *real_acc)
    {
        printf("\n------------------------\n");
        printf("Incorrect account number: \n");
        printf("\n------------------------\n");
        *logged_on = 0;
    }
    
}

void depositing_money(float *deposit, float *balance, float *previous_deposits_by_user,int *index_to_deposit)
{
    printf("\nHow much cash do you wish to deposit? \n");
    scanf("%f", &*deposit);
    if (*deposit < 0)
    {
        printf("\n------------------------------------\n");
        printf("You cannot deposit a negative number: \n");
        printf("\n------------------------------------\n");
    }
    else if(*deposit > 0)
    {
        printf("\n-----------------------------------------------------------------------------\n");
        printf("\nTo confirm, You have chosen to deposit %.2f EUR into your bank account\n", *deposit);
        printf("\n-----------------------------------------------------------------------------\n");
        *balance = *balance + *deposit;
        *(previous_deposits_by_user + *index_to_deposit) = *deposit;
        (*index_to_deposit)++;
        if(*index_to_deposit == 5)
        {
            *index_to_deposit = 0;
            
        }
    }
}

void withdrawing_money(float *withdraw, float *balance_in_account, float *last_withdraws, int *index_for_withdraws)
{
    printf("\nHow much money do you want to withdraw from your account?\n");
    scanf("%f", &*withdraw);
    if(*balance_in_account < 0)
    {
        printf("\n---------------------------------------------------------------------------------\n");
        printf("You cannot withdraw the money from the account because the balance is less than 0 EUR: \n");
        printf("\n---------------------------------------------------------------------------------\n");
       
    }
    else if(*balance_in_account > 0)
    {
        printf("\n-------------------------------------------------------------------\n");
        printf("\nTo confirm, You wish to withdraw %.2f EUR from your account\n", *withdraw);
        printf("\n-------------------------------------------------------------------\n");
        *balance_in_account = *balance_in_account - *withdraw;
        *(last_withdraws + *index_for_withdraws) = *withdraw;
        (*index_for_withdraws)++;
        if (*index_for_withdraws == 5)
        {
            *index_for_withdraws = 0;
        }
    }

}

void paying_your_bill(int *company_account_number,float *billtotal,float *a_balance,char *msg,int *verify_account_no,int *correct_acc_no, float *previouswithdraws,int *indexforwithdraws)
{
    printf("\nEnter the account number of the company: \n");
    scanf("%d",&*company_account_number);
    getchar();
    printf("\nEnter the bill amount that you are due to pay: \n");
    scanf("%f",&*billtotal);
    if(*a_balance - *billtotal >= 0)
    {

        printf("\nWrite a short note, e.g. This is my payment for the electricity bill: \n");
        getchar();
        gets(msg);

        printf("\nEnter your account number to verify that this is you: \n");
        scanf("%d", &*verify_account_no);


        if (*verify_account_no == *correct_acc_no)
        {
            printf("\n-------------------------\n");
            printf("\nSuccessful transaction!!!\n");
            *a_balance = *a_balance - *billtotal;
            *(previouswithdraws + *indexforwithdraws) = *billtotal;
            (*indexforwithdraws)++;
            if (*indexforwithdraws == 5)
            {
                *indexforwithdraws = 0;
            }
                        
            printf("\n-------------------------\n");
        }
        else
        {
            printf("\n----------------------------------\n");
            printf("\nIncorrect account number entered: \n");
            printf("\n----------------------------------\n");
        }
    }
    else if(*a_balance - *billtotal < 0)
    {
        printf("\n---------------------------------------------------------------\n");
        printf("You cannot pay for the bill - The account balance will go under 0 EUR: ");
        printf("\n---------------------------------------------------------------\n");
    }
}

void log_out_of_account(char *logout_option,int *count,int *lets_user_log_off)
{
    printf("\nDo you really want to logout? If Yes, press y and press n if No: \n");
    getchar();
    scanf("%c", &*logout_option);
    if(*logout_option == 'y' || *logout_option == 'Y')
    {
        printf("\n----------------------------------------------------\n");
        printf("You have successfully logged off! \n");
        printf("\n----------------------------------------------------\n");
        *count = 1;
        *lets_user_log_off = 0;
    }
    else if(*logout_option == 'n' || *logout_option == 'N')
    {
        printf("\n------------------------------------------------\n");
        printf("Ok. Enter any button to return back to main menu: \n");
        printf("\n------------------------------------------------\n");
        *lets_user_log_off = 1;
    }
    else
    {
        printf("\n------------------------------------------\n");
        printf("Not the correct option selected!!Try again: \n");
        printf("\n------------------------------------------\n");
        *lets_user_log_off = 1;
    }   
}

void exitprogram(int *check_whether_user_wants_to_exit)
{
    int exit_program_option = 0;
    printf("Do you want to exit this program? If yes, choose number 8. Otherwise, press any other button to return back to the menu: ");
    scanf("%d",&exit_program_option);
    if (exit_program_option == 8) // if the user chose 8
    {
        printf("\n-----------------------------------------------------------------------\n");
        printf("\nThanks for using this app!!! Press any button and you're done!! Goodbye!!");
        printf("\n-----------------------------------------------------------------------\n");
        *check_whether_user_wants_to_exit = 0; // this will stop the while loop from executing, which ends the program.
    }
    else
    {
        printf("\n--------------------\n");
        printf("Back to the main menu!");
        printf("\n--------------------\n");
        *check_whether_user_wants_to_exit = 1; // this will let the while loop continue running as normal.
    }
}
