This contains the documentation on the project LottoGame in C (also a class project, although improved and will be improved even more in my own time)


This program allows the user to play a lotto game. The user enters their six numbers, they can display the numbers they selected, they can sort the numbers from lowest to highest, they can compare the numbers with the winning numbers, they can see the frequency of the numbers selected by the user and they can exit the program. This is a fun game that give the user a chance to win amazing prizes if they guess the correct numbers. 

The '#include <stdio.h>' is a header file included so that there is access to functions related to standard input output operations. Two defines were made. This means that the programmer can use the name of the define instead of constantly writing the number everywhere. Then, function signatures were made. This tells the program how many parameters a function should expect and the type of the parameters that will be passed. 

In the main() function, there are a number of variables defined. There is also an array which holds the winning numbers and an array that holds the user's guessed numbers. The while loop will run as long as counter = 1. This means that when the user chooses to exit the program, the counter has to go to 0. A menu is presented to the user with six options. Whatever option they select will be saved inside a variable called option. Then, a int variable was created called 'ch'. This would make sure that if the user entered a letter instead of a number for the option, the program would recognise this and tell the user. 

In the switch case, there are six menu options which will call different functions to complete tasks. The first case is for option 1. If the user chose option 1, a function will be called and the user can enter their numbers. Variables 'second_option' up to 'fifth_option' are incremented because this shows that the user completed option 1. 

In the second case, there is a check going on to see whether the user has done the first option. If they have, a function for displaying numbers is called. Otherwise, they return back to the main menu. 

In the third case, if the user did option 1, a function is called for sorting the numbers in order. Otherwise, they return back to the menu.

In the fourth case, yet again, if the user did option 1, they can do option 4 which will call a function to compare the numbers with the winning ones. Otherwise, back to the menu.

In the fifth case, if the user did complete option 1, a for loop is created that copies the contents from one array to another and then this array is used as a parameter to the function that counts the frequency of the numbers selected.

The sixth option is if the user wishes to exit the program. A function is called which will ask the user if they wish to exit the program. If they decide to quit, the program ends. Otherwise, they return back to the menu.

If none of the options were selected, the user is shown an error message and they return back to the menu.


FUNCTIONS

The first function is the one that allows the user to select the numbers. The user enters six numbers. There is error checking going to see whether the user entered numbers which are less than 1 and numbers greater than 42. The numbers are then put inside the array that counts the frequency of the numbers entered. If the numbers were repeated, the options are decremented so that the user can do option 1 again and the frequency is changed to 0.

The second function is the one that displays the numbers entered. It is just a simple for loop which prints each element inside an array index. 

The third function is for sorting the numbers selected by the user in ascending order. The sorting algorithm I used was insertion sort. It is generally quicker than bubble sort and selection sort even though they perform at the same complexity. A temp variable was needed to store the value temporarily in the swap part. Then, a for loop was used which would iterate through the array, starting from position 1. The while loop would take the element ahead and compare it with the ones behind it and decrement so that other elements can be compared. 

Then, the fourth function was the one that compares the user's numbers with the winning ones. If the number is equal to the winning one, a score counter is incremented. Then, the numbers selected by the user are shown. Finally, if the user won a prize, this would be stated in the message. Otherwise, the program would tell the user that they did not get any prize. 

The fifth function is responsible for presenting the frequency of the numbers selected. A for loop is used to iterate over all the elements in the array that remembers the numbers entered. If the number appeared at least once, it appears as a number selected. 

The sixth and final function asks the user whether they wish to exit the program. If the user agrees to exit the program, a counter variable is set to 0 and is returned back to the case number 6 and the program ends. Otherwise, the counter variable has a value of 1 and it returns back to the case number 6. This means the user can continue using the program.
