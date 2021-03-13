/* Program that will simulate a mathematics quiz game
    Author: Amar Plakalo
    Date: 7 November 2019 updated 13/03/2021
    Used Visual Studio Code on Windows 10
*/

#include <stdio.h>


//  Function Signature

int start_quiz(int*,int*,int*);
int display_correct_incorrect(int*,int*);

int main()
{
    // Defined integer variables questions,correct,incorrect,option,answer,i,number1 and number2. All of these will be needed, in order for me to make this program work.
    
    int option;
    int correct = 0;
    int incorrect = 0;
    int questions = 0;
    int counter = 1;
    int option1 = 0;
    int option2 = 0;

    
    // Built a menu which will be displayed when this program is run
    while(counter == 1)
    { // Do statement is here so that the program repeats itself numerous times rather than running just once.       
        
        printf("Main Menu: \n");
        printf("Choose an option: \n");
        printf("1. Enter number of questions to be asked for this round: \n");
        printf("2. Start Quiz \n");
        printf("3. Display number of questions answered correctly and number of questions answered incorrectly: \n");
        printf("4. Exit Program \n");
       
        scanf("%d", &option);
    
        int ch;
        if( ( ch = getchar() ) != '\n' && ch != EOF )
        {
            printf("Incorrect Option!\n");
            correct = 0;
            incorrect = 0;
            option = 0;
        }
    
        switch(option)
        {
            case 1:
            {
                printf("Input the number of questions to be asked:\n");
                scanf("%d", &questions);


                while(questions > 5)
                {
                    printf("You cannot enter more than five questions. Try again: \n");
                    option1 = 0;
                    scanf("%d", &questions);
                    if( ( ch = getchar() ) != '\n' && ch != EOF )
                    {
                        printf("Incorrect Option!\n");
                        option1 = 0;
           
                    }

                }
                option1 = 1;
                option2 = 0;
                correct = 0;
                incorrect = 0;
                break;
                
            }
            
            case 2:
            {
                if (option1 == 1 && option2 == 0)
                {
                    printf("GOOD LUCK !!!\n");
                    start_quiz(&questions,&correct,&incorrect);
                    option2 = 1;
                    break;
                }
                else if(option1 == 0)
                {
                    printf("You cannot complete option 2 because you have not done option 1 yet. Do it first!! ");
                    break;
                }
                else if(option2 == 1)
                {
                    printf("\nOption2 is has already been executed. You need to option 1 first before executing option 2 again.\n");
                    break;
                }
            }
            
            case 3:
            {
                display_correct_incorrect(&correct,&incorrect);
                break;
            }
            
            case 4:
            {
                printf("Thanks for playing this quiz. See you again\n");
                counter = 0;
                break;
            }
            default:
            {
                printf("The option entered is not from 1-4. Try again!!\n");
                break;
            }
        }
    }
 
        getchar(); // Double getchar(); is here so that the program does not crash.
        getchar();
        return 0;
}

// start_quiz function will let the user complete the mathematical quiz by iterating over each question.
int start_quiz(int *no_of_qs,int *correct,int *incorrect)
{
    int number1 = 3;
    int number2 = 5;
    int answer = 0;
    int actual_answer;

    for(int i = 0; i < *no_of_qs; i++)
    { // Begin for   
        number2 ++;
        printf("%d * %d\n", number1,number2);
        scanf("%d", &answer);
        actual_answer = number1 * number2;
        
        // This is in case the user answered correctly 
        if(actual_answer == answer)
        {
            printf("You are correct! \n");
            (*correct)++;
        }
                
            // This is in case the user answered incorrectly.
        else
        {
            printf("You are incorrect.The correct answer is %d \n", actual_answer);
            (*incorrect)++;
                    
        }
    
    }
        
}

int display_correct_incorrect(int *correct,int *incorrect)
{

    printf("The number of answers you got correct are %d \n", *correct);
    printf("The number of answers you got incorrect are %d \n", *incorrect);
    printf("Thank you for playing this quiz!!! See you again soon \n");
        
    if(*correct != 0)
    {// Begin if   
        *correct = 0;
    } // End if
    
    // After the quiz is done and the user wants to continue to do another round, the incorrect counter will be brought down to 0.
    if (*incorrect != 0)
    {
        *incorrect = 0;
    }
    

        
}
