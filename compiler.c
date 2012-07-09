#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void compile(char *code, int *pointer)
{
    unsigned int i;

    for (i = 0; i < strlen(code); i++) {
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
        }
    }
}

int main(int argc, const char *argv[])
{
    int *p = calloc(30000, 30000);
    *p = 0;

    compile("+", p);
    assert(*p == 1);
    compile("-", p);
    assert(*p == 0);
    compile("++", p);
    assert(*p == 2);
    compile("--", p);
    assert(*p == 0);
    compile(">", p);
    assert(*++p == 0);
    compile("<", p);
    assert(*++p == 0);
    compile(">+", p);
    assert(*++p == 1);
    compile("<+", p);
    assert(*--p == 1);

    printf("Success!\n");

    return 0;
}
