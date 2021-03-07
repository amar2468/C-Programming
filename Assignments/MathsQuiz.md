This file contains documentation on the MathsQuiz.c project. This was my first C project that I did. It was a project done in college (class project)

This was my first class project in C. This program simulates a mathematics quiz. The user first writes down how many questions they want to answer. Then, they answer the maths questions. After this, the program shows how many answers were correct and how many were incorrect. After this, the user can exit the program. 

Variables such as the menu option, correct, incorrect and number of questions were created so that they can be used in the program. A while loop was created that will run while counter is equal to 1. If not, the loop will stop. There are four menu options and the user chooses which one they want.

If the user chooses option 1, they are asked how many questions they want to answer and this is saved inside a variable called 'questions' which is of type integer. If the user types that they want more than 5 questions, the program will tell them that this is impossible and will force them to enter the correct number. 

In option 2, the function is called which will allow the user to play the game. The function is a pass by reference one because it is necessary to change the value inside the address location of the variable and this must be permanent after the function returns the values. 

In option 3, the display correct, incorrect answers is called. It will display the number of times the user guessed correctly and incorrectly. This is also pass by reference. 

In option 4, the user quits the program. Counter is set to 0 meaning that they cannot run the menu again and the program quits.

If none of the options was selected, error message is printed and the user is returned back to the menu.

FUNCTIONS

The first function is the start_quiz() one. This function will run if the user chooses option 2. The for loop is there and it iterates through the questions. The number of questions will vary on the number of questions that the user chose. The question will be printed out and the user will enter their answer. The actual answer will be stored inside a variable and this will be compared with the user's answer. If the actual answer is equal to the user's answer, the correct variable will increment. Otherwise, the incorrect one will increment. The number of correct and incorrect will be returned back.

The other function is going to be executed if the user chose option 3. This shows how many times the user guessed correctly and how many times they guessed incorrectly. If the correct variable is greater than 0, it will be set to 0 so that when the user does another round of questions, the counters will be erased and the record is not saved. 
