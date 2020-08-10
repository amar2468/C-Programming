/* Program that will simulate a mathematics quiz game
    Author: Amar Plakalo
    Date: 7 November 2019
    Used Borland Compiler on Windows 10
*/

#include <stdio.h>
int main()
{
    // Defined integer variables questions,correct,incorrect,option,answer,i,number1 and number2. All of these will be needed, in order for me to make this program work.
    
    int questions,correct,incorrect,option;
    int answer = 0;
    int i;
    int number1 = 3;
    int number2 = 5;


    // Initialised variables correct and incorrect with the value 0. This is done because I don't want the program to assign random numbers into these two variables.
    correct = 0;
    incorrect = 0;

    
    // Built a menu which will be displayed when this program is run
do
{ // Do statement is here so that the program repeats itself numerous times rather than running just once.       
        
        printf("Main Menu: \n");
        printf("Choose an option: \n");
        printf("1. Enter number of questions to be asked for this round: \n");
        printf("2. Start Quiz \n");
        printf("3. Display number of questions answered correctly and number of questions answered incorrectly: \n");
        printf("4. Exit Program \n");
       
        scanf("%d", &option);
    
    
    
    // Error checking so that the program only accepts options 1,2,3,4.
    if( !(option == 1 || option == 2 || option == 3 || option == 4 ))
    { // Begin outer if statement
        printf("You entered an invalid number from the menu. Please input a number from 1-4 \n");

        
            if(option >= 'a' && option <= 'z' || option >= 'A' && option <= 'Z')
            { // Begin inner if statement
                printf("You entered a character which in this case is a letter. You are not allowed to do this. Press 1 to go back to main menu \n");
                scanf("%d", &option);
            } // End inner if statement
    } // End outer if statement
    
    // This is an if statement that checks for errors in the input by the user. If user enters an option other than 1 at the start, it will promt him/her that the first option should be number 1.
    if( ! (option == 1))
    { // Begin if statement
        printf("You must choose option 1 before you do this quiz \n");
        scanf("%d", &option);
    } // End if statement
    
    
    // This is an if statement that asks the user for the number of questions he/she wants if option 1 is pressed.    
    if(option == 1)
    { // Begin if statement
        printf("How many questions do you want to answer? \n");
        scanf("%d", &questions);
   
    
            if(option >= 'a' && option <= 'z' && option >= 'A' && option <= 'Z')
            { // Begin inner if statement
                printf("You entered a character which in this case is a letter. You are not allowed to do this. Press 1 to go back to main menu \n");
                scanf("%d", &option);
            } // End inner if statement
     } // End if statement
    
    
    
    // This is error checking in case the user enters more than five questions.
     if(questions > 5)
    { // Begin outer if
        printf("You cannot ask for more than five questions \n");
        questions = 0;
        printf("Press 1 to go back to the main menu \n");
        scanf("%d", &option);
        getchar();
            if( !(option == 1)) // This statement is here in case the user does not press number 1 when prompted
            { // Begin inner if
                printf("You did not press the right button. You can only press 1 if you want to go back to menu \n");
                scanf("%d", &option);
            } // End inner if
        
    } // End outer if
    
    // This menu is displayed after option 1.
    
        printf("Main Menu: \n");
        printf("Choose an option: \n");
        printf("1. Enter number of questions to be asked for this round: \n");
        printf("2. Start Quiz \n");
        printf("3. Display number of questions answered correctly and number of questions answered incorrectly: \n");
        printf("4. Exit Program \n");
       
        scanf("%d", &option);
    
            if( !(option == 2)) // Error checking in case user enters option 3 before option 2.
            {
                printf("You must do option 2 after picking option 1! \n");
                scanf("%d", &option);
            }
        
       
    
   // For statement in case option2 is picked. It will start the quiz.
    
    for(i = 0; i < questions; i++)
    { // Begin for   
        number2 ++;
        printf("%d * %d\n", number1,number2);
        scanf("%d", &answer);
        
        int correctanswer;
        
        correctanswer = number1 * number2;
        
       
    
        
    
       // This is in case the user answered correctly 
        if(number1 * number2 == answer)
        {
            printf("You are correct! \n", correctanswer);
        }
        
        // This is in case the user answered incorrectly.
        else
        {
            printf("You are incorrect.The correct answer is %d \n", correctanswer);
            
        }
        
        // if the answer given by the user is equal to the answer of the question, the correct counter will increment by one.
        if(answer == correctanswer)
        {
            correct++;
        }
        
        // If the answer given by the user is not equal to the answer of the question, the incorrect counter will increment by one.
        else
        {
            incorrect++;
        }
        
    }
    
 
        // This menu is displayed after option 2.
    
        printf("Main Menu: \n");
        printf("Choose an option: \n");
        printf("1. Enter number of questions to be asked for this round: \n");
        printf("2. Start Quiz \n");
        printf("3. Display number of questions answered correctly and number of questions answered incorrectly: \n");
        printf("4. Exit Program \n");
       
        scanf("%d", &option);

    // If user chooses option 3, he/she will be given the number of correct and incorrect answers. They will also be given a choice of whether they want to continue the quiz or to quit it.
    if(option == 3)
    { // Begin if
        printf("The number of answers you got correct are %d \n", correct);
        printf("The number of answers you got incorrect are %d \n", incorrect);
        printf("Thank you for playing this quiz!!! See you again soon \n");
        printf("If you want to continue with this quiz again, please press 1 \n");
        printf("Press 4 to quit \n");
        scanf("%d", &option);

        
    } // End if
    
    // After the quiz is done and the user wants to continue to do another round, the correct counter will be brought down to 0.
    if(correct > 0)
    { // Begin if   
        correct = 0;
    } // End if
    
    // After the quiz is done and the user wants to continue to do another round, the incorrect counter will be brought down to 0.
    if (incorrect > 0)
    {
        incorrect = 0;
    }
      
    // If the user wants to quit the quiz, he will need to press the enter button again. After he does so, the program stops.
    if(option == 4)
    {
        printf("Are you sure that you want to exit this program? If so, press the enter button again.\n");

    }
    
    
} // End do statement
while(option == 1 ); // This means that whenever option 1 is selected, the program will begin from the start.
 
    getchar(); // Double getchar(); is here so that the program does not crash.
    getchar();
    return 0;
} // End main()
