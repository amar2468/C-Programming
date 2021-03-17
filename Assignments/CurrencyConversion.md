This contains documentation on the CurrencyConversion project.


This program allows the user to choose between dollars and euros and coverts it into dollars or euros, depending on what you picked. After you selected a currency, you will be asked to enter up to 50 values that you wish to change into a different currency. Then, you will be presented with the values that were converted and the average of the values.

Two arrays were declared of the size 50 so that the user can enter up to 50 values. The reason why I had to allocate the array is because an array cannot be allocated in runtime. It has to be pre-allocated with how many values there will be inside it. The menu gives the user the chance to choose from 3 options.

If the user chooses option 1, the user needs to enter the values that will be converted into dollars. Then, the function to do the conversion is called and the array is passed along with the number of values entered, so the for loop can iterate over that amount of values. Once the function return the average, the average will be printed to screen.

If the user chose option 2, they will be asked to enter the values to be converted to euros. The function is then called with the array being passed as a parameter as well as the number of values that the user entered. The function will return the average and this will be printed to screen.

If the user chose option 3, the program asks the user whether they want to quit the program. If they do want to quit, the program will end.

FUNCTIONS

The first function is the one that changes euros to dollars. There is a for loop which takes the first value in the array and multiplies it by the exchange rate. This will be done for each value, in order to get the exchange rate. Then, the converted amount will be added to the total so that the average can be calculated. Then, the average is worked out and the value is returned. This will be printed to screen.

The second function is the one that changes dollars to euro. The same thing happens. The for loop runs and takes each value that was inputted by the user and multiplies it by the exchange rate. Then, this is added to the total and the average can be worked out. This is then returned so that the average can be printed out in the main().


