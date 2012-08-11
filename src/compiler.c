#include "compiler.h"

void initialize_pointer() {
  pointer = calloc(30000,30000);
}

void compile(int code)
{
  switch(code) {
    case PLUS:
      ++*pointer;
      break;
    case MINUS:
      --*pointer;
      break;
    case RIGHT:
      ++pointer;
      break;
    case LEFT:
      --pointer;
      break;
    case DOT:
      putchar(*pointer);
      break;
    case COMMA:
      printf("got COMMA\n");
      break;
    default:
      printf("dafuq is this?\n");
      break;
  }
}
