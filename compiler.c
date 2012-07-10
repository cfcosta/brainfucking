#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void compile(char *code, int *pointer)
{
    unsigned int i = 0;

    while(i < strlen(code)) {
        switch (code[i]) {
        case '+':
            ++*pointer;
            break;
        case '-':
            --*pointer;
            break;
        case '>':
            ++pointer;
            break;
        case '<':
            --pointer;
            break;
        case '.':
            putchar(*pointer);
            break;
        case '[':
            int j = 0;
            while(code[j] != ']') j++; 

            char *temp = strndup(code + (sizeof(char) * (i + j)), j);
            printf("temp = %s", &temp);

            i += j;

            break;
        default:
            printf("Unknown token %c\n", code[i]);
            break;
        }

        i++;
    }
}

int main(int argc, const char *argv[])
{
    int *p = calloc(30000, 30000);
    *p = 0;

    compile("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.", p);

    return 0;
}
