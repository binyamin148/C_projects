#include <stdio.h>
#include <stdlib.h>

/* Defines a constant with the length of the cache */
#define LENGTH 65535

/* Declares an array named 'memory' to simulate the memory tape, and initializes a pointer 'ptr' to the starting position */
char memory[LENGTH];
int ptr = 0;

/* Function to interpret BrainFuck code. */
void interpreter(char *code_bf)
{
    int currentIndex;
    /*  Declare an integer variable currentIndex to keep track of the current index
    while iterating through the code_bf array.*/

    for (currentIndex = 0; code_bf[currentIndex] != '\0'; currentIndex++)
    /* Initialize currentIndex to 0, representing the start of the array.
     * The loop condition checks if the character at the currentIndex position
     * in the code_bf array is not equal to the null character ('\0').
     * Increment currentIndex after each iteration to move to the next character
     * in the array.
     */

    {
        /* Increment the pointer by one (to point to the next cell to the right).*/
        if (code_bf[currentIndex] == '>')
        {
            if (ptr == LENGTH - 1)
                ptr = 0;
            else
                ptr++;
        }
        /* Decrement the pointer by one (to point to the next cell to the left). */
        else if (code_bf[currentIndex] == '<')
        {
            if (ptr == 0)
                ptr = LENGTH - 1;
            else
                ptr--;
        }
        /*Increment the byte at the pointer by one.*/
        else if (code_bf[currentIndex] == '+')
            memory[ptr]++;
        /*Decrement the byte at the pointer by one.*/
        else if (code_bf[currentIndex] == '-')
            memory[ptr]--;
        /*Output the byte at the pointer.*/
        else if (code_bf[currentIndex] == '.')
            printf("%c", memory[ptr]);
        /* Accept one byte of input, storing its value in the byte at the pointer.*/
        else if (code_bf[currentIndex] == ',')
            memory[ptr] = getchar();
        /* If the byte at the pointer is zero,
        then instead of moving the instruction pointer forward to the next command,
        jump it forward to the command after the matching ] command. */
        else if (code_bf[currentIndex] == '[')
        {
            if (memory[ptr] == 0)
            {
                int bracketCounter = 0;
                currentIndex++;
                while (bracketCounter > 0 || code_bf[currentIndex] != ']')
                {
                    if (code_bf[currentIndex] == '[')
                        bracketCounter++;
                    else if (code_bf[currentIndex] == ']')
                        bracketCounter--;
                    currentIndex++;
                }
            }
        }
        /* If the byte at the data pointer is nonzero,
        then instead of moving the instruction pointer forward to the next command,
        jump it back to the command after the matching [ command. */
        else if (code_bf[currentIndex] == ']')
        {
            if (memory[ptr] != 0)
            {
                int bracketCounter = 0;
                currentIndex--;
                while (bracketCounter > 0 || code_bf[currentIndex] != '[')
                {
                    if (code_bf[currentIndex] == ']')
                        bracketCounter++;
                    else if (code_bf[currentIndex] == '[')
                        bracketCounter--;
                    currentIndex--;
                }
            }
        }
    }
}

/* It reads input and invokes the interpreter */
int main()
{
    char code_bf[LENGTH];
    /* Define an array of characters with a length of LENGTH to store Brainfuck code entered by the user.*/

    printf("Enter the code:\n");
    /*Prompt the user to enter Brainfuck code.*/

    fgets(code_bf, LENGTH, stdin);
    /* Read input from the user and store it in the code_bf array.
    The fgets function reads at most LENGTH - 1 characters from stdin (standard input)
    and stores them into the array, adding a null character ('\0') at the end.*/

    printf("wow it was very hard:\n");
    /* Notify the user that the input was received and the program is processing it.*/

    interpreter(code_bf);
    /*  Call the interpreter function to interpret the Brainfuck code entered by the user.
    Pass the code_bf array as an argument to the interpreter function.*/

    return 0;
    /*Indicate successful execution of the program by returning 0.*/
}