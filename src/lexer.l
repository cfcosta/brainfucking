%{
#include "y.tab.h"
%}

plus \+
minus -
left \<
right \>
dot \.
comma \,
open_bracket \[
close_bracket \]

%option bison-bridge

%%

{plus} { return PLUS; }
{minus} { return MINUS; }
{left} { return LEFT; }
{right} { return RIGHT; }
{dot} { return DOT; }
{comma} { return COMMA; }
{open_bracket} { return OPEN_BRACKET; }
{close_bracket} { return CLOSE_BRACKET; }
. /* ignore all other input*/

%%
