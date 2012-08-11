#include "compiler.h"

void compile(int code)
{
  switch(code) {
    case PLUS:
      printf("got PLUS\n");
      break;
    case MINUS:
      printf("got MINUS\n");
      break;
    case LEFT:
      printf("got LEFT\n");
      break;
    case RIGHT:
      printf("got RIGHT\n");
      break;
    case DOT:
      printf("got DOT\n");
      break;
    case COMMA:
      printf("got COMMA\n");
      break;
    default:
      printf("dafuq is this?\n");
  }
}
