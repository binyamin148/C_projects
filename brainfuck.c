#include <stdio.h>
#include <stdlib.h>

#define LENGTH 65535

char memory[LENGTH];
int ptr = 0;

void interpreter(char *code_bf)
{
    int currentIndex;
    for (currentIndex = 0; code_bf[currentIndex] != '\0'; currentIndex++)
    {
        if (code_bf[currentIndex] == '>')
        {
            if (ptr == LENGTH - 1)
                ptr = 0;
            else
                ptr++;
        }
        else if (code_bf[currentIndex] == '<')
        {
            if (ptr == 0)
                ptr = LENGTH - 1;
            else
                ptr--;
        }
        else if (code_bf[currentIndex] == '+')
            memory[ptr]++;
        else if (code_bf[currentIndex] == '-')
            memory[ptr]--;
        else if (code_bf[currentIndex] == '.')
            printf("%c", memory[ptr]);
        else if (code_bf[currentIndex] == ',')
            memory[ptr] = getchar();
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

int main()
{
    char code_bf[LENGTH];
    printf("Enter the code:\n");
    fgets(code_bf, LENGTH, stdin);
    printf("wow it was very hard:\n");
    interpreter(code_bf);
    return 0;
}