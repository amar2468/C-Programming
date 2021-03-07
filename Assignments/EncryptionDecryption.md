This contains documentation on the EncryptionDecryption project that I did in college (class project).

Program that lets user enter or generate a four digit code. Then, this code is encryped and compared with the access_code. If it is correct then the user is displayed a message which says that the code entered was correct. If it is incorrect, a message stating that the  code is incorrect will be displayed to screen. The number of times a code was guessed correctly and incorrectly will be displayed to screen. The user also has an option to decrypt the encrypted code.

The program will have a structure used as well as functions which will do certain tasks. The structure contains the amount of times a code was entered correctly and the number of times it was entered incorrectly. 

There is a while loop which will run while the counter is equal to 1. Once this value is not 1, the loop will stop. The main menu contains 6 options that the user can choose from. The option the user chooses will be put inside a variable called 'option'. Inside the switch statement, there are a number of cases which do a particular task.

If the option selected was 1, the enter_code() function is called, which will allow the user to enter a code. The second option is then incremented which means that when the user does option 1, they can then do option 2. 

If the option selected was 2, the program first checks whether the user did option 1. If they did, the encrypt_code() function is called and it encrypts the code that was entered. Then, second option variable is set to 0 so that the user cannot do option 2 again (i.e. encrypt the code). The third option variable is incremented meaning that the user can now do option 3. 

If the user chose option 3, the program first checks whether they did option 2. If they did, the code_match() function is called which compares the access_code with the code entered or generated. Third option variable is set to 0 so the user cannot do option 3 again. Then, option 4 is incremented so that the user can do option 4. 

If the user chooses option 4, the program checks whether the user did option 3. If the user did, the decrypt_code() function is called and the fourth option variable is set to 0 so that the user cannot do option 4 again. 

If the user chose option 5, the correct_incorrect() function is called which counts the number of correct and incorrect times a code was entered. 

If the user picked option 6, the exit_program() function is called which asks the user whether they want to quit the program. 

If the incorrect menu option was selected, an error message is printed and the user is returned to the main menu. All the cases in the switch error check for mistakes from the user. 

FUNCTIONS

The enter_code() function takes in a parameter called code_entered. This function is one that does not return anything but it is a pass by reference one, meaning that it changes the value that is stored in a memory address of a variable. The user is presented with a choice to select 1 or 2. If they select 1, the user chooses the code. A for loop is used and it asks the user to enter each digit of the code and error checks whether the code is valid. Once the user enters the valid code, the for loop ends and the code is saved. If the user chose option 2, which is to generate a code, the for loop goes through 4 times and put four random digits from 0 to 9 into the array. If the user did not select 1 or 2, they will return back to the main menu. 

The encrypt_code() function encrypts the code that the user entered or generated. The for loop runs through the digits and performs the encryption as follows. The first number is swapped with the third number and the second number is swapped with the fourth number. All numbers are incremented then. If the value is equal to 10, set it to 0. Then, the encrypted code is printed to the screen. 

The next function is the code_match() one. It also uses pass by reference. The for loop is used and will compare the access_code with the code inputted by the user. The code that the user inputted was encrypted and this encrypted code is compared with the access_code which is the code that was set at the beginning. The counter is incremented if the element in the encrypted code that the user entered is the same as the access_code element. The elements have to be in the same position (i.e. if the first element in the encrypted code is the same as the first element in the access_code). If the counter is 4, meaning that every digit matches, a message is printed and the correct variable is incremented. Otherwise, incorrect variable is incremented. 

The decrypt_code() function decrypts the code that the user entered. The algorithm is as follows. Subtract 1 from each number. If a number has a value of -1, change to 9. Swap the 1st and 3rd number. Then, swap 2nd and 4th. Then, the code decrypted is printed to screen. 

The correct_incorrect() function shows the user the amount of times the code was entered correctly and incorrectly. A variable called person that represents the user who is guessing the code is created. The correct attempts value inside the variable is put inside the structure variable person.correct_code. The same is done with incorrect attempts. Then, the result is printed to the screen. 

Finally, the last function is exit_program(). It asks the user whether they want to quit the program. If the user wants to, they pres 6 and the program ends. Otherwise, it returns back to the main menu.
