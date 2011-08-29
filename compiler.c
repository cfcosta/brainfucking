#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void compile(char *code, int *pointer)
{
    if (!strncmp(code,"+", 1)) ++*pointer;
    if (!strncmp(code,"-", 1)) --*pointer;
}

int main (int argc, const char *argv[])
{
    int *p = malloc(sizeof(int));
    *p = 0;

    compile("+", p);
    assert(*p == 1);
    compile("-", p);
    assert(*p == 0);
    compile("++", p);
    assert(*p == 2);
    compile("--", p);
    assert(*p == 0);

    return 0;
}
