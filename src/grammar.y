%{

#include <stdio.h>

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
          PLUS { printf("PLUS\n"); }
           | MINUS { printf("MINUS\n"); }
           | LEFT { printf("LEFT\n"); }
           | RIGHT { printf("RIGHT\n"); }
           | DOT { printf("DOT\n"); }
           | COMMA { printf("COMMA\n"); }
           | OPEN_BRACKET { printf("OPEN_BRACKET\n"); }
           | CLOSE_BRACKET { printf("CLOSE_BRACKET\n"); }
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
