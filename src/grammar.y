%{

#include <stdio.h>
#include "compiler.h"

int yylex();
int yyparse();
FILE *yyin;

%}

%start list

%token PLUS MINUS
%token LEFT RIGHT
%token DOT COMMA
%token OPEN_BRACKET CLOSE_BRACKET

%%

list: /* empty */
  | list expression
  ;

expression:
          PLUS { compile(PLUS); }
           | MINUS { compile(MINUS); }
           | LEFT { compile(LEFT); }
           | RIGHT { compile(RIGHT); }
           | DOT { compile(DOT); }
           | COMMA { compile(COMMA); }
           | OPEN_BRACKET { compile(OPEN_BRACKET); }
           | CLOSE_BRACKET { compile(CLOSE_BRACKET); }
           ;

%%
int main (int argc, char const* argv[])
{
  ++argv, --argc;

  if (argc > 0)
    yyin = fopen(argv[0], "r");
  else
    yyin = stdin;

  do {
    yyparse();
  } while (!feof(yyin));

  return 0;
}
