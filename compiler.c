#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void compile(char *code, int *pointer)
{
    int i = 0, j = 0;
    char *temp;

    while (i < strlen(code)) {
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
            j = i + 1;
            while (code[j] != ']') j++;

            temp = strndup(code + (sizeof(char) * (i + 1)), j - i - 1);
            while(*pointer) {
              compile(temp, pointer);
            }

            i += (j - i);

            break;
        }

        i++;
    }
}

int main(int argc, const char *argv[])
{
    int *p = calloc(30000, 30000);
    char input[30000];

    *p = 0;
    fread(input, sizeof(input), 1, stdin);

    compile(input, p);

    return 0;
}

