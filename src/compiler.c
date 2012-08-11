#include "compiler.h"

void compile(int code)
{
  switch(code) {
    case PLUS:
      printf("got PLUS\n");
    case MINUS:
      printf("got MINUS\n");
  }
}
